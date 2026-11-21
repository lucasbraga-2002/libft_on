/* ************************************************************************** */

/*
** ESTUDO: ft_memchr
** O QUE RESOLVE: Localiza o primeiro byte igual a c entre os primeiros n bytes de um bloco.
** CAMINHO DO ALGORITMO: Percorre bytes (nao caracteres de string), compara como unsigned char e devolve o endereco do byte encontrado. O limite e n mesmo quando os dados contem '\0'.
** PARA DEFENDER: Por que nao parar em '\0'? Memoria pode conter zero como dado. Testes: zero interno, n=0, byte 255.
** O C original abaixo permanece intacto; comentarios sao somente para estudo.
*/

/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbraga-m <lbraga-m@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/07 21:43:32 by lbraga-m          #+#    #+#             */
/*   Updated: 2026/11/09 17:13:50 by lbraga-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	const unsigned char	*ps;
	/* Variavel local: identifique seu tipo e se armazena indice, comprimento ou endereco. */
	size_t				i;

	/* Le bytes sem poder altera-los por este ponteiro const. */
	ps = (const unsigned char *)s;
	/* Inicia o contador/estado com zero antes da primeira iteracao. */
	i = 0;
	/* Desvio de controle: se esta condicao for verdadeira, executamos o ramo correspondente, protegendo um limite ou caso especial. */
	if (!n)
	/* Termina a funcao aqui e entrega este valor ao chamador; observe se e ponteiro, tamanho ou sinal. */
		return (NULL);
	/* Este laco define quantos elementos serao examinados; identifique o indice/ponteiro que avanca dentro dele. */
	while (i != n)
	{
	/* Desvio de controle: se esta condicao for verdadeira, executamos o ramo correspondente, protegendo um limite ou caso especial. */
		if (ps[i] == (unsigned char)c)
	/* Termina a funcao aqui e entrega este valor ao chamador; observe se e ponteiro, tamanho ou sinal. */
			return ((void *)&ps[i]);
	/* Avanca uma posicao; e isso que permite ao laco progredir. */
		i++;
	}
	/* Termina a funcao aqui e entrega este valor ao chamador; observe se e ponteiro, tamanho ou sinal. */
	return (NULL);
}

/* #include <stdio.h>

int main(void)
{
	char	dados[] = {'A', '\0', 'B', 'C'};

	printf("Teste 1: %p\n", ft_memchr(dados, 'B', 4));
	printf("Teste 2: %p\n", ft_memchr(dados, 'B', 2));
	printf("Teste 3: %p\n", ft_memchr(dados, '\0', 4));
	printf("Teste 4: %p\n", ft_memchr(dados, 'A', 0));
	printf("Teste 5: %d\n", ft_memchr(dados, 'B', 4) == (void *)&dados[2]);
	return (0);
}
 */