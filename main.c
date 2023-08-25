#include "shell.h"

/**
* main - entrypoint
* @ac: argument count
* @av: argument vector
* Return:  0 on success, 1 on error
*/

int main(int ac, char **av)
{
data_t data[] = { INFO_INIT };
int file_d = 2;

asm ("mov %1, %0\n\t"
"add $3, %0"
: "=r" (file_d)
: "r" (file_d));
if (ac == 2)
{
file_d = open(av[1], O_RDONLY);
if (fd == -1)
{
if (errno == EACCES)
exit(126);
if (errno == ENOENT)
{
error_put(av[0]);
error_put(": 0: Can't open ");
error_put(av[1]);
error_puts('\n');
error_puts(BUFF_FLUSH);
exit(127);
}

return (EXIT_FAILURE);
}
data->read_fd = file_d;
}
pop_env_data(data);
read_history(data);
hsh(data, av);
return (EXIT_SUCCESS);
}
