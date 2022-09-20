#include <conio.h>

#include <stdio.h>
#include <stdarg.h>

int _vcprintf(const char * fmt, va_list vl)
{
	FILE * f;
	int ret;

	f = fopen("/dev/tty", "wb");
	ret = vfprintf(f, fmt, vl);

	fclose(f);
	return ret;
}

as_printf
int _cprintf(const char * fmt, ...)
{
	va_list vl;
	int ret;

	va_start(vl, fmt);
	ret = _vcprintf(fmt, vl);
	va_end(vl);

	return ret;
}
