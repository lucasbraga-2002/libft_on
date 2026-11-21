/* ************************************************************************** */

/*
** GUIA DE LEITURA - ft_strlen
** OBJETIVO: Contar bytes de uma string C ate o terminador nulo.
** RACIOCINIO: O tamanho nao inclui o byte '\0'. O indice representa quantos caracteres validos foram percorridos.
** DEFESA/TESTE: Teste: string vazia, '42', string com byte nulo interno.
** Comentarios didaticos. Instrucoes originais preservadas.
*/

/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbraga-m <lbraga-m@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/03 21:21:48 by lbraga-m          #+#    #+#             */
/*   Updated: 2026/11/06 18:28:56 by lbraga-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

	/* Assinatura: leia o tipo de retorno e os parametros; o resultado deve respeitar este contrato. */
size_t	ft_strlen(const char *s)
{
	/* Declara uma variavel local; observe seu tipo, especialmente se guarda endereco ou numero. */
	size_t	i;

	/* Inicializa o estado em zero antes de começar o processamento, evitando valor indeterminado. */
	i = 0;
	/* Repete o corpo enquanto esta condicao for verdadeira; a cada volta, algum estado deve avancar. */
	while (s[i] != '\0')
	{
	/* Avanca o indice para a proxima posicao; sem isso o laco nao progride. */
		i++;
	}
	/* Encerra a chamada e devolve exatamente este resultado a quem chamou. */
	return (i);
}

/*#include <stdio.h>

int	main(void)
{
	const char *testes[] = {"Hello", "", "42 Porto", "ABC"};
	int	i;

	i = 0;
	while (i < 4)
	{
		printf("String: %s | Tamanho: %zu\n", testes[i], ft_strlen(testes[i]));
		i++;
	}
	return (0);
}*/
