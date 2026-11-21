/* ************************************************************************** */
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


/*
 * LEITURA GUIADA — ft_split
 *
 * OBJETIVO: dividir a string s em trechos separados pelo caractere c.
 * Resultado: um array de char *; cada elemento aponta para uma string
 * alocada separadamente, e a ultima posicao do array guarda NULL.
 *
 * EXEMPLO: s = ",,42,,Porto,", c = ','
 * count_words encontra 2 blocos (nao conta virgulas repetidas).
 * malloc reserva 3 ponteiros: [ ? ][ ? ][ NULL ao final ].
 * fill_words cria "42" e "Porto"; j conta QUANTAS palavras ja criou.
 *
 * O PROJETO TEM QUATRO ETAPAS:
 * 1) count_words: contar blocos para dimensionar o array de ponteiros.
 * 2) ft_split: alocar os ponteiros (palavras + sentinela NULL).
 * 3) fill_words: avancar na origem, encontrar intervalos e alocar
 *    cada substring, preenchendo o array na ordem.
 * 4) free_split: se ft_substr falhar, liberar as j palavras criadas
 *    e o array de ponteiros antes de retornar NULL.
 *
 * INDICES: i e a posicao atual em s; start marca onde a palavra comeca;
 * i - start e a quantidade de caracteres daquela palavra; j marca
 * a proxima posicao livre do array. Sao papeis diferentes.
 *
 * DEFESA: simule delimitadores consecutivos, string vazia, e falha
 * na segunda substring. Explique por que count_words + 1 e por
 * que split[j] precisa ser NULL no sucesso.
 */

#include "libft.h"

	/* Auxiliar interna: so conta sequencias nao delimitadas; ainda nao aloca nenhuma string. */
static size_t	count_words(char const *s, char c)
{
	/* Quantos blocos de texto ja foram encontrados. */
	size_t	count;
	/* Indice do byte atual de s; avanca tanto por palavras como por separadores. */
	size_t	i;

	/* Nenhuma palavra foi vista antes de iniciar a leitura. */
	count = 0;
	/* A contagem comeca no primeiro byte de s. */
	i = 0;
	/* Enquanto a string nao acabou, decidir se estamos num separador ou no inicio de uma palavra. */
	while (s[i] != '\0')
	{
	/* Um caractere nao delimitador marca o inicio de um NOVO bloco: contamos uma palavra uma unica vez. */
		if (s[i] != c)
		{
	/* Ao entrar no bloco, incrementamos uma vez, antes de pular todos os seus caracteres. */
			count++;
	/* Avanca por toda a palavra atual ate o delimitador ou fim; isso evita contar as letras seguintes como novas palavras. */
			while (s[i] != '\0' && s[i] != c)
	/* Cada byte da palavra e consumido; o laco termina no proximo separador ou no fim. */
				i++;
		}
		else
	/* Se o byte era separador, pula um e volta ao laco externo. */
			i++;
	}
	/* Devolve a quantidade exata de palavras para reservar N+1 ponteiros. */
	return (count);
}

	/* Cleanup auxiliar: recebe o array e quantas strings foram realmente alocadas. */
static void	free_split(char **split, size_t count)
{
	/* Repete a limpeza apenas enquanto restarem strings alocadas; funciona mesmo quando count=0. */
	while (count > 0)
	{
	/* Reduz primeiro: indices validos das palavras criadas vao de 0 ate count_original-1. */
		count--;
	/* Libera uma substring individual. Nao basta liberar somente o array principal. */
		free(split[count]);
	}
	/* Depois das strings, libera o bloco que guarda os ponteiros para elas. */
	free(split);
}

	/* Preenche o array previamente alocado; nao o dimensiona novamente. */
static char	**fill_words(char **split, char const *s, char c)
{
	/* Posicao inicial da palavra atual dentro da string original. */
	size_t	start;
	/* Indice atual durante a procura de palavras: jamais deve andar para tras. */
	size_t	i;
	/* Quantidade de substrings produzidas e indice onde entrara a proxima. */
	size_t	j;

	/* fill_words comeca a buscar a primeira palavra desde o inicio de s. */
	i = 0;
	/* No inicio ainda nao existe nenhuma substring no array. */
	j = 0;
	/* Continua procurando proximas palavras ate chegar ao terminador da string. */
	while (s[i] != '\0')
	{
	/* Pula TODOS os delimitadores seguidos, impedindo substrings vazias entre eles. */
		while (s[i] == c)
	/* Pula uma posicao dentro da palavra para determinar onde ela termina. */
			i++;
	/* Se pular separadores nos levou ao fim, nao existe outra palavra para extrair. */
		if (s[i] == '\0')
	/* Sai do laco de extracao; a etapa seguinte acrescenta NULL no fim do array. */
			break ;
	/* Memoriza onde a palavra comeca, antes de avancar i ate o seu final. */
		start = i;
	/* Encontra a primeira posicao DEPOIS da palavra; essa posicao nao entra na substring. */
		while (s[i] != c && s[i] != '\0')
	/* Pula uma posicao dentro da palavra para determinar onde ela termina. */
			i++;
	/* Aloca a palavra usando o intervalo [start, i). Comprimento i-start exclui o delimitador. */
		split[j] = ft_substr(s, start, (i - start));
	/* Se a alocacao da substring falhar, j indica exatamente quantas strings anteriores precisam ser limpas. */
		if (split[j] == NULL)
		{
	/* Libera as palavras 0..j-1 ja concluidas e o array, evitando vazamento parcial. */
			free_split(split, j);
	/* Informa erro ao chamador: o array foi limpo e nao existe resultado utilizavel. */
			return (NULL);
		}
	/* Uma palavra foi criada com sucesso: a proxima vai para a posicao seguinte. */
		j++;
	}
	/* Sentinela final: quem receber o array pode percorre-lo ate encontrar ponteiro NULL. */
	split[j] = NULL;
	/* Devolve o array agora preenchido e terminado em NULL. */
	return (split);
}

	/* Interface publica: devolve um array de strings, portanto char **. */
char	**ft_split(char const *s, char c)
{
	/* Ponteiro para o primeiro elemento do array de ponteiros char *. */
	char	**split;

	/* Reserva um ponteiro por palavra e UM adicional para o NULL terminal. sizeof(char *) e o tamanho de cada elemento. */
	split = malloc((count_words(s, c) + 1) * sizeof(char *));
	/* Falhou a reserva do array: abortamos antes de tentar escrever em memoria nao alocada. */
	if (split == NULL)
	/* Se malloc do array falhou, nenhum ponteiro foi criado; nao precisamos chamar free_split. */
		return (NULL);
	/* Passa o array ja reservado ao preenchedor; ele faz as demais alocacoes e o cleanup se necessario. */
	return (fill_words(split, s, c));
}
