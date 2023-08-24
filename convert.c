#include "shell.h"

int interactive(info_t *info) {
    return (isatty(STDIN_FILENO) && info->readfd <= 2);
}

int _myalpha(int c) {
    return ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z'));
}

int _atoi(char *s) {
    int i, sign = 1, flag = 0, output;
    unsigned int result = 0;

    for (i = 0; s[i] != '\0' && flag != 2; i++) {
        if (s[i] == '-') {
            sign *= -1;
        }

        if (s[i] >= '0' && s[i] <= '9') {
            flag = 1;
            result *= 10;
            result += (s[i] - '0');
        } else if (flag == 1) {
            flag = 2;
        }
    }

    output = (sign == -1) ? -result : result;
    return output;
}

char *num_converter(long int num, int b, int f) {
    static char buffer[50];
    char s = 0;
    char *pointer;
    unsigned long num_copy = (f & UNSIGNED_CONVERTER) ? num : -num;

    pointer = &buffer[49];
    *pointer = '\0';
    do {
        *--pointer = (f & LOWERCASE_CONVERTER) ? "0123456789abcdef"[num_copy % b] : "0123456789ABCDEF"[num_copy % b];
        num_copy /= b;
    } while (num_copy != 0);
    
    if (!(f & UNSIGNED_CONVERTER) && num < 0) {
        *--pointer = '-';
    }
    
    return pointer;
}

int my_delim(char c, char *delim) {
    while (*delim) {
        if (*delim++ == c) {
            return 1;
        }
    }
    return 0;
}
