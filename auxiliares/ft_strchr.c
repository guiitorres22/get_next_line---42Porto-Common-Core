/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gtinani- <gtinani-@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/27 20:59:42 by guilherme         #+#    #+#             */
/*   Updated: 2024/05/06 18:28:14 by gtinani-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
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
	{
		return ((char *)(s + i));
	}
	return (NULL);
}
/*busca caractere especificado (c) em uma string (s)
**Ela percorre cada caractere da string até encontrar o
 caractere desejado ou o terminador nulo ('\0')
**Se encontrar o caractere, retorna um ponteiro para ele.
**Se o caractere desejado for o terminador nulo, retorna um
 ponteiro para o final da string.
**Caso contrário, retorna NULL.
*/
