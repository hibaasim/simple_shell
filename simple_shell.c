#include "main.h"

/**
 * main - function that run the program.
 * @argc: number of argument.
 * @argv: argument.
 * Return: Always 0;
 */

int main(int argc, char **argv)
{
	char *deli = " \n\t", *cmd;
	char **args;

	(void)argc;
	while (1)
	{
		prompt();
		signal(SIGINT, handle_sigint);
		cmd = read_line();
		if (strcmp(cmd, "exit") == 0)
		{
			free(cmd);
			break;
		}

		if (strcmp(cmd, "env") == 0)
		{
			print_env();
			free(cmd);
			continue;
		}

		args = tokenizer(cmd, deli);
		exec(args, argv);
		free_array(args);
	}
	return (0);
}


/**
 * prompt - print prompt to stdout if its interactive mode.
 *
 * Return: nothing.
*/
void prompt(void)
{
	if (isatty(STDIN_FILENO))
	{
		write(STDOUT_FILENO, "$$ ", 3);
	}
}


/**
 * handle_sigint - handle ctrl + c signal.
 * @sig: the signal.
 *
 * Return: nothing.
 */

void handle_sigint(int sig)
{
	(void)sig;
	write(STDOUT_FILENO, "\n", 1);
	write(STDOUT_FILENO, "$$ ", 3);
}


/**
 * free_array - free allocated array.
 * @args: allocated array to free.
 *
 * Return: nothing.
*/
void free_array(char **args)
{
	size_t i = 0;

	if (args == NULL)
	{
		return;
	}

	while (args[i])
	{
		free(args[i]);
		i++;
	}

	if (args[i] != NULL)
	{
		free(args[i]);
	}
	free(args);
}

