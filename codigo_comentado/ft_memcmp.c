/* ************************************************************************** */

/*
** FICHA DIDATICA: ft_memcmp
** OBJETIVO: Comparar dois blocos de memoria byte por byte ate n, sem terminador de string.
** ESTRATEGIA: Percorre os bytes como unsigned char, interrompe na primeira diferenca e devolve a subtracao, ou zero se os n bytes forem iguais.
** COMO DEFENDER: Defesa: n=0 nao examina bytes; por que unsigned char?
** O codigo original foi mantido; somente comentarios didaticos foram inseridos.
*/

/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbraga-m <lbraga-m@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/09 21:10:20 by lbraga-m          #+#    #+#             */
/*   Updated: 2026/11/10 17:42:33 by lbraga-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

	/* Entrada e saida do algoritmo: os tipos mostram se retorna endereco, numero ou nada. */
int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	/* Variavel local: determine se armazena tamanho, posicao ou endereco. */
	const unsigned char	*p1;
	/* Variavel local: determine se armazena tamanho, posicao ou endereco. */
	const unsigned char	*p2;
	/* Variavel local: determine se armazena tamanho, posicao ou endereco. */
	size_t				i;

	p1 = (const unsigned char *)s1;
	p2 = (const unsigned char *)s2;
	/* Comeca contador ou indice do zero. */
	i = 0;
	/* Laco: acompanhe o estado inicial, a condicao de parada e o avanco para provar que termina. */
	while (i < n)
	{
	/* Decisao: separa casos-limite do caminho normal; teste mentalmente os dois resultados possiveis. */
		if (p1[i] != p2[i])
	/* Retorno imediato: evita continuar apos um resultado ou falha ja determinados. */
			return (p1[i] - p2[i]);
	/* Avanca/regride no intervalo: assegura progresso do algoritmo. */
		i++;
	}
	/* Retorno imediato: evita continuar apos um resultado ou falha ja determinados. */
	return (0);
}

/* #include <stdio.h>

int main(void)
{
	unsigned char a[] = {10, 20, 30};
	unsigned char b[] = {10, 20, 40};
	unsigned char c[] = {200, 10, 30};
	unsigned char d[] = {100, 10, 30};
	char		  e[] = {'A', '\0', 'B'};
	char		  f[] = {'A', '\0', 'C'};

	printf("Teste 1: %d\n", ft_memcmp(a, b, 3));
	printf("Teste 2: %d\n", ft_memcmp(a, b, 2));
	printf("Teste 3: %d\n", ft_memcmp(c, d, 3));
	printf("Teste 4: %d\n", ft_memcmp(e, f, 3));
	printf("Teste 5: %d\n", ft_memcmp(a, b, 0));
	return (0);
}
 */