#include "shell.h"

/**
* shells_exit - exit the shell.
* @data: structure that holds arguments,
*   intended to uphold a constant function.
* @Deborah and @Victor
* Return: exits
* (0) if data.argv[0] != "exit"
*/
int shells_exit(data_t *data)
{
int exit_status;
if (data->argv[1])
{
exit_status = error_stoi(data->argv[1]);
if (exit_status == -1)
{
data->status = 2;
print_error(data, "Illegal number: ");
error_puts(data->argv[1]);
error_putchar('\n');
return (1);
}
data->error_num = exit_status;
return (-2);
}
data->error_num = -1;
return (-2);
}

/**
* change_dir - changes the current directory.
* @data: A structure that holds arguments,
*   intended to uphold a constant function.
* Return: Always 0
*/
int change_dir(data_t *data)
{
char *h, *dir, buffer[1024];
int r;
h = getcwd(buffer, 1024);
if (!h)
_puts("TODO: >>getcwd failure emsg here<<\n");
if (!data->argv[1])
{
dir = get_env(data, "HOME=");
if (!dir)
chdir((dir = get_env(data, "PWD=")) ? dir : "/");
else
r = chdir(dir);
}
else if (str_cmp(data->argv[1], "-") == 0)
{
if (!get_env(data, "OLDPWD="))
{
_puts(buffer);
_putchar('\n');
return (1);
}
_puts(get_env(data, "OLDPWD=")), _putchar('\n');
chdir((dir = get_env(data, "OLDPWD=")) ? dir : "/");
}
else
r = chdir(data->argv[1]);
if (r == -1)
{
print_error(data, "can't cd to ");
error_puts(data->argv[1]), error_putchar('\n');
}
else
{
set_env(data, "OLDPWD", get_env(data, "PWD="));
set_env(data, "PWD", getcwd(buffer, 1024));
}
return (0);
}

/**
* the_help - get the current directory changed.
* @data: A structure that holds arguments,
*   intended to uphold a constant function.
* Return: Always 0
*/
int the_help(data_t *data)
{
char **arg_array;
arg_array = data->argv;
_puts("help call works. Function not yet implemented \n");
return (0);
}
