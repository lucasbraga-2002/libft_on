/* ************************************************************************** */

/*
** GUIA DE LEITURA - ft_tolower
** OBJETIVO: Converter somente letras ASCII maiusculas em minusculas.
** RACIOCINIO: A transformacao so ocorre entre A e Z, sem alterar pontuacao ou caracteres ja minusculos.
** DEFESA/TESTE: Teste: 'A', 'Z', 'a', '!'.
** Comentarios didaticos. Instrucoes originais preservadas.
*/

/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tolower.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbraga-m <lbraga-m@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/06 20:05:44 by lbraga-m          #+#    #+#             */
/*   Updated: 2026/11/06 20:18:22 by lbraga-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

	/* Assinatura: leia o tipo de retorno e os parametros; o resultado deve respeitar este contrato. */
int	ft_tolower(int c)
{
	/* Verifica uma condicao antes de executar ou interromper o fluxo; explique os limites que ela protege. */
	if ((c >= 'A') && (c <= 'Z'))
	/* Explora a distancia de 32 codigos entre minusculas e maiusculas na tabela ASCII. */
		c = c + 32;
	/* Encerra a chamada e devolve exatamente este resultado a quem chamou. */
	return (c);
}

/* #include <stdio.h>

int	main(void)
{
	char b;
	
	b = 'Z';
	printf ("char conv: %c\n", ft_tolower(b));
	return (0);
} */