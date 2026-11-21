/* ************************************************************************** */

/*
** GUIA DE ESTUDO - ft_lstsize
** OBJETIVO: Contar quantos nos existem ate o ponteiro NULL final.
** ALGORITMO: Usa lst local para caminhar por next; incrementa contador para cada no; nao altera as ligacoes da lista.
** PERGUNTA DE DEFESA: Por que lst=lst->next nao modifica a lista do chamador? ATENCAO: conferir tipo de retorno exigido pelo subject.
** Instrucoes C originais intactas. Os comentarios sao exclusivos deste repositorio.
*/

/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbraga-m <lbraga-m@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/19 18:56:08 by lbraga-m          #+#    #+#             */
/*   Updated: 2026/11/19 19:06:03 by lbraga-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_lstsize(t_list *lst)
{
	/* Contador local armazena o numero de nos percorridos. */
	int		count;

	count = 0;
	/* Enquanto o no atual existir (ou houver proximo, em lstlast), repita; o avanco por next garante progresso. */
	while (lst != NULL)
	{
	/* Conta um no visitado; nao conta o NULL terminal. */
		count++;
	/* Move apenas o ponteiro local para o proximo no, sem alterar ligacoes reais. */
		lst = lst->next;
	}
	/* Devolve ao chamador o resultado da operacao, que pode ser um ponteiro de no ou NULL. */
	return (count);
}
