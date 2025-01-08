/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yfaustin <yfaustin@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/18 10:24:30 by yfaustin          #+#    #+#             */
/*   Updated: 2025/01/07 22:10:14 by yfaustin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static char	*append_buffer(char	**static_buffer, char **buffer)
{
	char	*new_static_buffer;

	new_static_buffer = ft_strjoin(*static_buffer, *buffer);
	free(*static_buffer);
	*static_buffer = new_static_buffer;
	return (*static_buffer);
}

static char	*extract_new_line(char **buffer)
{
	size_t		index;
	size_t		len;
	char		*line;
	char		*new_buffer;

	len = ft_strlen(*buffer);
	index = 0;
	while (buffer[0][index] && buffer[0][index] != '\n')
		index++;
	if (buffer[0][index] == '\n')
		index++;
	line = ft_strndup(*buffer, index);
	if (len == index)
	{
		free(*buffer);
		*buffer = NULL;
	}
	else
	{
		new_buffer = ft_strndup(*buffer + index, len);
		free(*buffer);
		*buffer = new_buffer;
	}
	return (line);
}

static char	*read_line(char *static_buffer, int fd)
{
	int		bytes_read;
	char	*buffer;

	buffer = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buffer)
		return (NULL);
	bytes_read = 1;
	buffer[0] = '\0';
	while (!(ft_strchr(buffer, '\n')))
	{
		bytes_read = read(fd, buffer, BUFFER_SIZE);
		if (bytes_read == -1)
			return (free(static_buffer), free(buffer), NULL);
		if (bytes_read == 0)
			break ;
		buffer[bytes_read] = '\0';
		if (static_buffer == NULL)
			static_buffer = ft_strndup(buffer, -1);
		else
			append_buffer(&static_buffer, &buffer);
	}
	return (free(buffer), static_buffer);
}

char	*get_next_line(int fd)
{
	static char	*static_buffer;
	char		*line;

	if (fd < 0 || BUFFER_SIZE < 0)
		return (NULL);
	static_buffer = read_line(static_buffer, fd);
	if (static_buffer == NULL)
		return (NULL);
	line = extract_new_line(&static_buffer);
	return (line);
}
