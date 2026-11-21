/* ************************************************************************** */

/*
** GUIA DE LEITURA - ft_isascii
** OBJETIVO: Verificar se o inteiro cabe na tabela ASCII original, de 0 a 127.
** RACIOCINIO: Nao confundir ASCII com caractere imprimivel: codigos de controle tambem sao ASCII.
** DEFESA/TESTE: Teste: -1, 0, 127 e 128.
** Comentarios didaticos. Instrucoes originais preservadas.
*/

/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isascii.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbraga-m <lbraga-m@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/03 19:12:07 by lbraga-m          #+#    #+#             */
/*   Updated: 2026/11/18 20:18:52 by lbraga-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

	/* Assinatura: leia o tipo de retorno e os parametros; o resultado deve respeitar este contrato. */
int	ft_isascii(int c)
{
	/* Verifica uma condicao antes de executar ou interromper o fluxo; explique os limites que ela protege. */
	if (c >= 0 && c <= 127)
	/* Encerra a chamada e devolve exatamente este resultado a quem chamou. */
		return (1);
	else
	/* Encerra a chamada e devolve exatamente este resultado a quem chamou. */
		return (0);
}

/*
#include <stdio.h>

int	main(void)
{
	/* Declara uma variavel local; observe seu tipo, especialmente se guarda endereco ou numero. */
	int	result;

	result = ft_isascii (128);
	printf ("result: %d\n", result);
	/* Encerra a chamada e devolve exatamente este resultado a quem chamou. */
	return (0);
}
*/