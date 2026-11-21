/* ************************************************************************** */

/*
** ESTUDO: ft_strrchr
** O QUE RESOLVE: Busca a ultima ocorrencia de um caractere na string, incluindo possivelmente o terminador.
** CAMINHO DO ALGORITMO: Primeiro encontra o fim da string, depois caminha de tras para frente: a primeira igualdade nessa caminhada e a ultima ocorrencia na ordem normal.
** PARA DEFENDER: Por que usar i >= 0? Para examinar ate a posicao zero. Testes: 'banana'/'a', 'b', ausente, '\0'.
** O C original abaixo permanece intacto; comentarios sao somente para estudo.
*/

/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbraga-m <lbraga-m@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/06 21:17:18 by lbraga-m          #+#    #+#             */
/*   Updated: 2026/11/16 18:00:12 by lbraga-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	/* Variavel local: identifique seu tipo e se armazena indice, comprimento ou endereco. */
	int	i;

	/* Inicia o contador/estado com zero antes da primeira iteracao. */
	i = 0;
	/* Este laco define quantos elementos serao examinados; identifique o indice/ponteiro que avanca dentro dele. */
	while (s[i] != '\0')
	/* Avanca uma posicao; e isso que permite ao laco progredir. */
		i++;
	/* Este laco define quantos elementos serao examinados; identifique o indice/ponteiro que avanca dentro dele. */
	while (i >= 0)
	{
	/* Desvio de controle: se esta condicao for verdadeira, executamos o ramo correspondente, protegendo um limite ou caso especial. */
		if (s[i] == (char)c)
	/* Termina a funcao aqui e entrega este valor ao chamador; observe se e ponteiro, tamanho ou sinal. */
			return ((char *) &s[i]);
	/* Reduz o indice/contador para visitar a parte anterior do intervalo. */
		i--;
	}
	/* Termina a funcao aqui e entrega este valor ao chamador; observe se e ponteiro, tamanho ou sinal. */
	return (NULL);
}

/* #include <stdio.h>

int	main(void)
{
	char	texto[] = "banana";


	printf("Teste 1: %s\n", ft_strrchr("banana", 'n'));
	printf("Teste 2: %s\n", ft_strrchr("banana", 'b'));
	printf("Teste 3: %p\n", (void *)ft_strrchr("banana", 'x'));
	printf("Teste 4: %s\n", ft_strrchr("banana", '\0'));
	printf("Teste 5: %d\n", ft_strrchr(texto, '\0') == &texto[6]);
	return (0);
} */
