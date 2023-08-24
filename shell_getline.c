#include "shell.h"

int _getline(information_t *info) {
    char buff[BUFFER_SIZE] = {'\0'};
    static char *array_cmmnd[10] = {NULL};
    static char array_operators[10] = {'\0'};
    ssize_t bytes_read;
    int i = 0;
  
    if (!array_cmmnd[0] || (array_operators[0] == '&' && errno != 0) || (array_operators[0] == '|' && errno == 0)) {
        for (i = 0; array_cmmnd[i]; i++) {
            free(array_cmmnd[i]);
            array_cmmnd[i] = NULL;
        }

        bytes_read = read(info->file_descriptor, &buff, BUFFER_SIZE - 1);
        if (bytes_read == 0)
            return (-1);

        i = 0;
        do {
            array_cmmnd[i] = str_duplicate(_strtok(i ? NULL : buff, "\n;"));
            i = check_logic_ops(array_cmmnd, i, array_operators);
        } while (array_cmmnd[i++]);
    }

    data->input_line = array_cmmnd[0];

    for (i = 0; array_cmmnd[i]; i++) {
        array_cmmnd[i] = array_cmmnd[i + 1];
        array_operators[i] = array_operators[i + 1];
    }

    return str_length(info->input_line);
}

int check_logic_ops(char *array_cmmnd[], int i, char array_operators[]) {
    char *temp = NULL;
    int m;

    for (m = 0; array_cmmnd[i] && array_cmmnd[i][m]; m++) {
        if (array_cmmnd[i][m] == '&' && array_cmmnd[i][m + 1] == '&') {
            temp = array_cmmnd[i];
            array_cmmnd[i][m] = '\0';
            array_cmmnd[i] = str_duplicate(array_cmmnd[i]);
            array_cmmnd[i + 1] = temp + m + 2;
            i++;
            array_operators[i] = '&';
            m = -1; // Reset to -1 to compensate for the increment in the loop
        } else if (array_cmmnd[i][m] == '|' && array_cmmnd[i][m + 1] == '|') {
            temp = array_cmmnd[i];
            array_cmmnd[i][m] = '\0';
            array_cmmnd[i] = str_duplicate(array_cmmnd[i]);
            array_cmmnd[i + 1] = temp + m + 2;
            i++;
            array_operators[i] = '|';
            m = -1; // Reset to -1 to compensate for the increment in the loop
        }
    }
    return i;
}

