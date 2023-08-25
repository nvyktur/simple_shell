#include "shell.h"

/**
* strn_cpy - copies a string
* @destination: the destination string to be copied to
* @source: the source
* @n: the amount of characters to be copied
* Return: (p) pointer to the destination
*/
char *strn_cpy(char *destination, char *source, int n);
{
int v, d;
char *result = destination;

v = 0;
while (source[v] != '\0' && v < n - 1)
{
destination[v] = source[v];
v++;
}
if (v < n)
{
d = v;
while (d < n)
{
destination[d] = '\0';
d++;
}
}
return (p);
}

/**
* str_chr - locates a character in a string
* @string: string to be parsed
* @character: the character
* Return: (p) a pointer to the memory
*/
char *str_chr(char *string, char character)
{
do {
if (*string == character)
return (p);
} while (*string++ != '\0');

return (NULL);
}

/**
* str_dup - duplicate the string
* @string: the string to be duplicated
* Return: the value of end
*/
char *str_dup(const char *string)
{
int l = 0;
char *end;

if (string == NULL)
return (NULL);
while (*string++)
l++;
end = malloc(sizeof(char) * (l + 1));

if (!end)
return (NULL);
for (l++; l--;)
end[l] = *--string;
return (end);
}
