/* ************************************************************************** */

/*
** ESTUDO: ft_bzero
** O QUE RESOLVE: Zera os primeiros n bytes de um bloco de memoria.
** CAMINHO DO ALGORITMO: Reaproveita ft_memset com o valor 0, evitando manter um segundo algoritmo de escrita de bytes.
** PARA DEFENDER: Por que nao usa strlen? Memoria binaria pode conter zeros internos. Testes: struct, array, n=0.
** O C original abaixo permanece intacto; comentarios sao somente para estudo.
*/

/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbraga-m <lbraga-m@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/04 18:46:43 by lbraga-m          #+#    #+#             */
/*   Updated: 2026/11/06 18:28:32 by lbraga-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

	/* Assinatura publica: tipo de retorno e parametros definem o contrato usado por quem chama. */
void	ft_bzero(void *s, size_t n)
{
	ft_memset(s, 0, n);
}

/*#include <stdio.h>

int	main(void)
{
	char	texto[] = "Hello";

	ft_bzero(texto, 2);
	printf("Primeiro byte: %d\n", texto[0]);
	printf("Segundo byte: %d\n", texto[1]);
	printf("Terceiro byte: %c\n", texto[2]);
	printf("String: %s\n", texto);
	printf("String a partir do indice 2: %s\n", &texto[2]);
	return (0);
}
*/