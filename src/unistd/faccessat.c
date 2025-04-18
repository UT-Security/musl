#include <unistd.h>
#include <fcntl.h>
#include <sys/wait.h>
#include "syscall.h"
#include "pthread_impl.h"

struct ctx {
	int fd;
	const char *filename;
	int amode;
	int p;
};

static int checker(void *p)
{
	struct ctx *c = p;
	int ret;
	ret = __syscall(SYS_faccessat, c->fd, c->filename, c->amode, 0);
	__syscall(SYS_write, c->p, &ret, sizeof ret);
	return 0;
}

int faccessat(int fd, const char *filename, int amode, int flag)
{
	if (flag) {
		int ret = __syscall(SYS_faccessat2, fd, filename, amode, flag);
		if (ret != -ENOSYS) return __syscall_ret(ret);
	}

	if (flag & ~AT_EACCESS)
		return __syscall_ret(-EINVAL);

	if (!flag)
		return syscall(SYS_faccessat, fd, filename, amode);

    return __syscall_ret(-EINVAL);
}
