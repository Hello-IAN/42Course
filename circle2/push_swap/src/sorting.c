/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yomin <yomin@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/18 17:29:46 by yomin             #+#    #+#             */
/*   Updated: 2022/09/18 17:29:47 by yomin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	_search_target(t_deque *a, t_deque *b, int size)
{
	int	cnt;

	cnt = find_way(a, size);
	if (cnt > (size / 2))
	{
		cnt = size - cnt;
		while (cnt-- > 0)
			rrot_a(a);
		push_b(a, b);
	}
	else if ((-1 < cnt) && (cnt <= (size / 2)))
	{
		while (cnt-- > 0)
			rot_a(a);
		push_b(a, b);
	}
}

void	sort_in_five(t_deque *a, t_deque *b)
{
	int	size;

	size = a->size;
	if (size == 4)
	{
		_search_target(a, b, a->size);
		_search_target(a, b, a->size - 1);
		sort_in_two(a);
		push_a(a, b);
		rot_a(a);
		push_a(a, b);
		rot_a(a);
	}
	if (size == 5)
	{
		_search_target(a, b, a->size);
		_search_target(a, b, a->size - 1);
		sort_in_three(a);
		push_a(a, b);
		rot_a(a);
		push_a(a, b);
		rot_a(a);
	}
}

int	sort_in_two(t_deque *a)
{
	if (a->head->idx > a->head->next->idx)
		return (swap_a(a));
	return (0);
}

int	sort_in_three(t_deque *a)
{
	if (a->head->idx > a->head->next->idx && \
		a->head->next->idx > a->tail->idx)
		return (swap_a(a) || rrot_a(a));
	else if (a->head->idx > a->tail->idx && \
			a->tail->idx > a->head->next->idx)
		return (rot_a(a));
	else if (a->tail->idx > a->head->idx && \
			a->head->idx > a->head->next->idx)
		return (swap_a(a));
	else if (a->head->next->idx > a->head->idx && \
			a->head->idx > a->tail->idx)
		return (rrot_a(a));
	else if (a->head->next->idx > a->tail->idx && \
			a->tail->idx > a->head->idx)
		return (swap_a(a) || rot_a(a));
	return (0);
}

void	search_size(t_deque *a, t_deque *b)
{
	if (a->size == 2)
		sort_in_two(a);
	else if (a->size == 3)
		sort_in_three(a);
	else if (a->size == 4 || a->size == 5)
		sort_in_five(a, b);
}
