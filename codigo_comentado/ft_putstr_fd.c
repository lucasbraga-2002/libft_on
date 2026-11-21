/* ************************************************************************** */

/*
** FICHA DIDATICA: ft_putstr_fd
** OBJETIVO: Escrever string caracter a caracter num file descriptor.
** ESTRATEGIA: Usa indice ate '\0', chamando write a cada caractere; NUL nao e enviado.
** COMO DEFENDER: Defesa: comparar custo de varias chamadas write versus uma unica.
** O codigo original foi mantido; somente comentarios didaticos foram inseridos.
*/

/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbraga-m <lbraga-m@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/18 20:53:37 by lbraga-m          #+#    #+#             */
/*   Updated: 2026/11/18 21:16:12 by lbraga-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

	/* Entrada e saida do algoritmo: os tipos mostram se retorna endereco, numero ou nada. */
void	ft_putstr_fd(char *s, int fd)
{
	/* Variavel local: determine se armazena tamanho, posicao ou endereco. */
	int	i;

	/* Comeca contador ou indice do zero. */
	i = 0;
	/* Laco: acompanhe o estado inicial, a condicao de parada e o avanco para provar que termina. */
	while (s[i] != '\0')
	{
	/* write recebe fd, endereco do primeiro byte e quantidade de bytes. */
		write(fd, &s[i], 1);
	/* Avanca/regride no intervalo: assegura progresso do algoritmo. */
		i++;
	}
}

/* #include <stdio.h>

int main(void)
{
	ft_putstr_fd("Hello, 42!\n", 1);
	ft_putstr_fd("Teste de erro!\n", 2);
	ft_putstr_fd("", 1);
	return (0);
} 
./a.out > stdout.txt 2> stderr.txt */