#include "simple_shell.h"

/**
 * execute_command - child process to execute based on user input
 * @pathbuf: pointer
 * @buff: pointer
 * Return: 0 on success
 * @argv: pointer of strings
 */
int execute_command(char **argv, char *buff, char *pathbuf)
{
	pid_t child_pid;
	int i, status, result, logout = 0;

	if (access(pathbuf, X_OK) != 0)
	{
		perror(argv[0]);
		return (1);
		exit(1);
	} else
	{
		child_pid = fork();
	}
	if (child_pid == -1)
	{
		perror("No such file or directory");
		exit(1);
	}
	if (child_pid == 0)
	{
		result = execve(pathbuf, argv, environ);
		if (result == -1)
		{
			perror(argv[0]);
			for (i = 0; argv[i]; i++)
				free(argv[i]);
			free(argv);
			free(buff);
			exit(127);
		}
	}
		wait(&status);
	if (WIFEXITED(status))
	{
		logout = WEXITSTATUS(status);
	}
	for (i = 0; argv[i]; i++)
		free(argv[i]);
	free(argv);
	free(buff);
	return (logout);
}
