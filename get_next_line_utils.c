/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mryoo <mryoo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/11 10:46:06 by mryoo             #+#    #+#             */
/*   Updated: 2023/08/21 17:54:37 by mryoo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_strdup(const char *s1)
{
	size_t	i;
	char	*src;

	if (!s1)
		return (NULL);
	src = (char *)malloc(sizeof(char) * (ft_strlen(s1) + 1));
	if (!src)
		return (NULL);
	i = 0;
	while (s1[i])
	{
		src[i] = s1[i];
		i++;
	}
	src[i] = '\0';
	return (src);
}

char	*ft_strjoin(char *s1, char *s2)
{
	char	*str;
	size_t	i;
	size_t	j;

	if (!s1 && !s2)
		return (NULL);
	j = ft_strlen(s1) + ft_strlen(s2);
	str = (char *)malloc(sizeof(char) * (j + 1));
	if (!str)
		return (NULL);
	i = 0;
	j = 0;
	while (*(s1 + i))
		*(str + j++) = *(s1 + i++);
	i = 0;
	while (*(s2 + i))
		*(str + j++) = *(s2 + i++);
	*(str + j) = '\0';
	return (str);
}

char	*ft_strchr(const char *s, int c)
{
	size_t	i;

	i = 0;
	while (*(s + i))
	{
		if (*(s + i) == c)
			return ((char *) s);
		i++;
	}
	return (NULL);
}

size_t	ft_strlen(const char *s)
{
	size_t	len;

	len = 0;
	if (!s)
		return (0);
	while (*(s + len) != '\0')
		len++;
	return (len);
}

void	ft_free(char *arr)
{
	if (arr)
	{
		free(arr);
		arr = 0;
	}
	return ;
}
