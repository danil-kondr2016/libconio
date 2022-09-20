#include <conio.h>

/* Самая небезопасная функция в библиотеке, как и функция
 * gets(), которая помечена устаревшей в C99 и удалена в С11. 
 */
char * _cgets(char * x)
{
	int c;

	while ((c = _getche()) != -1) {
		*x++ = (char)c;
	}
	*x++ = '\0';

	return x;
}
