#ifndef SHELL_H
#define SHELL_H

#define BUFFER_SIZE 11024

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

extern char **environ;

/**
 *display_prompt - Display the shell prompt.
 */
void display_prompt(void);

/**
 *execute_command - Execute a command in a child process.
 *@command: The command to be executed.
 */
void execute_command(char *command);

/**
 * custom_strcmp - Compare two strings.
 *@s1: The first string to be compared.
 *@s2: The second string to be compared.
 *
 *Description:
 *    This function compares two strings, s1 and s2, character by character.
 *    It returns an integer less than, equal to, or greater than zero if the
 *    first string is found to be less than, equal to, or greater than the
 *    second string, respectively.
 *
 *Return:
 *    An integer less than, equal to, or greater than zero if the first
 *    string is found to be less than, equal to, or greater than the second
 *    string, respectively.
 */

int custom_strcmp(const char *s1, const char *s2);

/**
 * custom_getenv - Get the value of an environment variable.
 * @name: The name of the environment variable.
 *
 * This function retrieves the value of the environment variable specified
 * by the given name.
 *
 * Return: A pointer to the value of the environment variable, or NULL if
 * the variable is not found.
 */

char *custom_getenv(const char *name);

#endif /*SHELL_H */

