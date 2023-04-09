/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   watch.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yomin <yomin@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/18 17:29:52 by yomin             #+#    #+#             */
/*   Updated: 2022/09/18 17:29:53 by yomin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	find_way(t_deque *b, int next_idx)
{
	int		cnt;
	t_node	*node;

	cnt = 0;
	node = b->head;
	while (node && (node->idx != (next_idx - 1)))
	{
		node = node->next;
		++cnt;
	}
	return (cnt);
}

void	search_target(t_deque *a, t_deque *b, int size)
{
	int	cnt;

	cnt = find_way(b, size);
	if (cnt > (size / 2))
	{
		cnt = size - cnt;
		while (cnt-- > 0)
			rrot_b(b);
		push_a(a, b);
	}
	else if ((-1 < cnt) && (cnt <= (size / 2)))
	{
		while (cnt-- > 0)
			rot_b(b);
		push_a(a, b);
	}
}

void	b_to_a(t_deque *a, t_deque *b)
{
	int	length;

	length = b->size;
	while (b->head)
	{
		search_target(a, b, length--);
	}
}

void	a_to_b(t_deque *a, t_deque *b, int size)
{
	const int	pivot = ((0.000000053 * (size * size)) + (0.03 * size) + 14.5);
	t_order		order;
	int			min;

	min = 0;
	order = get_order(a, a->size);
	while (a->head)
	{
		if (a->head->idx <= min)
		{
			push_b(a, b);
			min++;
		}
		else if (a->head->idx > min && a->head->idx <= min + pivot)
		{
			push_b(a, b);
			rot_b(b);
			min++;
		}
		else if (a->head->idx > (min + pivot) && order == ASC)
			rot_a(a);
		else if (a->head->idx > (min + pivot) && order == DEC)
			rrot_a(a);
	}
}
