#ifndef _CONIO_H_
#define _CONIO_H_

#include <stdarg.h>
#ifdef __cplusplus
extern "C" {
#endif

#if defined(__GNUC__)
#define as_printf __attribute__((format(printf, 1, 2)))
#define as_scanf __attribute__((format(scanf, 1, 2)))
#else
#define as_printf
#define as_scanf
#endif

#define getch _getch
#define getche _getche
#define ungetch _ungetch
#define kbhit _kbhit
#define putch _putch

#define cputs _cputs

#define vcprintf _vcprintf
#define cprintf _cprintf

#define vcscanf _vcscanf
#define cscanf _cscanf

extern int _getch(void);
extern int _getche(void);
extern int _ungetch(int ch);
extern int _kbhit(void);
extern int _putch(int ch);

extern int _cputs(const char * x);

extern int _vcprintf(const char * fmt, va_list vl);
extern as_printf int _cprintf(const char * fmt, ...);

extern char * _cgets(char * x);

extern int _vcscanf(const char * fmt, va_list vl);
extern as_scanf int _cscanf(const char * fmt, ...);

#ifdef __cplusplus
}
#endif

#endif
