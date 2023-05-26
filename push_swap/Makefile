NAME	=	push_swap
CFLAGS	=	-Wall -Wextra -Werror
CC		=	cc
SRC		=	main.c\
				ft_split.c\
				fill_nodes.c\
				pars.c\
				pars2.c\
				utils.c

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