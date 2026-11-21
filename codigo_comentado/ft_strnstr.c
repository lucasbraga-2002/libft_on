/* ************************************************************************** */

/*
** ESTUDO: ft_strnstr
** O QUE RESOLVE: Procura uma substring, mas nunca examina alem do limite len na string maior.
** CAMINHO DO ALGORITMO: Laco externo testa posicoes candidatas; laco interno tenta casar os caracteres da substring. j < len - i impede que a tentativa ultrapasse o limite restante. O padrao vazio e encontrado imediatamente.
** PARA DEFENDER: Por que len - i? E o espaco que falta a partir do indice atual. Testes: padrao vazio, len=0, padrao atravessando len.
** O C original abaixo permanece intacto; comentarios sao somente para estudo.
*/

/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbraga-m <lbraga-m@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/10 17:53:08 by lbraga-m          #+#    #+#             */
/*   Updated: 2026/11/12 18:57:04 by lbraga-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	/* Variavel local: identifique seu tipo e se armazena indice, comprimento ou endereco. */
	size_t	i;
	/* Variavel local: identifique seu tipo e se armazena indice, comprimento ou endereco. */
	size_t	j;

	/* Inicia o contador/estado com zero antes da primeira iteracao. */
	i = 0;
	/* Desvio de controle: se esta condicao for verdadeira, executamos o ramo correspondente, protegendo um limite ou caso especial. */
	if (*little == '\0')
	/* Termina a funcao aqui e entrega este valor ao chamador; observe se e ponteiro, tamanho ou sinal. */
		return ((char *)&big[i]);
	/* Este laco define quantos elementos serao examinados; identifique o indice/ponteiro que avanca dentro dele. */
	while (i < len && big[i] != '\0')
	{
	/* Inicia o contador/estado com zero antes da primeira iteracao. */
		j = 0;
	/* Este laco define quantos elementos serao examinados; identifique o indice/ponteiro que avanca dentro dele. */
		while (j < len - i && little[j] && big[i + j] == little[j])
	/* Avanca uma posicao; e isso que permite ao laco progredir. */
			j++;
	/* Desvio de controle: se esta condicao for verdadeira, executamos o ramo correspondente, protegendo um limite ou caso especial. */
		if (little[j] == '\0')
	/* Termina a funcao aqui e entrega este valor ao chamador; observe se e ponteiro, tamanho ou sinal. */
			return ((char *)&big[i]);
	/* Avanca uma posicao; e isso que permite ao laco progredir. */
		i++;
	}
	/* Termina a funcao aqui e entrega este valor ao chamador; observe se e ponteiro, tamanho ou sinal. */
	return (NULL);
}

/* #include <stdio.h>

int	main(void)
{
	//big
	char bg[] = "XYZabcIJK";
	char bg1[] = "abcXYZabc";
	char bg2[] = "aabc";
	//little
	char lit[] = "abc";
	char lit1[] = "";
	//bytes
	size_t len =  6; 
	size_t len1 = 0;
	size_t len2 = 9;
	size_t len3 = 4;
	
	printf("found: %s\n", ft_strnstr(bg, lit, len));
	printf("found: %s\n", ft_strnstr(bg, lit1, len));
	printf("found: %s\n", ft_strnstr(bg1, lit, len2));
	printf("found: %s\n", ft_strnstr(bg, lit, len1));
	printf("found: %s\n", ft_strnstr(bg2, lit, len3));
} */