NAME = push_swap

SRC = parsing.c/
		

OBJ = $(SRC:%.c=$(OBJ_DIR)/%.o)
OBJ_BONUS = $(SRC_BONUS:%.c=$(OBJ_DIR)/%.o)
OBJ_DIR = Obj
CC = cc
CFLAGS = -g -Wall -Wextra -Werror
AR = ar -rcs

all : $(NAME)

$(NAME) : $(OBJ)
	$(AR) $(NAME) $(OBJ)

$(OBJ_DIR)/%.o:%.c | $(OBJ_DIR)
	$(CC) $(CFLAGS) -c $< -o $@

$(OBJ_DIR) :
	mkdir -p $(OBJ_DIR)

bonus : $(OBJ_BONUS)
	ar rcs $(NAME) $(OBJ_BONUS)

test :
	make && $(CC) $(CFLAGS) main.c libft.a && ./a.out
	
clean :
	rm -rf $(OBJ_DIR) $(OBJ_BONUS)

fclean : clean
	rm -f $(NAME) 

re: fclean all

.PHONY : all clean fclean re bonus test