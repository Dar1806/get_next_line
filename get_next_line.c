/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmeunier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/27 13:57:16 by nmeunier          #+#    #+#             */
/*   Updated: 2025/11/27 13:57:16 by nmeunier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*fill_line(int fd, char *buffer, char *left_c)
{
	ssize_t	readf;
	char	*tmp;

	readf = 1;
	while (readf > 0)
	{
		readf = read(fd, buffer, BUFFER_SIZE);
		if (readf == -1)
		{
			free (left_c);
			return (NULL);
		}
		else if (readf == 0)
			break ;
		buffer[readf] = '\0';
		if (!left_c)
			left_c = ft_strdup(buffer);
		tmp = left_c;
		left_c = ft_strjoin(tmp, buffer);
		free(tmp);
		tmp = NULL;
		if (ft_strchr(buffer, '\n'))
			break ;
	}
	return (left_c);
}

char	*get_next_line(int fd)
{
	static char	*left_c;
	char		*buffer;
	char		*line;

	buffer = malloc(sizeof(char) * BUFFER_SIZE + 1);
	if (!buffer)
		return (NULL);
	if (fd < 0 || BUFFER_SIZE <= 0)
	{
		free(buffer);
		free(left_c);
		buffer = NULL;
		left_c = NULL;
		return (NULL);
	}
	line = fill_line(fd, buffer, left_c);
	free(buffer);
	buffer = NULL;
	if (!line)
		return (NULL);
	return (line);
}

int	main(void)
{
	char	*line;
	int		fd;

	line = "";
	fd = open("test.txt", O_RDONLY);
	line = get_next_line(fd);
	printf("premier %s\n", line);
}
