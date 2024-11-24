/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tat-nguy <tat-nguy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/08 19:56:17 by tat-nguy          #+#    #+#             */
/*   Updated: 2024/11/22 17:32:33 by tat-nguy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

//update the buffer and return line

char	*get_next_line(int fd)
{
	static char	*buffer;
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0 || read(fd, 0, 0) < 0)
		return (NULL);
	buffer = ft_read_file(fd, buffer); //TODO
	if (buffer == NULL)
		return (NULL);
	line = ft_line(buffer); //TODO
	buffer = ft_next(buffer); //TODO
	return (line);
}

char	*ft_read_file(int fd, char *rest)
{
	char	*buffer;
	int		byte_read;
	
	if (rest == NULL)
		rest = ft_calloc(1, 1);
	buffer = ft_calloc(BUFFER_SIZE + 1, sizeof(char));
	byte_read = 1;
	while (byte_read > 0)
	{
		byte_read = read(fd, buffer, BUFFER_SIZE);
		if (byte_read < 0)
		{
			free(buffer);
			return (NULL);
		}
		buffer[byte_read] = 0;
		rest = ft_free(rest, buffer); //TODO
		if (ft_strchr(buffer, '\n'))
			break;
	}
	free(buffer);
	return (rest);
}


