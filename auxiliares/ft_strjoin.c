/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gtinani- <gtinani-@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/07 16:06:53 by gtinani-          #+#    #+#             */
/*   Updated: 2024/05/07 16:31:14 by gtinani-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*nstr;
	size_t	i;
	size_t	j;

	if (!s1 || !s2)
		return (NULL);
	nstr = (char *)malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 1));
	if (nstr)
	{
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
		return (nstr);
	}
	return (NULL);
}
/*
** Função ft_strjoin
** -----------------
** Esta função concatena duas strings (s1 e s2) em uma nova string.
** A nova string é alocada dinamicamente e contém o conteúdo de s1
** seguido pelo conteúdo de s2. O resultado é uma única string que
** combina os dois argumentos.
**
** Parâmetros:
** - s1: A primeira string a ser concatenada.
** - s2: A segunda string a ser concatenada.
**
** Retorno:
** - Se a alocação de memória for bem-sucedida, a função retorna um
**   ponteiro para a nova string resultante.
** - Caso contrário, retorna NULL.
**
** Observações:
** - Certifique-se de liberar a memória alocada para a nova string
**   quando não for mais necessária (usando free()).
** - Se s1 ou s2 forem NULL, a função também retornará NULL.
*/
