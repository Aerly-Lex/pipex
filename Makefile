NAME	:= pipex

NAME_BONUS := pipex_bonus

CC		:= gcc

FLAGS	:= -Wall -Wextra -Werror #-fsanitize=address -g

SRC		:= pipex.c ft_error.c pipex_utils.c

SRC_BONUS	:= pipex_bonus.c ft_error.c pipex_utils.c

PRINTF	:= ft_printf

LIBFT	:= libft

OBJ		:= $(SRC:.c=.o)

OBJ_BONUS	:= $(SRC_BONUS:.c=.o)

%.o: %.c
	@$(CC) $(FLAGS) -c $< -o $@

all: $(NAME)

$(NAME): $(OBJ)
	$(MAKE) -C $(LIBFT)
	$(MAKE) -C $(PRINTF)
	$(CC) $(FLAGS) $(OBJ) -o $(NAME) -L$(LIBFT) -lft -L$(PRINTF) -lftprintf

#$(BONUS):
bonus: $(OBJ_BONUS)
	$(MAKE) -C $(LIBFT)
	$(MAKE) -C $(PRINTF)
	$(CC) $(FLAGS) $(OBJ_BONUS) -o $(NAME_BONUS) -L$(LIBFT) -lft -L$(PRINTF) -lftprintf

clean:
	$(MAKE) -C $(LIBFT) clean
	$(MAKE) -C $(PRINTF) clean
	rm -f $(OBJ) $(OBJ_BONUS)

fclean: clean
	$(MAKE) -C $(LIBFT) fclean
	$(MAKE) -C $(PRINTF) fclean
	rm -f $(NAME) $(NAME_BONUS)

re: fclean all

.PHONY: all, clean, fclean, re, bonus
