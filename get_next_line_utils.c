/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndwairi <ndwairi@learner.42.tech>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/04 17:04:14 by ndwairi           #+#    #+#             */
/*   Updated: 2026/10/08 14:43:49 by ndwairi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "get_next_line.h"

int	ft_strlen(const char *s)
{
	int	i;

	i = 0;
	if (!s)
		return (0);
	while (s[i])
		i++;
	return (i);
}

int	temp_length(const char *temp)
{
	int	i;

	i = 0;
	if (!temp)
		return (0);
	while (temp[i] && temp[i] != '\n')
		i++;
	if (temp[i] == '\n')
		i++;
	return (i);
}

char	*ft_strchr(const char *str, int ch)
{
	unsigned char	c;

	if (!str)
		return (NULL);
	c = (unsigned char)ch;
	while (*str != '\0')
	{
		if ((unsigned char)*str == c)
			return ((char *)str);
		str++;
	}
	if (c == '\0')
		return ((char *)str);
	return (NULL);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	i;
	size_t	j;
	char	*news;

	if (!s2)
		return (NULL);
	news = malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 1));
	if (!news)
		return (NULL);
	i = 0;
	while (s1 && s1[i])
	{
		news[i] = s1[i];
		i++;
	}
	j = 0;
	while (s2[j])
		news[i++] = s2[j++];
	news[i] = '\0';
	return (news);
}

char	*trim_temp(char *temp)
{
	char	*new_temp;
	int		i;
	int		j;
	int		k;

	i = 0;
	while (temp[i] && temp[i] != '\n')
		i++;
	if (!temp[i] || !temp[i + 1])
	{
		free(temp);
		return (NULL);
	}
	j = i + 1;
	while (temp[j])
		j++;
	new_temp = malloc(sizeof(char) * (j - i));
	k = 0;
	while (new_temp && temp[++i])
		new_temp[k++] = temp[i];
	if (new_temp)
		new_temp[k] = '\0';
	free(temp);
	return (new_temp);
}
