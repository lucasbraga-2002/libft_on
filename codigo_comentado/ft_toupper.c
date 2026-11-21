/* ************************************************************************** */

/*
** GUIA DE LEITURA - ft_toupper
** OBJETIVO: Converter somente letras ASCII minusculas em maiusculas.
** RACIOCINIO: Somar ou subtrair 32 funciona nesses intervalos ASCII; fora deles retorna o proprio valor.
** DEFESA/TESTE: Teste: 'a', 'z', 'A', '4'.
** Comentarios didaticos. Instrucoes originais preservadas.
*/

/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_toupper.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbraga-m <lbraga-m@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/06 16:59:41 by lbraga-m          #+#    #+#             */
/*   Updated: 2026/11/06 20:01:00 by lbraga-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

	/* Assinatura: leia o tipo de retorno e os parametros; o resultado deve respeitar este contrato. */
int	ft_toupper(int c)
{
	/* Verifica uma condicao antes de executar ou interromper o fluxo; explique os limites que ela protege. */
	if ((c >= 'a') && (c <= 'z'))
	/* Explora a distancia de 32 codigos entre minusculas e maiusculas na tabela ASCII. */
		c = c - 32;
	/* Encerra a chamada e devolve exatamente este resultado a quem chamou. */
	return (c);
}

/* #include <stdio.h>

int main(void)
{
	char b;
	
	b = 'd';
	printf ("char conv: %c\n", ft_toupper(b));
	return (0);
} */
