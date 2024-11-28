/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tat-nguy <tat-nguy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/08 19:56:17 by tat-nguy          #+#    #+#             */
/*   Updated: 2024/11/27 15:19:13 by tat-nguy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

char	*get_next_line(int fd)
{
	static char	*buffer[4096];
	char		*line;

	if (fd < 0 || fd >= 4096 || BUFFER_SIZE <= 0 || read(fd, 0, 0) < 0)
		return (NULL);
	buffer[fd] = ft_read_file(fd, buffer[fd]);
	if (buffer[fd] == NULL)
		return (NULL);
	line = ft_line(buffer[fd]);
	buffer[fd] = ft_remain(buffer[fd]);
	return (line);
}

char	*ft_read_file(int fd, char *remain)
{
	char	*buffer;
	int		byte_read;

	if (remain == NULL)
		remain = ft_calloc(1, 1);
	buffer = ft_calloc(BUFFER_SIZE + 1, sizeof(char));
	if (!buffer)
		return (NULL);
	byte_read = 1;
	while (byte_read > 0)
	{
		byte_read = read(fd, buffer, BUFFER_SIZE);
		if (byte_read < 0)
		{
			free(buffer);
			return (NULL);
		}
		buffer[byte_read] = '\0';
		remain = ft_lineappend(remain, buffer);
		if (!remain)
		{
			free(buffer);
			return (NULL);
		}
		if (ft_strchr(buffer, '\n') != NULL)
			break ;
	}
	free(buffer);
	return (remain);
}

char	*ft_line(char *buffer)
{
	char	*line;
	int		i;

	if (buffer == NULL || buffer[0] == '\0')
		return (NULL);
	i = 0;
	while (buffer[i] != '\0' && buffer[i] != '\n')
		i++;
	line = ft_calloc(i + 2, sizeof(char));
	if (line == NULL)
		return (NULL);
	i = 0;
	while (buffer[i] != '\0' && buffer[i] != '\n')
	{
		line[i] = buffer[i];
		i++;
	}
	if (buffer[i] != '\0' && buffer[i] == '\n')
		line[i++] = '\n';
	return (line);
}

char	*ft_remain(char *buffer)
{
	int		i;
	int		j;
	char	*remain;

	i = 0;
	while (buffer[i] != '\0' && buffer[i] != '\n')
		i++;
	if (buffer[i] == '\0')
	{
		free(buffer);
		return (NULL);
	}
	remain = ft_calloc((ft_strlen(buffer) - i + 1), sizeof(char));
	if (remain == NULL)
		return (NULL);
	i += (buffer[i] == '\n');
	j = 0;
	while (buffer[i] != '\0')
		remain[j++] = buffer[i++];
	remain[j] = '\0';
	free(buffer);
	return (remain);
}

char	*ft_lineappend(char *remain, char *buffer)
{
	char	*temp;

	temp = ft_strjoin(remain, buffer);
	free(remain);
	return (temp);
}

#include <fcntl.h>
#include <stdio.h>

int   main(void)
{
    char    *line1;
	//char	*line2;
	//char	*line3;
    int     i;
    int     fd1;
	//int		fd2;
	//int		fd3;


    fd1 = open("text.txt", O_RDONLY);
	//fd2 = open("number.txt", O_RDONLY);
	//fd3 = open("long.txt", O_RDONLY);

    i = 1;
    while (i < 10)
	{
		line1 = get_next_line(fd1);
        printf("text1 [%02i]: %s", i, line1);
        free(line1);
	// 	line2 = get_next_line(fd2);
	// 	printf("text2 [%02i]: %s", i, line2);
    //    free(line2);
	// 	line3 = get_next_line(fd3);
	// 	printf("text3 [%02i]: %s", i, line3);
    //    free(line3);
        i++;
	}
    close(fd1);
	//close(fd2);
	// close(fd3);
    return (0);
}