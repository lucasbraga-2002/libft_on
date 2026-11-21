/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbraga-m <lbraga-m@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/18 17:55:50 by lbraga-m          #+#    #+#             */
/*   Updated: 2026/11/18 19:12:46 by lbraga-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


/*
 * LEITURA GUIADA — ft_itoa
 *
 * OBJETIVO: converter um inteiro para uma NOVA string decimal.
 * Para 123, o resultado deve conter '1','2','3','\0'. Para -42,
 * deve conter '-','4','2','\0'. A memoria pertence ao chamador.
 *
 * A CONSTRUCAO OCORRE DE TRAS PARA FRENTE:
 * 1) count_char descobre quantas posicoes serao usadas, inclusive '-'.
 * 2) malloc reserva esse numero MAIS 1 para o terminador '\0'.
 * 3) %10 pega o ultimo digito; /10 elimina esse digito.
 * 4) Preencher o array do final para o inicio corrige a ordem natural
 *    da extracao (3, 2, 1 para o numero 123).
 *
 * POR QUE long? O modulo de INT_MIN nao cabe num int assinado.
 * Como nbr e long, podemos mudar o sinal antes de extrair digitos.
 * Caso zero e especial: o laco nbr>0 nao executaria nenhuma vez.
 *
 * EXEMPLO 123: len=3, str[3]='\0'; escreve str[2]='3',
 * str[1]='2', str[0]='1'.
 */

#include "libft.h"

	/* Conta as posicoes de texto necessarias antes da alocacao; por ser static, so e visivel neste arquivo. */
static size_t	count_char(int n)
{
	/* Guarda um comprimento nao negativo; o mesmo tipo sera usado para dimensionar malloc. */
	size_t	len;

	/* Comeca sem contar digitos; cada divisao do numero acrescentara uma posicao. */
	len = 0;
	/* Zero exige um '0'; numero negativo exige um '-' adicional. Ambos precisam de uma posicao especial. */
	if (n <= 0)
	/* Reserva uma posicao para o caractere '0' ou para o sinal negativo '-'. */
		len = 1;
	/* Cada iteracao conta um digito decimal, ate a divisao sucessiva zerar n. */
	while (n != 0)
	{
	/* Remove o ultimo digito na contagem: 123 -> 12 -> 1 -> 0. */
		n = n / 10;
	/* Acrescenta uma posicao para o digito que acabou de ser contado. */
		len++;
	}
	/* Entrega o comprimento da representacao textual, ainda sem incluir o byte '\0'. */
	return (len);
}

char	*ft_itoa(int n)
{
	/* Ponteiro para o novo bloco de memoria que recebera os caracteres. */
	char	*str;
	/* Copia do inteiro em um tipo maior: permite transformar INT_MIN em positivo com seguranca. */
	long	nbr;
	/* Guarda um comprimento nao negativo; o mesmo tipo sera usado para dimensionar malloc. */
	size_t	len;

	/* Preserva o valor de entrada e prepara um numero representavel tambem depois da negacao. */
	nbr = n;
	/* Obtem a quantidade exata de posicoes para sinal e digitos antes de alocar. */
	len = count_char(nbr);
	/* Reserva posicoes para todos os caracteres mais UM byte de terminacao. */
	str = malloc(len + 1);
	/* Se nao ha memoria, nao podemos escrever nela; devolvemos falha imediatamente. */
	if (str == NULL)
	/* Sinaliza falha de alocacao ao chamador. */
		return (NULL);
	/* Fecha a string na ultima posicao reservada, para leitura segura por funcoes de string. */
	str[len] = '\0';
	/* Caso zero: o laco que testa nbr>0 nao preencheria qualquer digito. */
	if (nbr == 0)
	/* Escreve a unica representacao valida do valor zero. */
		str[0] = '0';
	/* Numero negativo: a string precisa de sinal e os digitos devem ser extraidos do valor positivo. */
	if (nbr < 0)
	{
	/* Reserva o primeiro caractere para o sinal, que nao sera sobrescrito pelo laco dos digitos. */
		str[0] = '-';
	/* Converte o modulo para positivo; o tipo long impede overflow de INT_MIN nesse ambiente. */
		nbr = -nbr;
	}
	/* Enquanto houver digitos, extrai o ultimo e grava do fim da string para o inicio. */
	while (nbr > 0)
	{
	/* Recua para a posicao livre anterior ao terminador ou ao ultimo digito gravado. */
		len--;
	/* %10 extrai o ultimo digito numerico (0..9); somar '0' o transforma no caractere ASCII correspondente. */
		str[len] = nbr % 10 + '0';
	/* Descarta o digito ja escrito. Ex.: 123 vira 12, depois 1, depois 0. */
		nbr = nbr / 10;
	}
	/* Devolve o bloco com a nova string; quem chama devera liberar essa memoria mais tarde. */
	return (str);
}
