/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yfaustin <yfaustin@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/18 10:24:30 by yfaustin          #+#    #+#             */
/*   Updated: 2024/12/18 10:53:40 by yfaustin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include "libft.h"
#include <unistd.h>

#define BUFFER_SIZE 10

int	find_new_line(char	*str)
{
	while (*str)
	{
		if (*str == '\n')
			return (1);
		str++;
	}
	return (0);
}

int	read_line(char **static_buffer, int fd)
{
	int				bytes_read;
	static char		*new_static_buffer;

	while (1)
	{
		char	buffer[BUFFER_SIZE];

		bytes_read = read(fd, buffer, BUFFER_SIZE);

		if (bytes_read == -1)
			return (-1); // error
		if (bytes_read == 0)
			return (-1); // tratar dps
		if (find_new_line(buffer))
			return (0);
	}
}

char	*get_next_line(int	fd)
{
	static char *static_buffer;
	char		buffer[BUFFER_SIZE];

	read_line(&static_buffer, fd);


	return (0);
}
