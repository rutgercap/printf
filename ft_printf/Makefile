NAME		=	libftprintf.a

SRCS		=	ft_printf.c\
				flaghandlers.c\
				conversions.c\
				formatting.c\
				utilities.c
SRC_OBJS	=	$(SRCS:.c=.o)

HEADER		=	ft_printf.h 

LIBFT		=	libft/libft.a	## weghalen? ## check hoe deze makefile checkt of libft up to date is

AR			=	ar -rcs

CFLAGS		= 	-Wall -Wextra -Werror


all:		$(NAME)
$(NAME):	$(SRC_OBJS)
			$(MAKE) -C libft
			cp $(LIBFT) $(NAME)
			$(AR) $(NAME) $(SRC_OBJS)

%.o: %.c
	$(CC) -c $(CFLAGS) -o $@ $<

clean:
	rm -f $(SRC_OBJS)

san:
	$(MAKE) WITH_SAN=1 all

fclean: clean
	rm -f $(NAME)

libft:
		$(MAKE) -C libft
		cp $(LIBFT) $(NAME)

re:	fclean all

phony:
	all clean fclean re