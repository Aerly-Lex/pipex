NAME = libftprintf.a

CC = cc

CFLAGS = -Wall -Werror -Wextra

SRC =	ft_printf.c \
		ft_putnbr_i_d.c \
		ft_putnbr_p.c \
		ft_putnbr_u.c

OBJ = $(SRC:.c=.o)

%.o: %.c
	@$(CC) $(CFLAGS) -c $<

all: $(NAME)

$(NAME): $(OBJ)
	ar rcs $(NAME) $(OBJ)

clean:
	@rm -f *.o

fclean: clean
	@rm -f $(NAME)
	@echo $(NAME) deleted

re: fclean all
