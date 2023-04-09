/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operation_swap_ss.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yomin <yomin@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/18 17:29:38 by yomin             #+#    #+#             */
/*   Updated: 2022/09/18 17:29:40 by yomin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	_swap_a(t_deque *a)
{
	t_node	*tmp_head;
	t_node	*tmp_node;

	tmp_head = a->head;
	if (!tmp_head || !tmp_head->next)
	{
		write(2, "stack has a few value\n", 22);
		return ;
	}
	tmp_node = tmp_head->next;
	tmp_head->next = tmp_node->next;
	insert_head(a, tmp_node);
	if (tmp_head->next)
		tmp_head->next->prev = tmp_head;
}

static void	_swap_b(t_deque *b)
{
	t_node	*tmp_head;
	t_node	*tmp_node;

	tmp_head = b->head;
	if (!tmp_head || !tmp_head->next)
	{
		write(2, "stack has a few value\n", 22);
		return ;
	}
	tmp_node = tmp_head->next;
	tmp_head->next = tmp_node->next;
	insert_head(b, tmp_node);
	if (tmp_head->next)
		tmp_head->next->prev = tmp_head;
}

int	swap_ss(t_deque *a, t_deque *b)
{
	if (!a->head || !a->head->next || \
	!b->head || !b->head->next)
	{
		write(2, "stack has a few value\n", 22);
		return (1);
	}
	_swap_a(a);
	_swap_b(b);
	write(1, "ss\n", 3);
	return (0);
}
