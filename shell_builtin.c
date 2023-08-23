#include "shell.h"

/**
 * Exit - Exits the shell
 * @infomation: Structure containing potential arguments.
 * Return: Exits with a given exit status.
 */
int Exit(ShellInfo *infomation)
{
	int exitstatus = 0;

	if (infomation->argv[1]) /* If there is an exit argument */
	{
		exitstatus = error_vyktor(infomation->argv[1]);
		if (exitstatus == -1)
		{
			infomation->status = 2;
			printerror(infomation, "Illegal number: ");
			eputs(info->argv[1]);
			eputchar('\n');
			return 1;
		}
		infomation->err_num = exit_status;
		return -2;
	}
	infomation->err_num = -1;
	return -2;
}

/**
 * Cd - Changes the current directory of the process
 * @infomation: Structure containing potential arguments.
 * Return: Always 0.
 */
int Cd(ShellInfo *infomation)
{
	char *s, *dir, buffer[1024];
	int chdiret;

	s = getcwd(buffer, 1024);
	if (!s)
		_puts("TODO: >>getcwd failure emsg here<<\n");

	if (!infomation->argv[1])
	{
		dir = ge_ten(infomation, "HOME=");
		if (!dir)
			chdiret = chdir((dir = ge_ten(infomation, "PWD=")) ? dir : "/");
		else
			chdiret = chdir(dir);
	}
	else if (_strcmp(infomation->argv[1], "-") == 0)
	{
		if (!ge_ten(infomation, "OLDPWD="))
		{
			_puts(s);
			_putchar('\n');
			return 1;
		}
		_puts(ge_ten(infomation, "OLDPWD="));
		_putchar('\n');
		chdiret = chdir((dir = ge_ten(infomation, "OLDPWD=")) ? dir : "/");
	}
	else
		chdiret = chdir(info->argv[1]);

	if (chdiret == -1)
	{
		void printerror(infomation, "can't cd to ");
		eputs(info->argv[1]);
		eputchar('\n');
	}
	else
	{
		_seten(info, "OLDPWD", ge_ten(info, "PWD="));
		_seten(info, "PWD", getcwd(buffer, 1024));
	}

	return 0;
}

/**
 * help - Displays help information.
 * @infomation: Structure containing potential arguments.
 * Return: Always 0.
 */
int help(ShellInfo *infomation)
{
	/* Display help information here */
	_puts("Help function is not yet implemented\n");
	return 0;
}
