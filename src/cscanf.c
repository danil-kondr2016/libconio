#include <conio.h>

#include <stdio.h>
#include <stdarg.h>

int _vcscanf(const char * fmt, va_list vl)
{
	FILE * f;
	int ret;

	f = fopen("/dev/tty", "rb");
	ret = vfscanf(f, fmt, vl);

	fclose(f);
	return ret;
}

as_scanf
int _cscanf(const char * fmt, ...)
{
	va_list vl;
	int ret;

	va_start(vl, fmt);
	ret = _vcscanf(fmt, vl);
	va_end(vl);

	return ret;
}
