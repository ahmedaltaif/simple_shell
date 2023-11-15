#include "simple_shell.h"

void _print(const char *user_string)
{
	size_t length = strlen(user_string);
    ssize_t count = 0;
	if (isatty(STDIN_FILENO) == 1)
	{
		count = write(STDOUT_FILENO, user_string, length);
        if (count == -1)
		    exit(0);
	}
}


char *_memsete(char *ptr, char val, unsigned int num)
{
	unsigned int i;

	for (i = 0; i < num; i++)
		ptr[i] = val;
	return (ptr);
}


void _puts(char *str)
{
	int c;

	for (c = 0; str[c] != '\0'; c++)
		_putchar(str[c]);
	_putchar('\n');
}

int _putchar(char c)
{
	return (write(1, &c, 1));
}
