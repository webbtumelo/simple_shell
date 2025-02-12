#include "header.h"

char *error_env(char **args);
char *error_1(char **args);
char *error_2_exit(char **args);
char *error_2_cd(char **args);
char *error_2_syntax(char **args);
/**
 * error_env - function of the prototype
 * @args: An array of arguments passed to the command.
 *
 * Return: The error
 */
char *error_env(char **args)
{
	char *error, *hist_str;
	int lenght;

	hist_str = _itoa(hist);
	if (!hist_str)
		return (NULL);

	args--;
	lenght = _strlen(name) + _strlen(hist_str) + _strlen(args[0]) + 45;
	error = malloc(sizeof(char) * (lenght + 1));
	if (!error)
	{
		free(hist_str);
		return (NULL);
	}

	_strcpy(error, name);
	_strcat(error, ": ");
	_strcat(error, hist_str);
	_strcat(error, ": ");
	_strcat(error, args[0]);
	_strcat(error, ": Unable to add/remove from environment\n");

	free(hist_str);
	return (error);
}

/**
 * error_1 - function of the prototype
 * @args: An array of arguments passed to the command.
 *
 * Return: The error
 */
char *error_1(char **args)
{
	char *error;
	int lenght;

	lenght = _strlen(name) + _strlen(args[0]) + 13;
	error = malloc(sizeof(char) * (lenght + 1));
	if (!error)
		return (NULL);

	_strcpy(error, "alias: ");
	_strcat(error, args[0]);
	_strcat(error, " not found\n");

	return (error);
}

/**
 * error_2_exit - function of the prototype
 * @args: An array of arguments passed to the command.
 *
 * Return: The error
 */
char *error_2_exit(char **args)
{
	char *error, *hist_str;
	int lenght;

	hist_str = _itoa(hist);
	if (!hist_str)
		return (NULL);

	lenght = _strlen(name) + _strlen(hist_str) + _strlen(args[0]) + 27;
	error = malloc(sizeof(char) * (lenght + 1));
	if (!error)
	{
		free(hist_str);
		return (NULL);
	}

	_strcpy(error, name);
	_strcat(error, ": ");
	_strcat(error, hist_str);
	_strcat(error, ": exit: Illegal number: ");
	_strcat(error, args[0]);
	_strcat(error, "\n");

	free(hist_str);
	return (error);
}

/**
 * error_2_cd - function of the prototype
 * @args: An array of arguments passed to the command.
 *
 * Return: The error.
 */
char *error_2_cd(char **args)
{
	char *error, *hist_str;
	int lenght;

	hist_str = _itoa(hist);
	if (!hist_str)
		return (NULL);

	if (args[0][0] == '-')
		args[0][2] = '\0';
	lenght = _strlen(name) + _strlen(hist_str) + _strlen(args[0]) + 24;
	error = malloc(sizeof(char) * (lenght + 1));
	if (!error)
	{
		free(hist_str);
		return (NULL);
	}

	_strcpy(error, name);
	_strcat(error, ": ");
	_strcat(error, hist_str);
	if (args[0][0] == '-')
		_strcat(error, ": cd: Illegal option ");
	else
		_strcat(error, ": cd: can't cd to ");
	_strcat(error, args[0]);
	_strcat(error, "\n");

	free(hist_str);
	return (error);
}

/**
 * error_2_syntax - function of the prototype
 * @args: An array of arguments passed to the command.
 *
 * Return: The error
 */
char *error_2_syntax(char **args)
{
	char *error, *hist_str;
	int lenght;

	hist_str = _itoa(hist);
	if (!hist_str)
		return (NULL);

	lenght = _strlen(name) + _strlen(hist_str) + _strlen(args[0]) + 33;
	error = malloc(sizeof(char) * (lenght + 1));
	if (!error)
	{
		free(hist_str);
		return (NULL);
	}

	_strcpy(error, name);
	_strcat(error, ": ");
	_strcat(error, hist_str);
	_strcat(error, ": Syntax error: \"");
	_strcat(error, args[0]);
	_strcat(error, "\" unexpected\n");

	free(hist_str);
	return (error);
}
