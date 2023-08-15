/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bschweit <bschweit@student.42mulhouse.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/15 04:29:11 by bschweit          #+#    #+#             */
/*   Updated: 2023/08/15 04:29:11 by bschweit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include <string.h>
#include <stdio.h>
#include "get_next_line.h"

/*int	main(void)
{
	char	*line;
	int		i;
	int		fd1;
	int		fd2;
	int		fd3;

	fd1 = open("test.txt", O_RDONLY);
	//fd2 = open("test2.txt", O_RDONLY);
	//fd3 = open("test3.txt", O_RDONLY);
	i = 1;
	while (i < 20)
	{
		line = get_next_line(fd1);
		printf("line [%02d]: %s", i, line);
		free(line);
		line = get_next_line(fd2);
		printf("line [%02d]: %s", i, line);
		free(line);
		line = get_next_line(fd3);
		printf("line [%02d]: %s", i, line);
		free(line);
		i++;
	}
	close(fd1);
	//close(fd2);
	//close(fd3);
	return (0);
}*/

char	*real_line(char *line_buf)
{
	int		i;
	char	*str;

	i = 0;
	if (!line_buf[i])
		return (NULL);
	while (line_buf[i] != '\0' && line_buf[i] != '\n')
		i++;
	str = malloc(sizeof(char) * (i + 2));
	if (!str)
		return (NULL);
	i = 0;
	while (line_buf[i] != '\0' && line_buf[i] != '\n')
	{
		str[i] = line_buf[i];
		i++;
	}
	if (line_buf[i] == '\n')
	{
		str[i] = line_buf[i];
		i++;
	}
	str[i] = '\0';
	return (str);
}

char	*read_file(int fd, char *line_fd)
{
	int		readed;
	char	*buf;

	buf = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	readed = 1;
	if (!buf)
		return (NULL);
	while (!ft_strchr(line_fd, '\n') && readed != 0)
	{
		readed = read(fd, buf, BUFFER_SIZE);
		if (readed == -1)
		{
			free(buf);
			return (NULL);
		}
		buf[readed] = '\0';
		line_fd = ft_strjoin(line_fd, buf);
	}
	free(buf);
	return (line_fd);
}

char	*clean_line_buf(char *line_buf)
{
	int		i;
	int		j;
	char	*str;

	i = 0;
	j = 0;
	while (line_buf[i] != '\0' && line_buf[i] != '\n')
		i++;
	if (line_buf[i] == '\0')
	{
		ft_memset(line_buf, 0, ft_strlen(line_buf));
		free(line_buf);
		return (NULL);
	}
	str = malloc(sizeof(char) * (ft_strlen(line_buf) - i + 1));
	if (!str)
		return (NULL);
	while (line_buf[++i] != '\0')
	{
		str[j++] = line_buf[i];
	}
	str[j] = '\0';
	ft_memset(line_buf, 0, ft_strlen(line_buf));
	free(line_buf);
	return (str);
}

char	*get_next_line(int fd)
{
	static char	*line_buf[1024 + 1];
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (0);
	line_buf[fd] = read_file(fd, line_buf[fd]);
	if (!line_buf[fd])
		return (NULL);
	line = real_line(line_buf[fd]);
	line_buf[fd] = clean_line_buf(line_buf[fd]);
	return (line);
}
