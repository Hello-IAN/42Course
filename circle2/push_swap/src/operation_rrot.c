/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operation_rrot.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yomin <yomin@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/18 17:29:28 by yomin             #+#    #+#             */
/*   Updated: 2022/09/18 17:29:30 by yomin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	rrot_a(t_deque *a)
{
	t_node	*tmp_head;

	tmp_head = a->tail;
	if (!a->head)
	{
		write(2, "stack has a few value\n", 22);
		return (1);
	}
	if (tmp_head->prev == NULL)
		return (0);
	a->tail = tmp_head->prev;
	tmp_head->prev = NULL;
	a->tail->next = NULL;
	insert_head(a, tmp_head);
	write(1, "rra\n", 4);
	return (0);
}

int	rrot_b(t_deque *b)
{
	t_node	*tmp_head;

	tmp_head = b->tail;
	if (!b->head)
	{
		write(2, "stack has a few value\n", 22);
		return (1);
	}
	if (tmp_head->prev == NULL)
		return (0);
	b->tail = tmp_head->prev;
	tmp_head->prev = NULL;
	b->tail->next = NULL;
	insert_head(b, tmp_head);
	write(1, "rrb\n", 4);
	return (0);
}
