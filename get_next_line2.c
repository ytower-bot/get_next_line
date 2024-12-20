/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yfaustin <yfaustin@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/18 10:24:30 by yfaustin          #+#    #+#             */
/*   Updated: 2024/12/20 00:53:25 by yfaustin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include "libft.h"
#include <stdio.h>

#define BUFFER_SIZE 10

char	*trim_buffer(char *static_buffer, char *line)
{
	char	*rest;
	int		len;
	int		i;

	len = ft_strlen(static_buffer);
	i = 0;
	if (static_buffer[0] == '\n')
		static_buffer++;
	while (static_buffer[i])
	{
		if (static_buffer[i] == '\n')
			break;
		i++;
	}
	printf("i: %d\n", i);
	rest = ft_substr(static_buffer, i, len - i);
	printf("rest:%s\n", rest);
	return (rest);
}

char	*extract_new_line(char	*buffer)
{
	size_t		index;
	char		*line;

	index = 0;
	while (buffer[index])
	{
		index++;
		if (buffer[index] == '\n')
			break;
	}
	line = ft_substr(buffer, 0, index);
	return (line);
}

char	*read_line(char *static_buffer, int fd)
{
	int		bytes_read;
	char	*buffer;
	int		index;
	
	buffer = (char *)malloc(BUFFER_SIZE + 1);
	if (!buffer)
		return (NULL);
	bytes_read = 1;
	index = 0;
	if (static_buffer == NULL)
		static_buffer = ft_strdup("");
	while (bytes_read > 0 && !(ft_strchr(buffer, '\n')))
	{
		bytes_read = read(fd, buffer, BUFFER_SIZE);
		if (bytes_read == -1)
		{
			free(buffer);
			free(static_buffer);
			return (NULL);
		}
		static_buffer = ft_strjoin(static_buffer, buffer);
		index++;
	}
	free(buffer);
	static_buffer[index * bytes_read] = '\0';
	return (static_buffer);
}

char	*get_next_line(int	fd)
{
	static char 	*static_buffer;
	char			*line;

	if (fd < 0 || BUFFER_SIZE < 0)
		return (NULL);
	static_buffer = read_line(static_buffer, fd);
	printf("static_buffer (read_line):%s\n", static_buffer);
	line = extract_new_line(static_buffer);
	static_buffer = trim_buffer(static_buffer, line);
//	printf("static_buffer (trim_buffer):%s\n", static_buffer);
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
	printf("\n========== 1 ==========\n\n");
	str = get_next_line(fd);
	printf("\n=======================\n\n");
	printf("\n========== 2 ==========\n\n");
	str = get_next_line(fd);
	printf("\n=======================\n\n");
//	printf("\ngnl:\n%s\n", str);
//	printf("\ngnl:\n%s\n", str);
//	str = get_next_line(fd);
//	printf("bytes read: %d\ngnl:\n%s\n", bytes_read, str);
	close(fd);
	return (0);
}
