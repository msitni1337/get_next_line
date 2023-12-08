#ifndef GET_NEXT_LINE_h
#define GET_NEXT_LINE_h

#ifndef BUFFER_SIZE
#define BUFFER_SIZE 1024
#endif

#include <stdlib.h>
#include <unistd.h>

typedef struct s_line
{
	int fd;
	char *rem_line;
	struct s_line *next;
} t_line;

char *get_next_line(int fd);
int st_getnl(const char *str);
void	*free_all(t_line**head);
void *free_line_node(t_line **lines, t_line*line);
void	st_strcpyshift(char *dest, char *src, int n);
int st_strlen(char *str);


#endif
