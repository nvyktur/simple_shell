#include "shell.h"

/**
* interact - returns true if shell is interactive mode
* @data: pointer structure that holds arguments,
*   intended to uphold a constant function.
* @Deborah and Victor
* Return: 1 if interactive mode, 0 otherwise
*/

int interact(data_t *data)
{
return (isatty(STDIN_FILENO) && data->readfd <= 2);
}

/**
* _myalphabet - checks for alphabetic character
* @character: character
* Return: 1 if alphabetic, 0 otherwise
*/

int _myalphabet(int character)
{
if ((character >= 'a' && character <= 'z') || (character >= 'A' && character <= 'Z'))
return (1);
else
return (0);
}

/**
* _stoi - converts a string to an integer
* @s: the string to be converted
* @Deborah and Victor
* Return: The converted number if successful, otherwise 0.
*/

int _stoi(char *s)
{
int i, sign = 1, flag = 0, output;
unsigned int result = 0;

for (i = 0; s[i] != '\0' && flag != 2; i++)
{
if (s[i] == '-')
sign *= -1;

if (s[i] >= '0' && s[i] <= '9')
{
flag = 1;
result *= 10;
result += (s[i] - '0');
}
else if (flag == 1)
flag = 2;
}

output = (sign == -1) ? -result : result;
return (output);
}

/**
* _delimeter - checks if character is a delimeter
* @character: the char
* @delime: the delimeter string
* Return: 1 if true, 0 if false
*/
int _delimeter(char character, char *delime)
{
while (*delime)
if (*delime++ == character)
return (1);
return (0);
}

/**
* convert_to_num - function to convert numbers
* @num: number
* @b: base of the number
* @f: flags
* Return: pointer value
*/

char *convert_to_num(long int num, int b, int f)
{
static char *arr;
static char buffer[50];
char s = 0;
char *pointer;
unsigned long num = num;

if (!(f & UNSIGNED_CONVERTER) && num < 0)
{
num = -num;
s = '-';
}
arr = f & LOWERCASE_CONVERTER ?
"0123456789abcdef" : "0123456789ABCDEF";
pointer = &buffer[49];
*pointer = '\0';
do {
*--pointer = arr[num % b];
num /= b;
} while (num != 0);
if (s)
*--pointer = s;
return (pointer);
}
