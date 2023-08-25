#include "shell.h"

/**
 * get_env - gets string array copy
 * @data: A structure that holds arguments,
 *   intended to uphold a constant function.
 * @Victor and @Deborah
 * Return: 0
 */

char **get_env(data_t *data)
{
if (!data->env_list || data->env_modify)
{
data->env_list = list_str(data->env_list);
data->env_modify = 0;
}
return (data->env_list);
}

/**
 * remove_env - remove the variable.
 * @data: A structure that holds arguments,
 *          intended to uphold a constant function.
 * @var_name: The variable to be removed.
 * Return: 0 on success, 1 on failure.
 */

int remove_env(data_t *data, char *var_name)
{
node_t *t = data->env_list;
size_t r = 0;
char *m;

if (!n || !var_name)
return (0);
while (t)
{
m = starting(n->str, var_name);
if (m && *m == '=')
{
data->env_modify = del_node_index(&(data->env_list), w);
w = 0;
t = data->env_list;
continue;
}
t = t->next;
w++;
}
return (data->env_modify);
}

/**
 * establish_env - environment variable initialization
 * @data: A structure that holds arguments,
 *   intended to uphold a constant function.
 * @var: variable
 * @w: The value to set for the variable.
 * Return:0 on success, 1 on failure.
 */

int establish_env(data_t *data, char *var, char *w)
{
char *buffer = NULL;
node_t *t;
char *m;

if (!var || !w)
return (0);
buffer = malloc(str_length(var) + str_length(w) + 2);
if (!buffer)
return (1);
str_copy(buffer, var);
str_cat(buffer, "=");
str_cat(buffer, w);
t = data->environment;
while (t)
{
m = starting(t->str, var);
if (m && *m == '=')
{
free(t->str);
t->str = buffer;
data->env_modify = 1;
return (0);
}
t = t->next;
}
add_node_at_end(&(data->environment), buffer, 0);
free(buffer);
data->env_modify = 1;
return (0);
}
