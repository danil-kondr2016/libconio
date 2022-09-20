OBJS=src/getch.o src/putch.o src/kbhit.o
OBJS+=src/cprintf.o src/cputs.o src/cscanf.o
OBJS+=src/cgets.o
CFLAGS=-Iinclude/

PREFIX=/usr/local

libconio.a: $(OBJS)
	ar rcs $@ $(OBJS)

.c.o:
	cc -c $(CFLAGS) $< -o $@

clean:
	rm $(OBJS) libconio.a

install:
	install -m644 -t$(PREFIX)/include include/conio.h
	install -m644 -t$(PREFIX)/lib libconio.a

uninstall:
	rm $(PREFIX)/include/conio.h
	rm $(PREFIX)/lib/libconio.a
