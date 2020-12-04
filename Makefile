NAME		=	output

SRCS		=	main.c\
				ft_printf/libftprintf.a\
				ft_printf/libft/libft.a

ifdef WITH_SAN
CFLAGS		= 	-Wall -Wextra -fsanitize=address -g
else
CFLAGS		= 	-Wall -Werror -Wextra
endif

all:	libft printf
	$(CC) $(CFLAGS) $(SRCS) -o $(NAME)
	$(MAKE) run

run:
	./$(NAME)

libft:
	cd ft_printf/libft && make

printf:
	cd ft_printf/ && make

norm:
	norminette -R CheckForbiddenSourceHeader