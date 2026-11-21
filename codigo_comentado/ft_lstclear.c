/* ************************************************************************** */
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


/*
 * LEITURA GUIADA — ft_lstclear
 *
 * IDEIA: a lista e uma corrente de nos. Para destruir o no atual e ainda
 * alcancar o seguinte, precisamos memorizar o endereco do seguinte ANTES
 * da liberacao. ptr e essa memoria temporaria.
 *
 * EXEMPLO: *lst -> A -> B -> C -> NULL
 *  1) ptr guarda B; ft_lstdelone libera A; *lst passa a apontar B.
 *  2) ptr guarda C; libera B; *lst passa a apontar C.
 *  3) ptr guarda NULL; libera C; *lst vira NULL.
 *
 * MODELO DE MEMORIA: lst e t_list ** (endereco da variavel head);
 * *lst e t_list * (endereco do primeiro no). Alterar *lst muda head
 * no codigo de quem chamou; avancar apenas um ponteiro local nao mudaria.
 *
 * DIFERENCA IMPORTANTE: ft_lstdelone ja chama del(content) e free(no);
 * chamar free mais uma vez seria double free. Nao acesse o no apos free.
 *
 * DEFESA: explique por que a ordem salvar -> liberar -> avancar e
 * obrigatoria; percorra mentalmente lista vazia, um no e tres nos.
 * Os comentarios abaixo sao didaticos; nao fazem parte da entrega 42.
 */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	/* ptr vai guardar temporariamente o ENDERECO do proximo no, nao o conteudo dele. */
	t_list	*ptr;

	/* Primeiro verificamos se recebemos o endereco de head e uma funcao de limpeza validos. So depois podemos acessar *lst ou chamar del. */
	if (lst == NULL || del == NULL)
	/* Se um parametro essencial e invalido, sair evita desreferenciar NULL ou chamar um ponteiro de funcao inexistente. */
		return ;
	/* Em cada repeticao, *lst e o no que ainda precisa ser destruido. Quando chega a NULL, ate o ultimo no ja foi processado. */
	while (*lst != NULL)
	{
	/* Antes de liberar o no atual, copiamos seu next para ptr. Depois da liberacao, tentar ler (*lst)->next seria use-after-free. */
		ptr = (*lst)->next;
	/* A funcao auxiliar executa del sobre content e depois free no no atual. ptr continua valido como endereco do proximo no. */
		ft_lstdelone(*lst, del);
	/* Atualizamos o ponteiro original de cabeca com o endereco salvo. Na ultima volta ptr e NULL, deixando a lista vazia. */
		*lst = ptr;
	}
}
