CC = cc
CFLAGS = -Wall -Wextra -Werror
RM = rm -f

#output file names
NAME_CLIENT = client
NAME_SERVER = server
NAME_CLIENT_BONUS = client_bonus
NAME_SERVER_BONUS = server_bonus

#Mandatory source
FILES_CLIENT = client.c
SRCS_CLIENT = $(FILES_CLIENT)
OBJS_CLIENT = $(SRCS_CLIENT:.c=.o)
FILES_SERVER = server.c
SRCS_SERVER = $(FILES_SERVER)
OBJS_SERVER = $(SRCS_SERVER:.c=.o)

#Bonus source
FILES_CLIENT_BONUS = client_bonus.c
SRCS_CLIENT_BONUS = $(FILES_CLIENT_BONUS)
OBJS_CLIENT_BONUS = $(SRCS_CLIENT_BONUS:.c=.o)
FILES_SERVER_BONUS = server_bonus.c
SRCS_SERVER_BONUS = $(FILES_SERVER_BONUS)
OBJS_SERVER_BONUS = $(SRCS_SERVER_BONUS:.c=.o)
HEADER = server.h
HEADER_BONUS = server_bonus.h

.PHONY: all clean fclean re bonus

all: $(NAME_CLIENT) $(NAME_SERVER)

$(NAME_CLIENT): $(OBJS_CLIENT)
	@echo --------------------------------
	@echo $@ Making...
	$(CC) $(CFLAGS) $(SRCS_CLIENT) -o $(NAME_CLIENT)

$(NAME_SERVER): $(OBJS_SERVER)
	@echo --------------------------------
	@echo $@ Making...
	$(CC) $(CFLAGS) $(SRCS_SERVER) -I$(HEADER) -o $(NAME_SERVER)

bonus: $(NAME_CLIENT_BONUS) $(NAME_SERVER_BONUS)

$(NAME_CLIENT_BONUS): $(OBJS_CLIENT_BONUS)
	@echo --------------------------------
	@echo $@ Making...
	$(CC) $(CFLAGS) $(SRCS_CLIENT_BONUS) -o $(NAME_CLIENT_BONUS)

$(NAME_SERVER_BONUS): $(OBJS_SERVER_BONUS)
	@echo --------------------------------
	@echo $@ Making...
	$(CC) $(CFLAGS) $(SRCS_SERVER_BONUS) -I$(HEADER_BONUS) -o $(NAME_SERVER_BONUS)

clean:
	$(RM) $(OBJS_CLIENT) $(OBJS_SERVER) $(OBJS_CLIENT_BONUS) $(OBJS_SERVER_BONUS)

fclean: clean
	$(RM) $(NAME_CLIENT) $(NAME_SERVER) $(NAME_CLIENT_BONUS) $(NAME_SERVER_BONUS)

re:
	make fclean
	make all
