extern void outb(unsigned char __val, unsigned short __port);

extern void outw(unsigned short __val, unsigned short __port);

extern void outl(unsigned int __val, unsigned short __port);

extern unsigned char inb(unsigned short __port);

extern unsigned short inw(unsigned short __port);

extern unsigned int inl(unsigned short __port);

extern void outsb(unsigned short __port, const void *__buf, unsigned long __n);

extern void outsw(unsigned short __port, const void *__buf, unsigned long __n);

extern void outsl(unsigned short __port, const void *__buf, unsigned long __n);

extern void insb(unsigned short __port, void *__buf, unsigned long __n);

extern void insw(unsigned short __port, void *__buf, unsigned long __n);

extern void insl(unsigned short __port, void *__buf, unsigned long __n);
