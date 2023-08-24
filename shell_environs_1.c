#include "shell.h"

char *env_get_key(char *key, information_t *info) {
    int key_length = str_length(key);

    for (int i = 0; info->env[i]; i++) {
        if (str_compare(key, info->env[i], key_length) && info->env[i][key_length] == '=') {
            return info->env[i] + key_length + 1;
        }
    }
    return NULL;
}

int env_set_key(char *key, char *value, information_t *info) {
    int key_length = str_length(key);

    if (key == NULL || value == NULL || info->env == NULL)
        return 1;

    for (int i = 0; info->env[i]; i++) {
        if (str_compare(key, info->env[i], key_length) && info->env[i][key_length] == '=') {
            free(info->env[i]);
            info->env[i] = str_concat(str_duplicate(key), "=");
            info->env[i] = str_concat(info->env[i], value);
            return 0;
        }
    }

    info->env[i] = str_concat(str_duplicate(key), "=");
    info->env[i] = str_concat(info->env[i], value);
    info->env[i + 1] = NULL;
    return 0;
}

int env_remove_key(char *key, information_t *info) {
    int key_length = str_length(key);

    if (key == NULL || info->env == NULL)
        return 0;

    for (int i = 0; info->env[i]; i++) {
        if (str_compare(key, info->env[i], key_length) && info->env[i][key_length] == '=') {
            free(info->env[i]);
            for (int j = i; info->env[j]; j++) {
                info->env[j] = info->env[j + 1];
            }
            return 1;
        }
    }
    return 0;
}

void print_environ(information_t *info) {
    for (int m = 0; info->env[m]; m++) {
        _print(info->env[m]);
        _print("\n");
    }
}

