/* ************************************************************************** */

/*
** FICHA DIDATICA: ft_strjoin
** OBJETIVO: Concatenar duas strings em uma terceira alocada dinamicamente.
** ESTRATEGIA: Calcula tamanho total, reserva bytes mais terminador, copia a primeira e concatena a segunda no mesmo buffer.
** COMO DEFENDER: Defesa: nova string nao compartilha armazenamento com as originais.
** O codigo original foi mantido; somente comentarios didaticos foram inseridos.
*/

/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbraga-m <lbraga-m@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/17 15:52:24 by lbraga-m          #+#    #+#             */
/*   Updated: 2026/11/17 16:20:55 by lbraga-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

	/* Entrada e saida do algoritmo: os tipos mostram se retorna endereco, numero ou nada. */
char	*ft_strjoin(char const *s1, char const *s2)
{
	/* Variavel local: determine se armazena tamanho, posicao ou endereco. */
	char	*join;
	/* Variavel local: determine se armazena tamanho, posicao ou endereco. */
	size_t	len;

	/* O comprimento exclui '\0'; frequentemente precisamos reservar um byte extra. */
	len = (ft_strlen(s1) + ft_strlen(s2));
	/* Reserva armazenamento na heap; e preciso liberar no futuro ou no tratamento de falha. */
	join = malloc(len + 1);
	/* Decisao: separa casos-limite do caminho normal; teste mentalmente os dois resultados possiveis. */
	if (join == NULL)
	/* Retorno imediato: evita continuar apos um resultado ou falha ja determinados. */
		return (NULL);
	/* Copia dentro da capacidade informada; inclui terminador quando cabe. */
	ft_strlcpy(join, s1, len + 1);
	/* Anexa usando a capacidade TOTAL de destino, nao apenas a sobra. */
	ft_strlcat(join, s2, len + 1);
	/* Retorno imediato: evita continuar apos um resultado ou falha ja determinados. */
	return (join);
}

/* #include <stdio.h>

int	main(void)
{
	char	*result;

	result = ft_strjoin("Hello", "World");
	if (result == NULL)
		return (1);
	printf("Resultado: [%s]\n", result);
	free(result);
	return (0);
} */