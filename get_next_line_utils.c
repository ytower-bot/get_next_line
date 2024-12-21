/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yfaustin <yfaustin@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/21 20:03:59 by yfaustin          #+#    #+#             */
/*   Updated: 2024/12/21 20:10:07 by yfaustin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
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

char	*ft_strdup(const char *s)
{
	char	*str_dup;
	size_t	len;
	size_t	i;

	if (s == NULL)
		return (NULL);
	len = ft_strlen(s);
	str_dup = malloc((len + 1) * sizeof(char));
	if (str_dup == NULL)
		return (NULL);
	i = 0;
	while (i < len)
	{
		str_dup[i] = s[i];
		i++;
	}
	str_dup[i] = '\0';
	return (str_dup);
}

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

size_t	ft_strlen(const char *s)
{
	size_t	len;

	len = 0;
	while (s[len])
		len++;
	return (len);
}

char	*ft_substr(const char *s, unsigned int start, size_t len)
{
	char	*sub;

	if (!s)
		return (NULL);
	if (ft_strlen(s) < start)
		return (ft_strdup(""));
	if (ft_strlen(s + start) < len)
		len = ft_strlen(s + start);
	sub = malloc(sizeof(char) * (len + 1));
	if (sub == NULL)
		return (NULL);
	ft_strlcpy(sub, s + start, len + 1);
	return (sub);
}
