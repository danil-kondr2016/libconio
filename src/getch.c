#include <conio.h>

#include <termios.h>
#include <unistd.h>
#include <fcntl.h>

#define GETCH_BUF_SIZE 4096
static int _getch_buf[GETCH_BUF_SIZE];
static int _getch_c = 0;

static int _getchx(int echo)
{
	struct termios o, n;
	int c;
	int fd;

	fd = open("/dev/tty", O_RDWR);
	tcgetattr(fd, &o);

	n = o;
	n.c_lflag &= ~ICANON;
	if (!echo)
		n.c_lflag &= ~ECHO;
	else
		n.c_lflag |= ECHO;

	tcsetattr(fd, TCSANOW, &n);

	if (read(fd, &c, 1) <= 0)
		c = -1;

	tcsetattr(fd, TCSANOW, &o);
	close(fd);

	return c;
}

int _getch(void)
{
	if (_getch_c < 1)
		return _getchx(0);
	else
		return _getch_buf[--_getch_c];
}

int _getche(void)
{
	if (_getch_c < 1)
		return _getchx(1);
	else
		return _getch_buf[--_getch_c];
}

int _ungetch(int ch)
{
	if (_getch_c >= GETCH_BUF_SIZE)
		return -1;

	_getch_buf[_getch_c++] = ch;

	return ch;
}
