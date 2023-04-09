# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: yomin <yomin@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/11/23 16:59:06 by yomin             #+#    #+#              #
#    Updated: 2022/11/23 16:59:08 by yomin            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = cc
CFLAGS = -Wall -Wextra -Werror -g3
RM = rm -f

#output file names
NAME = philo

#Mandatory source
DIR_SRCS_MANDATORY = ./src
FILES_PHILO = action.c\
				check.c\
				free.c\
				gen.c\
				philo.c\
				print.c\
				time.c\
				utils.c
SRCS_PHILO = $(addprefix $(DIR_SRCS_MANDATORY)/, $(FILES_PHILO))
OBJS_PHILO = $(SRCS_PHILO:.c=.o)



.PHONY: all clean fclean re bonus

all: $(NAME)

$(NAME): $(OBJS_PHILO)
	@echo --------------------------------
	@echo $@ Making...
	$(CC) $(CFLAGS) $(SRCS_PHILO) -I. -o $(NAME)

clean:
	$(RM) $(OBJS_PHILO)

fclean: clean
	$(RM) $(NAME)

re:
	make fclean
	make all
