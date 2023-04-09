/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_bonus.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yomin <yomin@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/18 17:15:17 by yomin             #+#    #+#             */
/*   Updated: 2022/09/18 17:15:18 by yomin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_BONUS_H
# define PUSH_SWAP_BONUS_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1
# endif

# define TRUE 1
# define FALSE 0
# define ERROR -1
# define STDIN 0
# define STDOUT 1
# define STDERR 2

# include <stdlib.h>
# include <unistd.h>

typedef struct s_node
{
	int				data;
	int				idx;
	struct s_node	*prev;
	struct s_node	*next;
}	t_node;

typedef struct s_deque
{
	int				size;
	struct s_node	*head;
	struct s_node	*tail;
}	t_deque;

typedef struct s_lst
{
	char			data[BUFFER_SIZE];
	int				data_len;
	int				flag;
	struct s_lst	*next;
}	t_lst;

t_node	*make_node(int value);
t_deque	*create_deque(void);
t_deque	*input_values_a(char **values, t_deque *deque);
t_lst	*clear_lst(t_lst *lst);
t_lst	*reset_lst(t_lst *lst);
t_lst	*make_new_lst(int fd);
char	**ft_split(char const *s, char c);
char	*get_total_buf(t_lst *lst);
char	*add_str_all(const char **argv);
char	*cpy_string(t_lst *lst);
char	*get_next_line(int fd);
int		find_nl(const char *buf, int size);
int		reset_buf(char *buf, const char *src, int size);
int		ft_atoi(const char *nptr);
int		get_size(t_deque *deque);
int		swap_a(t_deque *a);
int		swap_b(t_deque *b);
int		swap_ss(t_deque *a, t_deque *b);
int		push_a(t_deque *a, t_deque *b);
int		push_b(t_deque *a, t_deque *b);
int		rot_a(t_deque *a);
int		rot_b(t_deque *b);
int		rot_rr(t_deque *a, t_deque *b);
int		rrot_a(t_deque *a);
int		rrot_b(t_deque *b);
int		rrot_rr(t_deque *a, t_deque *b);
int		*make_idex(t_deque *deque);
int		case_rot(char *str, t_deque *a, t_deque *b);
int		select_func(char *str, t_deque *a, t_deque *b);
int		calling_op(char *str, t_deque *a, t_deque *b);
void	insert_head(t_deque *deque, t_node *node);
void	insert_tail(t_deque *deque, t_node *node);
void	ft_swap(int *i, int *j);
void	sort_arr(int *arr, int size);
void	match_idx(t_deque *deque, int *arr);
void	free_values(char *s1, char **s2, t_deque *deque);
void	print_error(const char *str);

#endif
