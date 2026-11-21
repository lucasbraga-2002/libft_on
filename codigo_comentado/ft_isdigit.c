/* ************************************************************************** */

/*
** GUIA DE LEITURA - ft_isdigit
** OBJETIVO: Verificar se um codigo de caractere corresponde a um algarismo ASCII de 0 a 9.
** RACIOCINIO: A comparacao dupla restringe o intervalo; o retorno 1/0 representa verdadeiro/falso.
** DEFESA/TESTE: Teste: '0', '9', '/', ':'.
** Comentarios didaticos. Instrucoes originais preservadas.
*/

/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isdigit.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbraga-m <lbraga-m@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/03 18:15:12 by lbraga-m          #+#    #+#             */
/*   Updated: 2026/11/03 18:29:20 by lbraga-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

	/* Assinatura: leia o tipo de retorno e os parametros; o resultado deve respeitar este contrato. */
int	ft_isdigit(int c)
{
	/* Verifica uma condicao antes de executar ou interromper o fluxo; explique os limites que ela protege. */
	if (c >= '0' && c <= '9')
	/* Encerra a chamada e devolve exatamente este resultado a quem chamou. */
		return (1);
	else
	/* Encerra a chamada e devolve exatamente este resultado a quem chamou. */
		return (0);
}
