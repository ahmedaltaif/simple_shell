#include "simple_shell.h"
/**
 * readCommand - stdin and stores it in a buffer
 * Return: a pointer to the buffer
 */
char *readCommand(void)
{
	ssize_t bytesRead;
	size_t bufferSize = 0;
	int index;
	char *cBuff = NULL;

	bytesRead = getline(&cBuff, &bufferSize, stdin);

	if ((bytesRead == -1) || _strcmp("exit", cBuff) == 0)
	{
		free(cBuff);

		if (isatty(STDIN_FILENO) != 0)
			write(STDOUT_FILENO, "\n", 1);

		exit(0);
	}

	if (cBuff[bytesRead - 1] == '\n' || cBuff[bytesRead - 1] == '\t')
		cBuff[bytesRead - 1] = '\0';

	for (index = 0; cBuff[index]; index++)
	{
		if (cBuff[index] == '#' && cBuff[index - 1] == ' ')
		{
			cBuff[index] = '\0';
			break;
		}
	}

	return (cBuff);
}
