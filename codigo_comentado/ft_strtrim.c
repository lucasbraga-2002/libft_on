/* ************************************************************************** */

/*
** FICHA DIDATICA: ft_strtrim
** OBJETIVO: Remover de ambas as pontas caracteres que pertencem ao conjunto set.
** ESTRATEGIA: Dois indices delimitam o intervalo: start avanca por caracteres do conjunto; end recua sem atravessar start; substr copia o intervalo restante.
** COMO DEFENDER: Defesa: set e conjunto de caracteres, nao substring; caso tudo seja removido.
** O codigo original foi mantido; somente comentarios didaticos foram inseridos.
*/

/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbraga-m <lbraga-m@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/17 16:23:00 by lbraga-m          #+#    #+#             */
/*   Updated: 2026/11/17 17:36:17 by lbraga-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

	/* Entrada e saida do algoritmo: os tipos mostram se retorna endereco, numero ou nada. */
char	*ft_strtrim(char const *s1, char const *set)
{
	/* Variavel local: determine se armazena tamanho, posicao ou endereco. */
	size_t	start;
	/* Variavel local: determine se armazena tamanho, posicao ou endereco. */
	size_t	end;

	/* Comeca contador ou indice do zero. */
	start = 0;
	/* Laco: acompanhe o estado inicial, a condicao de parada e o avanco para provar que termina. */
	while (s1[start] != '\0' && ft_strchr(set, s1[start]))
		start++;
	/* O comprimento exclui '\0'; frequentemente precisamos reservar um byte extra. */
	end = ft_strlen(s1);
	/* Laco: acompanhe o estado inicial, a condicao de parada e o avanco para provar que termina. */
	while (end > start && ft_strchr(set, s1[end - 1]))
	/* Avanca/regride no intervalo: assegura progresso do algoritmo. */
		end--;
	/* Retorno imediato: evita continuar apos um resultado ou falha ja determinados. */
	return (ft_substr(s1, start, end - start));
}

/* #include <stdio.h>

int	main(void)
{
	char	*str;
	char	*chr;

	str = "..//ABCDEF..//";
	chr = "..//";
	printf("Resultado: %s\n", ft_strtrim(str, chr));
} */