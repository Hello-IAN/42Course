.SUFFIXES : .c .o

CC = gcc
CFLAGS = -Wall -Wextra -Werror

NAME = libft.a

SRC = ft_isalpha.c\
		  ft_isdigit.c\
		  ft_isalnum.c\
		  ft_isascii.c\
		  ft_isprint.c\
		  ft_atoi.c\
		  ft_tolower.c\
		  ft_toupper.c\
		  ft_strncmp.c\
		  ft_memcmp.c\
		  ft_bzero.c\
		  ft_putchar_fd.c\
		  ft_putendl_fd.c\
		  ft_putnbr_fd.c\
		  ft_putstr_fd.c\
		  ft_striteri.c\
		  ft_strlcpy.c\
		  ft_strlen.c\
		  ft_strlcat.c\
		  ft_calloc.c\
		  ft_memchr.c\
		  ft_memcpy.c\
		  ft_memmove.c\
		  ft_memset.c\
		  ft_itoa.c\
		  ft_strchr.c\
		  ft_strjoin.c\
		  ft_strmapi.c\
		  ft_strnstr.c\
		  ft_strrchr.c\
		  ft_strtrim.c\
		  ft_substr.c\
		  ft_strdup.c\
		  ft_split.c
BSRC = ft_lstsize.c\
		   ft_lstadd_back.c\
		   ft_lstadd_front.c\
		   ft_lstclear.c\
		   ft_lstdelone.c\
		   ft_lstiter.c\
		   ft_lstlast.c\
		   ft_lstmap.c\
		   ft_lstnew.c
OBJS = $(SRC:.c=.o)
BOBJS = $(BSRC:.c=.o)

all: $(NAME)

bonus:
	@make bonus=1 all

ifdef bonus
$(NAME): $(OBJS) $(BOBJS)
	ar cr $(NAME) $(OBJS) $(BOBJS)
else
$(NAME): $(OBJS)
	ar cr $(NAME) $(OBJS)
endif

clean:
	rm -f $(OBJS) $(BOBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY : all bonus clean fclean re
