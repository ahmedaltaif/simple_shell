#include "simple_shell.h"

/**
 * get_executable_path - Get the executable path for execve
 * @argv: Pointer to an array of strings
 * Return: A pointer to the string to use with execve
 * @path_string: Pointer to the path string
 * @path_duplicate: Duplicate pointer of the path string
 */

char *get_executable_path(char **argv, char *path_string, char *path_duplicate)
{
	char *token, *executable_path = NULL, *comparison_path= NULL;
	static char temporary_buffer[256];
	int token_count = 0, path_found_flag = 0, index = 0, token_length = 0;
	struct stat path_stat;

	path_duplicate = NULL;
	path_duplicate = _strdup(path_string);
	token_count = countPathElements(path_duplicate);
	token = strtok(path_duplicate, ": =");

	while (token != NULL)
	{
		comparison_path = buildCombinedPath(temporary_buffer, argv, token);
		if (stat(comparison_path, &path_stat) == 0)
		{
			executable_path = comparison_path;
			path_found_flag = 1;
			break;
		}

		if (index < token_count - 2)
		{
			token_length = _strlen(token);
			if (token[token_length + 1] == ':')
			{
				if (stat(argv[0], &path_stat) == 0)
				{
					executable_path = argv[0];
					path_found_flag = 1;
					break;
				}
			}
		}
		index++;
		token = strtok(NULL, ":");
	}

	if (path_found_flag == 0)
		executable_path = argv[0];

	free(path_duplicate);
	return executable_path;
}



/**
 * comparePathWithEnvVar - a function that compares path with environ
 * @pathString: pointer to environ strin
 * Return: 0 (success)
 * @envVarString: pointer path strin
 */

int comparePathWithEnvVar(const char *pathString, const char *envVarString)
{
	int index;

	for (index = 0; envVarString[index] != '='; index++)
	{
		if (pathString[index] != envVarString[index])
			return -1;
	}

	return 0;
}

/**
 * countPathElements - counts the number of path tokens
 * @pathString: pointer to strin
 * Return: number of path tokens
 */

int countPathElements(char *pathString)
{
	int index, isNewElement = 1, elementCount = 0;

	for (index = 0; pathString[index]; index++)
	{
		if (pathString[index] != ':' && isNewElement == 1)
		{
			elementCount += 1;
			isNewElement = 0;
		}
		if (pathString[index + 1] == ':')
		{
			isNewElement = 1;
		}
	}

	return elementCount;
}

/**
 * buildCombinedPath - concatenate a user strin with a path token
 * @resultBuffer: pointer to a static array to store the concatenated strin
 * @arrayElement: pointer to an array of user strins.
 * @token: pointer to a path token
 * Return: 0 (success)
 */

char *buildCombinedPath(char *resultBuffer, char **arrayElement, char *token)
{
	int length = 0;

	_memsete(resultBuffer, 0, 256);
	length = _strlen(token) + _strlen(arrayElement[0]) + 2;
	_strcat(resultBuffer, token);
	_strcat(resultBuffer, "/");
	_strcat(resultBuffer, arrayElement[0]);
	resultBuffer[length - 1] = '\0';
	return (resultBuffer);
}

/**
 * get_environ - gets path token from environ
 * @name: pointer to path strin
 * Return: pointer to path strin or NULL
 */

/**
 * s_env - prints the environ
 * Return: 0 on success
 */

int s_env(void)
{
	int i;

	for (i = 0; environ[i]; i++)
		_puts(environ[i]);
	return (0);
}