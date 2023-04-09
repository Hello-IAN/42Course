/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yomin <yomin@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/18 17:30:00 by yomin             #+#    #+#             */
/*   Updated: 2022/09/18 17:30:17 by yomin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# define TRUE 1
# define FALSE 0

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

typedef enum e_order
{
	ASC = 0,
	DEC = 1
}	t_order;

t_node	*make_node(int value);
t_deque	*create_deque(void);
t_deque	*input_values_a(char **values, t_deque *deque);
char	**ft_split(char const *s, char c);
char	*add_str_all(const char **argv);
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
int		find_way(t_deque *b, int next_idx);
int		sort_in_two(t_deque *a);
int		sort_in_three(t_deque *a);
int		get_order(t_deque *a, int size);
int		*make_idex(t_deque *deque);
void	insert_head(t_deque *deque, t_node *node);
void	insert_tail(t_deque *deque, t_node *node);
void	ft_swap(int *i, int *j);
void	sort_arr(int *arr, int size);
void	match_idx(t_deque *deque, int *arr);
void	b_to_a(t_deque *a, t_deque *b);
void	a_to_b(t_deque *a, t_deque *b, int size);
void	search_target(t_deque *a, t_deque *b, int size);
void	free_values(char *s1, char **s2, t_deque *deque);
void	search_size(t_deque *a, t_deque *b);
void	sort_in_five(t_deque *a, t_deque *b);
void	print_error(const char *str);

#endif
