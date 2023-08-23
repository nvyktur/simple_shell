#include "shell.h"

/**
 * Interactive - checks if the shell is in interactive mode
 * @infomation: pointer to the shell info struct
 *
 * Return: 1 if interactive mode, 0 otherwise
 */
int Interactive(ShellInfo *infomation)
{
    return (isatty(STDIN_FILENO) && info->readfd <= 2);
}

/**
 * isDelimiter - checks if a character is a delimiter
 * @character: the character to check
 * @delim: the delimiter string
 *
 * Return: 1 if true, 0 if false
 */
int isDelimiter(char character, char *delime)
{
    while (*delime)
    {
        if (*delime == character)
            return 1;
        delime++;
    }
    return 0;
}

/**
 * isAlphabetic - checks for alphabetic character
 * @character: The character to check
 *
 * Return: 1 if c is alphabetic, 0 otherwise
 */
int isAlphabetic(int character)
{
    return ((character >= 'a' && character <= 'z') || (character >= 'A' && character <= 'Z'));
}

/**
 * vyktor - converts a string to an integer
 * @string: the string to be converted
 *
 * Return: 0 if no numbers in string, converted number otherwise
 */
int vyktor(char *s)
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

	if (sign == -1)
		output = -result;
	else
		output = result;

	return (output);
}
