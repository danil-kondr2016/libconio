#include "conio.h"

#include <termios.h>
#include <unistd.h>
#include <fcntl.h>

int _putch(int ch)
{
	if (write(STDOUT_FILENO, &ch, 1) <= 0)
		ch = -1;
	return ch;
}

int putch(int ch)
{
	return _putch(ch);
}
