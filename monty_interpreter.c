#include "monty.h"

int main(int argc, char **argv)
{
	size_t bufsize = 1024;
	char *buf = malloc(sizeof(char) * 1024), **lines = NULL;
	int i = 0, count = 0;
	FILE *fd;


	if (argc != 2)
	{
		free(buf);
		fprintf(stderr,"USAGE: monty file\n");
		exit (EXIT_FAILURE);
	}
	memset(buf, '\0', 1024);
	

	fd = fopen(argv[1], "r");

	if (fd == NULL)
	{
		fprintf(stderr, "Error: Can't open file %s\n", argv[1]);
		exit (EXIT_FAILURE);
	}
/*	fread(r, &buf, &bufsize, fd);
	if (*r == -1)
	{
		free(buf);
		return (-1);
	} */
	while (getline(&buf, &bufsize, fd) != EOF)
			count++;
	fclose(fd);
/*	dup = malloc(sizeof(char) * (r + 1));
	strcpy(dup, buf);
	for (i = 0; dup[i] != '\0'; i++)
	{
		if (dup[i] == '\n')
			count++;
	}
	i = 0;*/
	lines = malloc(sizeof(char *) * (count + 1));

	fd = fopen(argv[1], "r");

	while (getline(&buf, &bufsize, fd) != EOF)
	{
		lines[i] = buf;
//		printf("lines[%d] -> %s\n", i, lines[i]);
		i++;
	}

	lines[count] = NULL;
	for (i = 0; lines[i]; i++)
		printf ("%s\n", lines[i]);

	_matcher(lines);
	free(lines), free(buf);
	fclose(fd);
	return (0);
}
