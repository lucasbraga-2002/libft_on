/* ************************************************************************** */

/*
** ESTUDO: ft_memmove
** O QUE RESOLVE: Copia n bytes permitindo que a origem e destino se sobreponham.
** CAMINHO DO ALGORITMO: Compara a direcao dos buffers: se destino esta antes de origem, copiar para frente e seguro; caso contrario percorre de tras para frente para nao sobrescrever bytes que ainda precisam ser lidos.
** PARA DEFENDER: Por que o laco decrementa n ANTES do acesso? Para copiar o ultimo indice valido primeiro. Testes: deslocar 'abcdef' a direita e a esquerda no mesmo array.
** O C original abaixo permanece intacto; comentarios sao somente para estudo.
*/

/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbraga-m <lbraga-m@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/04 20:57:40 by lbraga-m          #+#    #+#             */
/*   Updated: 2026/11/13 19:29:51 by lbraga-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	unsigned char		*pd;
	const unsigned char	*ps;

	/* Desvio de controle: se esta condicao for verdadeira, executamos o ramo correspondente, protegendo um limite ou caso especial. */
	if (dest == 0 && src == 0)
	/* Termina a funcao aqui e entrega este valor ao chamador; observe se e ponteiro, tamanho ou sinal. */
		return (NULL);
	/* Interpreta a regiao de memoria como sequencia de bytes, sem mudar seu endereco. */
	pd = (unsigned char *)dest;
	/* Le bytes sem poder altera-los por este ponteiro const. */
	ps = (const unsigned char *)src;
	/* Desvio de controle: se esta condicao for verdadeira, executamos o ramo correspondente, protegendo um limite ou caso especial. */
	if (pd < ps)
		ft_memcpy(dest, src, n);
	else
	{
	/* Este laco define quantos elementos serao examinados; identifique o indice/ponteiro que avanca dentro dele. */
		while (n > 0)
		{
	/* Reduz o indice/contador para visitar a parte anterior do intervalo. */
			n--;
	/* Escreve numa posicao calculada: confira o limite maximo permitido antes de executar. */
			pd[n] = ps[n];
		}
	}
	/* Termina a funcao aqui e entrega este valor ao chamador; observe se e ponteiro, tamanho ou sinal. */
	return (dest);
}

/* #include <stdio.h>

int	main(void)
{
	char	texto1[] = "ABCDE";
	char	texto2[] = "ABCDE";
	char	texto3[] = "ABCDE";
	char 	origem[] = "Hello";
	char 	destino[] = "XXXXX";


	ft_memmove(texto1 + 1, texto1, 4);
	printf("Teste 1: %s\n", texto1);

	ft_memmove(texto2, texto2 + 1, 4);
	printf("Teste 2: %s\n", texto2);

	ft_memmove(texto3, texto3, 4);
	printf("Teste 3: %s\n", texto3);

	ft_memmove(destino, origem, 5);
	printf("Teste 4: %s\n", destino);
	return (0);
} */