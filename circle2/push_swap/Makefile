CC = cc
CFLAGS = -Wall -Wextra -Werror
RM = rm -f

#output file names
NAME = push_swap
NAME_BONUS = checker

#Mandatory source
DIR_SRCS_MANDATORY = ./src
FILES_PUSH_SWAP = deque.c\
				ft_split.c\
				ft_str.c\
				index.c\
				matching.c\
				operation_push.c\
				operation_rot_rr.c\
				operation_rot.c\
				operation_rrot.c\
				operation_swap_ss.c\
				operation_swap.c\
				push_swap.c\
				simul.c\
				sorting.c\
				utils.c\
				watch.c
SRCS_PUSH_SWAP = $(addprefix $(DIR_SRCS_MANDATORY)/, $(FILES_PUSH_SWAP))
OBJS_PUSH_SWAP = $(SRCS_PUSH_SWAP:.c=.o)

#Bonus source
DIR_SRCS_BONUS = ./bonus
FILES_PUSH_SWAP_BONUS = deque_bonus.c\
					fp_bonus.c\
					ft_split_bonus.c\
					ft_str_bonus.c\
					gnl_bonus.c\
					gnl_utils_bonus.c\
					index_bonus.c\
					matching_bonus.c\
					operation_push_bonus.c\
					operation_rot_bonus.c\
					operation_rrot_bonus.c\
					operation_swap_bonus.c\
					push_swap_bonus.c\
					utils_bonus.c
SRCS_PUSH_SWAP_BONUS = $(addprefix $(DIR_SRCS_BONUS)/, $(FILES_PUSH_SWAP_BONUS))
OBJS_PUSH_SWAP_BONUS = $(SRCS_PUSH_SWAP_BONUS:.c=.o)

.PHONY: all clean fclean re bonus

all: $(NAME)

$(NAME): $(OBJS_PUSH_SWAP)
	@echo --------------------------------
	@echo $@ Making...
	$(CC) $(CFLAGS) $(SRCS_PUSH_SWAP) -I. -o $(NAME)

bonus: $(NAME_BONUS)

$(NAME_BONUS): $(OBJS_PUSH_SWAP_BONUS)
	@echo --------------------------------
	@echo $@ Making...
	$(CC) $(CFLAGS) $(MLXFLAGS) $(SRCS_PUSH_SWAP_BONUS) -I. -o $(NAME_BONUS)

clean:
	$(RM) $(OBJS_PUSH_SWAP) $(OBJS_PUSH_SWAP_BONUS)

fclean: clean
	$(RM) $(NAME) $(NAME_BONUS)

re:
	make fclean
	make all