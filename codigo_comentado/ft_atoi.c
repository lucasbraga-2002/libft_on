/* ************************************************************************** */

/*
** GUIA DE LEITURA - ft_atoi
** OBJETIVO: Ler uma representacao decimal textual e formar um inteiro.
** RACIOCINIO: O algoritmo pula espacos ASCII, identifica sinal e acumula os digitos com resultado*10 + digito. Para apos o primeiro nao digito.
** DEFESA/TESTE: Teste: '  -42abc', '+0', '007' e sinais duplicados; overflow de int nao e validado.
** Comentarios didaticos. Instrucoes originais preservadas.
*/

/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbraga-m <lbraga-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/13 21:07:17 by lbraga-m          #+#    #+#             */
/*   Updated: 2026/11/14 15:11:01 by lbraga-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

	/* Assinatura: leia o tipo de retorno e os parametros; o resultado deve respeitar este contrato. */
int	ft_atoi(const char *nptr)
{
	/* Declara uma variavel local; observe seu tipo, especialmente se guarda endereco ou numero. */
	int		i;
	/* Declara uma variavel local; observe seu tipo, especialmente se guarda endereco ou numero. */
	int		signal;
	/* Declara uma variavel local; observe seu tipo, especialmente se guarda endereco ou numero. */
	long	result;

	/* Inicializa o estado em zero antes de começar o processamento, evitando valor indeterminado. */
	i = 0;
	/* Inicializa com valor neutro para o sinal ou marcador verdadeiro, conforme a variavel. */
	signal = 1;
	/* Inicializa o estado em zero antes de começar o processamento, evitando valor indeterminado. */
	result = 0;
	/* Repete o corpo enquanto esta condicao for verdadeira; a cada volta, algum estado deve avancar. */
	while ((nptr[i] >= 9 && nptr[i] <= 13) || (nptr[i] == ' '))
	/* Avanca o indice para a proxima posicao; sem isso o laco nao progride. */
		i++;
	/* Verifica uma condicao antes de executar ou interromper o fluxo; explique os limites que ela protege. */
	if (nptr[i] == '-' || nptr[i] == '+')
	{
	/* Verifica uma condicao antes de executar ou interromper o fluxo; explique os limites que ela protege. */
		if (nptr[i] == '-')
	/* Inverte o sinal acumulado quando encontra '-'. */
			signal = signal * -1;
	/* Avanca o indice para a proxima posicao; sem isso o laco nao progride. */
		i++;
	}
	/* Repete o corpo enquanto esta condicao for verdadeira; a cada volta, algum estado deve avancar. */
	while (nptr[i] >= '0' && nptr[i] <= '9')
	{
	/* Multiplica por dez para abrir a proxima casa decimal e soma o valor numerico do digito ASCII. */
		result = (result * 10) + (nptr[i] - '0');
	/* Avanca o indice para a proxima posicao; sem isso o laco nao progride. */
		i++;
	}
	/* Encerra a chamada e devolve exatamente este resultado a quem chamou. */
	return (result * signal);
}

/* #include <stdio.h>

int main(void)
{
	printf("%d\n", ft_atoi("42"));
	printf("%d\n", ft_atoi("-427"));
	printf("%d\n", ft_atoi("   +57"));
	printf("%d\n", ft_atoi("\t  \n42"));
	printf("%d\n", ft_atoi("123abc"));
	printf("%d\n", ft_atoi("0"));
	printf("%d\n", ft_atoi("-0"));
	printf("%d\n", ft_atoi("+"));
	printf("%d\n", ft_atoi("abc123"));
	printf("%d\n", ft_atoi(""));
	printf("%d\n", ft_atoi("-2147483648"));
	printf("%d\n", ft_atoi("2147483648"));
	printf("%d\n", ft_atoi("2147483647"));
} */