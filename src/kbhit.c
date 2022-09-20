#include <conio.h>

#include <string.h>
#include <termios.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/time.h>
#include <sys/select.h>

int _kbhit(void)
{
	struct termios o, n;
	struct timeval tv;
	fd_set set;
	int c;
	int fd;

	fd = open("/dev/tty", O_RDWR);
	memset(&tv, 0, sizeof(tv));

	tcgetattr(fd, &o);

	n = o;
	n.c_lflag &= ~(ICANON | ECHO);
	tcsetattr(fd, TCSANOW, &n);

	FD_ZERO(&set);
	FD_SET(fd, &set);

	select(1, &set, 0, 0, &tv);

	if (FD_ISSET(fd, &set)) {
		c = 1;
	} else {
		c = 0;
	}

	tcsetattr(fd, TCSANOW, &o);

	return c;
}
