.SUFFIXES : .c .o

CC = gcc
CFLAGS = -Wall -Wextra -Werror

NAME = libftprintf.a

SRC = ft_printf.c\
	  find_form.c\
	  p_put_addr.c\
	  p_put_char.c\
	  p_put_hex.c\
	  p_put_nbr.c\
	  p_put_str.c
OBJS = $(SRC:.c=.o)

all: $(NAME)

$(NAME): $(OBJS)
	ar cr $(NAME) $(OBJS)

clean:
	rm -f $(OBJS) $(BOBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY : all bonus clean fclean re
