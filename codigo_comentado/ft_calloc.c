/* ************************************************************************** */

/*
** FICHA DIDATICA: ft_calloc
** OBJETIVO: Reservar nmemb * size bytes e inicializar todos com zero.
** ESTRATEGIA: Antes da multiplicacao, nmemb > SIZE_MAX/size detecta overflow sem executar multiplicacao perigosa; depois malloc e bzero.
** COMO DEFENDER: Defesa: se a multiplicacao estourasse, malloc poderia reservar menos memoria que o esperado.
** O codigo original foi mantido; somente comentarios didaticos foram inseridos.
*/

/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbraga-m <lbraga-m@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/15 14:33:58 by lbraga-m          #+#    #+#             */
/*   Updated: 2026/11/16 16:20:03 by lbraga-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

	/* Entrada e saida do algoritmo: os tipos mostram se retorna endereco, numero ou nada. */
void	*ft_calloc(size_t nmemb, size_t size)
{
	/* Variavel local: determine se armazena tamanho, posicao ou endereco. */
	void	*ptr;

	/* Decisao: separa casos-limite do caminho normal; teste mentalmente os dois resultados possiveis. */
	if (size != 0 && nmemb > SIZE_MAX / size)
	/* Retorno imediato: evita continuar apos um resultado ou falha ja determinados. */
		return (NULL);
	/* Reserva armazenamento na heap; e preciso liberar no futuro ou no tratamento de falha. */
	ptr = malloc(nmemb * size);
	/* Decisao: separa casos-limite do caminho normal; teste mentalmente os dois resultados possiveis. */
	if (ptr == NULL)
	/* Retorno imediato: evita continuar apos um resultado ou falha ja determinados. */
		return (NULL);
	/* Inicializa toda a area alocada com zeros, byte a byte. */
	ft_bzero(ptr, nmemb * size);
	/* Retorno imediato: evita continuar apos um resultado ou falha ja determinados. */
	return (ptr);
}

/* #include <stdio.h>

int	main(void)
{
	int	*numeros;
	int	i;

	numeros = ft_calloc(5, sizeof(int));
	if (numeros == NULL)
	{
		printf("Falha na alocacao\n");
		return (1);
	}
	i = 0;
	while (i < 5)
	{
		printf("numeros[%d] = %d\n", i, numeros[i]);
		i++;
	}
	free(numeros);
	void	*ptr_zero;

	ptr_zero = ft_calloc(0, 10);
	printf("ft_calloc(0, 10): %p\n", ptr_zero);
	free(ptr_zero);
	void	*ptr_overflow;

	ptr_overflow = ft_calloc(SIZE_MAX, 2);
	printf("Overflow: %p\n", ptr_overflow);
	free(ptr_overflow);
	return (0);
} */
