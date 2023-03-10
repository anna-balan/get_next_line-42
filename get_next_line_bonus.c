/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbalan <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/10 19:05:08 by hbalan            #+#    #+#             */
/*   Updated: 2023/03/10 19:44:00 by hbalan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

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

char	*get_next_line(int fd)
{
	static char	*s[1024];
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	s[fd] = read_from_fd(fd, s[fd]);
	if (!s[fd])
		return (NULL);
	line = read_line(s[fd]);
	s[fd] = next_line(s[fd]);
	return (line);
}

/*#include <stdio.h>
#include <fcntl.h>
int main(void)
{
    int fd1, fd2;
    char *line;

    fd1 = open("test1.txt", O_RDONLY);
    fd2 = open("test2.txt", O_RDONLY);
    
    while ((line = get_next_line(fd1)) != NULL) {
        printf("file1.txt: %s\n", line);
        free(line);
    }

    while ((line = get_next_line(fd2)) != NULL) {
        printf("file2.txt: %s\n", line);
        free(line);
    }

    close(fd1);
    close(fd2);

    return 0;
}

*/