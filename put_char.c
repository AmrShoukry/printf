#include <unistd.h>
#include "main.h"

/**
 * put_char - Entry point
 *
 * @character: character
 *
 * Description: 'print a character'
 *
 * Return: Always 0 (Success)
 */

void put_char(char character)
{
	write(1, &character, 1);
}
