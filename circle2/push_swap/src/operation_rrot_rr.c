/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operation_rrot_rr.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yomin <yomin@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/18 17:29:32 by yomin             #+#    #+#             */
/*   Updated: 2022/09/18 17:29:33 by yomin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	_rrot_a(t_deque *a)
{
	t_node	*tmp_head;

	tmp_head = a->tail;
	if (!a->head)
	{
		write(2, "stack has a few value\n", 22);
		return ;
	}
	if (tmp_head->prev == NULL)
		return ;
	a->tail = tmp_head->prev;
	tmp_head->prev = NULL;
	a->tail->next = NULL;
	insert_head(a, tmp_head);
}

static void	_rrot_b(t_deque *b)
{
	t_node	*tmp_head;

	tmp_head = b->tail;
	if (!b->head)
	{
		write(2, "stack has a few value\n", 22);
		return ;
	}
	if (tmp_head->prev == NULL)
		return ;
	b->tail = tmp_head->prev;
	tmp_head->prev = NULL;
	b->tail->next = NULL;
	insert_head(b, tmp_head);
}

int	rrot_rr(t_deque *a, t_deque *b)
{
	if (!a->head || !b->head)
	{
		write(2, "stack has a few value\n", 22);
		return (1);
	}
	_rrot_a(a);
	_rrot_b(b);
	write(1, "rrr\n", 4);
	return (0);
}
