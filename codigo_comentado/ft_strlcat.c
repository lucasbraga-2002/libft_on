/* ************************************************************************** */

/*
** ESTUDO: ft_strlcat
** O QUE RESOLVE: Anexa uma string a um buffer de tamanho total dstsize, respeitando a capacidade.
** CAMINHO DO ALGORITMO: Conta o comprimento efetivo do destino ate no maximo dstsize. Se o destino ja ocupa todo o limite, retorna dstsize+strlen(src) sem escrever; caso contrario copia no espaco livre, finaliza e retorna comprimento original de dst + strlen(src).
** PARA DEFENDER: Por que o retorno nao e necessariamente o comprimento final? Ele indica tamanho que se tentou construir. Testes: sem espaco, buffer vazio, truncamento.
** O C original abaixo permanece intacto; comentarios sao somente para estudo.
*/

/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbraga-m <lbraga-m@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/12 19:01:39 by lbraga-m          #+#    #+#             */
/*   Updated: 2026/11/13 20:26:05 by lbraga-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

	/* Assinatura publica: tipo de retorno e parametros definem o contrato usado por quem chama. */
size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	/* Variavel local: identifique seu tipo e se armazena indice, comprimento ou endereco. */
	size_t	i;
	/* Variavel local: identifique seu tipo e se armazena indice, comprimento ou endereco. */
	size_t	j;

	/* Inicia o contador/estado com zero antes da primeira iteracao. */
	i = 0;
	/* Inicia o contador/estado com zero antes da primeira iteracao. */
	j = 0;
	/* Este laco define quantos elementos serao examinados; identifique o indice/ponteiro que avanca dentro dele. */
	while (i < dstsize && dst[i] != '\0')
	/* Avanca uma posicao; e isso que permite ao laco progredir. */
		i++;
	/* Desvio de controle: se esta condicao for verdadeira, executamos o ramo correspondente, protegendo um limite ou caso especial. */
	if (i == dstsize)
	/* Termina a funcao aqui e entrega este valor ao chamador; observe se e ponteiro, tamanho ou sinal. */
		return (dstsize + ft_strlen(src));
	/* Este laco define quantos elementos serao examinados; identifique o indice/ponteiro que avanca dentro dele. */
	while (src[j] != '\0' && j < dstsize - i - 1)
	{
	/* Escreve numa posicao calculada: confira o limite maximo permitido antes de executar. */
		dst[i + j] = src[j];
	/* Avanca uma posicao; e isso que permite ao laco progredir. */
		j++;
	}
	/* Grava o terminador da string; ele ocupa um byte extra de capacidade. */
	dst[i + j] = '\0';
	/* Termina a funcao aqui e entrega este valor ao chamador; observe se e ponteiro, tamanho ou sinal. */
	return (i + ft_strlen(src));
}

/* #include <stdio.h>

int main(void)
{
	char dst[10] = "42";
	char src[] = "Porto";
	size_t dstsize = 6;

	printf("soma: %zu\n", ft_strlcat(dst, src, dstsize));
	printf("dst result: %s\n", dst);
	
	char dst1[10] = "42";
	char src1[] = "Porto";
	size_t dstsize1 = 10;
	
	printf("soma: %zu\n", ft_strlcat(dst1, src1, dstsize1));
	printf("dst result: %s\n", dst1);

	char dst2[10] = "42Porto";
	char src2[] = "ABC";
	size_t dstsize2 = 4;
	
	printf("soma: %zu\n", ft_strlcat(dst2, src2, dstsize2));
	printf("dst result: %s\n", dst2);
} */