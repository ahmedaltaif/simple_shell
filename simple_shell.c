#include "simple_shell.h"

int main(void)
{
	char *prompt = "ahmed$ ";
	char *pathVariable = NULL;
	char *pathBuffer = NULL;
	char *commandBuffer = NULL;
	char **arguments = NULL;
	int logoutFlag = 0;

	pathVariable = getenv("PATH");
	if (pathVariable == NULL)
		return (-1);
	while (true)
	{
		arguments = NULL;

		_print(prompt);
		commandBuffer = readCommand();
		if (*commandBuffer != '\0')
		{
			arguments = tokenize_command(commandBuffer);
			if (arguments == NULL)
			{
				free(commandBuffer);
				continue;
			}
			pathBuffer = get_executable_path(arguments, pathVariable, commandBuffer);

			if (_builtin(arguments, commandBuffer, logoutFlag) == 1)
				continue;

			logoutFlag = execute_command(arguments, commandBuffer, pathBuffer);
		}
		else
		{
			free(commandBuffer);
		}
	}
	return (0);
}
