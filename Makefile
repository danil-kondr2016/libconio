OBJS=src/getch.o src/putch.o src/kbhit.o
CFLAGS=-Iinclude/

libconio.a: $(OBJS)
	ar rcs $@ $(OBJS)

.c.o:
	cc -c $(CFLAGS) $< -o $@

clean:
	rm $(OBJS) libconio.a
