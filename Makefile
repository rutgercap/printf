NAME		=	output

SRCS		=	main.c\
				libft/libft.a\
				ft_printf/libftprintf.a

ifdef WITH_SAN
CFLAGS		= 	-Wall -Wextra -fsanitize=address -g
else
CFLAGS		= 	-Wall -Werror -Wextra
endif

all:		libft	printf
	$(CC) $(CFLAGS) $(SRCS) -o $(NAME)

libft:
	libft/make

printf:
	ft_printf/make

printf:
	ft_printf/

norm:
	norminette -R CheckForbiddenSourceHeader