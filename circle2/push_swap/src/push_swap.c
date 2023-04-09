/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yomin <yomin@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/18 17:29:41 by yomin             #+#    #+#             */
/*   Updated: 2022/09/18 17:29:42 by yomin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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

	if (argc <= 2)
		return (0);
	deque_a = 0;
	deque_a = init_parse(argv, deque_a);
	if (!deque_a)
		print_error("failed to make deque\n");
	deque_b = create_deque();
	deque_b->size = deque_a->size;
	if (deque_a->size <= 5)
		search_size(deque_a, deque_b);
	else
	{
		a_to_b(deque_a, deque_b, deque_a->size);
		b_to_a(deque_a, deque_b);
	}
	free(deque_b);
	return (0);
}
