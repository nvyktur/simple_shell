#include "shell.h"

int builtin_env(information_t *info) {
    if (info->tokens[1] == NULL)
        print_environ(info);
    else {
        char cpname[50] = {'\0'};
        char *var_copy = NULL;
        int i;

        for (i = 0; info->tokens[1][i] && info->tokens[1][i] != '='; i++)
            cpname[i] = info->tokens[1][i];

        if (info->tokens[1][i] == '=') {
            var_copy = str_duplicate(env_get_key(cpname, info));
            if (var_copy != NULL) {
                env_set_key(cpname, info->tokens[1] + i + 1, info);
                print_environ(info);
                if (env_get_key(cpname, info) == NULL) {
                    _print(info->tokens[1]);
                    _print("\n");
                } else {
                    env_set_key(cpname, var_copy, info);
                    free(var_copy);
                }
            }
        } else {
            errno = 2;
            perror(info->command_name);
            errno = 127;
        }
    }
    return 0;
}

int builtin_set_env(information_t *info) {
    if (info->tokens[1] == NULL || info->tokens[2] == NULL)
        return 0;
    if (info->tokens[3] != NULL) {
        errno = E2BIG;
        perror(info->command_name);
        return 5;
    }
    env_set_key(info->tokens[1], info->tokens[2], info);
    return 0;
}

char *builtin_get_env(information_t *info, const char *name) {
    list_t *node = info->env;

    while (node) {
        char *h = starts_with(node->string, name);
        if (h && *h)
            return h;
        node = node->next;
    }
    return NULL;
}

int builtin_unset_env(information_t *info) {
    if (info->tokens[1] == NULL)
        return 0;
    if (info->tokens[2] != NULL) {
        errno = E2BIG;
        perror(info->command_name);
        return 5;
    }
    env_remove_key(info->tokens[1], info);
    return 0;
}
