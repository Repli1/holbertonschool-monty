#include "monty.h"

int main(int argc, char **argv)
{
	size_t bufsize = 1024;
	char *buf = malloc(sizeof(char) * 1024), **lines = NULL, *dup = NULL, *token = NULL;
	int fd, r, i = 0, count = 0;

	if (argc != 2)
	{
		free(buf);
		fprintf(stderr,"USAGE: monty file\n");
		exit (EXIT_FAILURE);
	}
	memset(buf, '\0', 1024);
	fd = open(argv[1], O_RDONLY);
	if (fd == -1)
	{
		fprintf(stderr, "Error: Can't open file %s\n", argv[1]);
		exit (EXIT_FAILURE);
	}
	r = read(fd, buf, bufsize);
	if (r == -1)
	{
		free(buf);
		return (-1);
	}
	dup = malloc(sizeof(char) * (r + 1));
	strcpy(dup, buf);
	for (i = 0; dup[i] != '\0'; i++)
	{
		if (dup[i] == '\n')
			count++;
	}
	i = 0;
	token = strtok(dup, "\n");
	lines = malloc(sizeof(char *) * (count + 1));
	while (token)
	{
		lines[i] = token;
		token = strtok(NULL, "\n");
		i++;
	}
	lines[count] = NULL;
	_matcher(lines);
	free(dup), free(lines), free(buf);
	return (0);
}
