# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mingylee <mingylee@student.42seoul.>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/07/11 14:24:34 by mingylee          #+#    #+#              #
#    Updated: 2023/02/23 16:31:56 by mingylee         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = cc
CFLAGS = -Wall -Wextra -Werror -O3 #-g3 -fsanitize=address
LIB_FLAGS = -l mlx -framework OpenGL -framework Appkit

NAME = miniRT

SRCS = main.c\
	   src/ray.c\
	   src/hit.c\
	   src/cam.c\
	   src/convert.c\
	   src/cylinder_object.c\
	   src/ft_memset.c\
	   src/ft_split.c\
	   src/ft_strrch.c\
	   src/get_next_line.c\
	   src/get_next_line_utils.c\
	   src/get_objects_options_utils.c\
	   src/get_objects_optionsacl.c\
	   src/get_objects_optionsfree.c\
	   src/get_objects_optionsspc.c\
	   src/hit_record.c\
	   src/init_utils.c\
	   src/keyhooks.c\
	   src/light.c\
	   src/make_object.c\
	   src/mlx_window.c\
	   src/operator_vector_1.c\
	   src/operator_vector_2.c\
	   src/operator_vector_3.c\
	   src/object_utils.c\
	   src/parser.c\
	   src/parser_utils.c\
	   src/phong_lighting.c\
	   src/plane_object.c\
	   src/sphere_object.c\
	   src/trace.c



OBJS = $(SRCS:%.c=%.o)
HEADERDIR = ./includes

INCLUDES = -I $(HEADERDIR) -I minilibx_macos -I minilibx_mms_20191025_beta

%.o: %.c
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $(<:.c=.o)

all : $(NAME)

$(NAME) : $(OBJS)
	$(CC) $(CFLAGS) $(INCLUDES) $(LIB_FLAGS) $(OBJS) -o $(NAME)

clean :
	rm -rf $(OBJS)

fclean : clean
	rm -rf $(NAME)

re : fclean
	$(MAKE) all

.PHONY : all clean fclean re bonus
