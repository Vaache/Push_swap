
NAME			= push_swap
BONUS			= checker
SRC_DIR 		= src
BONUS_DIR		= bonus
SRCS			= $(wildcard $(SRC_DIR)/*.c)
SRCS_B			= $(wildcard $(BONUS_DIR)/*.c) $(wildcard $(SRC_DIR)/*.c)
MAIN_SRC		= $(filter-out $(SRC_DIR)/main.c, $(SRCS_B))
HEADERS			= $(wildcard inc/*.h)
OBJ_DIR			= obj/main
B_OBJ_DIR		= obj/checker
OBJ_ROOT_DIR	= obj
INCS			= -Iinc
MAIN_OBJS		= $(patsubst $(SRC_DIR)/%.c, $(OBJ_DIR)/%.o, $(SRCS))
B_OBJS			= $(patsubst $(SRC_DIR)/%.c, $(B_OBJ_DIR)/%.o, $(MAIN_SRC))
CC				= cc
RM				= rm -rf
CFLAGS			= -Wall -Wextra -Werror
MK				= mkdir -p

# test :
# 	@echo $(SRCS)
# 	@echo
# 	@echo $(SRCS_B)
# 	@echo
# 	@echo $(MAIN_SRC)

all:			$(OBJ_DIR) $(NAME)

$(OBJ_DIR): $(SRC_DIR)
	$(MK) $(OBJ_DIR)

$(B_OBJ_DIR): $(SRC_DIR)
	$(MK) $(B_OBJ_DIR)

$(OBJ_DIR)/%.o:	$(SRC_DIR)/%.c $(HEADERS)
	$(CC) $(CFLAGS) $(INCS) -c $< -o $@

$(B_OBJ_DIR)/%.o: $(SRC_DIR)/%.c $(HEADERS)
	$(CC) $(CFLAGS) $(INCS) -c $< -o $@

$(NAME):		$(MAIN_OBJS)
				$(CC) $(CFLAGS) $(INCS) -o $(NAME) $(MAIN_OBJS)

bonus: $(B_OBJ_DIR) $(OBJ_DIR) 	$(BONUS)

$(BONUS):	$(B_OBJS)
	$(CC) $(CFLAGS) $(INCS) -o $(BONUS) $(B_OBJS)

clean:			
				$(RM) $(OBJ_ROOT_DIR)

fclean:			clean
				$(RM) $(NAME)
				$(RM) $(BONUS)

re:				fclean all bonus

.PHONY:			all clean fclean re bonus

# test:	$(NAME)
# 		$(eval ARG = $(shell jot -r 5 0 200000000))
# 		./push_swap $(ARG) | ./checker $(ARG)
# 		@echo -n "Instructions: "
# 		@./push_swap $(ARG) | wc -l

# test_my:		$(NAME)	$(BONUS_NAME)
# 				$(eval ARG = $(shell jot -r 500 0 2000000))
# 				./push_swap $(ARG) | ./checker $(ARG)
# 				@echo -n "Instructions: "
# 				@./push_swap $(ARG) | wc -l
#				./push_swap $(ARG)

