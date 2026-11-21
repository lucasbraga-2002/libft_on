/* ************************************************************************** */

/*
** GUIA DE ESTUDO - ft_lstlast
** OBJETIVO: Encontrar e devolver o endereco do ultimo no, sem modificar a lista.
** ALGORITMO: Percorre apenas enquanto existe no atual E existe um proximo; assim para no ultimo e nao no NULL apos ele.
** PERGUNTA DE DEFESA: Por que nao while(lst != NULL)? Porque precisamos devolver o ultimo no, nao NULL.
** Instrucoes C originais intactas. Os comentarios sao exclusivos deste repositorio.
*/

/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstlast.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbraga-m <lbraga-m@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/19 19:09:19 by lbraga-m          #+#    #+#             */
/*   Updated: 2026/11/19 19:19:25 by lbraga-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

	/* Esta funcao devolve um endereco de no ou NULL. */
t_list	*ft_lstlast(t_list *lst)
{
	/* Enquanto o no atual existir (ou houver proximo, em lstlast), repita; o avanco por next garante progresso. */
	while (lst && lst->next != NULL)
	/* Move apenas o ponteiro local para o proximo no, sem alterar ligacoes reais. */
		lst = lst->next;
	/* Devolve ao chamador o resultado da operacao, que pode ser um ponteiro de no ou NULL. */
	return (lst);
}
