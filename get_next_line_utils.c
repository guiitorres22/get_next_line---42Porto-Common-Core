/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gtinani- <gtinani-@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/10 16:55:53 by gtinani-          #+#    #+#             */
/*   Updated: 2024/09/19 21:03:46 by gtinani-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(const char *str)
{
	size_t	i;

	i = 0;
	if (!str)
		return (0);
	while (str[i] != '\0')
		i++;
	return (i);
}

char	*ft_strdup(const char *s)
{
	char	*dst;
	size_t	i;

	dst = (char *)malloc(sizeof(char) * (ft_strlen((char *)s)) + 1);
	if (!dst)
		return (NULL);
	i = 0;
	while (s[i] != '\0')
	{
		dst[i] = s[i];
		i++;
	}
	dst[i] = '\0';
	return (dst);
}

void	*ft_calloc(size_t nmemb, size_t size)
{
	void	*p;
	size_t	i;

	p = malloc(nmemb * size);
	if (!p)
	{
		return (NULL);
	}
	i = 0;
	while (i < (nmemb * size))
	{
		((char *)p)[i] = 0;
		i++;
	}
	return (p);
}

char	*ft_strjoin(char *s1, char *s2)
{
	size_t	i;
	size_t	c;
	char	*str;

	if (!s1)
	{
		s1 = (char *)malloc(1 * sizeof(char));
		s1[0] = '\0';
	}
	if (!s1 || !s2)
		return (NULL);
	str = malloc((ft_strlen(s1) + ft_strlen(s2) + 1) * sizeof(char));
	if (str == NULL)
		return (NULL);
	i = -1;
	c = 0;
	if (s1)
		while (s1[++i] != '\0')
			str[i] = s1[i];
	while (s2[c] != '\0')
		str[i++] = s2[c++];
	str[ft_strlen(s1) + ft_strlen(s2)] = '\0';
	free(s1);
	return (str);
}

char	*ft_strchr(const char *s, int c)
{
	size_t	i;

	i = 0;
	if (s == NULL)
		return (NULL);
	while ((unsigned char)s[i] != (unsigned char)c && s[i])
		i++;
	if ((unsigned char)c == (unsigned char)s[i])
		return ((char *)(s + i));
	return (NULL);
}
