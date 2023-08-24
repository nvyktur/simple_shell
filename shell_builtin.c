#include "shell.h"

int builtin_exit(information_t *info) {
    if (info->tokens[1]) {
        for (int i = 0; info->tokens[1][i]; i++) {
            if ((info->tokens[1][i] < '0' || info->tokens[1][i] > '9') &&
                info->tokens[1][i] != '+') {
                errno = 2;
                return 2;
            }
        }
        errno = _atoi(info->tokens[1]);
    }
    free_all_info(info);
    exit(errno);
}

int builtin_cd(information_t *info) {
    char *dir_home = env_get_key("HOME", info);
    char *dir_old = NULL;
    char old_dir[128] = {0};
    int error_code = 0;

    if (info->tokens[1]) {
        if (str_compare(info->tokens[1], "-", 0)) {
            dir_old = env_get_key("OLDPWD", info);
            if (dir_old) {
                error_code = set_work_directory(info, dir_old);
                _print(env_get_key("PWD", info));
                _print("\n");
                return error_code;
            }
        } else {
            return set_work_directory(info, info->tokens[1]);
        }
    } else {
        if (!dir_home)
            dir_home = getcwd(old_dir, sizeof(old_dir));
        return set_work_directory(info, dir_home);
    }
    return 0;
}

int set_work_directory(information_t *info, char *new_dir) {
    char old_dir[128] = {0};
    getcwd(old_dir, sizeof(old_dir));

    if (!str_compare(old_dir, new_dir, 0)) {
        int err_code = chdir(new_dir);
        if (err_code == -1) {
            errno = 2;
            return 3;
        }
        env_set_key("PWD", new_dir, info);
    }
    env_set_key("OLDPWD", old_dir, info);
    return 0;
}

int builtin_help(information_t *info) {
    char *help_messages[6] = {
        HELP_EXIT_MSG, HELP_ENV_MSG, HELP_SETENV_MSG,
        HELP_UNSETENV_MSG, HELP_CD_MSG, NULL
    };

    if (info->tokens[1] == NULL) {
        _print(HELP_MSG + 6);
        return 1;
    }

    for (int i = 0; help_messages[i]; i++) {
        if (str_compare(info->tokens[1], help_messages[i], str_length(info->tokens[1]))) {
            _print(help_messages[i] + str_length(info->tokens[1]) + 1);
            return 1;
        }
    }

    errno = EINVAL;
    perror(info->command_name);
    return 0;
}

int builtin_alias(information_t *info) {
    if (info->tokens[1] == NULL)
        return print_alias(info, NULL);

    int i = 0;
    while (info->tokens[++i]) {
        if (count_characters(data->tokens[i], "="))
            set_alias(info->tokens[i], info);
        else
            print_alias(info, info->tokens[i]);
    }

    return 0;
}

