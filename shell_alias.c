#include "shell.h"

int print_alias(information_t *info, char *alias) {
    if (!info->alias_list)
        return 0;

    int alias_length = (alias) ? str_length(alias) : 0;
    char buffer[250];

    for (int i = 0; info->alias_list[i]; i++) {
        if (!alias || (str_compare(info->alias_list[i], alias, alias_length) &&
            info->alias_list[i][alias_length] == '=')) {
            snprintf(buffer, sizeof(buffer), "'%s'\n", info->alias_list[i]);
            _print(buffer);
        }
    }

    return 0;
}

char *get_alias(information_t *info, char *name) {
    if (!name || !info->alias_list)
        return NULL;

    int alias_length = str_length(name);

    for (int i = 0; info->alias_list[i]; i++) {
        if (str_compare(name, info->alias_list[i], alias_length) &&
            info->alias_list[i][alias_length] == '=') {
            return info->alias_list[i] + alias_length + 1;
        }
    }

    return NULL;
}

int set_alias(char *alias_string, information_t *info) {
    if (!alias_string || !info->alias_list)
        return 1;

    int i = 0;
    while (alias_string[i] && alias_string[i] != '=')
        i++;

    char *temp = get_alias(info, alias_string + i + 1);

    for (int m = 0; info->alias_list[m]; m++) {
        if (str_compare(alias_string, info->alias_list[m], i) &&
            info->alias_list[m][i] == '=') {
            free(info->alias_list[m]);
            break;
        }
    }

    char buffer[250];
    snprintf(buffer, sizeof(buffer), "%s%s", alias_string, (temp) ? temp : "");
    info->alias_list[i] = str_duplicate(buffer);

    return 0;
}
