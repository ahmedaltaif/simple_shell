#include "simple_shell.h"
char *readCommand(void)
{
    ssize_t bytesRead;
    size_t bufferSize = 0;
    int index;
    char *commandBuffer = NULL;

    bytesRead = getline(&commandBuffer, &bufferSize, stdin);

    if ((bytesRead == -1) || _strcmp("exit", commandBuffer) == 0)
    {
        free(commandBuffer);

        if (isatty(STDIN_FILENO) != 0)
            write(STDOUT_FILENO, "\n", 1);

        exit(0);
    }

    if (commandBuffer[bytesRead - 1] == '\n' || commandBuffer[bytesRead - 1] == '\t')
        commandBuffer[bytesRead - 1] = '\0';

    for (index = 0; commandBuffer[index]; index++)
    {
        if (commandBuffer[index] == '#' && commandBuffer[index - 1] == ' ')
        {
            commandBuffer[index] = '\0';
            break;
        }
    }

    return commandBuffer;
}