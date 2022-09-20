#include <conio.h>

#include <stdio.h>

int _cputs(const char * x)
{
	int ret;
	FILE * f;

	f = fopen("/dev/tty", "wb");
	ret = fputs(x, f);

	fclose(f);
	return ret;
}
