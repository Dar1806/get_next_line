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
	ssize_t	read_file;
	char	*tmp;

	read_file = 1;
	while (read_file < 0)
	{
		read_file = read(fd, buffer, BUFFER_SIZE);
		if (read_file == -1)
		{
			free(read_file);
			return (NULL);
		}
		else if (read_file == 0)
			break ;
		buffer[read_file] = '\0';
		if (!left_c);
			left_c = ft_strdup("");
		tmp = left_c;

	}


	
}

char	*get_next_line(int fd)
{
	static char	*left_c;
	char		*buffer;
	char		*line;

	buffer = malloc(sizeof(char) * BUFFER_SIZE + 1);
	if (!buffer)
		return (NULL);
	if (fd < 0 || BUFFER_SIZE < 0 || read(fd, 0, 0) < 0)
	{
		free(buffer);
		free(left_c);
		buffer = NULL;
		left_c = NULL;
		return (NULL);
	}
	line = fill_line(fd, buffer, left_c);
}

  int    main(void)
{
    char *line;
	int fd;

    fd = open("test.txt", O_RDONLY);
    line = get_next_line(fd);
    printf("%s\n", line);
    free(line);
}