# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mchaarou <mchaarou@student.1337.ma>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2026/11/20 00:23:45 by mchaarou          #+#    #+#              #
#    Updated: 2026/11/20 00:23:47 by mchaarou         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME =	libftprintf.a
SRC = ft_printf.c ft_putnbr_base.c tools.c
OBJS = $(SRC:.c=.o)
HEADER = ft_printf.h

CC = cc
RM = rm -f
CFLAGS = -Wall -Wextra -Werror

%.o: %.c $(HEADER)
	$(CC) $(CFLAGS) -c $< -o $@

all: $(NAME)

$(NAME): $(OBJS)
	@ar rcs $(NAME) $^

clean:
	@$(RM) $(OBJS)

fclean: clean
	@$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re
