/* ************************************************************************** */

/*
** GUIA DE ESTUDO - ft_lstadd_front
** OBJETIVO: Adicionar um no na frente de uma lista encadeada, atualizando seu inicio.
** ALGORITMO: Primeiro liga new->next ao antigo primeiro no; so depois altera *lst para apontar a new. A ordem evita perder o restante da lista.
** PERGUNTA DE DEFESA: Por que t_list **? Para modificar o ponteiro da cabeca do chamador.
** Instrucoes C originais intactas. Os comentarios sao exclusivos deste repositorio.
*/

/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_front.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbraga-m <lbraga-m@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/19 18:21:55 by lbraga-m          #+#    #+#             */
/*   Updated: 2026/11/19 18:53:16 by lbraga-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

	/* Esta funcao retorna void: a alteracao acontece em ponteiros ou efeitos colaterais. */
void	ft_lstadd_front(t_list **lst, t_list *new)
{
	/* Trata um caso especial antes do caminho normal; avalie NULL, lista vazia e falha de alocacao. */
	if (lst == NULL || new == NULL)
	/* Interrompe esta funcao void; nada mais deve acontecer nesse caso. */
		return ;
	/* Conecta o novo no ao antigo primeiro; fazer isso antes de *lst=new preserva a cadeia. */
	new->next = *lst;
	*lst = new;
}
