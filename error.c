#include "shell.h"

/**
 * error_put - prints an input string
 * @data_string: string to be printed
 * Return: Nothing
 */
void error_put(char *data_string)
{
int r = 0;

if (!data_string)
return;
while (str[r] != '\0')
{
error_put(str[r]);
r++;
}
}

/**
 * error_puts - writes the char c to input
 * @character: The char to print
 * Return: On success 1, On error, -1 is returned
 */
int error_puts(char character)
{
static int r;
static char buff[WRIT_BUFF_SIZE];

if (character == BUFF_FLUSH || r >= WRIT_BUFF_SIZE)
{
write(2, buff, r);
r = 0;
}
if (character != BUFF_FLUSH)
buff[r++] = character;
return (1);
}

/**
 * put_file_d - writes the charcter to given file_descriptor
 * @character: char to print
 * @file_d: file_descriptor to write to
 * Return: On success 1.
 */
int put_file_d(char character, int file_d)
{
static int r;
static char buff[WRIT_BUFF_SIZE];

if (character == BUFF_FLUSH || r >= WRIT_BUFF_SIZE)
{
write(file_d, buff, r);
r = 0;
}
if (character != BUFF_FLUSH)
buff[r++] = character;
return (1);
}

/**
 * puts_file_d - prints an input
 * @data_string: string to be printed
 * @file_d: the file_descriptor to write to
 * Return: the number of chars
 */
int puts_file_d(char *data_string, int file_d)
{
int r = 0;

if (!data_string)
return (0);
while (*data_string)
{
r += put_file_d(*data_string++, file_d);
}
return (r);
}
