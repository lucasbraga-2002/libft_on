/* ************************************************************************** */

/*
** ESTUDO: ft_memcpy
** O QUE RESOLVE: Copia exatamente n bytes de src para dest, desde que as regioes nao se sobreponham.
** CAMINHO DO ALGORITMO: Converte ambos os ponteiros para ponteiros de byte, copia com o mesmo indice e retorna dest. Os atalhos iniciais cobrem n=0 e ambos ponteiros nulos, mas nao validam ponteiro nulo isolado.
** PARA DEFENDER: Quando usar memmove? Quando existe sobreposicao. Testes: bytes com zeros internos, n=0, buffers separados.
** O C original abaixo permanece intacto; comentarios sao somente para estudo.
*/

/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbraga-m <lbraga-m@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/04 19:30:01 by lbraga-m          #+#    #+#             */
/*   Updated: 2026/11/13 19:29:44 by lbraga-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	unsigned char		*d;
	const unsigned char	*s;
	/* Variavel local: identifique seu tipo e se armazena indice, comprimento ou endereco. */
	size_t				i;

	/* Desvio de controle: se esta condicao for verdadeira, executamos o ramo correspondente, protegendo um limite ou caso especial. */
	if (!n)
	/* Termina a funcao aqui e entrega este valor ao chamador; observe se e ponteiro, tamanho ou sinal. */
		return (dest);
	/* Desvio de controle: se esta condicao for verdadeira, executamos o ramo correspondente, protegendo um limite ou caso especial. */
	if (!dest && !src)
	/* Termina a funcao aqui e entrega este valor ao chamador; observe se e ponteiro, tamanho ou sinal. */
		return (NULL);
	/* Interpreta a regiao de memoria como sequencia de bytes, sem mudar seu endereco. */
	d = (unsigned char *)dest;
	/* Le bytes sem poder altera-los por este ponteiro const. */
	s = (const unsigned char *)src;
	/* Inicia o contador/estado com zero antes da primeira iteracao. */
	i = 0;
	/* Este laco define quantos elementos serao examinados; identifique o indice/ponteiro que avanca dentro dele. */
	while (i < n)
	{
	/* Escreve numa posicao calculada: confira o limite maximo permitido antes de executar. */
		d[i] = s[i];
	/* Avanca uma posicao; e isso que permite ao laco progredir. */
		i++;
	}
	/* Termina a funcao aqui e entrega este valor ao chamador; observe se e ponteiro, tamanho ou sinal. */
	return (dest);
}

/*#include <stdio.h>

int	main(void)
{
	char	origem[] = "Hello";
	char	destino[] = "XXXXX";

	ft_memcpy(destino, origem, 3);
	printf("Teste 1: %s\n", destino);

	ft_memcpy(destino, origem, 5);
	printf("Teste 2: %s\n", destino);

	ft_memcpy(destino, origem, 0);
	printf("Teste 3: %s\n", destino);

	return (0);
}
*/