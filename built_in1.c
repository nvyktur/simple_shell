#include "shell.h"

/**
 * itsHistory - displays the history list, one command by line, preceded
 *              with line numbers, starting at 0.
 * @infomation: Structure containing potential arguments. Used to maintain
 *        constant function prototype.
 *  Return: Always 0
 */
int itsHistory(ShellInfo *infomation)
{
	print_list(infomation->history);
	return (0);
}

/**
 * unset_alias - sets alias to string
 * @info: parameter struct
 * @str: the string alias
 *
 * Return: Always 0 on success, 1 on error
 */
int unset_alias(ShellInfo  *infomation, char *str)
{
	char *p, c;
	int ret;

	p = _strchr(str, '=');
	if (!p)
		return (1);
	c = *p;
	*p = 0;
	ret = delete_node_at_index(&(info->alias),
		get_node_index(info->alias, node_starts_with(info->alias, str, -1)));
	*p = c;
	return (ret);
}

/**
 * set_alias - sets alias to string
 * @infomation: parameter struct
 * @str: the string alias
 *
 * Return: Always 0 on success, 1 on error
 */
int set_alias(ShellInfo *infomation, char *str)
{
	char *p;

	p = _strchr(str, '=');
	if (!p)
		return (1);
	if (!*++p)
		return (unset_alias(infomation, str));

	unset_alias(infomation, str);
	return (add_node_end(&(infomation->alias), str, 0) == NULL);
}

/**
 * print_alias - prints an alias string
 * @node: the alias node
 *
 * Return: Always 0 on success, 1 on error
 */
int print_alias(List *node)
{
	char *p = NULL, *a = NULL;

	if (node)
	{
		p = _strchr(node->str, '=');
		for (a = node->str; a <= p; a++)
		_putchar(*a);
		_putchar('\'');
		_puts(p + 1);
		_puts("'\n");
		return (0);
	}
	return (1);
}

/**
 * itsAlias - mimics the alias builtin (man alias)
 * @infomation: Structure containing potential arguments. Used to maintain
 *          constant function prototype.
 *  Return: Always 0
 */
int itsAlias(ShellInfo *infomation)
{
	int i = 0;
	char *p = NULL;
	List *node = NULL;

	if (infomation->argc == 1)
	{
		node = infomation->alias;
		while (node)
		{
			print_alias(node);
			node = node->next;
		}
		return (0);
	}
	for (i = 1; infomation->argv[i]; i++)
	{
		p = _strchr(infomation->argv[i], '=');
		if (p)
			set_alias(infomation, infomation->argv[i]);
		else
			print_alias(node_starts_with(infomation->alias, infomation->argv[i], '='));
	}

	return (0);
}
