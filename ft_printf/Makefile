NAME		=	libftprintf.a

SRCS		=	ft_printf.c\
				arghandlers.c
SRC_OBJS	=	$(SRCS:.c=.o)

HEADER		=	ft_printf.h 

LIBFT		=	/libft/libft.a	## weghalen? ## check hoe deze makefile checkt of libft up to date is

AR			=	ar -rcs

ifdef WITH_SAN
CFLAGS		= 	-Wall -Wextra -fsanitize=address -g
else
CFLAGS		= 	-Wall -Wextra #Werror
endif

all:		$(NAME)
$(NAME):	$(SRC_OBJS)
			$(AR) $(NAME) $(SRC_OBJS)

%.o: %.c
	$(CC) -c $(CFLAGS) -o $@ $<

clean:
	rm -f $(OBJ_FILES) $(TEST_FILE)

san:
	$(MAKE) WITH_SAN=1 all

fclean: clean
	rm -f $(NAME)

re:	fclean all

phony:
	all clean fclean re