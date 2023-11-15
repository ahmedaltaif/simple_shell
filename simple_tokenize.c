#include "simple_shell.h"


char **tokenize_command(char *buffer)
{
	int i = 0;
	int count = 0;
	char *token;
	char **av;
	char *delm = " \n";

	count = _strspl(buffer);
	if (!count)
		return (NULL);
	av = malloc((count + 1) * sizeof(char *));
	if (av == NULL)
		exit(1);
	token = strtok(buffer, delm);
	while (token != NULL)
	{
		av[i] = _strdup(token);
		token = strtok(NULL, delm);
		i++;
	}
	av[i] = NULL;
	return (av);
}