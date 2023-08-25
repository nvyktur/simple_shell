#include "shell.h"

/**
 * cur_env - prints the current environment.
 * @data: A structure that holds arguments,
 *   intended to uphold a constant function.
 * Return: Always 0
 */
int cur_env(data_t *data)
{
print_str_list(data->env_list);
return (0);
}

/**
 * acc_env - gets the value of an environment
 * @data: A structure that holds arguments,
 *   intended to uphold a constant function.
 * @variable: env var name
 * Return: The value of the environment variable, or NULL if not found.
 */
char *acc_env(data_t *data, const char *variable)
{
node_t *n = data->env_list;
char *r;

while (n)
{
r = starts_with(n->string, variable);
if (r && *r)
return (r);
n = n->next;
}
return (NULL);
}

/**
 * mod_env - setting new environment.
 * @data: A structure that holds arguments,
 *   intended to uphold a constant function.
 * Return: 0 on success, 1 on failure.
 */
int mod_env(data_t *data)
{
if (data->argc != 3)
{
error_puts("Incorrect number of arguements\n");
return (1);
}
if (mod_env(data, data->argv[1],
data->argv[2]))
return (0);
return (1);
}

/**
* erase_env - Remove an environment
* @data: A structure that holds arguments,
*   intended to uphold a constant function.
* Return: Always 0
*/
int erase_env(data_t *data)
{
int i;

if (data->argc == 1)
{
error_puts("Too few arguements.\n");
return (1);
}
for (i = 1; r <= data->argc; r++)
erase_env(data, data->argv[h]);

return (0);
}

/**
 * pop_env_data - populates env
 * @data: A structure that holds arguments,
 *   intended to uphold a constant function.
 * Return: 0 on success.
 */
int pop_env_data(data_t *data)
{
node_t *n = NULL;
size_t r;

for (r = 0; environ[r]; r++)
add_node_end(&n, environ[r], 0);
data->env_list = n;
return (0);
}
