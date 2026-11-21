/* ************************************************************************** */

/*
** GUIA DE ESTUDO - ft_lstmap
** OBJETIVO: Construir NOVA lista com novos nos cujos conteudos resultam de aplicar f nos originais.
** ALGORITMO: Comeca new=NULL; para cada no transforma content, aloca outro no e anexa com add_back. Se alocacao do no falhar, destroi content temporario e a lista parcial com lstclear.
** PERGUNTA DE DEFESA: Por que usar &new no add_back e lstclear? Quem libera content se ft_lstnew falhar?
** Instrucoes C originais intactas. Os comentarios sao exclusivos deste repositorio.
*/

/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbraga-m <lbraga-m@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/20 15:40:16 by lbraga-m          #+#    #+#             */
/*   Updated: 2026/11/20 18:30:11 by lbraga-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

	/* Esta funcao devolve um endereco de no ou NULL. */
t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	void	*content;
	t_list	*new;
	t_list	*node;

	/* Trata um caso especial antes do caminho normal; avalie NULL, lista vazia e falha de alocacao. */
	if (lst == NULL || f == NULL || del == NULL)
	/* Devolve ao chamador o resultado da operacao, que pode ser um ponteiro de no ou NULL. */
		return (NULL);
	/* Cria uma lista nova vazia; a primeira insercao deve atualizar a cabeca. */
	new = NULL;
	/* Enquanto o no atual existir (ou houver proximo, em lstlast), repita; o avanco por next garante progresso. */
	while (lst != NULL)
	{
	/* Aplica a funcao fornecida ao conteudo do no original e guarda o resultado separado. */
		content = f(lst->content);
	/* Cria uma estrutura de no para guardar o novo content. Falha aqui exige limpeza. */
		node = ft_lstnew(content);
	/* Trata um caso especial antes do caminho normal; avalie NULL, lista vazia e falha de alocacao. */
		if (node == NULL)
		{
	/* Se nao houve no para receber content, esse conteudo temporario precisa ser destruido isoladamente. */
			del(content);
	/* Desfaz todos os nos ja criados antes da falha, evitando vazamento da lista parcial. */
			ft_lstclear(&new, del);
	/* Devolve ao chamador o resultado da operacao, que pode ser um ponteiro de no ou NULL. */
			return (NULL);
		}
	/* Passa &new porque a funcao precisa poder atualizar a cabeca quando a lista esta vazia. */
		ft_lstadd_back(&new, node);
	/* Move apenas o ponteiro local para o proximo no, sem alterar ligacoes reais. */
		lst = lst->next;
	}
	/* Devolve ao chamador o resultado da operacao, que pode ser um ponteiro de no ou NULL. */
	return (new);
}
