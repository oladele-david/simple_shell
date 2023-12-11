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

