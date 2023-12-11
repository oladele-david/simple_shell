#include "shell.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

/**
 *execute_command - Execute a command in a child process.
 *@command: The command to be executed.
 *
 *This function takes a command as input, tokenizes it, and executes it in a
 *child process using execvp. It searches for the command in the directories
 *specified by the PATH environment variable. It waits for the child process to
 *complete and prints an error message if the command is not found.
 *
 *Return: Always 0
 */

static void execute_in_child(char *full_path, char *args[]);
static void search_and_execute(char *command, char *args[], char *path);

void execute_command(char *command)
{
	char *path = getenv("PATH");

	char *args[64];
	int arg_count = 0;
	char *token = strtok(command, " ");

	while (token != NULL)
	{
		args[arg_count++] = token;
		token = strtok(NULL, " ");
	}

	args[arg_count] = NULL;

	search_and_execute(command, args, path);
}

/**
 *execute_in_child - Execute a command in a child process.
 *@full_path: The full path to the executable command.
 *@args: Array of command-line arguments.
 *
 *This function forks a child process and executes the specified command
 *using execv. If the execution fails, it prints an error message.
 */

static void execute_in_child(char *full_path, char *args[])
{
	pid_t child_pid;

	child_pid = fork();

	if (child_pid == -1)
	{
		perror("fork");
		exit(EXIT_FAILURE);
	}

	if (child_pid == 0)
	{
		if (execv(full_path, args) == -1)
		{
			perror(args[0]);
			exit(EXIT_FAILURE);
		}
	}
}

/**
 *search_and_execute - Search for and execute a
 *command in the PATH directories.
 *@args: Array of command-line arguments.
 *@path: The PATH environment variable containing directories.
 *
 *This function searches for the command in the directories specified by the
 *PATH environment variable. If found, it executes the command in a child
 *process. If the command is not found, it prints an error message.
 */

static void search_and_execute(char __attribute__((unused)) *command, char *args[], char *path)
{
	int status;

	char *path_copy = strdup(path);
	char *dir = strtok(path_copy, ":");

	while (dir != NULL)
	{
		char *full_path = malloc(strlen(dir) + strlen(args[0]) + 2);

		sprintf(full_path, "%s/%s", dir, args[0]);

		if (access(full_path, X_OK) == 0)
		{
			execute_in_child(full_path, args);
			waitpid(-1, &status, 0);

			if (WIFEXITED(status) && WEXITSTATUS(status) == EXIT_FAILURE)
			{
				fprintf(stderr, "simple_shell: Command not found: %s\n", args[0]);
			}

			free(full_path);
			free(path_copy);
			return;
		}

		free(full_path);
		dir = strtok(NULL, ":");
	}

	fprintf(stderr, "simple_shell: Command not found: %s\n", args[0]);
	free(path_copy);
}
