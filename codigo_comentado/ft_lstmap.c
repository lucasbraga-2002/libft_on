/* ************************************************************************** */
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


/*
 * LEITURA GUIADA — ft_lstmap
 *
 * OBJETIVO: percorrer a lista ORIGINAL e construir uma SEGUNDA lista
 * com nos independentes. Para cada content original, f gera o content
 * do novo no; ft_lstnew cria a estrutura; ft_lstadd_back conecta os nos.
 *
 * Imagine lst: [1]->[2]->NULL, e f criando o dobro de cada inteiro.
 * new comeca NULL. A primeira volta cria [2] e define new como sua
 * cabeca. A segunda cria [4] e o conecta. Ao fim, retorna [2]->[4].
 * A cadeia original nao foi religada nem liberada.
 *
 * PONTEIROS: new e t_list *; &new e t_list **. Passar &new para add_back
 * permite mudar a cabeca quando a lista ainda esta vazia. node guarda
 * um no individual; content guarda o resultado de f, que nao e um no.
 *
 * FALHA: se f criou content mas ft_lstnew nao conseguiu criar a
 * estrutura, del(content) limpa o recurso ainda SEM no; ft_lstclear
 * remove a parte da nova lista que ja foi construida. Sao duas
 * responsabilidades diferentes.
 *
 * CUIDADO: f precisa obedecer ao contrato esperado de ownership:
 * os conteudos produzidos devem poder ser destruidos por del, sem
 * comprometer a lista original. Este codigo nao verifica f == NULL
 * como resultado da chamada: NULL pode ser um conteudo valido.
 *
 * DEFESA: acompanhe a primeira insercao, explique &new, e simule
 * uma falha no terceiro malloc de ft_lstnew.
 */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	/* Armazena o endereco do CONTEUDO transformado por f. void * nao informa o tipo concreto do objeto. */
	void	*content;
	/* Guarda o endereco da cabeca da nova lista; ele deve sobreviver a todas as voltas. */
	t_list	*new;
	/* Guarda o no recem-criado em cada volta, antes de liga-lo a new. */
	t_list	*node;

	/* Sem lista ou callbacks validos, nao e possivel mapear e garantir a limpeza. Checamos antes de chamar f ou del. */
	if (lst == NULL || f == NULL || del == NULL)
	/* Na entrada, NULL indica que nao ha uma lista valida a devolver. */
		return (NULL);
	/* A lista de destino comeca sem nos. Nao se deve criar um no usando content ainda nao inicializado. */
	new = NULL;
	/* O laco percorre a lista ORIGINAL ate depois do ultimo no. A condicao nao depende de new, pois ela comeca vazia. */
	while (lst != NULL)
	{
	/* Envia para f o conteudo do no atual e guarda o ponteiro retornado. Nao substitui o content do no original. */
		content = f(lst->content);
	/* Aloca uma NOVA estrutura t_list e coloca nela o endereco content; ft_lstnew nao duplica os bytes desse conteudo. */
		node = ft_lstnew(content);
	/* Se o malloc do no falhou, content pode ter sido criado por f mesmo assim: nao podemos simplesmente retornar. */
		if (node == NULL)
		{
	/* Destrui apenas o conteudo recem-criado que ficou sem no, usando a funcao de limpeza recebida. */
			del(content);
	/* Destrui todos os nos que ja foram ligados a nova lista e seus conteudos. &new permite zerar a cabeca. */
			ft_lstclear(&new, del);
	/* Na falha de alocacao, NULL indica que a nova lista nao foi construida; antes disso todo recurso temporario foi limpo. */
			return (NULL);
		}
	/* Conecta node ao final da lista de destino. No primeiro no, altera new de NULL para o endereco de node. */
		ft_lstadd_back(&new, node);
	/* Avanca apenas o ponteiro local que visita a lista original; os links next da origem nao mudam. */
		lst = lst->next;
	}
	/* Se tudo deu certo, entrega o ponteiro para a primeira estrutura da nova lista; quem recebeu assume sua gestao. */
	return (new);
}
