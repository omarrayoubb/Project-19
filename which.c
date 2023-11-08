#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <dirent.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
int main(int ac, char *av[], char *env[])
{
	if (ac < 2)
	{
		printf("Usage: %s Not found", av[0]);
		exit (EXIT_FAILURE);
	}
	char *path = getenv("PATH");
	if (!path)
	{
		perror("environment");
		exit(EXIT_FAILURE);
	}
	char *token = strtok(path, ":");
	while(token)
	{
		DIR *fold = opendir(token);
		if (!fold)
		{
			token = strtok(NULL, ":");
			continue;
		}
		struct dirent *rd;
		struct stat st;
		while ((rd = readdir(fold)) != NULL)
		{
			if (strcmp(av[1], rd->d_name) == 0)
			{
				printf("%s/%s\n", token, av[1]);
				closedir(fold);
				exit(EXIT_SUCCESS);
			}
		}
			token = strtok(NULL, ":");
		closedir(fold);
	}
	return	(0);
}  
