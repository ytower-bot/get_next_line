/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yfaustin <yfaustin@42.student.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/03 17:14:18 by yfaustin          #+#    #+#             */
/*   Updated: 2024/10/03 17:14:20 by yfaustin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(const char *s1, const char *set)
{
	int		i;
	int		end;
	char	*str;

	if (!s1 || !set)
		return (NULL);
	i = 0;
	end = ft_strlen(s1) - 1;
	while (ft_strchr(set, s1[i]) && i <= end)
		i++;
	if (i > end)
		return (ft_strdup(&s1[++end]));
	while (ft_strchr(set, s1[end]) && end >= 0)
		end--;
	str = malloc(end - i + 2);
	if (!str)
		return (NULL);
	ft_strlcpy(str, &s1[i], end - i + 2);
	return (str);
}
