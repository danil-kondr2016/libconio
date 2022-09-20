#include <conio.h>

#include <termios.h>
#include <unistd.h>
#include <fcntl.h>

int _putch(int ch)
{
	int fd;

	fd = open("/dev/tty", O_RDWR);
	if (write(fd, &ch, 1) <= 0)
		ch = -1;
	close(fd);
	return ch;
}
