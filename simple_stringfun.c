#include "simple_shell.h"

/**
 * _strspl - a function that counts number of words in strin
 * @strin: pointer to strin
 * Return: number of words
 */
int _strspl(char *strin)
{
	int i;
	int flag = 1;
	int count = 0;

	for (i = 0; strin[i]; i++)
	{
		if (strin[i] != ' ' && flag == 1)
		{
			count += 1;
			flag = 0;
		}
		if (strin[i + 1] == ' ')
			flag = 1;
	}
	return (count);
}


/**
 * _strdup - a function is used to duplicates a strin
 * @strin: pointer to strin.
 * Return: a pointer to a new strin that is a duplicate
 */

char *_strdup(char *strin)
{
	int i;
	char *dst;

	if (strin == NULL)
		return (NULL);
	for (i = 0; strin[i] != '\0'; i++)
		;
	dst = malloc(sizeof(char) * (i + 1));

	if (dst == NULL)
		return (NULL);
	for (i = 0; strin[i] != '\0'; i++)
	{
		dst[i] = strin[i];
	}
	dst[i] = '\0';
	return (dst);
}

/**
 * _strcmp - a function that compares two strins
 * @st1: char type
 * Return: integer value
 * @st2: char type
 */

int _strcmp(const char *st1, const char *st2)
{
	while ((*st1 != '\0' && *st2 != '\0') && *st1 == *st2)
	{
		st1++;
		st2++;
	}
	if (*st1 == *st2)
		return (0);
	else
		return (*st1 - *st2);
}


/**
 * _strlen - a function that used to calculate the length of a strin
 * @str: pointer to strin
 * Return: integer
 */

int _strlen(char *str)
{
	int i;

	for (i = 0; str[i]; i++)
		;
	return (i);
}

/**
 * _strcat - a function is used to concatenate two strins
 * @dst: the first strin
 * Return: a pointer to the first strin after the combining
 * @con: the second strin
 */

char *_strcat(char *dst, char *con)
{
	int i, j;

	for (i = 0; dst[i] != '\0'; i++)
		;
	for (j = 0; con[j] != '\0'; j++, i++)
		dst[i] = con[j];
	dst[i] = '\0';
	return (dst);
}