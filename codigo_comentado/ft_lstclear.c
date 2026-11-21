/* ************************************************************************** */

/*
** GUIA DE ESTUDO - ft_lstclear
** OBJETIVO: Destruir todos os nos e limpar o ponteiro para o inicio.
** ALGORITMO: Guarda o proximo no em ptr ANTES de apagar o atual; chama lstdelone e atualiza *lst. Quando ptr vira NULL, o ponteiro original tambem vira NULL.
** PERGUNTA DE DEFESA: Mostre por que free seguido de acesso a next seria use-after-free.
** Instrucoes C originais intactas. Os comentarios sao exclusivos deste repositorio.
*/

/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbraga-m <lbraga-m@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/19 21:20:55 by lbraga-m          #+#    #+#             */
/*   Updated: 2026/11/20 16:05:28 by lbraga-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

	/* Esta funcao retorna void: a alteracao acontece em ponteiros ou efeitos colaterais. */
void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*ptr;

	/* Trata um caso especial antes do caminho normal; avalie NULL, lista vazia e falha de alocacao. */
	if (lst == NULL || del == NULL)
	/* Interrompe esta funcao void; nada mais deve acontecer nesse caso. */
		return ;
	/* Enquanto o no atual existir (ou houver proximo, em lstlast), repita; o avanco por next garante progresso. */
	while (*lst != NULL)
	{
	/* Salva o endereco do proximo no ANTES de liberar o atual, evitando perder o resto da lista. */
		ptr = (*lst)->next;
	/* Destrui o no atual e seu conteudo; depois nao podemos mais acessar campos desse no. */
		ft_lstdelone(*lst, del);
		*lst = ptr;
	}
}
