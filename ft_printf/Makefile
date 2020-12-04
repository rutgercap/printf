NAME		=	libftprintf.a

SRCS		=	ft_printf.c
SRC_OBJS	=	$(SRCS:.c=.o)

HEADER		=	ft_printf.h 

LIBFT		=	../libft/libft.a	## weghalen?

ar			=	ar -rcs

ifdef WITH_SAN
CFLAGS		= 	-Wall -Wextra -fsanitize=address -g
else
CFLAGS		= 	-Wall -Werror -Wextra
endif

all:		$(NAME)
$(NAME):	$(SRC_OBJS)
			$(AR) $(NAME) $(SRC_OBJS)

%.o: %.c
	$(CC) -c $(CFLAGS) -o $@ $<

clean:
	rm -f $(OBJ_FILES) $(TEST_FILE)

fclean: clean
	rm -f $(NAME)

re:	fclean all

phony:
	libft all