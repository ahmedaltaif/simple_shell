#include "simple_shell.h"

/**
 * _builtin - check if first user string is a built-in
 * @logout: exit status
 * @buffer: pointer to user string
 * Return: 1 if user string is equal to env or 0 otherwise
 * @argv: pointer to array
 */
int _builtin(char **argv, char *buffer, int logout)
{
	int i, status;

	if (_strcmp(argv[0], "env") == 0)
	{
		s_env();
	}
	else if (_strcmp(argv[0], "exit") == 0)
	{
		status = (argv[1] != NULL) ? atoi(argv[1]) : logout;
		fflush(stdout);
		for (i = 0; argv[i]; i++)
			free(argv[i]);
		free(argv);
		free(buffer);
		exit(status);
	}
	else if (_strcmp(argv[0], "cd") == 0)
	{
		char dr[120];

		status = (argv[1] == NULL) ? chdir(getcwd(dr, sizeof(dr))) : chdir(argv[1]);
		if (status != 0)
			return (1);
	}
	else
	{
		return (0);
	}

	for (i = 0; argv[i]; i++)
		free(argv[i]);

	free(argv);
	free(buffer);
	return (1);
}
