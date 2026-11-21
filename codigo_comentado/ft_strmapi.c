/* ************************************************************************** */

/*
** FICHA DIDATICA: ft_strmapi
** OBJETIVO: Criar nova string aplicando f(indice, caractere) a cada caractere original.
** ESTRATEGIA: Aloca strlen+1, escreve resultado de f no mesmo indice da nova string e finaliza com NUL; original nao e alterada.
** COMO DEFENDER: Defesa: funcao recebe char por valor e retorna novo char.
** O codigo original foi mantido; somente comentarios didaticos foram inseridos.
*/

/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbraga-m <lbraga-m@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/18 19:30:53 by lbraga-m          #+#    #+#             */
/*   Updated: 2026/11/18 20:23:10 by lbraga-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

	/* Entrada e saida do algoritmo: os tipos mostram se retorna endereco, numero ou nada. */
char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	/* Variavel local: determine se armazena tamanho, posicao ou endereco. */
	char			*str;
	/* Variavel local: determine se armazena tamanho, posicao ou endereco. */
	unsigned int	i;

	/* Comeca contador ou indice do zero. */
	i = 0;
	/* Reserva armazenamento na heap; e preciso liberar no futuro ou no tratamento de falha. */
	str = malloc(ft_strlen(s) + 1);
	/* Decisao: separa casos-limite do caminho normal; teste mentalmente os dois resultados possiveis. */
	if (str == NULL)
	/* Retorno imediato: evita continuar apos um resultado ou falha ja determinados. */
		return (NULL);
	/* Laco: acompanhe o estado inicial, a condicao de parada e o avanco para provar que termina. */
	while (s[i] != '\0')
	{
	/* Callback recebe indice e caractere/endereco conforme a assinatura; compare map e iter. */
		str[i] = f(i, s[i]);
	/* Avanca/regride no intervalo: assegura progresso do algoritmo. */
		i++;
	}
	str[i] = '\0';
	/* Retorno imediato: evita continuar apos um resultado ou falha ja determinados. */
	return (str);
}

/* #include <stdio.h>

static char	transform(unsigned int i, char c)
{
	return (c + i);
}

int	main(void)
{
	char	*result;

	result = ft_strmapi("ABC", transform);
	if (result == NULL)
		return (1);
	printf("Original:  ABC\n");
	printf("Resultado: %s\n", result);
	free(result);
	return (0);
} */