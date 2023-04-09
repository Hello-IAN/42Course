# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: yomin <yomin@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/08/30 18:28:41 by yomin             #+#    #+#              #
#    Updated: 2022/08/30 18:29:22 by yomin            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = cc
CFLAGS = -Wall -Wextra -Werror
MLXFLAGS = -Lmlx -lmlx -framework OpenGL -framework AppKit
RM = rm -f

#output file names
NAME_FRACTOL = fractol
NAME_FRACTOL_BONUS = fractol_bonus

#mlx
DIR_MLX = ./mlx
MLX = libmlx.a

#Mandatory source
DIR_SRCS_MANDATORY = ./src
FILES_FRACTOL = fractal.c\
				hook.c\
				julia.c\
				mandel.c\
				set_color.c\
				utils.c
SRCS_FRACTOL = $(addprefix $(DIR_SRCS_MANDATORY)/, $(FILES_FRACTOL))
OBJS_FRACTOL = $(SRCS_FRACTOL:.c=.o)

#Bonus source
DIR_SRCS_BONUS = ./bonus
FILES_FRACTOL_BONUS = fractal_bonus.c\
					hook_bonus.c\
					julia_bonus.c\
					mandel_bonus.c\
					ship_bonus.c\
					utils_bonus.c\
					set_color_bonus.c
SRCS_FRACTOL_BONUS = $(addprefix $(DIR_SRCS_BONUS)/, $(FILES_FRACTOL_BONUS))
OBJS_FRACTOL_BONUS = $(SRCS_FRACTOL_BONUS:.c=.o)

.PHONY: all clean fclean re bonus

all: $(NAME_FRACTOL)

$(NAME_FRACTOL): $(OBJS_FRACTOL)
	@echo --------------------------------
	@echo $@ Making...
	@if [ -e $(MLX) ]; \
		then \
		echo "$(MLX) made already";\
	else \
		make -C $(DIR_MLX) &&\
		cp $(DIR_MLX)/$(MLX) .&&\
		echo "make a mlx completely";\
	fi
	$(CC) $(CFLAGS) $(MLXFLAGS) $(SRCS_FRACTOL) -I. -o $(NAME_FRACTOL)

bonus: $(NAME_FRACTOL_BONUS)

$(NAME_FRACTOL_BONUS): $(OBJS_FRACTOL_BONUS)
	@echo --------------------------------
	@echo $@ Making...
	@if [ -e $(MLX) ]; \
		then \
		echo "$(MLX) made already";\
	else \
		make -C $(DIR_MLX) &&\
		cp $(DIR_MLX)/$(MLX) .&&\
		echo "make a mlx completely";\
	fi
	$(CC) $(CFLAGS) $(MLXFLAGS) $(SRCS_FRACTOL_BONUS) -I. -o $(NAME_FRACTOL_BONUS)

clean:
	make clean -C $(DIR_MLX)
	$(RM) $(OBJS_FRACTOL) $(OBJS_FRACTOL_BONUS)

fclean: clean
	$(RM) $(MLX)
	$(RM) $(NAME_FRACTOL) $(NAME_FRACTOL_BONUS)

re:
	make fclean
	make all
