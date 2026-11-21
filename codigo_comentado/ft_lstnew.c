/* ************************************************************************** */

/*
** GUIA DE ESTUDO - ft_lstnew
** OBJETIVO: Criar um no de lista alocado dinamicamente.
** ALGORITMO: malloc reserva a estrutura t_list; content guarda o ponteiro recebido, sem copiar o conteudo; next comeca NULL para indicar fim.
** PERGUNTA DE DEFESA: Duas alocacoes? ft_lstnew aloca somente o no; nao aloca nem libera content.
** Instrucoes C originais intactas. Os comentarios sao exclusivos deste repositorio.
*/

/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbraga-m <lbraga-m@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/19 18:07:40 by lbraga-m          #+#    #+#             */
/*   Updated: 2026/11/19 18:19:40 by lbraga-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

	/* Esta funcao devolve um endereco de no ou NULL. */
t_list	*ft_lstnew(void *content)
{
	t_list	*node;

	/* Reserva espaco na heap para um no t_list; nao cria automaticamente memoria para content. */
	node = malloc(sizeof(t_list));
	/* Trata um caso especial antes do caminho normal; avalie NULL, lista vazia e falha de alocacao. */
	if (node == NULL)
	/* Devolve ao chamador o resultado da operacao, que pode ser um ponteiro de no ou NULL. */
		return (NULL);
	/* Copia o endereco recebido para o campo content, NAO copia os bytes do objeto apontado. */
	node->content = content;
	/* Inicializa elo seguinte como fim de lista; outros nos podem ser conectados depois. */
	node->next = NULL;
	/* Devolve ao chamador o resultado da operacao, que pode ser um ponteiro de no ou NULL. */
	return (node);
}

/* #include <stdio.h>

int	main(void)
{
	t_list	*node;
	char	text[] = "42 Porto";

	node = ft_lstnew(text);
	if (node == NULL)
		return (1);
	printf("Content: %s\n", (char *)node->content);
	printf("Next: %p\n", (void *)node->next);
	free(node);
	return (0);
} */