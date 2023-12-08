#include "shell.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>


/**
 *display_prompt - Display the shell prompt.
 */
void display_prompt(void)
{
	printf("# simple_shell$ ");
	fflush(stdout);
}

/**
 *execute_command - Execute a command in a child process.
 *@command: The command to be executed.
 */
void execute_command(char *command)
{
	pid_t child_pid;
	int status;

	child_pid = fork();

	if (child_pid == -1)
	{
		perror("fork");
		exit(EXIT_FAILURE);
	}

	if (child_pid == 0)
	{
		if (execlp(command, command, NULL) == -1)
		{
			perror(command);
			exit(EXIT_FAILURE);
		}
	}
	else
	{
		waitpid(child_pid, &status, 0);

		if (WIFEXITED(status) && WEXITSTATUS(status) == EXIT_FAILURE)
		{
			fprintf(stderr, "simple_shell: Command not found: %s\n", command);
		}
	}
}
