/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yfaustin <yfaustin@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/18 10:24:30 by yfaustin          #+#    #+#             */
/*   Updated: 2024/12/21 20:01:56 by yfaustin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include "libft.h"
#include <stdio.h>

#define BUFFER_SIZE 10

char	*extract_new_line(char	**buffer)
{
	size_t		index;
	size_t		len;
	char		*line;

	len = ft_strlen(*buffer);
	index = 0;
	while (buffer[0][index])
	{
		if (buffer[0][index] == '\n')
			break;
		index++;
	}
	line = ft_substr(*buffer, 0, index + 1);
	if (len == index + 1)
		*buffer = NULL;
	else
		*buffer = ft_substr(*buffer, index + 1, len);
	return (line);
}

char	*read_line(char *static_buffer, int fd)
{
	int		bytes_read;
	char	buffer[BUFFER_SIZE + 1];
	char	*new_static_buffer;

	bytes_read = 1;
	while (!(ft_strchr(buffer, '\n')))
	{
		bytes_read = read(fd, buffer, BUFFER_SIZE);
		if (bytes_read == -1)
			return (free(static_buffer), NULL);
		if (bytes_read == 0)
			break;
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

char	*get_next_line(int	fd)
{
	static char 	*static_buffer;
	char			*line;

	if (fd < 0 || BUFFER_SIZE < 0)
		return (NULL);
	static_buffer = read_line(static_buffer, fd);
	if (static_buffer == NULL)
		return (NULL);
	line = extract_new_line(&static_buffer);
	return (line);
}

#include <fcntl.h>

int	main(void)
{
	int		fd;
	int		bytes_read;
	char	buffer[BUFFER_SIZE];
	char	*str;

	fd = open("text.txt", O_RDONLY);
	
	do {
		str = get_next_line(0);
		if (str == NULL)
			break;
		printf("%s", str);
	} while (str);

	close(fd);
	return (0);
}
