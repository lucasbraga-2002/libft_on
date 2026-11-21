/* ************************************************************************** */

/*
** FICHA DIDATICA: ft_itoa
** OBJETIVO: Converter int em string decimal com sinal.
** ESTRATEGIA: count_char conta espaco para digitos e sinal; copia n para long para negar INT_MIN com seguranca; grava digitos de tras para frente usando %10 e /10.
** COMO DEFENDER: Defesa: por que contar antes, por que escrever do fim, por que long e caso zero.
** O codigo original foi mantido; somente comentarios didaticos foram inseridos.
*/

/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbraga-m <lbraga-m@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/18 17:55:50 by lbraga-m          #+#    #+#             */
/*   Updated: 2026/11/18 19:12:46 by lbraga-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

	/* Funcao auxiliar static: seu nome so existe neste arquivo, reduzindo a interface publica. */
static size_t	count_char(int n)
{
	/* Variavel local: determine se armazena tamanho, posicao ou endereco. */
	size_t	len;

	/* Comeca contador ou indice do zero. */
	len = 0;
	/* Decisao: separa casos-limite do caminho normal; teste mentalmente os dois resultados possiveis. */
	if (n <= 0)
		len = 1;
	/* Laco: acompanhe o estado inicial, a condicao de parada e o avanco para provar que termina. */
	while (n != 0)
	{
		n = n / 10;
		len++;
	}
	/* Retorno imediato: evita continuar apos um resultado ou falha ja determinados. */
	return (len);
}

	/* Entrada e saida do algoritmo: os tipos mostram se retorna endereco, numero ou nada. */
char	*ft_itoa(int n)
{
	/* Variavel local: determine se armazena tamanho, posicao ou endereco. */
	char	*str;
	/* Variavel local: determine se armazena tamanho, posicao ou endereco. */
	long	nbr;
	/* Variavel local: determine se armazena tamanho, posicao ou endereco. */
	size_t	len;

	nbr = n;
	len = count_char(nbr);
	/* Reserva armazenamento na heap; e preciso liberar no futuro ou no tratamento de falha. */
	str = malloc(len + 1);
	/* Decisao: separa casos-limite do caminho normal; teste mentalmente os dois resultados possiveis. */
	if (str == NULL)
	/* Retorno imediato: evita continuar apos um resultado ou falha ja determinados. */
		return (NULL);
	/* Posicao calculada pelo comprimento: importante observar o byte reservado a NUL. */
	str[len] = '\0';
	/* Decisao: separa casos-limite do caminho normal; teste mentalmente os dois resultados possiveis. */
	if (nbr == 0)
		str[0] = '0';
	/* Decisao: separa casos-limite do caminho normal; teste mentalmente os dois resultados possiveis. */
	if (nbr < 0)
	{
		str[0] = '-';
	/* Trata o sinal numerico; o uso de long permite representar o modulo de INT_MIN. */
		nbr = -nbr;
	}
	/* Laco: acompanhe o estado inicial, a condicao de parada e o avanco para provar que termina. */
	while (nbr > 0)
	{
	/* Avanca/regride no intervalo: assegura progresso do algoritmo. */
		len--;
	/* Posicao calculada pelo comprimento: importante observar o byte reservado a NUL. */
		str[len] = nbr % 10 + '0';
		nbr = nbr / 10;
	}
	/* Retorno imediato: evita continuar apos um resultado ou falha ja determinados. */
	return (str);
}
