#include "shell.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

/**
 * execute_command - Execute a command in a child process.
 * @command: The command to be executed.
 *
 * This function takes a command as input, tokenizes it, and executes it in a
 * child process using execvp. It waits for the child process to complete and
 * prints an error message if the command is not found.
 *
 * Return: Always 0
 */

void execute_command(char *command)
{
	pid_t child_pid;
	int status;
	char *args[64];
	int arg_count = 0;
	char *token = strtok(command, " ");

	while (token != NULL)
	{
		args[arg_count++] = token;
		token = strtok(NULL, " ");
	}

	args[arg_count] = NULL;
	child_pid = fork();

	if (child_pid == -1)
	{
		perror("fork");
		exit(EXIT_FAILURE);
	}

	if (child_pid == 0)
	{
		if (execvp(args[0], args) == -1)
		{
			perror(args[0]);
			exit(EXIT_FAILURE);
		}
	}
	else
	{
		waitpid(child_pid, &status, 0);

		if (WIFEXITED(status) && WEXITSTATUS(status) == EXIT_FAILURE)
		{
			fprintf(stderr, "simple_shell: Command not found: %s\n", args[0]);
		}
	}
}
