/* ************************************************************************** */

/*
** FICHA DIDATICA: ft_substr
** OBJETIVO: Criar string nova contendo ate len caracteres a partir da posicao start.
** ESTRATEGIA: Se start esta alem do fim, devolve nova string vazia. Ajusta len ao que resta, reserva len+1 e copia com terminador.
** COMO DEFENDER: Defesa: por que s+start e valido apos checar start? Por que len+1?
** O codigo original foi mantido; somente comentarios didaticos foram inseridos.
*/

/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbraga-m <lbraga-m@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/16 19:10:34 by lbraga-m          #+#    #+#             */
/*   Updated: 2026/11/16 21:39:24 by lbraga-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

	/* Entrada e saida do algoritmo: os tipos mostram se retorna endereco, numero ou nada. */
char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	/* Variavel local: determine se armazena tamanho, posicao ou endereco. */
	size_t	s_len;
	/* Variavel local: determine se armazena tamanho, posicao ou endereco. */
	char	*sub;

	/* O comprimento exclui '\0'; frequentemente precisamos reservar um byte extra. */
	s_len = ft_strlen(s);
	/* Decisao: separa casos-limite do caminho normal; teste mentalmente os dois resultados possiveis. */
	if (start >= s_len)
	/* Retorno imediato: evita continuar apos um resultado ou falha ja determinados. */
		return (ft_strdup(""));
	/* Decisao: separa casos-limite do caminho normal; teste mentalmente os dois resultados possiveis. */
	if (len > s_len - start)
		len = s_len - start;
	/* Reserva armazenamento na heap; e preciso liberar no futuro ou no tratamento de falha. */
	sub = malloc(len + 1);
	/* Decisao: separa casos-limite do caminho normal; teste mentalmente os dois resultados possiveis. */
	if (sub == NULL)
	/* Retorno imediato: evita continuar apos um resultado ou falha ja determinados. */
		return (NULL);
	/* Copia dentro da capacidade informada; inclui terminador quando cabe. */
	ft_strlcpy(sub, s + start, len + 1);
	/* Retorno imediato: evita continuar apos um resultado ou falha ja determinados. */
	return (sub);
}

/* #include <stdio.h>

int	main(void)
{
	char	*rst;
	char	*rst1;
	char	*rst2;

	rst = ft_substr("PROGRAMACAO", 3, 5);
	rst1 = ft_substr("ABC", 10, 3);
	rst2 = ft_substr("ABCDEFG", 2, 0);
	if (rst == NULL || rst1 == NULL || rst2 == NULL)
		return (1);
	printf("Resultado: %s\n", rst);
	printf("Resultado: [%s]\n", rst1);
	printf("Resultado: [%s]\n", rst2);
	free(rst);
	free(rst1);
	free(rst2);
	return (0);
} */