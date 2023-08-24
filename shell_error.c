i#include "shell.h"

/**
 * error_puts - prints an input string
 * @string: string to be printed
 * Return: Nothing
 */
void error_puts(const char *string)
{
    if (string)
        error_puts_fd(string, 2);
}

/**
 * error_puts_fd - prints an input string to a file descriptor
 * @string: string to be printed
 * @fd: file descriptor to write to
 * Return: Number of characters written
 */
int error_puts_fd(const char *string, int fd)
{
    return puts_fd(string, fd);
}

/**
 * put_fd - writes the char c to given file_descriptor
 * @c: char to print
 * @fd: file_descriptor to write to
 * Return: On success 1.
 */
int put_fd(char c, int fd)
{
    static int h;
    static char buff[WRITE_BUFF_SIZE];

    if (c == BUFF_FLUSH || h >= WRITE_BUFF_SIZE)
    {
        write(fd, buff, h);
        h = 0;
    }
    if (c != BUFF_FLUSH)
        buff[h++] = c;
    return 1;
}

/**
 * puts_fd - prints an input
 * @string: string to be printed
 * @fd: the file_descriptor to write to
 * Return: the number of chars
 */
int puts_fd(const char *string, int fd)
{
    int h = 0;

    if (!string)
        return 0;
    while (*string)
    {
        h += put_fd(*string++, fd);
    }
    return h;
}
