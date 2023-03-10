/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbalan <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/06 09:58:50 by hbalan            #+#    #+#             */
/*   Updated: 2023/03/06 15:27:40 by hbalan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*read_input(int fd, char *s)
{
	char	*buff;
	int		read_bytes;

	read_bytes = 1;
	buff = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buff)
		return (NULL);
	while (read_bytes != 0 && !ft_strchr(s, '\n'))
	{
		read_bytes = read(fd, buff, BUFFER_SIZE);
		if (read_bytes == -1)
		{
			free(buff);
			return (NULL);
		}
		buff[read_bytes] = '\0';
		s = ft_strjoin(s, buff);
	}
	free(buff);
	return (s);
}

char	*get_line(char *s)
{
	char	*res;
	int		i;

	i = 0;
	if (!*s)
		return (NULL);
	while (s[i] && s[i] != '\n')
		i++;
	res = malloc(sizeof(char) * (i + 2));
	if (!res)
		return (NULL);
	i = 0;
	while (s[i] && s[i] != '\n')
	{
		res[i] = s[i];
		i++;
	}
	if (s[i] == '\n')
	{
		res[i] = s[i];
		i++;
	}
	res[i] = '\0';
	return (res);
}

char	*next_line(char *s)
{
	char	*res;
	int		i;
	int		j;

	i = 0;
	j = 0;
	while (s[i] && s[i] != '\n')
		i++;
	if (!s[i])
	{
		free(s);
		return (NULL);
	}
	res = malloc(sizeof(char) * (ft_strlen(s) + 1 - i));
	if (!res)
		return (NULL);
	i++;
	while (s[i])
		res[j++] = s[i++];
	res[j] = '\0';
	free(s);
	return (res);
}

char	*get_next_line(int fd)
{
	static char	*s;
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	s = read_input(fd, s);
	if (!s)
		return (NULL);
	line = get_line(s);
	s = next_line(s);
	return (line);
}

#include <stdio.h>
#include <fcntl.h>

int	main(void)
{
	char	*line;
	int		fd;
	// int		fd2;
	// int		fd3;
	int		i;
    
	fd = open("test1.txt", O_RDONLY);
	//bonus
	//fd2 = open("test2.txt", O_RDONLY);
	//fd3 = open("test3.txt", O_RDONLY);
    
	i = 0;
	
	while (line)
	{
		line = get_next_line(fd);
		
		printf("line %d: %s", i, line);
		free(line);
		i++;
	}
	// while (i < 10)
	// {
	// 	line = get_next_line(fd);
	// 	printf("line %d: %s", i, line);
	// 	free(line);
	// 	//bonuses
	// 	//line = get_next_line(fd2);
	// 	//printf("line %d: %s", i, line);
	// 	//free(line);
	// 	//line = get_next_line(fd3);
	// 	//printf("line %d: %s", i, line);
	// 	//free(line);
	// 	i++;
	// }
	close(fd);
	// close(fd2);
	// close(fd3);
	return (0);
}
