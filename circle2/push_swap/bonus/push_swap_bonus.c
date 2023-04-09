/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yomin <yomin@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/18 17:14:31 by yomin             #+#    #+#             */
/*   Updated: 2022/09/18 17:14:32 by yomin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

static int	check_sort(t_deque *a)
{
	t_node	*node;
	int		prev_idx;

	if (a->size == 1)
		return (TRUE);
	prev_idx = a->head->idx;
	node = a->head->next;
	while (node)
	{
		if (prev_idx > node->idx)
			return (FALSE);
		prev_idx = node->idx;
		node = node->next;
	}
	return (TRUE);
}

t_deque	*init_parse(char *argv[], t_deque *deque_a)
{
	char	*str_tmp;
	char	**values;
	int		*arr_tmp;
	t_deque	*deck;

	str_tmp = add_str_all((const char **)argv);
	if (!str_tmp)
		return (FALSE);
	values = ft_split(str_tmp, ' ');
	if (!values)
		return (FALSE);
	deque_a = create_deque();
	if (!deque_a)
		return (FALSE);
	deck = deque_a;
	deque_a = input_values_a(values, deck);
	arr_tmp = make_idex(deque_a);
	if (!arr_tmp)
	{
		free_values(str_tmp, values, deque_a);
		return (FALSE);
	}
	match_idx(deque_a, arr_tmp);
	free_values(str_tmp, values, NULL);
	return (deque_a);
}

int	main(int argc, char *argv[])
{
	t_deque	*deque_a;
	t_deque	*deque_b;
	char	*cmd;

	if (argc < 2)
		return (0);
	deque_a = 0;
	deque_a = init_parse(argv, deque_a);
	if (!deque_a)
		print_error("Error\n");
	deque_b = create_deque();
	cmd = get_next_line(STDIN);
	while (cmd)
	{
		calling_op(cmd, deque_a, deque_b);
		free(cmd);
		cmd = get_next_line(STDIN_FILENO);
	}
	if (check_sort(deque_a) == TRUE)
		write(STDOUT, "OK\n", 3);
	else
		write(STDOUT, "KO\n", 3);
	free_values(NULL, NULL, deque_a);
	free_values(NULL, NULL, deque_b);
	return (0);
}
