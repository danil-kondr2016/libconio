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

	memset(&tv, 0, sizeof(tv));

	tcgetattr(STDIN_FILENO, &o);

	n = o;
	n.c_lflag &= ~(ICANON | ECHO);
	tcsetattr(STDIN_FILENO, TCSANOW, &n);

	FD_ZERO(&set);
	FD_SET(STDIN_FILENO, &set);

	select(1, &set, 0, 0, &tv);

	if (FD_ISSET(STDIN_FILENO, &set)) {
		c = 1;
	} else {
		c = 0;
	}

	tcsetattr(STDIN_FILENO, TCSANOW, &o);

	return c;
}

int kbhit(void)
{
	return _kbhit();
}
