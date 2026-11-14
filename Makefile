NAME =	ftprintf.a
SRC = ft_printf.c ft_putnbr_base.c tools.c
OBJS = $(SRC:.c=.o)

CC = cc
RM = rm -f
CFLAGS = -Wall -Wextra -Werror

%.o: %.c
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
