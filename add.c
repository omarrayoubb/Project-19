#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
extern char ** environ;
int main(int ac, char *av[], char *env[])
{
	(void)ac;
	(void) av;
	printf("%p\n", *environ);
	printf("%p\n", *env);
	return (0);
}
