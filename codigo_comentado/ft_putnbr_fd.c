/* ************************************************************************** */

/*
** GUIA DE ESTUDO - ft_putnbr_fd
** OBJETIVO: Escrever a representacao decimal de qualquer int em um file descriptor.
** ALGORITMO: Transforma em long, escreve '-' se necessario, usa recursao com nb/10 para imprimir os digitos mais significativos primeiro e nb%10 para imprimir o ultimo.
** PERGUNTA DE DEFESA: Explique a pilha de chamadas com 123 e por que long protege INT_MIN.
** Instrucoes C originais intactas. Os comentarios sao exclusivos deste repositorio.
*/

/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbraga-m <lbraga-m@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/18 21:17:58 by lbraga-m          #+#    #+#             */
/*   Updated: 2026/11/19 19:11:24 by lbraga-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

	/* Esta funcao retorna void: a alteracao acontece em ponteiros ou efeitos colaterais. */
void	ft_putnbr_fd(int n, int fd)
{
	long	nb;

	nb = n;
	/* Trata um caso especial antes do caminho normal; avalie NULL, lista vazia e falha de alocacao. */
	if (nb < 0)
	{
	/* Escreve um unico caractere por reutilizacao da funcao auxiliar. */
		ft_putchar_fd('-', fd);
	/* Torna o valor positivo com tipo long para evitar overflow de INT_MIN. */
		nb = -nb;
	}
	/* Trata um caso especial antes do caminho normal; avalie NULL, lista vazia e falha de alocacao. */
	if (nb > 9)
	/* Recursao: processa os digitos anteriores primeiro. Cada chamada espera para imprimir seu ultimo digito. */
		ft_putnbr_fd(nb / 10, fd);
	/* Escreve um unico caractere por reutilizacao da funcao auxiliar. */
	ft_putchar_fd((nb % 10) + '0', fd);
}

/* #include <limits.h>

int	main(void)
{
	ft_putnbr_fd(42, 1);
	ft_putchar_fd('\n', 1);
	ft_putnbr_fd(-123, 1);
	ft_putchar_fd('\n', 1);
	ft_putnbr_fd(0, 1);
	ft_putchar_fd('\n', 1);
	ft_putnbr_fd(INT_MAX, 1);
	ft_putchar_fd('\n', 1);
	ft_putnbr_fd(INT_MIN, 1);
	ft_putchar_fd('\n', 1);
	ft_putnbr_fd(-42, 2);
	ft_putchar_fd('\n', 2);
	return (0);
} */