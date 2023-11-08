#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
int main()
{
			while (1)
			{
				printf("$ ");
				
				char *line = NULL;
				size_t size = 0;
				ssize_t get;
				
				get = getline(&line, &size, stdin);
				if (get == -1)
				{
					perror("getline");
					free(line);
					exit(EXIT_FAILURE);
				}
				if (line[get - 1] == '\n')
					line[get - 1] = '\0';
				
				char *token;
				char *args[100];
				int i = 0;

				token = strtok(line, " ");
				while (token != NULL)
				{
					args[i++] = token;
					token = strtok(NULL, " ");
				} 
				args[i] = NULL;

				pid_t pid = fork();
				if (pid < 0)
				{
					perror("fork");
					free(line);
					exit(EXIT_FAILURE);
				} else if (pid == 0)
				{
					execve(args[0], args, NULL);
				} else {
					int st;
					wait(&st);
					free (line);
				}
		}
	return (0);
}
