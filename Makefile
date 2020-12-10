NAME		=	output

SRCS		=	main.c\
				ft_printf/libftprintf.a\
				ft_printf/libft/libft.a

DEBUG_SRCS	=	main.c\
				ft_printf/*.c\
				ft_printf/libft/src/*.c\

ifdef WITH_SAN
CFLAGS		= 	-Wall -Wextra -fsanitize=address -g
else
CFLAGS		= 	-Wall -Wextra -fsanitize=address -g
endif

all:	libft printf
	$(CC) $(CFLAGS) $(SRCS) -o $(NAME)
	$(MAKE) run

debug:
	$(CC) $(CFLAGS) $(DEBUG_SRCS) -o $(NAME)
	lldb $(NAME)

run:
	./$(NAME)

re:
	cd ft_printf/libft && make re
	cd ft_printf/ && make re
	rm $(NAME)

libft:
	cd ft_printf/libft && make

printf:
	cd ft_printf/ && make

norm:
	norminette -R CheckForbiddenSourceHeader