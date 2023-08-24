/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mryoo <mryoo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/11 10:46:11 by mryoo             #+#    #+#             */
/*   Updated: 2023/08/21 18:16:22 by mryoo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	static char	*backup;
	char		*buf;
	char		*line;
	size_t		n;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	buf = (char *)malloc(sizeof(char) * BUFFER_SIZE + 1);
	if (!buf)
		return (ft_free(backup), backup = NULL, ft_free(buf), NULL);
	n = 1;
	backup = get_data(fd, backup, buf, n);
	ft_free(buf);
	if (!backup)
		return (free(backup), backup = NULL, NULL);
	line = get_one_line(backup);
	if (!line)
		return (free(backup), backup = NULL, free(line), line = NULL, NULL);
	backup = get_remain_line(backup);
	return (line);
}

char	*get_data(int fd, char *arr, char *buf, int n)
{
	char	*temp;

	while (n != 0)
	{
		n = read(fd, buf, BUFFER_SIZE);
		if (n == -1)
			return (ft_free(arr), NULL);
		buf[n] = '\0';
		temp = arr;
		if (!temp)
			temp = ft_strdup("");
		if (!temp)
		{
			ft_free(arr);
			return (NULL);
		}
		arr = ft_strjoin(temp, buf);
		ft_free(temp);
		temp = NULL;
		if (!arr)
			return (NULL);
		if (ft_strchr(arr, '\n') != NULL)
			break ;
	}
	return (arr);
}

char	*get_one_line(char *arr)
{
	int		idx;
	char	*one;

	if (ft_strlen(arr) == 0)
		return (NULL);
	idx = 0;
	while (*(arr + idx) != '\n' && *(arr + idx) != '\0')
		idx++;
	if (*(arr + idx) == '\0')
		one = (char *)malloc(sizeof(char) * (idx + 1));
	else
		one = (char *)malloc(sizeof(char) * (idx + 2));
	if (!one)
		return (NULL);
	idx = 0;
	while (*(arr + idx) != '\0' && *(arr + idx) != '\n')
	{
		*(one + idx) = *(arr + idx);
		idx++;
	}
	if (*(arr + idx) == '\n')
		*(one + idx++) = '\n';
	*(one + idx) = '\0';
	return (one);
}

char	*get_remain_line(char *arr)
{
	int		n;
	int		idx;
	char	*temp;

	n = 0;
	while (*(arr + n) != '\n' && *(arr + n) != '\0')
		n++;
	if (*(arr + n) == '\0')
		return (ft_free(arr), NULL);
	temp = (char *)malloc(sizeof(char) * (ft_strlen(arr) - n + 1));
	if (!temp)
	{
		ft_free(arr);
		return (NULL);
	}
	idx = 0;
	while (*(arr + ++n) != '\0')
		*(temp + idx++) = *(arr + n);
	*(temp + idx) = '\0';
	ft_free(arr);
	return (temp);
}
