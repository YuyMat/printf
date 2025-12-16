NAME =  libftprintf.a
SRCS = srcs/ft_printf.c srcs/printf_cspdi.c srcs/printf_uxX.c srcs/put_unsigned_nbr.c
OBJS = $(SRCS:.c=.o)
CFLAGS = -Wall -Wextra -Werror -I/include

.PHONY: all clean fclean re

LIBFT_DIR = libft
LIBFT = $(LIBFT_DIR)/libft.a

all: $(NAME)

$(NAME): $(OBJS)
	make -C $(LIBFT_DIR)
	cp $(LIBFT) $(NAME)
	ar rcs $(NAME) $(OBJS)

%.o: %.c
	cc $(CFLAGS) -c $< -o $@

clean:
	make clean -C $(LIBFT_DIR)
	rm -f $(OBJS)

fclean: clean
	make fclean -C $(LIBFT_DIR)
	rm -f $(NAME)

re: fclean all
