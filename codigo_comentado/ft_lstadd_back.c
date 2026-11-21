/* ************************************************************************** */

/*
** GUIA DE ESTUDO - ft_lstadd_back
** OBJETIVO: Anexar no ao final de uma lista encadeada.
** ALGORITMO: Se ponteiros sao invalidos retorna. Se lista vazia, adiciona na frente e termina. Caso contrario acha ultimo no e conecta seu next ao novo no.
** PERGUNTA DE DEFESA: Por que ft_lstlast(*lst)->next = new e nao new = ft_lstlast(*lst)->next?
** Instrucoes C originais intactas. Os comentarios sao exclusivos deste repositorio.
*/

/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbraga-m <lbraga-m@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/19 19:27:33 by lbraga-m          #+#    #+#             */
/*   Updated: 2026/11/19 19:48:56 by lbraga-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

	/* Esta funcao retorna void: a alteracao acontece em ponteiros ou efeitos colaterais. */
void	ft_lstadd_back(t_list **lst, t_list *new)
{
	/* Trata um caso especial antes do caminho normal; avalie NULL, lista vazia e falha de alocacao. */
	if (lst == NULL || new == NULL)
	/* Interrompe esta funcao void; nada mais deve acontecer nesse caso. */
		return ;
	/* Trata um caso especial antes do caminho normal; avalie NULL, lista vazia e falha de alocacao. */
	if (*lst == NULL)
	{
	/* Reutiliza a insercao no inicio para o caso de lista originalmente vazia. */
		ft_lstadd_front(lst, new);
	/* Interrompe esta funcao void; nada mais deve acontecer nesse caso. */
		return ;
	}
	/* Altera o campo next do ultimo no, criando a nova ligacao; nao e uma simples atribuicao local. */
	ft_lstlast(*lst)->next = new;
}
