#include "simple_shell.h"

/**
 * _builtin - check if first user string is a built-in
 * @logout: exit status
 * @buf: pointer to user string
 * Return: 1 if user string is equal to env or 0 otherwise
 * @arv: pointer to array
 */
int _builtin(char **argv, char *buffer, int logout)
{
	int i, status;

	if (_strcmp(argv[0], "env") == 0)
	{
		s_env();
		for (i = 0; argv[i]; i++)
			free(argv[i]);
		free(argv);
		free(buffer);
		return (1);
	}
	else if (_strcmp(argv[0], "exit") == 0)
	{
		status = logout;

		if (argv[1] != NULL)
			status = atoi(argv[1]);

		fflush(stdout);

		for (i = 0; argv[i]; i++)
			free(argv[i]);

		free(argv);
		free(buffer);
		exit(status);
	}
	else if (_strcmp(argv[0], "cd") == 0)
	{
		char dir[120];

		if (argv[1] == NULL)
		{
			status = chdir(getcwd(dir, sizeof(dir)));
			return (1);
		}
		else
		{
			status = chdir(argv[1]);
			return (1);
		}

		if (status != 0)
			return (1);
	}
	else
		return (0);
}
