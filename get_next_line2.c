/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yfaustin <yfaustin@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/18 10:24:30 by yfaustin          #+#    #+#             */
/*   Updated: 2024/12/18 17:55:38 by yfaustin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include "libft.h"
#include <stdio.h>

#define BUFFER_SIZE 100

char	*trim_static_buffer(char *static_buffer)
{
	while (*static_buffer != '\0')
}

char	*extract_new_line(char	*buffer)
{
	size_t		index;
	char		*line;

	index = 0;
	while (buffer[index])
	{
		if (buffer[index] == '\n')
			break;
		index++;
	}
	line = ft_substr(buffer, 0, index);
	free(buffer);
	return (line);
}

char	*read_line(char *static_buffer, int fd)
{
	int		bytes_read;
	char	*buffer;
	
	buffer = (char *)malloc(BUFFER_SIZE + 1);
	if (!buffer)
		return (NULL);
	bytes_read = 1;
	if (static_buffer == NULL)
		static_buffer = ft_strdup("");
	while (bytes_read > 0 && !ft_strchr(buffer, '\n'))
	{
		bytes_read = read(fd, buffer, BUFFER_SIZE);
		if (bytes_read == -1)
		{
			free(buffer);
			free(static_buffer);
			return (NULL);
		}
		static_buffer = ft_strjoin(static_buffer, buffer);
	}
	free(buffer);
	static_buffer[bytes_read] = '\0';
	return (static_buffer);
}

char	*get_next_line(int	fd)
{
	static char 	*static_buffer;
	char			*line;

	if (fd < 0 || BUFFER_SIZE < 0)
		return (NULL);
	static_buffer = read_line(static_buffer, fd);

	line = extract_new_line(static_buffer);

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
	str = get_next_line(fd);
	printf("bytes read: %d\ngnl:\n%s\n", bytes_read, str);
//	str = get_next_line(fd);
//	printf("bytes read: %d\ngnl:\n%s\n", bytes_read, str);
	close(fd);
	return (0);
}
