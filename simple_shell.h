#ifndef SHELL_H
#define SHELL_H

#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <string.h>
#include <unistd.h>
#include <signal.h>
#include <stdbool.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <fcntl.h>
#include <stddef.h>

extern char **environ;

void _print(const char *user_string);
int dis_prompt(void);
char *readCommand(void);
int execute_command(char **argv, char *buff, char *pathbuf);
int _strcmp(const char *str1, const char *str2);
char *_strdup(char *string);
int _strspl(char *string);
int _strlen(char *str);
char *_strcat(char *dest, char *con);
char **tokenize_command(char *buffer);
char *get_executable_path(char **argv, char *path_string, char *path_duplicate);
int comparePathWithEnvVar(const char *pathString, const char *envVarString);
int countPathElements(char *pathString);
char *buildCombinedPath(char *resultBuffer, char **arrayElement, char *token);
int s_env(void);
char *_memsete(char *ptr, char val, unsigned int num);
int _builtin(char **argv, char *buffer, int logout);
void _puts(char *str);
int _putchar(char c);

#endif