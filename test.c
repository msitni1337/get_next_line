#include "get_next_line.h"
#include <stdio.h>
#include <fcntl.h>

int main(int c, char**v)
{
	int fd = open(v[1], O_RDONLY);
	char *line = get_next_line(fd);
	while(line)
	{
//		printf("[\n");
//		printf("%s", line);
//		printf("]\n");
		free(line);
		line = get_next_line(fd);
	}
	dump_unfreed_ptr();
}
/*
int main(int c, char**v)
{
	(void) c;
	
	if (!(c - 1))
		printf("give me paths to file to read from.\n");
	
	int*fds = malloc(c - 1); 
	for (int i = 1; i < c; i++)
	{
		fds[i - 1] = open(v[i], O_RDONLY);
		if (fds[i - 1] < 0)
			printf("Path: [%s] is invalid, skipping..\n", v[i]);
	}
	
	while (1)
	{
		char fd_choice[10];
		printf("Enter file descriptor number from 0 to %d: ", c - 2);
		fflush(0);
		fd_choice[read(0, fd_choice, 9)] = 0;
		if (atoi(fd_choice) >= 0 && atoi(fd_choice) < c - 1 && fds[atoi(fd_choice)] > -1)
		{
			char *line = get_next_line(fds[atoi(fd_choice)]);
			printf("[\n");
			printf("%s", line);
			printf("]\n");
		}
		else
		{
			printf("INVALID FD CHOICE!\n");
		}
	}
}
*/
