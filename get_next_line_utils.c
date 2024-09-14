/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gtinani- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/10 16:55:53 by gtinani-          #+#    #+#             */
/*   Updated: 2024/09/10 19:17:39 by gtinani-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(const char *str)
{
	size_t	i;

	i = 0;
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

char	*ft_strjoin(char *s1, char *s2)
{
	char	*nstr;
	size_t	i;
	size_t	j;

	nstr = ft_calloc(((ft_strlen((char *)s1) + ft_strlen((char *)s2)) + 1), sizeof(char));
	if (nstr == 0)
		return (NULL);
	i = 0;
	while (s1 && s1[i] != '\0')
	{
		nstr[i] = s1[i];
		i++;
	}
	j = 0;
	while (s2 && s2[j] != '\0')
	{
		nstr[i] = s2[j];
		j++;
		i++;
	}
	nstr[i] = '\0';
	free(s1);
	return (nstr);
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
	return (NULL);;
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
