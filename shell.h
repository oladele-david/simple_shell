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

#endif /*SHELL_H */

