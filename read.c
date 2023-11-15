#include "main.h"

/**
 * read_line - function to read the user input (commands and arguments).
 * Return: user input (commands and arguments).
 */

char *read_line(void)
{
	char *cmd = NULL;
	size_t cmd_size = 0;
	ssize_t byte_read;

	byte_read = getline(&cmd, &cmd_size, stdin);
	if (byte_read == -1)
	{
		free(cmd);
		if (isatty(STDIN_FILENO))
			write(STDOUT_FILENO, "\n", 1);
		exit(EXIT_SUCCESS);
	}
	else
	{
		if (cmd[byte_read - 1] == '\n')
		{
			cmd[byte_read - 1] = '\0';
		}
		return (cmd);
	}
}

/**
 * error_msg - print error massege and exit.
 * @argv: passed arguments to main func.
 * @args: array of command and arguments.
 * Return: nothing.
*/
void error_msg(char **argv, char **args)
{
	write(STDERR_FILENO, argv[0], strlen(argv[0]));
	write(STDERR_FILENO, ": ", 2);
	write(STDERR_FILENO, "1", 1);
	write(STDERR_FILENO, ": ", 2);
	write(STDERR_FILENO, args[0], strlen(args[0]));
	write(STDERR_FILENO, ": not found\n", 12);
	free_array(args);
	exit(127);

}
