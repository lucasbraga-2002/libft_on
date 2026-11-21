/* ************************************************************************** */

/*
** FICHA DIDATICA: ft_striteri
** OBJETIVO: Aplicar funcao f a cada caractere existente de uma string, sem criar copia.
** ESTRATEGIA: Passa o endereco &s[i], permitindo que callback altere diretamente a string, e avanca indice ate NUL.
** COMO DEFENDER: Defesa: diferenca entre f(i,s[i]) e f(i,&s[i]); esta funcao retorna void.
** O codigo original foi mantido; somente comentarios didaticos foram inseridos.
*/

/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striteri.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbraga-m <lbraga-m@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/18 20:25:03 by lbraga-m          #+#    #+#             */
/*   Updated: 2026/11/18 20:43:49 by lbraga-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

	/* Entrada e saida do algoritmo: os tipos mostram se retorna endereco, numero ou nada. */
void	ft_striteri(char *s, void (*f)(unsigned int, char *))
{
	/* Variavel local: determine se armazena tamanho, posicao ou endereco. */
	unsigned int	i;

	/* Comeca contador ou indice do zero. */
	i = 0;
	/* Laco: acompanhe o estado inicial, a condicao de parada e o avanco para provar que termina. */
	while (s[i] != '\0')
	{
	/* Callback recebe indice e caractere/endereco conforme a assinatura; compare map e iter. */
		f(i, &s[i]);
	/* Avanca/regride no intervalo: assegura progresso do algoritmo. */
		i++;
	}
}

/* #include <stdio.h>

static void	transform(unsigned int i, char *c)
{
	*c = *c + i;
}

int	main(void)
{
	char	str[] = "ABC";

	ft_striteri(str, transform);
	printf("Resultado: %s\n", str);
	return (0);
} */