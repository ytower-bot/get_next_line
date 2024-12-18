/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yfaustin <yfaustin@42.student.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/01 17:56:23 by yfaustin          #+#    #+#             */
/*   Updated: 2024/12/18 17:03:25 by yfaustin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(const char *s1, const char *s2)
{
	char	*str;
	size_t	len_s1;
	size_t	len;
	size_t	i;
	
	len_s1 = ft_strlen(s1);
	len = len_s1 + ft_strlen(s2);
	str = malloc(sizeof(char) * len + 1);
	if (str == NULL)
		return (NULL);
	i = 0;
	while (s1[i])
	{
		str[i] = s1[i];
		i++;
	}
	i = 0;
	while (s2[i])
	{
		str[len_s1 + i] = s2[i];
		i++;
	}
	str[len_s1 + i] = '\0';
	return (str);
}
