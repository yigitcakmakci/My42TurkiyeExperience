NAME = libftprintf.a

PRINTFSRC = ft_printf/ft_print_char.c ft_printf/ft_print_hex.c ft_printf/ft_print_nbr.c \
ft_printf/ft_print_ptr.c ft_printf/ft_print_str.c ft_printf/ft_printf.c ft_printf/ft_print_unsigned.c

OBJ = $(PRINTFSRC:.c=.o)

all: $(NAME)

CC = cc
CFLAGS = -Wall -Wextra -Werror

$(NAME) : $(OBJ)
	ar rcs $(NAME) $(OBJ)

%.o:%.c ft_prinf.h
	$(CC) $(CFLAGS) -c $< -o $@

clean :
	rm -f $(OBJ)

fclean : clean
	rm -f $(NAME)

re: fclean all

.PHONY :  all clean fclean re