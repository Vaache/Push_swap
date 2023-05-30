NAME	=	push_swap
CFLAGS	=	-Wall -Wextra -Werror -fsanitize=address
CC		=	cc
SRC		=	main.c\
				ft_split.c\
				fill_nodes.c\
				pars.c\
				pars2.c\
				utils.c\
				panic.c\
				list_swap.c\
				list_push.c\
				list_rotate.c\
				list_revers_rotate.c\
				counter.c\
				alghorithm.c

OBJ			= $(SRC:.c=.o)

.PHONY	:	all clean fclean re

all : $(NAME)

%.o : %.c
	$(CC) $(CFLAGS) -c $< -o $@

$(NAME) : $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) -o $(NAME)

clean :
		rm -rf $(OBJ)

fclean : clean
		rm -rf $(NAME)

re : fclean all