/* ************************************************************************** */

/*
** GUIA DE ESTUDO - ft_lstiter
** OBJETIVO: Executar uma funcao sobre o conteudo de cada no existente.
** ALGORITMO: Enquanto lst existir, invoca f(lst->content) e avanca pelo next; nao cria ou apaga nos.
** PERGUNTA DE DEFESA: Diferenca entre iterar (f retorna void) e mapear (f gera outro conteudo).
** Instrucoes C originais intactas. Os comentarios sao exclusivos deste repositorio.
*/

/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstiter.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbraga-m <lbraga-m@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/20 14:57:23 by lbraga-m          #+#    #+#             */
/*   Updated: 2026/11/20 19:12:53 by lbraga-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

	/* Esta funcao retorna void: a alteracao acontece em ponteiros ou efeitos colaterais. */
void	ft_lstiter(t_list *lst, void (*f)(void *))
{
	/* Trata um caso especial antes do caminho normal; avalie NULL, lista vazia e falha de alocacao. */
	if (lst == NULL || f == NULL)
	/* Interrompe esta funcao void; nada mais deve acontecer nesse caso. */
		return ;
	/* Enquanto o no atual existir (ou houver proximo, em lstlast), repita; o avanco por next garante progresso. */
	while (lst != NULL)
	{
	/* Callback atua sobre o conteudo atual; a estrutura de lista permanece intacta. */
		f(lst->content);
	/* Move apenas o ponteiro local para o proximo no, sem alterar ligacoes reais. */
		lst = lst->next;
	}
}
