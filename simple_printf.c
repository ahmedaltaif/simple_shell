#include "simple_shell.h"
/**
 * _print - prints a string to the standard output
 * Return: number of byets
 * @user_string: pointer to string
 */
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
/**
 * _memsete - used to fill a block of memory with a particular value
 * @ptr: pointer to the block of memory to be filled
 * Return: pointer to the block of memory that was filled
 * @val: value to be used to fill the block of memory
 * @num: number of bytes to be filled
 */
char *_memsete(char *ptr, char val, unsigned int num)
{
	unsigned int i;

	for (i = 0; i < num; i++)
		ptr[i] = val;
	return (ptr);
}

/**
 * _puts - prints a string
 * @str: string to print
 */
void _puts(char *str)
{
	int c;

	for (c = 0; str[c] != '\0'; c++)
		_putchar(str[c]);
	_putchar('\n');
}
/**
 * _putchar - print char.
 *
 * @c: pointer to string.
 *
 * Return: number of byets.
 */
int _putchar(char c)
{
	return (write(1, &c, 1));
}
