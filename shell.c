Shell.c


#ifndef SHELL_H
#define SHELL_H

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <signal.h>
#include <fcntl.h>

typedef struct information {
    char *program_name;
    char *input_line;
    char *command_name;
    int exec_counter;
    int file_descriptor;
    char **tokens;
    char **env;
    char **alias_list;
} information_t;

typedef struct builtins {
    char *builtin;
    int (*function)(information_t *info);
} builtins;

void inicialize_data(information_t *data, int arc, char *argv[], char **env);
void sisifo(char *prompt, information_t *data);
void handle_ctrl_c(int opr UNUSED);

int _getline(information_t *info);
int check_logic_ops(char *array_cmmnd[], int i, char array_operators[]);

int builtin_exit(information_t *info);
int builtin_cd(information_t *info);
int set_work_directory(information_t *info, char *new_dir);
int builtin_help(information_t *info);
int builtin_alias(information_t *info);

int print_alias(information_t *info, char *alias);
char *get_alias(information_t *info, char *name);
int set_alias(char *alias_string, information_t *info);

int builtin_env(information_t *info);
int builtin_set_env(information_t *info);
char *builtin_get_env(information_t *info, const char *name);
int builtin_unset_env(information_t *info);

void expand_variables(information_t *data);
void expand_alias(information_t *data);
int buffer_add(char *buffer, char *str_to_add);

void tokenize(information_t *data);
char *_strtok(char *line, char *delim);

int execute(information_t *data);
int builtins_list(information_t *data);

char **tokenize_path(information_t *data);
int find_program(information_t *data);

void free_array_of_pointers(char **directories);
void free_recurrent_data(information_t *data);
void free_all_data(information_t *data);

int _print(char *string);
int _printe(char *string);
int _print_error(int errorcode, information_t *data);

int str_length(char *string);
char *str_duplicate(char *string);
int str_compare(char *string1, char *string2, int number);
char *str_concat(char *string1, char *string2);
void str_reverse(char *string);

void long_to_string(long number, char *string, int base);
int _atoi(char *s);
int count_characters(char *string, char *character);

#endif

