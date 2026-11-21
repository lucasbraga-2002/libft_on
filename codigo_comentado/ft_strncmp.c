/* ************************************************************************** */

/*
** ESTUDO: ft_strncmp
** O QUE RESOLVE: Compara ate n bytes de duas strings e retorna zero, negativo ou positivo conforme a ordem lexicografica.
** CAMINHO DO ALGORITMO: Compara pares de caracteres, devolve imediatamente a diferenca no primeiro par diferente; se chega ao terminador sem diferenca encerra. Converte a unsigned char antes da subtracao para tratar bytes acima de 127 corretamente.
** PARA DEFENDER: Por que n=0 retorna 0? Nenhum byte foi comparado. Testes: prefixos, n=0, caractere de valor 255.
** O C original abaixo permanece intacto; comentarios sao somente para estudo.
*/

/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbraga-m <lbraga-m@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/07 19:42:57 by lbraga-m          #+#    #+#             */
/*   Updated: 2026/11/07 21:37:44 by lbraga-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

	/* Assinatura publica: tipo de retorno e parametros definem o contrato usado por quem chama. */
int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	/* Variavel local: identifique seu tipo e se armazena indice, comprimento ou endereco. */
	size_t	i;

	/* Inicia o contador/estado com zero antes da primeira iteracao. */
	i = 0;
	/* Este laco define quantos elementos serao examinados; identifique o indice/ponteiro que avanca dentro dele. */
	while (i < n)
	{
	/* Desvio de controle: se esta condicao for verdadeira, executamos o ramo correspondente, protegendo um limite ou caso especial. */
		if (s1[i] != s2[i])
	/* Termina a funcao aqui e entrega este valor ao chamador; observe se e ponteiro, tamanho ou sinal. */
			return ((unsigned char)s1[i] - (unsigned char)s2[i]);
	/* Desvio de controle: se esta condicao for verdadeira, executamos o ramo correspondente, protegendo um limite ou caso especial. */
		if (!s1[i])
	/* Termina a funcao aqui e entrega este valor ao chamador; observe se e ponteiro, tamanho ou sinal. */
			return (0);
	/* Avanca uma posicao; e isso que permite ao laco progredir. */
		i++;
	}
	/* Termina a funcao aqui e entrega este valor ao chamador; observe se e ponteiro, tamanho ou sinal. */
	return (0);
}

/* #include <stdio.h>

int main(void)
{
	printf("Resultado: %d\n", ft_strncmp("abc", "abc", 10));
	printf("Resultado: %d\n", ft_strncmp("abc", "abcd", 5));
	printf("Resultado: %d\n", ft_strncmp("abcd", "abc", 5));
	printf("Teste n=0: %d\n", ft_strncmp("abc", "xyz", 0));
	printf("Teste unsigned: %d\n", ft_strncmp("\xff", "\x01", 1));
	
} */