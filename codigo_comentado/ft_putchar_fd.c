/* ************************************************************************** */

/*
** FICHA DIDATICA: ft_putchar_fd
** OBJETIVO: Enviar um caractere para um file descriptor.
** ESTRATEGIA: write(fd,&c,1) passa endereco do char e quantidade exata de um byte.
** COMO DEFENDER: Defesa: fd=1 normalmente stdout; fd=2 stderr; write e syscall de bytes.
** O codigo original foi mantido; somente comentarios didaticos foram inseridos.
*/

/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putchar_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbraga-m <lbraga-m@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/18 20:47:21 by lbraga-m          #+#    #+#             */
/*   Updated: 2026/11/18 20:53:08 by lbraga-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

	/* Entrada e saida do algoritmo: os tipos mostram se retorna endereco, numero ou nada. */
void	ft_putchar_fd(char c, int fd)
{
	/* write recebe fd, endereco do primeiro byte e quantidade de bytes. */
	write(fd, &c, 1);
}

/* int	main(void)
{
	ft_putchar_fd('A', 1);
	ft_putchar_fd('B', 2);
	return (0);
}
./a.out > stdout.txt 2> stderr.txt */