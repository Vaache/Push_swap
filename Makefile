NAME	=	push_swap
CFLAGS	=	-Wall -Wextra -Werror #-fsanitize=
CC		=	cc
SRC		=	./src/main.c\
				./src/ft_split.c\
				./src/fill_nodes.c\
				./src/pars.c\
				./src/pars2.c\
				./src/utils.c\
				./src/panic.c\
				./src/list_swap.c\
				./src/list_push.c\
				./src/list_rotate.c\
				./src/list_revers_rotate.c\
				./src/counter.c\
				./src/alghorithm.c\
				./src/butterfly.c\
				./src/ft_free.c

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


#test:	$(NAME)
#		$(eval ARG = $(shell jot -r 500 0 200000000))
#		./push_swap $(ARG) | ./checker $(ARG)
#		@echo -n "Instructions: "
#		@./push_swap $(ARG) | wc -l
# test_my:	$(NAME)    $(BONUS_NAME)
#                 $(eval ARG = $(shell jot -r 500 0 2000000))
#                 ./push_swap $(ARG) | ./checker $(ARG)
#                 @echo -n "Instructions: "
#                 @./push_swap $(ARG) | wc -l
# ./
