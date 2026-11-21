/* ************************************************************************** */

/*
** GUIA DE ESTUDO - ft_putendl_fd
** OBJETIVO: Escrever uma string seguida de quebra de linha para um file descriptor.
** ALGORITMO: Reutiliza ft_putstr_fd para a sequencia de caracteres e ft_putchar_fd para o '\n'.
** PERGUNTA DE DEFESA: Por que a quebra de linha e um caractere separado?
** Instrucoes C originais intactas. Os comentarios sao exclusivos deste repositorio.
*/

/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putendl_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbraga-m <lbraga-m@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/18 21:07:16 by lbraga-m          #+#    #+#             */
/*   Updated: 2026/11/18 21:15:43 by lbraga-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

	/* Esta funcao retorna void: a alteracao acontece em ponteiros ou efeitos colaterais. */
void	ft_putendl_fd(char *s, int fd)
{
	/* Primeiro envia o texto antes de acrescentar a quebra de linha. */
	ft_putstr_fd(s, fd);
	/* Escreve um unico caractere por reutilizacao da funcao auxiliar. */
	ft_putchar_fd('\n', fd);
}

/* int	main(void)
{
	ft_putendl_fd("Hello, 42!", 1);
	ft_putendl_fd("Mensagem de erro", 2);
	return (0);
}
./a.out > stdout.txt 2> stderr.txt */