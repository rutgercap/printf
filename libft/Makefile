NAME		=	libft.a

SRCS 		=	src/ft_atoi.c\
				src/ft_putchar_fd.c\
				src/ft_bzero.c\
				src/ft_calloc.c\
				src/ft_isalnum.c\
				src/ft_isalpha.c\
				src/ft_isascii.c\
				src/ft_isdigit.c\
				src/ft_isprint.c\
				src/ft_itoa.c\
				src/ft_memccpy.c\
				src/ft_memchr.c\
				src/ft_memcmp.c\
				src/ft_memcpy.c\
				src/ft_memmove.c\
				src/ft_memset.c\
				src/ft_strncmp.c\
				src/ft_tolower.c\
				src/ft_toupper.c\
				src/ft_strlen.c\
				src/ft_strrchr.c\
				src/ft_strchr.c\
				src/ft_strnstr.c\
				src/ft_strdup.c\
				src/ft_strlcat.c\
				src/ft_strlcpy.c\
				src/ft_split.c\
				src/ft_substr.c\
				src/ft_strjoin.c\
				src/ft_strtrim.c\
				src/ft_strmapi.c\
				src/ft_putstr_fd.c\
				src/ft_putnbr_fd.c\
				src/ft_isspace.c\
				src/ft_putendl_fd.c\
				src/ft_abs.c\
				src/ft_strnlen.c
SRC_OBJS	=	$(SRCS:.c=.o)

HEADER		= 	src/libft.h

AR			=	ar -rcs

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
	rm -f $(SRC_OBJS) $(TEST_FILE)

fclean: clean
	rm -f $(NAME)

test:
	$(CC) $(SRCS) $(TEST_MAIN) $(FLAGS) -o $(TEST_FILE) && ./$(TEST_FILE)
	$(MAKE) fclean

memtest:
	$(MAKE) WITH_SAN=1 WITH_BONUS=1 all test

re:	fclean all

norm:
	norminette -R CheckForbiddenSourceHeader src/*.c

.PHONY:	all clean fclean re memtest norm
