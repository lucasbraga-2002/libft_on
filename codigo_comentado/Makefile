# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lbraga-m <lbraga-m@student.42porto.com>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2026/11/06 18:53:59 by lbraga-m          #+#    #+#              #
#    Updated: 2026/11/20 19:15:34 by lbraga-m         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# GUIA DE ESTUDO - Makefile
# NAME indica o arquivo final: biblioteca estatica de objetos .o.
# SRCS enumera os arquivos .c; OBJS transforma os sufixos com substituicao.
# A regra %.o: %.c libft.h recompila o objeto quando codigo ou header mudam.
# AR junta os objetos no arquivo .a; a biblioteca e ligada ao programa final.
# OBSERVACAO: este Makefile e uma copia fiel da branch privada, nao uma
# certificacao de conformidade do alvo bonus ao subject. Revisar na entrega.

NAME = libft.a

CC = cc
CFLAGS = -Wall -Wextra -Werror
AR = ar rcs

SRCS = ft_isalpha.c ft_isdigit.c ft_isalnum.c ft_isascii.c \
       ft_isprint.c ft_strlen.c ft_memset.c ft_bzero.c \
       ft_memcpy.c ft_memmove.c ft_toupper.c ft_tolower.c \
	   ft_strchr.c ft_strrchr.c ft_strncmp.c ft_memchr.c \
	   ft_strlcpy.c ft_memcmp.c ft_strnstr.c ft_strlcat.c \
	   ft_atoi.c ft_calloc.c ft_strdup.c ft_substr.c \
	   ft_strjoin.c ft_strtrim.c ft_split.c ft_itoa.c \
	   ft_strmapi.c ft_striteri.c ft_putchar_fd.c \
	   ft_putstr_fd.c ft_putendl_fd.c ft_putnbr_fd.c \
	   ft_lstnew.c ft_lstadd_front.c ft_lstsize.c \
	   ft_lstlast.c ft_lstadd_back.c ft_lstdelone.c \
	   ft_lstclear.c ft_lstiter.c ft_lstmap.c

OBJS = $(SRCS:.c=.o)

bonus: $(NAME)

all: $(NAME)

%.o: %.c libft.h
	$(CC) $(CFLAGS) -c $< -o $@

$(NAME): $(OBJS)
	$(AR) $(NAME) $(OBJS)

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re