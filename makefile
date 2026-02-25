NAME = push_swap

SRC =   main.c \
        disorder.c \
        parsing/parsing.c \
        parsing/free_error.c \
        parsing/ft_split.c \
        parsing/utils1.c \
        parsing/utils2.c \
        indexing/index.c \
        operations/push.c \
        operations/rotate.c \
        operations/rrotate.c \
        operations/swap.c \
        sort/simple_sort.c \
        sort/small_sort.c \
        sort/medium_sort.c \
		sort/complexe_sort.c \
		sort/adaptative_sort.c \
        sort/bench.c \
        ft_printf/ft_printf.c \
        ft_printf/ft_printf_utils.c \
        ft_printf/ft_printf_format.c \

OBJ     = $(SRC:%.c=$(OBJ_DIR)/%.o)
OBJ_DIR = Obj
CC      = cc
CFLAGS  = -Wall -Wextra -Werror -I .

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) -o $(NAME) -lm

$(OBJ_DIR)/%.o: %.c | $(OBJ_DIR)
	@mkdir -p $(dir $@)
	$(CC) $(CFLAGS) -c $< -o $@

$(OBJ_DIR):
	mkdir -p $(OBJ_DIR)

clean:
	rm -rf $(OBJ_DIR)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re