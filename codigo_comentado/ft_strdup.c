/* ************************************************************************** */

/*
** GUIA DE LEITURA - ft_strdup
** OBJETIVO: Alocar outra regiao de memoria e copiar os bytes de uma string, inclusive o terminador.
** RACIOCINIO: ft_strlen + 1 reserva espaco para '\0'; se malloc falha retorna NULL; o chamador libera a copia.
** DEFESA/TESTE: Teste: string vazia, alterar a copia sem alterar o original.
** Comentarios didaticos. Instrucoes originais preservadas.
*/

/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbraga-m <lbraga-m@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/16 16:32:59 by lbraga-m          #+#    #+#             */
/*   Updated: 2026/11/16 19:08:33 by lbraga-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s1)
{
	/* Declara uma variavel local; observe seu tipo, especialmente se guarda endereco ou numero. */
	size_t	i;
	char	*cpy;

	/* Inicializa o estado em zero antes de começar o processamento, evitando valor indeterminado. */
	i = 0;
	/* Pede memoria na heap; sem essa alocacao a copia nao teria armazenamento proprio. */
	cpy = malloc(ft_strlen(s1) + 1);
	/* Verifica uma condicao antes de executar ou interromper o fluxo; explique os limites que ela protege. */
	if (cpy == NULL)
	/* Encerra a chamada e devolve exatamente este resultado a quem chamou. */
		return (NULL);
	/* Repete o corpo enquanto esta condicao for verdadeira; a cada volta, algum estado deve avancar. */
	while (s1[i] != '\0')
	{
	/* Copia um byte da origem para a mesma posicao do novo buffer. */
		cpy[i] = s1[i];
	/* Avanca o indice para a proxima posicao; sem isso o laco nao progride. */
		i++;
	}
	/* Escreve o terminador NUL obrigatorio ao fim da nova string. */
	cpy[i] = '\0';
	/* Encerra a chamada e devolve exatamente este resultado a quem chamou. */
	return (cpy);
}

/* #include <stdio.h>

int	main(void)
{
	char	*s1;
	char	*cpy;

	s1 = "ABCDE";
	cpy = ft_strdup(s1);
	if (cpy == NULL)
		return (1);
	printf("Original: %s\n", s1);
	printf("Copia:    %s\n", cpy);
	cpy[0] = 'X';
	printf("Original depois: %s\n", s1);
	printf("Copia depois:    %s\n", cpy);
	free(cpy);
	return (0);
} */