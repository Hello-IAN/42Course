/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simul.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yomin <yomin@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/18 17:29:43 by yomin             #+#    #+#             */
/*   Updated: 2022/09/18 17:29:44 by yomin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	simulate_swap(t_node *node, int size)
{
	int	cnt;
	int	pivot;
	int	flag;
	int	prev_idx;

	cnt = 0;
	prev_idx = node->idx;
	while (node)
	{
		pivot = 5 + (size / 50);
		flag = 0;
		while (pivot-- > 0 && node)
		{
			if (prev_idx < node->idx)
				flag = 1;
			prev_idx = node->idx;
			node = node->next;
		}
		if (flag == 0)
			++cnt;
	}
	return (cnt);
}

int	get_order(t_deque *a, int size)
{
	int	cnt;

	cnt = simulate_swap(a->head, size);
	if (((double)cnt / (double)(5 + (size / 50)) >= 0.85))
		cnt = 1;
	else
		cnt = 0;
	return (cnt);
}
