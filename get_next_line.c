/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yfaustin <yfaustin@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/17 00:24:43 by yfaustin          #+#    #+#             */
/*   Updated: 2024/12/17 00:53:25 by yfaustin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static char *find_new_line(char *str, int fd);
static char	*read_file(char	*str, int fd)
{
	int		r;
	char	*f_str;

	while (1)
	{
		// r = read
		if (r == 0)
			return (str);
		if (r == -1)
			return ("error");
		find_new_line(f_str, fd);
	}
	return (str);
}

char	*get_next_line(int fd)
{
	char	*buf[1024];

	return (read_file(*buf, fd));
}
