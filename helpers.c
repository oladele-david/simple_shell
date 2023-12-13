#include "shell.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

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

int custom_strcmp(const char *s1, const char *s2)
{
	while (*s1 && (*s1 == *s2))
	{
		s1++;
		s2++;
	}

	return (*(unsigned char *) s1 - *(unsigned char *) s2);
}

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

char *custom_getenv(const char *name)
{
	return (getenv(name));
}
