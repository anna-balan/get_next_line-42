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
//to read input from fd and store it in static var s
char	*read_from_fd(int fd, char *s)
{
	char	*buf;
	int		bytes_count;

	bytes_count = 1;
	buf = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buf)
		return (NULL);
	while (bytes_count != 0 && !ft_strchr(s, '\n'))
	{
		bytes_count = read(fd, buf, BUFFER_SIZE);
		if (bytes_count == -1)
		{
			free(buf);
			return (NULL);
		}
		buf[bytes_count] = '\0';
		s = ft_strjoin(s, buf);
	}
	free(buf);
	return (s);
}
//to extract the first line of text from s and return it
char	*read_line(char *s)
{
	char	*line;
	int		i;

	i = 0;
	if (!*s)
		return (NULL);
	while (s[i] && s[i] != '\n')
		i++;
	line = malloc(sizeof(char) * (i + 2));
	if (!line)
		return (NULL);
	i = 0;
	while (s[i] && s[i] != '\n')
	{
		line[i] = s[i];
		i++;
	}
	if (s[i] == '\n')
	{
		line[i] = s[i];
		i++;
	}
	line[i] = '\0';
	return (line);
}

// to remove first line from s and store remaining in s
char	*next_line(char *s)
{
	char	*line;
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
	line = malloc(sizeof(char) * (ft_strlen(s) + 1 - i));
	if (!line)
		return (NULL);
	i++;
	while (s[i])
		line[j++] = s[i++];
	line[j] = '\0';
	free(s);
	return (line);
}
// reads input from the fd, and returns the next line of text until  \n is found
char	*get_next_line(int fd)
{
	static char	*s;
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	s = read_from_fd(fd, s);
	if (!s)
		return (NULL);
	line = read_line(s);
	s = next_line(s);
	return (line);
}

#include <stdio.h>
#include <fcntl.h>

/*int	main(void)
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
*/