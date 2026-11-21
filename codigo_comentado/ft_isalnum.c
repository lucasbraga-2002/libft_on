/* ************************************************************************** */

/*
** GUIA DE LEITURA - ft_isalnum
** OBJETIVO: Combinar duas classificacoes ja implementadas: letra OU digito.
** RACIOCINIO: Chamar ft_isalpha e ft_isdigit evita duplicar a regra dos intervalos; o operador || aceita qualquer um.
** DEFESA/TESTE: Teste: 'A', '7', '-'.
** Comentarios didaticos. Instrucoes originais preservadas.
*/

/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalnum.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbraga-m <lbraga-m@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/03 18:34:24 by lbraga-m          #+#    #+#             */
/*   Updated: 2026/11/18 20:18:16 by lbraga-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

	/* Assinatura: leia o tipo de retorno e os parametros; o resultado deve respeitar este contrato. */
int	ft_isalnum(int c)
{
	/* Verifica uma condicao antes de executar ou interromper o fluxo; explique os limites que ela protege. */
	if (ft_isalpha(c) == 1 || ft_isdigit(c) == 1)
	/* Encerra a chamada e devolve exatamente este resultado a quem chamou. */
		return (1);
	else
	/* Encerra a chamada e devolve exatamente este resultado a quem chamou. */
		return (0);
}
