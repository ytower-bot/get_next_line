/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yfaustin <yfaustin@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/17 00:24:43 by yfaustin          #+#    #+#             */
/*   Updated: 2024/12/18 13:39:02 by yfaustin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include "libft.h"

#define BUF_SIZE 10

static char	*extract_new_line(char	**buffer)
{
	return (*buffer);
}

static int	find_new_line(char *buffer[])
{
	int	i;

	i = 0;
	while (*buffer)
	{
		if (*buffer[i] == '\n')
			return (0);
		i++;
	}
	return (1);
}

static int	read_line(int fd, char **static_buffer)
{
	static char	*new_static_buffer;
	int		bytes_read;
	
	while (1)
	{
		char	buffer[BUF_SIZE];
		bytes_read = read(fd, buffer, BUF_SIZE);
		if (bytes_read == -1)
			return (-1);
		if (bytes_read == 0)
			return NULL;
		new_static_buffer = ft_strjoin(*static_buffer, buffer);
		free(buffer);
		*static_buffer = new_static_buffer;
		if (find_new_line(&buffer))
			return (0);
	}
}

char	*get_next_line(int fd)
{
	char		buffer[BUF_SIZE];
	static char	*static_buffer;
	
	if (!buffer || !find_new_line(buffer))
		if (read_line(fd, &static_buffer) == -1)
			return ("error");
	if (buffer != NULL)
		return (extract_new_line(&buffer));
	return (0);
}
