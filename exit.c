#include "shell.h"


int exit_shell(info_t *info)
{
	int exit_check;

	if (info->argv[1]) 
	{
		exit_check = convert_to_integer(info->argv[1]);
		if (exit_check == -1)
		{
			info->status = 2;
			print_error(info, "Illegal number: ");
			_eputs(info->argv[1]);
			_eputchar('\n');
			return (1);
		}
		info->err_num = convert_to_integer(info->argv[1]);
		return (-2);
	}
	info->err_num = -1;
	return (-2);
}


int change_directory(info_t *info)
{
	char *s, *dir, buffer[1024];
	int chdir_ret;

	s = getcwd(buffer, 1024);
	if (!s)
		_puts("TODO: >>getcwd failure emsg here<<\n");
	if (!info->argv[1])
	{
		dir = getenv(info, "HOME=");
		if (!dir)
			chdir_ret = 
				chdir((dir = getenv(info, "PWD=")) ? dir : "/");
		else
			chdir_ret = chdir(dir);
	}
	else if (_strcmp(info->argv[1], "-") == 0)
	{
		if (!getenv(info, "OLDPWD="))
		{
			_puts(s);
			_putchar('\n');
			return (1);
		}
		_puts(getenv(info, "OLDPWD=")), _putchar('\n');
		chdir_ret = 
			chdir((dir = getenv(info, "OLDPWD=")) ? dir : "/");
	}
	else
		chdir_ret = chdir(info->argv[1]);
	if (chdir_ret == -1)
	{
		print_error(info, "can't cd to ");
		_eputs(info->argv[1]), _eputchar('\n');
	}
	else
	{
		setenv(info, "OLDPWD", getenv(info, "PWD="));
		setenv(info, "PWD", getcwd(buffer, 1024));
	}
	return (0);
}


int help_shell(info_t *info)
{
	char **arg_array;

	arg_array = info->argv;
	_puts("help call works. Function not yet implemented \n");
	if (0)
		_puts(*arg_array);
	return (0);
}
