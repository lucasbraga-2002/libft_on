/* ************************************************************************** */

/*
** FICHA DIDATICA: ft_split
** OBJETIVO: Dividir a string em palavras separadas pelo delimitador c e devolver array terminado em NULL.
** ESTRATEGIA: count_words conta blocos; fill_words pula delimitadores, identifica cada trecho e aloca substrings. Em falha, free_split desfaz TODAS as alocacoes anteriores, inclusive o array.
** COMO DEFENDER: Defesa: explicar tres alocacoes (array, strings, terminadores), j como numero de palavras prontas, e por que split[j]=NULL.
** O codigo original foi mantido; somente comentarios didaticos foram inseridos.
*/

/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbraga-m <lbraga-m@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/17 17:44:48 by lbraga-m          #+#    #+#             */
/*   Updated: 2026/11/18 17:16:12 by lbraga-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

	/* Funcao auxiliar static: seu nome so existe neste arquivo, reduzindo a interface publica. */
static size_t	count_words(char const *s, char c)
{
	/* Variavel local: determine se armazena tamanho, posicao ou endereco. */
	size_t	count;
	/* Variavel local: determine se armazena tamanho, posicao ou endereco. */
	size_t	i;

	/* Comeca contador ou indice do zero. */
	count = 0;
	/* Comeca contador ou indice do zero. */
	i = 0;
	/* Laco: acompanhe o estado inicial, a condicao de parada e o avanco para provar que termina. */
	while (s[i] != '\0')
	{
	/* Decisao: separa casos-limite do caminho normal; teste mentalmente os dois resultados possiveis. */
		if (s[i] != c)
		{
			count++;
	/* Laco: acompanhe o estado inicial, a condicao de parada e o avanco para provar que termina. */
			while (s[i] != '\0' && s[i] != c)
	/* Avanca/regride no intervalo: assegura progresso do algoritmo. */
				i++;
		}
		else
	/* Avanca/regride no intervalo: assegura progresso do algoritmo. */
			i++;
	}
	/* Retorno imediato: evita continuar apos um resultado ou falha ja determinados. */
	return (count);
}

	/* Funcao auxiliar static: seu nome so existe neste arquivo, reduzindo a interface publica. */
static void	free_split(char **split, size_t count)
{
	/* Laco: acompanhe o estado inicial, a condicao de parada e o avanco para provar que termina. */
	while (count > 0)
	{
	/* Avanca/regride no intervalo: assegura progresso do algoritmo. */
		count--;
		free(split[count]);
	}
	free(split);
}

	/* Funcao auxiliar static: seu nome so existe neste arquivo, reduzindo a interface publica. */
static char	**fill_words(char **split, char const *s, char c)
{
	/* Variavel local: determine se armazena tamanho, posicao ou endereco. */
	size_t	start;
	/* Variavel local: determine se armazena tamanho, posicao ou endereco. */
	size_t	i;
	/* Variavel local: determine se armazena tamanho, posicao ou endereco. */
	size_t	j;

	/* Comeca contador ou indice do zero. */
	i = 0;
	/* Comeca contador ou indice do zero. */
	j = 0;
	/* Laco: acompanhe o estado inicial, a condicao de parada e o avanco para provar que termina. */
	while (s[i] != '\0')
	{
	/* Laco: acompanhe o estado inicial, a condicao de parada e o avanco para provar que termina. */
		while (s[i] == c)
	/* Avanca/regride no intervalo: assegura progresso do algoritmo. */
			i++;
	/* Decisao: separa casos-limite do caminho normal; teste mentalmente os dois resultados possiveis. */
		if (s[i] == '\0')
			break ;
		start = i;
	/* Laco: acompanhe o estado inicial, a condicao de parada e o avanco para provar que termina. */
		while (s[i] != c && s[i] != '\0')
	/* Avanca/regride no intervalo: assegura progresso do algoritmo. */
			i++;
	/* Extrai o intervalo calculado, criando uma nova string terminada em NUL. */
		split[j] = ft_substr(s, start, (i - start));
	/* Decisao: separa casos-limite do caminho normal; teste mentalmente os dois resultados possiveis. */
		if (split[j] == NULL)
		{
	/* Desfaz alocacoes ja feitas quando algo falha: nao pode esquecer recursos anteriores. */
			free_split(split, j);
	/* Retorno imediato: evita continuar apos um resultado ou falha ja determinados. */
			return (NULL);
		}
	/* Avanca/regride no intervalo: assegura progresso do algoritmo. */
		j++;
	}
	/* Sentinela: encerra o array de ponteiros para quem o percorre. */
	split[j] = NULL;
	/* Retorno imediato: evita continuar apos um resultado ou falha ja determinados. */
	return (split);
}

	/* Entrada e saida do algoritmo: os tipos mostram se retorna endereco, numero ou nada. */
char	**ft_split(char const *s, char c)
{
	/* Variavel local: determine se armazena tamanho, posicao ou endereco. */
	char	**split;

	/* Reserva armazenamento na heap; e preciso liberar no futuro ou no tratamento de falha. */
	split = malloc((count_words(s, c) + 1) * sizeof(char *));
	/* Decisao: separa casos-limite do caminho normal; teste mentalmente os dois resultados possiveis. */
	if (split == NULL)
	/* Retorno imediato: evita continuar apos um resultado ou falha ja determinados. */
		return (NULL);
	/* Retorno imediato: evita continuar apos um resultado ou falha ja determinados. */
	return (fill_words(split, s, c));
}
