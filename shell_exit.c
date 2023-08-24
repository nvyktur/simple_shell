#include "shell.h"

/**
 * strn_cpy - copies a string
 * @dest: the destination string to be copied to
 * @src: the source
 * @n: the amount of characters to be copied
 * Return: a pointer to the destination
 */
char *strn_cpy(char *dest, const char *src, int n)
{
    int j;

    for (j = 0; j < n - 1 && src[j] != '\0'; j++)
        dest[j] = src[j];
    dest[j] = '\0';

    return dest;
}

/**
 * str_chr - locates a character in a string
 * @s: string to be parsed
 * @c: the char
 * Return: a pointer to the memory area s where the character was found, or NULL if not found
 */
char *str_chr(const char *s, char c)
{
    while (*s != '\0')
    {
        if (*s == c)
            return (char *)s;
        s++;
    }

    return NULL;
}

/**
 * str_dup - duplicate the string
 * @s: the string to be duplicated
 * Return: a pointer to the duplicated string, or NULL if memory allocation fails
 */
char *str_dup(const char *s)
{
    size_t len = str_length(s);
    char *end = malloc(len + 1);

    if (end)
        str_n_cpy(end, s, len + 1);

    return end;
}

