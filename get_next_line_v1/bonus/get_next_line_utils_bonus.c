/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tat-nguy <tat-nguy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/08 19:57:04 by tat-nguy          #+#    #+#             */
/*   Updated: 2024/11/27 15:10:41 by tat-nguy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

size_t	ft_strlen(char *str)
{
	unsigned int	i;

	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}

void	*ft_calloc(unsigned int nmemb, unsigned int size)
{
	char			*s;
	unsigned int	i;

	s = malloc(sizeof(char) * (nmemb * size));
	if (s == NULL)
		return (NULL);
	i = 0;
	while (i < (nmemb * size))
	{
		((char *)s)[i] = 0;
		i++;
	}
	return (s);
}

char	*ft_strchr(char *s, char c)
{
	int		i;

	i = 0;
	while (s[i] != '\0')
	{
		if (s[i] == c)
			return (s + i);
		i++;
	}
	if (c == 0)
		return (s + i);
	return (NULL);
}

char	*ft_strjoin(char *s1, char *s2)
{
	unsigned int	len;
	char			*new;
	unsigned int	i;
	unsigned int	j;

	len = ft_strlen(s1) + ft_strlen(s2);
	new = malloc(sizeof(char) * (len + 1));
	if (new == NULL)
		return (NULL);
	i = 0;
	while (s1[i] != '\0')
	{
		new[i] = s1[i];
		i++;
	}
	j = 0;
	while (s2[j] != '\0')
		new[i++] = s2[j++];
	new[i] = 0;
	return (new);
}
