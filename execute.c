#include "main.h"

/**
 * exec - function to execute commands with arguments.
 * @args: the commands and arguments to execute.
 * @argv: arguments passed to main func.
 * Return: nothing.
 */

void exec(char **args, char **argv)
{
	int status;
	pid_t pid = fork();
	char *cmmd;

	if (pid < 0)
	{
		perror("simple_shell");
		free_array(args);
		exit(EXIT_FAILURE);
	}
	else if (pid == 0)
	{
		if (args[0])
		{
		cmmd = get_path(args[0]);
		if (cmmd)
		{
			execve(cmmd, args, environ);
			perror("simple_shell");
			free(cmmd);
			free_array(args);
			exit(127);
		}
		else
		{
			error_msg(argv, args);
		}
		}
		free_array(args);
		exit(EXIT_SUCCESS);
	}
	else
	{
		waitpid(pid, &status, 0);
	}
}

/**
 * print_env - print all envirnomental variables.
 *
 * Return: nothing.
 */
void print_env(void)
{
	unsigned int i = 0;

	while (environ[i])
	{
		write(STDOUT_FILENO, environ[i], strlen(environ[i]));
		write(STDOUT_FILENO, "\n", 1);
		i++;
	}
}
