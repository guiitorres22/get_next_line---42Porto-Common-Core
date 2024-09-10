#include "get_next_line.h"

size_t ft_strlen(const char *str)
{
    size_t  i;

    i = 0;
    while (str[i] != '\0')
	    i++;
    return (i);
}


char *ft_strdup(const char *s) 
{
    char    *dst;
    size_t	i;
    size_t  len;

    len = ft_strlen(s);
    dst = malloc((len + 1) * sizeof(char));
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


char *ft_strjoin(char *s1, char *s2) 
{
    char    *nstr;
    size_t  i;
    size_t  j;
    
    if	(!s1)
    {
    	s1 = malloc(sizeof(char) * 1);
    	if (!s1)
    		return (NULL);
    	s1[0] = '\0';
    }
    nstr = (char *)malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 1));
    if (!nstr)
    {
    	free(s1);
    	return (NULL);
    	
    }
    i = 0;
    while (s1[i])
    {
	nstr[i] = s1[i];
	i++;
    }
    j = 0;
    while (s2[j])
    {
	nstr[i + j] = s2[j];
	j++;
    }
    nstr[i + j] = '\0';
    free(s1);
    return (nstr);
}


char *ft_strchr(const char *s, int c)
{
    size_t	i;

    i = 0;
    while (s[i] != '\0')
    {
	if (s[i] == (char)c)
	{
	    return ((char *)(s + i));
	}
	i++;
    }
    if ((char)c == '\0')
	return ((char *)(s + i));
    return (NULL);
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
