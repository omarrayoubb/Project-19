#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
extern char ** environ;
int main(int ac, char *av[])
{
	int i =0;
	(void) ac;
	(void) av;
	while (environ[i])
	{
		printf("%s\n", environ[i]);
		i++;
	}
	return (0);
}
