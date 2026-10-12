/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndwairi <ndwairi@learner.42.tech>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/04 17:03:48 by ndwairi           #+#    #+#             */
/*   Updated: 2026/10/11 12:45:07 by ndwairi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "get_next_line.h"

static char	*fill_static(int fd, char *temp, char *buffer)
{
	char	*old;
	ssize_t	size;

	while (!ft_strchr(temp, '\n'))
	{
		size = read(fd, buffer, BUFFER_SIZE);
		if (size < 0)
		{
			free(temp);
			return (NULL);
		}
		if (size == 0)
			break ;
		buffer[size] = '\0';
		old = temp;
		temp = ft_strjoin(old, buffer);
		free(old);
		if (!temp)
			return (NULL);
	}
	return (temp);
}

static char	*read_buffer(int fd, char *temp)
{
	char	*buffer;

	buffer = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buffer)
	{
		free(temp);
		return (NULL);
	}
	temp = fill_static(fd, temp, buffer);
	free(buffer);
	return (temp);
}

static char	*extract_the_line(const char *temp)
{
	char	*res;
	int		size;
	int		i;

	i = 0;
	size = temp_length(temp);
	res = malloc(sizeof(char) * (size + 1));
	if (!res)
		return (NULL);
	res[size] = '\0';
	while (i < size)
	{
		res[i] = temp[i];
		i++;
	}
	return (res);
}

char	*get_next_line(int fd)
{
	static char	*temp;
	char		*res;

	if (fd < 0 || read(fd, 0, 0) < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	temp = read_buffer(fd, temp);
	if (!temp)
		return (NULL);
	res = extract_the_line(temp);
	if (!res)
	{
		free(temp);
		temp = NULL;
		return (NULL);
	}
	temp = trim_temp(temp);
	return (res);
}
