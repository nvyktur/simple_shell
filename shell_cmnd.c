#include "shell.h"

/**
 * display_history - displays the history , starting at 0.
 * @data: A structure that holds arguments,
 *   intended to uphold a constant function.
 * Return: Always 0
 */
int display_history(data_t *data)
{
print_list(data->history);
return (0);
}

/**
 * nosetting_alias - sets alias to string
 * @data: parameter struct
 * @string: the string alias
 * @Deborah @Victor
 * Return: Always 0 on success, 1 on error
 */
int nosetting_alias(data_t *data, char *string)
{
char *h, m;
int r;

h = _strchr(string, '=');
if (!h)
return (1);
m = *h;
*h = 0;
r = delete_node_at_index(&(data->alias),
get_node_index(data->alias,
starts_the_node(data->alias, str, -1)));
*h = m;
return (r);
}

/**
 * sets_alias - sets alias to string
 * @data: parameter struct
 * @string: the string alias
 * Return: Always 0 on success, 1 on error
 */
int sets_alias(data_t *data, char *string)
{
char *h;

h = _strchr(string, '=');
if (!h)
return (1);
if (!*++h)
return (nosetting_alias(data, string));

nosetting_alias(data, string);
return (add_node_end(&(data->alias), string, 0) == NULL);
}

/**
 * print_alias - prints an alias string
 * @n: the alias node
 * @Deborah and @Victor
 * Return: Always 0 on success, 1 on error
 */
int print_alias(list_t *n)
{
char *h = NULL, *m = NULL;

if (n)
{
h = _strchr(n->str, '=');
for (m = n->str; m <= h; m++)
_putchar(*m);
_putchar('\'');
_puts(h + 1);
_puts("'\n");
return (0);
}
return (1);
}

/**
 * mimic_alias - mimics the alias
 * @data: A structure that holds arguments,
 *   intended to uphold a constant function.
 * Return: Always 0
 */
int mimic_alias(data_t *data)
{
int i = 0;
char *h = NULL;
list_t *n = NULL;

if (data->argc == 1)
{
n = data->alias;
while (n)
{
print_alias(n);
n = n->next;
}
return (0);
}
for (i = 1; data->argv[i]; i++)
{
h = _strchr(data->argv[i], '=');
if (h)
sets_alias(data, data->argv[i]);
else
print_alias(node_starts_with(data->alias,
data->argv[i], '='));
}
return (0);
}
