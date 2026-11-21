/* ************************************************************************** */

/*
** GUIA DE ESTUDO - ft_lstdelone
** OBJETIVO: Destruir um unico no e seu conteudo, sem apagar nos seguintes.
** ALGORITMO: del(lst->content) lida com a memoria de conteudo; free(lst) libera separadamente a estrutura. Nao acessa next.
** PERGUNTA DE DEFESA: Por que del antes de free? Caso contrario lst->content seria acesso apos liberar o no.
** Instrucoes C originais intactas. Os comentarios sao exclusivos deste repositorio.
*/

/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdelone.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbraga-m <lbraga-m@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/19 21:03:35 by lbraga-m          #+#    #+#             */
/*   Updated: 2026/11/20 16:14:27 by lbraga-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

	/* Esta funcao retorna void: a alteracao acontece em ponteiros ou efeitos colaterais. */
void	ft_lstdelone(t_list *lst, void (*del)(void *))
{
	/* Trata um caso especial antes do caminho normal; avalie NULL, lista vazia e falha de alocacao. */
	if (lst == NULL || del == NULL)
	/* Interrompe esta funcao void; nada mais deve acontecer nesse caso. */
		return ;
	/* Executa callback de limpeza sobre o conteudo; a propria estrutura ainda existe aqui. */
	del(lst->content);
	/* Libera a estrutura do no. Nao use seus campos apos esta chamada. */
	free(lst);
}
