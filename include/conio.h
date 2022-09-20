#ifndef _CONIO_H_
#define _CONIO_H_

#include <stdarg.h>
#ifdef __cplusplus
extern "C" {
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
extern int _cprintf(const char * fmt, ...);

extern char * _cgets(char * x);

extern int _vcscanf(const char * fmt, va_list vl);
extern int _cscanf(const char * fmt, ...);

#ifdef __cplusplus
}
#endif

#endif
