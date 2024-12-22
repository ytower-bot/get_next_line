/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yfaustin <yfaustin@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/18 10:24:30 by yfaustin          #+#    #+#             */
/*   Updated: 2024/12/21 22:02:46 by yfaustin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include "get_next_line_utils.h"

#ifndef BUFFER_SIZE
# define BUFFER_SIZE 42
#endif

static char	*ft_strchr(const char *s, int c)
{
	int				i;
	unsigned char	p;

	i = 0;
	p = c;
	if (p == '\0')
	{
		i = ft_strlen(s);
		return ((char *)&s[i++]);
	}
	while (s[i])
	{
		if (s[i] == p)
			return ((char *)s + i);
		i++;
	}
	return (NULL);
}

static char	*extract_new_line(char	**buffer)
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
	line = ft_substr(*buffer, 0, index);
	if (len == index)
	{
		free(*buffer);
		*buffer = NULL;
	}
	else
	{
		new_buffer = ft_substr(*buffer, index, len);
		free(*buffer);
		*buffer = new_buffer;
	}
	return (line);
}

static char	*read_line(char *static_buffer, int fd)
{
	int		bytes_read;
	char	buffer[BUFFER_SIZE + 1];
	char	*new_static_buffer;

	bytes_read = 1;
	buffer[0] = '\0';
	while (!(ft_strchr(buffer, '\n')))
	{
		bytes_read = read(fd, buffer, BUFFER_SIZE);
		if (bytes_read == -1)
			return (free(static_buffer), NULL);
		if (bytes_read == 0)
			break ;
		buffer[bytes_read] = '\0';
		if (static_buffer == NULL)
			static_buffer = ft_strdup(buffer);
		else
		{
			new_static_buffer = ft_strjoin(static_buffer, buffer);
			free(static_buffer);
			static_buffer = new_static_buffer;
		}
	}
	return (static_buffer);
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
