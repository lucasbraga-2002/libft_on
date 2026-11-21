/* ************************************************************************** */

/*
** GUIA DE LEITURA - ft_isprint
** OBJETIVO: Detectar os codigos ASCII com representacao imprimivel, de 32 (espaco) a 126 (~).
** RACIOCINIO: A diferenca para isascii e que tab, quebra de linha e DEL nao sao imprimiveis.
** DEFESA/TESTE: Teste: 31, 32, 126, 127.
** Comentarios didaticos. Instrucoes originais preservadas.
*/

/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isprint.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbraga-m <lbraga-m@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/03 19:53:39 by lbraga-m          #+#    #+#             */
/*   Updated: 2026/11/03 21:19:44 by lbraga-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

	/* Assinatura: leia o tipo de retorno e os parametros; o resultado deve respeitar este contrato. */
int	ft_isprint(int c)
{
	/* Verifica uma condicao antes de executar ou interromper o fluxo; explique os limites que ela protege. */
	if (c >= 32 && c <= 126)
	/* Encerra a chamada e devolve exatamente este resultado a quem chamou. */
		return (1);
	else
	/* Encerra a chamada e devolve exatamente este resultado a quem chamou. */
		return (0);
}

/*#include <stdio.h>

int	main(void)
{
	int	testes[4];
	int	i;

	testes[0] = 31;
	testes[1] = 32;
	testes[2] = 126;
	testes[3] = 127;
	i = 0;
	while (i < 4)
	{
		printf("ASCII %d: %d\n", testes[i], ft_isprint(testes[i]));
		i++;
	}
	return (0);
}
*/