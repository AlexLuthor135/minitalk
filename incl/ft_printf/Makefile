SRCS			=	ft_printf_s.c ft_printf_c.c ft_printf_d.c\
					ft_printf_p.c ft_printf_prc.c ft_printf_u.c\
					ft_printf_u.c ft_printf_x.c ft_printf_x2.c\
					ft_printf.c


OBJS	=	${SRCS:.c=.o}

CC				= gcc
RM				= rm -f
CFLAGS			= -Wall -Wextra -Werror -I.

NAME			= libftprintf.a

all:			$(NAME)

$(NAME):  $(OBJS)
				ar rcs $@ $^

clean:
				$(RM) $(OBJS)

fclean:			clean
				$(RM) $(NAME)

re:				fclean $(NAME)

.PHONY:			all clean fclean re