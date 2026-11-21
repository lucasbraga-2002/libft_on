/* ************************************************************************** */

/*
** ESTUDO: ft_strchr
** O QUE RESOLVE: Busca a primeira ocorrencia de um caractere numa string C. Retorna um ponteiro para o ponto encontrado, nao uma copia.
** CAMINHO DO ALGORITMO: Percorre ate '\0', comparando cada byte com o caractere alvo convertido para char. Depois do laco compara tambem o terminador: assim buscar '\0' devolve o endereco do fim da string.
** PARA DEFENDER: Por que comparar depois do while? Porque o while para ANTES de examinar '\0'. Testes: 'banana'/'a', ausente, '\0'.
** O C original abaixo permanece intacto; comentarios sao somente para estudo.
*/

/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbraga-m <lbraga-m@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/06 20:20:45 by lbraga-m          #+#    #+#             */
/*   Updated: 2026/11/13 19:30:35 by lbraga-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	/* Variavel local: identifique seu tipo e se armazena indice, comprimento ou endereco. */
	int	i;

	/* Inicia o contador/estado com zero antes da primeira iteracao. */
	i = 0;
	/* Este laco define quantos elementos serao examinados; identifique o indice/ponteiro que avanca dentro dele. */
	while (s[i] != '\0')
	{
	/* Desvio de controle: se esta condicao for verdadeira, executamos o ramo correspondente, protegendo um limite ou caso especial. */
		if (s[i] == (char)c)
	/* Termina a funcao aqui e entrega este valor ao chamador; observe se e ponteiro, tamanho ou sinal. */
			return ((char *)&s[i]);
		else
	/* Avanca uma posicao; e isso que permite ao laco progredir. */
			i++;
	}
	/* Desvio de controle: se esta condicao for verdadeira, executamos o ramo correspondente, protegendo um limite ou caso especial. */
	if (s[i] == (char)c)
	/* Termina a funcao aqui e entrega este valor ao chamador; observe se e ponteiro, tamanho ou sinal. */
		return ((char *)&s[i]);
	/* Termina a funcao aqui e entrega este valor ao chamador; observe se e ponteiro, tamanho ou sinal. */
	return (NULL);
}

/* #include <stdio.h>

int	main(void)
{
	printf("Teste 1: %s\n", ft_strchr("banana", 'a'));
	printf("Teste 2: %p\n", (void *)ft_strchr("banana", 'x'));
	printf("Teste 3: %s\n", ft_strchr("banana", '\0'));
	return (0);
} */
