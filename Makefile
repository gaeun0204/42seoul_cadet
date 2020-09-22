NAME = libftprintf.a

SRCS = ft_printf.c \
		case_pct.c \
		case_c.c \
		case_s.c \
		case_p.c \
		case_di.c \
		case_ux.c \
		libft_utils.c \
		other_utils.c \
		parsing.c

OBJS = $(SRCS:%.c=%.o)

CFLAGS = -Wall -Wextra -Werror

$(NAME) : $(OBJS)
	ar rc $@ $^

%.o: %.c
	gcc $(CFLAGS) -c -o $@ $<

all : $(NAME)

clean :
	rm -f $(OBJS)

fclean : clean
	rm -f $(NAME)

re : fclean all

.PHONY : all clean fclean re
