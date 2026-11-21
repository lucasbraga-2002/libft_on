/* ************************************************************************** */

/*
** ESTUDO: ft_strlcpy
** O QUE RESOLVE: Copia uma string para um buffer com capacidade dstsize sem ultrapassar seus limites.
** CAMINHO DO ALGORITMO: Se dstsize=0 nao escreve. Caso contrario copia no maximo dstsize-1 caracteres e finaliza com '\0'; retorna o tamanho INTEIRO da origem, nao o numero copiado.
** PARA DEFENDER: Por que reservar um byte? Para o terminador. Testes: dstsize 0, 1, 3; compare retorno com strlen(src).
** O C original abaixo permanece intacto; comentarios sao somente para estudo.
*/

/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbraga-m <lbraga-m@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/06 16:38:15 by lbraga-m          #+#    #+#             */
/*   Updated: 2026/11/09 20:38:46 by lbraga-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

	/* Assinatura publica: tipo de retorno e parametros definem o contrato usado por quem chama. */
size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize)
{
	/* Variavel local: identifique seu tipo e se armazena indice, comprimento ou endereco. */
	size_t	i;

	/* Desvio de controle: se esta condicao for verdadeira, executamos o ramo correspondente, protegendo um limite ou caso especial. */
	if (!dstsize)
	/* Termina a funcao aqui e entrega este valor ao chamador; observe se e ponteiro, tamanho ou sinal. */
		return (ft_strlen(src));
	/* Inicia o contador/estado com zero antes da primeira iteracao. */
	i = 0;
	/* Este laco define quantos elementos serao examinados; identifique o indice/ponteiro que avanca dentro dele. */
	while (src[i] && i < dstsize - 1)
	{
	/* Escreve numa posicao calculada: confira o limite maximo permitido antes de executar. */
		dst[i] = src[i];
	/* Avanca uma posicao; e isso que permite ao laco progredir. */
		i++;
	}
	/* Grava o terminador da string; ele ocupa um byte extra de capacidade. */
	dst[i] = '\0';
	/* Termina a funcao aqui e entrega este valor ao chamador; observe se e ponteiro, tamanho ou sinal. */
	return (ft_strlen(src));
}

/* #include <stdio.h>

int main(void)
{
    char dst1[10];
    char dst2[4];
    char dst3[1];

    printf("Teste 1: %zu | %s\n",
        ft_strlcpy(dst1, "Ola", sizeof(dst1)), dst1);
    printf("Teste 2: %zu | %s\n",
        ft_strlcpy(dst2, "Hello", sizeof(dst2)), dst2);
    printf("Teste 3: %zu | %s\n",
        ft_strlcpy(dst3, "Hello", sizeof(dst3)), dst3);
    printf("Teste 4: %zu\n",
        ft_strlcpy(NULL, "Hello", 0));
    return (0);
} */
