/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gtinani- <gtinani-@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/26 16:25:23 by gtinani-          #+#    #+#             */
/*   Updated: 2024/04/26 16:38:19 by gtinani-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s)
{
	char	*dst;
	size_t	i;
	size_t	l;

	i = 0;
	l = ft_strlen(s);
	dst = malloc((l + 1) * sizeof(char));
	if (!dst)
		return (NULL);
	while (s[i] != '\0')
	{
		dst[i] = s[i];
		i++;
	}
	dst[i] = '\0';
	return (dst);
}
/* Função ft_strdup: Duplica uma string
**Calcula o tamanho da string original
**Aloca memória para a nova string 
(incluindo espaço para o caractere nulo)
**Retorna NULL se a alocação de memória falhar
**Copia os caracteres da string original para a nova string
** Adiciona o caractere nulo ao final da nova string
**Retorna a nova string duplicada
*/
