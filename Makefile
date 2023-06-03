NAME	=	push_swap
CFLAGS	=	-Wall -Wextra -Werror #-fsanitize=
CC		=	cc
SRC		=	$(wildcard src/*.c)
OBJS_DIR	=	obj
MK		=	mkdir
OBJS		= 	$(patsubst src/%.c, $(OBJS_DIR)/%.o, $(SRC))

.PHONY	:	all clean fclean re

all : $(NAME)

$(OBJS_DIR)/%.o : ./src/%.c | $(OBJS_DIR)
		@$(CC) $(CFLAGS) -c $< -o $@

$(NAME) : $(OBJS)
		@$(CC) $(CFLAGS) $(OBJS) -o $(NAME)
		@echo COMPILED

$(OBJS_DIR) :
		@$(MK) -p $(OBJS_DIR)

clean :
		@rm -rf $(OBJS)

fclean : clean
		@rm -rf $(NAME)
		@rm -rf $(OBJS_DIR)

re : clean fclean clean_obj_dir all

# test:	$(NAME)
# 		$(eval ARG = $(shell jot -r 10000 0 200000000))
# 		./push_swap $(ARG) | ./checker $(ARG)
# 		@echo -n "Instructions: "
# 		@./push_swap $(ARG) | wc -l
# test_my:	$(NAME)    $(BONUS_NAME)
#                 $(eval ARG = $(shell jot -r 500 0 2000000))
#                 ./push_swap $(ARG) | ./checker $(ARG)
#                 @echo -n "Instructions: "
#                 @./push_swap $(ARG) | wc -l
# ./