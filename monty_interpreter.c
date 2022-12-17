#include "monty.h"

/**
 * main - monty_interpreter
 * @argc: number of args
 * @argv: pointer to a string of args
 * Return: (0) if succed, EXIT_FAILURE if it fails
 */

int main(int argc, char **argv)
{
	size_t bufsize = 1024;
	char *buf = malloc(sizeof(char) * 1024), **lines = NULL;
	int i = 0, count = 0;
	FILE *fd;

	if (argc != 2)
	{
		free(buf);
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}
	memset(buf, '\0', 1024);
	fd = fopen(argv[1], "r");
	if (fd == NULL)
	{
		free(buf);
		fprintf(stderr, "Error: Can't open file %s\n", argv[1]);
		exit(EXIT_FAILURE);
	}
	while (getline(&buf, &bufsize, fd) != EOF)
		count++;
	fclose(fd);
	lines = malloc(sizeof(char *) * (count + 1));
	fd = fopen(argv[1], "r");
	while (getline(&buf, &bufsize, fd) != EOF)
	{
		lines[i] = malloc(sizeof(char) * strlen(buf) + 1);
		strcpy(lines[i], buf);
		i++;
	}
	lines[count] = NULL;
	_matcher(lines);
	for (i = 0; lines[i]; i++)
		free(lines[i]);
	free(lines), free(buf), fclose(fd);
	return (0);
}
