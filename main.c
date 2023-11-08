#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
/**
 * main - fork example
 *
 * Return: Always 0.
 */
int main(void)
{
	/*int id;
	char *s[] = {"/bin/ls", "-l", "/tmp", NULL};
	int i = 0;
	int se;
	*/
	
	char *s[] = {"/bin/ls", "-l", "/sys",NULL};
	int sd;
	int id;
	int i = 0;
	
	for(i = 0; i < 5; i++)
	{
		id = fork();
	if (id == 0)
	{
		if (execve(s[0], s, NULL) == -1)
			perror("error");
	}
	else
		wait(&sd);
	}
	return (0);
}
