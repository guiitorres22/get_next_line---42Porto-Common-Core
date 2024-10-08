/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gtinani- <gtinani-@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/10 16:54:47 by gtinani-          #+#    #+#             */
/*   Updated: 2024/09/23 20:15:13 by gtinani-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*extract_line(char *line)
{
	int		i;
	char	*n_line;

	i = 0;
	if (!line[i])
		return (NULL);
	while (line[i] && line[i] != '\n')
		i++;
	n_line = (char *)malloc(sizeof(char) * (i + 2));
	if (!n_line)
		return (NULL);
	i = 0;
	while (line[i] && line[i] != '\n')
	{
		n_line[i] = line[i];
		i++;
	}
	if (line[i] == '\n')
	{
		n_line[i] = line[i];
		i++;
	}
	n_line[i] = '\0';
	return (n_line);
}

char	*new_line(char *line)
{
	char	*n_line;
	int		i;
	int		j;

	i = 0;
	j = 0;
	while (line && line[i] && line[i] != '\n')
		i++;
	if (!line[i])
	{
		free(line);
		return (NULL);
	}
	n_line = (char *)malloc((ft_strlen(line) - i + 1) * sizeof(char));
	if (!n_line)
		return (NULL);
	i++;
	while (line[i])
		n_line[j++] = line[i++];
	n_line[j] = '\0';
	free(line);
	return (n_line);
}

char	*read_and_join(int fd, char *line)
{
	char	*buffer;
	int		byte_read;

	buffer = (char *)malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (!buffer)
		return (NULL);
	byte_read = 1;
	while (!ft_strchr(line, '\n') && byte_read != 0)
	{
		byte_read = read(fd, buffer, BUFFER_SIZE);
		if (byte_read == -1)
		{
			free(buffer);
			return (NULL);
		}
		buffer[byte_read] = '\0';
		line = ft_strjoin(line, buffer);
	}
	free (buffer);
	return (line);
}

char	*get_next_line(int fd)
{
	static char	*line;
	char		*line_to_return;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	line = read_and_join(fd, line);
	if (!line)
		return (NULL);
	if (line[0] == '\0')
	{
		free(line);
		line = NULL;
		return (NULL);
	}
	line_to_return = extract_line(line);
	if (!line_to_return)
	{
		free(line);
		line = NULL;
		return (NULL);
	}
	line = new_line(line);
	return (line_to_return);
}
