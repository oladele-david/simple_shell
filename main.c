#include "shell.h"
#include <string.h>
#include <stdio.h>
#include <stdlib.h>

/**
 *main - Entry point for the simple shell program.
 *
 *Return: EXIT_SUCCESS on success, otherwise EXIT_FAILURE.
 */

int main(void)
{
	char buffer[BUFFER_SIZE];

	while (1)
	{
		display_prompt();

		if (fgets(buffer, BUFFER_SIZE, stdin) == NULL)
		{
			printf("\n");
			break;
		}

		buffer[strcspn(buffer, "\n")] = '\0';

		if (strcmp(buffer, "exit") == 0)
		{
			break;
		}

		execute_command(buffer);
	}

	return (EXIT_SUCCESS);
}
