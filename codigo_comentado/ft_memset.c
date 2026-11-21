/* ************************************************************************** */

/*
** ESTUDO: ft_memset
** O QUE RESOLVE: Escreve um mesmo byte em n posicoes de memoria, sem depender de terminador de string.
** CAMINHO DO ALGORITMO: Converte void* para unsigned char* para operar byte a byte; usa n como limite exato, nao para em zero; retorna o ponteiro original.
** PARA DEFENDER: Por que unsigned char? Para tratar bytes puros. Testes: preencher com 0, 255, n=0.
** O C original abaixo permanece intacto; comentarios sao somente para estudo.
*/

/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbraga-m <lbraga-m@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/04 16:57:02 by lbraga-m          #+#    #+#             */
/*   Updated: 2026/11/06 18:28:51 by lbraga-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *s, int c, size_t n)
{
	unsigned char	*ptr;
	/* Variavel local: identifique seu tipo e se armazena indice, comprimento ou endereco. */
	size_t			i;

	/* Interpreta a regiao de memoria como sequencia de bytes, sem mudar seu endereco. */
	ptr = (unsigned char *)s;
	/* Inicia o contador/estado com zero antes da primeira iteracao. */
	i = 0;
	/* Este laco define quantos elementos serao examinados; identifique o indice/ponteiro que avanca dentro dele. */
	while (i < n)
	{
	/* Escreve numa posicao calculada: confira o limite maximo permitido antes de executar. */
		ptr[i] = c;
	/* Avanca uma posicao; e isso que permite ao laco progredir. */
		i++;
	}
	/* Termina a funcao aqui e entrega este valor ao chamador; observe se e ponteiro, tamanho ou sinal. */
	return (s);
}

/*#include <stdio.h>

int	main(void)
{
	char	texto[6] = "Hello";
	char	letras[4] = "ABC";
	char	zeros[4] = "ABC";
	char	sem_alteracao[4] = "ABC";
	void	*retorno;

	ft_memset(texto, 'X', 2);
	printf("Teste 1: %s | Esperado: XXllo\n", texto);

	ft_memset(letras, 'Z', 3);
	printf("Teste 2: %s | Esperado: ZZZ\n", letras);

	ft_memset(sem_alteracao, 'X', 0);
	printf("Teste 3: %s | Esperado: ABC\n", sem_alteracao);

	ft_memset(zeros, 0, 2);
	printf("Teste 4: %d %d %d | Esperado: 0 0 67\n",
		zeros[0], zeros[1], zeros[2]);

	retorno = ft_memset(texto, 'A', 1);
	printf("Teste 5: %d | Esperado: 1\n", retorno == texto);

	return (0);
}
*/