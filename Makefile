SRC = main.c\
			push_swap.c\
			make_list.c\
			util.c\
			util2.c\
			ps_functions1.c\
			ps_functions2.c\
			ps_algo.c\
			ps_flags.c

OBJ = $(SRC:.c=.o)

NAME = push_swap

all: $(NAME)

$(NAME):
			gcc -c $(SRC) -I./libft -Wall -Werror -Wextra
			gcc -o $(NAME) $(OBJ) -L./libft -lft

clean:
		rm -f $(OBJ)

fclean: clean
		rm -f $(NAME)

re: fclean all

me: all clean
