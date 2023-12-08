#include "get_next_line.h"

int st_getnl(const char *str)
{
	int i;

	i = 0;
	while (str && str[i] && str[i] != '\n')
		i++;
	if (str && str[i] == '\n')
		return i;
	return -1;
}

void	*free_all(t_line**head)
{
	t_line *tmp;

	if (head && *head)
	{
		while (*head)
		{
			if ((*head)->rem_line)
				free((*head)->rem_line);
			tmp = *head;
			*head = (*head)->next;
			free(tmp);
		}
	}
	return NULL;
}

void *free_line_node(t_line **lines, t_line*line)
{
	t_line *tmp;

	if (lines && *lines && line == *lines)
	{
		if (line->rem_line)
			free(line->rem_line);
		*lines = line->next;
		free(line);
	}
	else
	{
		tmp = *lines;
		while (tmp->next && tmp->next != line)
			tmp = tmp->next;
		if (tmp)
		{
			if (line->rem_line)
				free(line->rem_line);
			tmp->next = line->next;
			free(tmp);
		}
	}
	return NULL;
}

void	st_strcpyshift(char *dest, char *src, int n)
{
	int	i;

	i = 0;
	while (src[i] && i < n)
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = 0;
	while (src[i])
	{
		*src = src[i];
		src++;
		i++;	
	}
	*src = 0;
}

int st_strlen(char *str)
{
	int i;

	i = 0;
	while (str && str[i])
		i++;
	return i;
}
