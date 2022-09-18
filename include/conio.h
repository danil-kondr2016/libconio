#ifndef _CONIO_H_
#define _CONIO_H_

#ifdef __cplusplus
extern "C" {
#endif

extern int _getch(void);
extern int _getche(void);
extern int _ungetch(int ch);
extern int _kbhit(void);
extern int _putch(int ch);

extern int getch(void);
extern int getche(void);
extern int ungetch(int ch);
extern int kbhit(void);
extern int putch(int ch);

#ifdef __cplusplus
}
#endif

#endif
