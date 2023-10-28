SRCS_CLIENT		=	client.c 
SRCS_SERVER		=	server.c

CC_FLAGS		=	-Wall -Wextra -Werror -g
CC				=	gcc
SRCS_F			=	srcs/
OBJS_F			=	objs/

LIBFT = incl/libft/
PRINTF = incl/ft_printf/

OBJS_CLIENT	=	$(SRCS_CLIENT:.c=.o)
OBJS_SERVER	=	$(SRCS_SERVER:.c=.o)
OBJS_P1		=	$(addprefix $(OBJS_F), $(OBJS_CLIENT))
OBJS_P2		=	$(addprefix $(OBJS_F), $(OBJS_SERVER))
SERVER		= 	server
CLIENT		=	client
NAME		=	$(SERVER) $(CLIENT)

all: $(NAME)

$(OBJS_F)%.o: $(SRCS_F)%.c Makefile client.h server.h
	@mkdir -p $(OBJS_F)
	@echo "Working on: $<"
	@$(CC) $(CC_FLAGS) -O3 -c $< -o $@

$(CLIENT): $(OBJS_P1)
	@$(MAKE) -C $(LIBFT) 
	@$(MAKE) -C $(PRINTF) 
	@$(CC) $(CC_FLAGS) -O3 $(PRINTF)/libftprintf.a $(LIBFT)/libft.a -o $(CLIENT) $(OBJS_P1)
	@echo "OK"

$(SERVER): $(OBJS_P2)
	@$(MAKE) -C $(LIBFT) 
	@$(MAKE) -C $(PRINTF) 
	@$(CC) $(CC_FLAGS) -O3 $(PRINTF)/libftprintf.a $(LIBFT)/libft.a -o $(SERVER) $(OBJS_P2)
	@echo "OK"

clean:
	@rm -rf $(OBJS_F)
	@$(MAKE) fclean -C $(LIBFT) 
	@$(MAKE) fclean -C $(PRINTF) 

fclean:	clean
	@rm -rf $(NAME)

re:		fclean all

.PHONY:	all clean fclean re