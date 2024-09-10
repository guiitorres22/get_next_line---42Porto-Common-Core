/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gtinani- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/10 16:54:47 by gtinani-          #+#    #+#             */
/*   Updated: 2024/09/10 18:37:24 by gtinani-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*extract_line(char *line)
{
	int		i;
	char	*n_line;

	i = 0;
	while (line[i] && line[i] != '\n')
		i++;
	if (line[i] == '\n')
		i++;
	n_line = (char *)ft_calloc((i + 1), sizeof(char));
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
	if (line[i] == '\0')
	{
		free(line);
		return (NULL);
	}
	n_line = ft_calloc((ft_strlen(line) - i + 1), sizeof(char));
	if (!n_line)
		return (NULL);
	i++;
	while (line[i])
		n_line[j++] = line[i++];
	n_line[i] = '\0';
	free(line);
	return (n_line);
}

char	*read_and_join(int fd, char *line)
{
	char	*buffer;
	int		byte_read;

	buffer = ft_calloc(BUFFER_SIZE + 1, sizeof(char));
	if (!buffer)
		return (NULL);
	byte_read = read(fd, buffer, BUFFER_SIZE);
	while (byte_read > 0)
	{
		if (!line)
			line = ft_strdup("");
		line = ft_strjoin(line, buffer);
		if (ft_strchr(line, '\n'))
			break ;
		byte_read = read(fd, buffer, BUFFER_SIZE);
	}
	if (byte_read < 0)
	{
		free(buffer);
		free(line);
		return (NULL);
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
	if (!line)
		line = ft_strdup("");
	line = read_and_join(fd, line);
	if (!line || line[0] == '\0')
	{
		free(line);
		line = NULL;
		return (NULL);
	}
	line_to_return = extract_line(line);
	line = new_line(line);
	return (line_to_return);
}
/*
int main(void)
{
	char *line;
	int i;
	int file;

	file = open("test.txt", O_RDONLY);
	if (file == -1) {
		perror("Error opening file");
		return (1);
	}
	i = 1;
	printf("buffer size > %d\n", BUFFER_SIZE);
	line = get_next_line(file);
	while (line != 0)
	{
		printf("line [%02d]:%s\n", i, line);
		free(line);
		line = get_next_line(file);
		i++;
	}
	close(file);
	return (0);
}
*/
/*int main(void)
{
	char *line;
	int i;
	int fd1;

	fd1 = open("test.txt", O_RDONLY);
	if (fd1 == -1) {
		perror("Error opening file");
		return (1);
	}
	i = 1;
	printf("Buffer size > %d\n", BUFFER_SIZE);
	line = get_next_line(fd1);
	while (line != 0)
	{
		printf("line [%02d]:%s\n", i, line);
		free(line);
		line = get_next_line(fd1);
		i++;
	}
	close(fd1);
	return (0);
} 
int main() 
{
    char *filename;
    char *line;
    int fd;

    // Test 1
    filename = "test.txt";
    fd = open(filename, O_RDONLY);
    if (fd == -1) {
        perror("Error opening file");
        return 1;
    }
    printf("Reading from %s:\n", filename);
    while ((line = get_next_line(fd)) != NULL) {
        printf("%s", line);
        free(line);
    }
    close(fd);
    printf("\n");
}
    // Test 2
    filename = "test2.txt";
    fd = open(filename, O_RDONLY);
    if (fd == -1) {
        perror("Error opening file");
        return 1;
    }
    printf("Reading from %s:\n", filename);
    while ((line = get_next_line(fd)) != NULL) {
        printf("%s", line);
        free(line);
    }
    close(fd);
    printf("\n");

    // Test 3
    filename = "test3.txt";
    fd = open(filename, O_RDONLY);
    if (fd == -1) {
        perror("Error opening file");
        return 1;
    }
    printf("Reading from %s:\n", filename);
    while ((line = get_next_line(fd)) != NULL) {
        printf("%s", line);
        free(line);
    }
    close(fd);
    printf("\n");

    // Test 4
    filename = "test4.txt";
    fd = open(filename, O_RDONLY);
    if (fd == -1) {
        perror("Error opening file");
        return 1;
    }
    printf("Reading from %s:\n", filename);
    while ((line = get_next_line(fd)) != NULL) {
        printf("%s", line);
        free(line);
    }
    close(fd);
    printf("\n");

	    // Test 5
    filename = "test5.txt";
    fd = open(filename, O_RDONLY);
    if (fd == -1) {
        perror("Error opening file");
        return 1;
    }
    printf("Reading from %s:\n", filename);
    while ((line = get_next_line(fd)) != NULL) {
        printf("%s", line);
        free(line);
    }
    close(fd);
    printf("\n");
	
    return 0;
} */
/* int main() {
    char *filename;
    char *line;
    int fd;

    // Test 1
    filename = "test1.txt";
    fd = open(filename, O_RDONLY);
    if (fd == -1) {
        perror("Error opening file");
        return 1;
    }
    printf("Reading from %s:\n", filename);
    while ((line = get_next_line(fd)) != NULL) {
        printf("%s", line);
        free(line);
    }
    close(fd);
    printf("\n");

    // Test 2: Arquivo inexistente (fd = NULL)
    filename = "nonexistent.txt";
    fd = open(filename, O_RDONLY);
    if (fd == -1) {
        perror("Error opening file");
        return 1;
    }
    printf("Reading from %s:\n", filename);
    while ((line = get_next_line(fd)) != NULL) {
        printf("%s", line);
        free(line);
    }
    close(fd);
    printf("\n");

    return 0;
} */
