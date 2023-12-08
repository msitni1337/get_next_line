#include "get_next_line.h"

t_line* st_add_fd(t_line **head, int fd)
{
	t_line* node;

	node = malloc(sizeof(t_line));
	if (!node)
		return free_all(head);
	node->rem_line = malloc(BUFFER_SIZE);
	if (!node->rem_line)
		return free_all(head);
	node->rem_line[0] = 0;
	node->fd = fd;
	node->next = *head;
	*head = node;
	return node;
}

t_line* st_get_line(t_line**lines, int fd)
{
	t_line*line;

	if (!lines)
		return NULL;
	line = *lines;
	while (line)
	{
		if (line->fd == fd)
			break;
		line = line->next;
	}
	if (line)
		return line;
	return st_add_fd(lines, fd);
}

char* st_construct_line(char*buff, char**result)
{
	char *line;
	int result_len;
	int buff_len;

	buff_len = st_getnl(buff);
	if (buff_len == -1)
		buff_len = BUFFER_SIZE;
	if (!*result)
	{
		*result = malloc(buff_len + 1);
		if (*result)
			st_strcpyshift(*result, buff, st_getnl(buff));
		return *result;
	}
	result_len = st_strlen(*result);
	line = malloc(result_len + buff_len +1);
	if (!line)
		return NULL;
	st_strcpyshift(line, *result, result_len);
	st_strcpyshift(line + result_len, buff, buff_len);
	free(*result);
	*result = line;
	return line;
}

char* st_get_result(t_line**lines, t_line*line, char*buff)
{
	int bytes_read;
	char	*result;

	result = 0;
	if (!st_construct_line(line->rem_line, &result))
		return free_all(lines);
	if (st_getnl(result) != -1)
		return result;
	while (st_getnl(result) == -1)
	{	
		bytes_read = read(line->fd, buff, BUFFER_SIZE);
		if (bytes_read <= 0)
			break;
		buff[bytes_read] = 0;
		if(!st_construct_line(buff, &result))
			return free_all(lines);
	}
	if (bytes_read == -1)
		return free_all(lines);
	if (!bytes_read)
		free_line_node(lines, line);
	else
		st_strcpyshift(line->rem_line, buff, BUFFER_SIZE);	
	return result;
}

char *get_next_line(int fd)
{
	static t_line* lines;
	t_line* line;
	char *buff;
	char*	res;

	if (fd < 0)
		return NULL;
	line = st_get_line(&lines, fd);
	if (!lines)
		line = st_add_fd(&lines, fd);
	if (!line)
		return free_all(&lines);
	buff = malloc(BUFFER_SIZE + 1);
	if (!buff)
		return free_all(&lines);
	res = st_get_result(&lines, line, buff);
	free(buff);
	return res;
}
