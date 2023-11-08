#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
extern char **environ;
struct path
{
	char *d;
	struct path *p;
};

struct path *linkpath()
{
	char *p = getenv("PATH");
	char *token = strtok(p, ":");
	struct path *head = '\0';

	while (token)
	{
		struct path *new, *tmp;
		new = malloc(sizeof(struct path));
		new->d = token;
		new->p = NULL;
		if (!head)
		{
			head = new;
		}
		else 
		{
			tmp = head;
			while (tmp->p)
			{
				tmp = tmp->p;
			}
			tmp->p =new;
		}
		token = strtok(NULL, ":");
	}
		return (head);
}
int main(int ac, char *av[], char *env[])
{
	struct path *c;
	c = linkpath();
	while(c->p)
	{
		printf("%s\n", c->d);
		c = c->p;
	}
	return (0);
}
