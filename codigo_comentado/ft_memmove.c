/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbraga-m <lbraga-m@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/04 20:57:40 by lbraga-m          #+#    #+#             */
/*   Updated: 2026/11/13 19:29:51 by lbraga-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


/*
 * LEITURA GUIADA — ft_memmove
 *
 * PROBLEMA: copiar n bytes, mesmo quando origem e destino ocupam parte
 * da MESMA regiao de memoria. Copiar sempre do inicio poderia destruir
 * bytes da origem antes de termos a chance de le-los.
 *
 * EXEMPLO: buffer = "ABCDE", mover 4 bytes de buffer para buffer+1.
 * Se copiar da esquerda para direita, gravar A na posicao 1 sobrescreve
 * B, que ainda sera lido. Copiar do fim resolve: D vai para posicao 4,
 * C para 3, B para 2, A para 1; resultado "AABCD".
 *
 * No outro sentido (destino antes da origem), copiar do inicio funciona.
 * O algoritmo escolhe o sentido, sempre realizando n atribuicoes de bytes.
 *
 * PONTO DE REVISAO: a comparacao pd < ps entre enderecos de objetos
 * independentes nao e portavel segundo C; o comportamento de memmove
 * deve ser analisado com atencao a validade dos ponteiros.
 */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	/* Ponteiro para os bytes do DESTINO. unsigned char permite escrever cada byte individualmente. */
	unsigned char		*pd;
	/* Ponteiro para os bytes da ORIGEM. const indica que esta funcao nao pretende altera-los por ps. */
	const unsigned char	*ps;

	/* Caso especial da sua implementacao: quando os dois ponteiros sao nulos, sai antes de tentar acessar os buffers. */
	if (dest == 0 && src == 0)
	/* Devolve NULL no caso especial de ambos os enderecos serem nulos. */
		return (NULL);
	/* Converte o ponteiro generico de destino em ponteiro para byte sem copiar nenhum dado. */
	pd = (unsigned char *)dest;
	/* Faz o mesmo com a origem, preservando a indicacao de leitura (const). */
	ps = (const unsigned char *)src;
	/* Se o destino vier antes da origem no mesmo bloco, copiar para frente evita sobrescrever bytes ainda nao lidos. */
	if (pd < ps)
	/* Reaproveita sua copia byte a byte: nesta direcao nao ha risco de destruir bytes que ainda serao lidos. */
		ft_memcpy(dest, src, n);
	/* Se o destino nao vier antes, percorremos de tras para frente, protegendo os bytes anteriores da origem. */
	else
	{
	/* Ainda existem n bytes para copiar. O contador sera reduzido ate zero. */
		while (n > 0)
		{
	/* O ultimo indice valido e n-1. Decrementar ANTES do acesso impede escrever na posicao n (fora da faixa). */
			n--;
	/* Copia um byte do fim para o inicio; esse sentido torna seguro o deslocamento para a direita dentro do mesmo buffer. */
			pd[n] = ps[n];
		}
	}
	/* Por contrato, a funcao devolve o endereco inicial do destino recebido, nao a posicao final copiada. */
	return (dest);
}

/* #include <stdio.h>

int	main(void)
{
	char	texto1[] = "ABCDE";
	char	texto2[] = "ABCDE";
	char	texto3[] = "ABCDE";
	char 	origem[] = "Hello";
	char 	destino[] = "XXXXX";


	ft_memmove(texto1 + 1, texto1, 4);
	printf("Teste 1: %s\n", texto1);

	ft_memmove(texto2, texto2 + 1, 4);
	printf("Teste 2: %s\n", texto2);

	ft_memmove(texto3, texto3, 4);
	printf("Teste 3: %s\n", texto3);

	ft_memmove(destino, origem, 5);
	printf("Teste 4: %s\n", destino);
	return (0);
} */