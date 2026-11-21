/* ************************************************************************** */

/*
** GUIA DE LEITURA - ft_isalpha
** OBJETIVO: Reconhecer letras ASCII sem usar libc. Compara o numero do caractere a dois intervalos continuos: A-Z e a-z.
** RACIOCINIO: A condição usa || porque basta pertencer a um dos dois intervalos; caracteres fora deles devolvem 0.
** DEFESA/TESTE: Teste: 'A', 'z', '0', 0 e 128.
** Comentarios didaticos. Instrucoes originais preservadas.
*/

/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalpha.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbraga-m <lbraga-m@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/03 17:58:47 by lbraga-m          #+#    #+#             */
/*   Updated: 2026/11/18 20:18:59 by lbraga-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

	/* Assinatura: leia o tipo de retorno e os parametros; o resultado deve respeitar este contrato. */
int	ft_isalpha(int c)
{
	/* Verifica uma condicao antes de executar ou interromper o fluxo; explique os limites que ela protege. */
	if ((c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z'))
	/* Encerra a chamada e devolve exatamente este resultado a quem chamou. */
		return (1);
	else
	/* Encerra a chamada e devolve exatamente este resultado a quem chamou. */
		return (0);
}
