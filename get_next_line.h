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
void *free_ptr(void*ptr, void*ptr1,void*ptr2, char**ptr3);
char	*ft_substr(char const *s, long start, long len);
char	*ft_strjoin(char *s1, char *s2);
int ft_strlen(const char *str);


#endif
