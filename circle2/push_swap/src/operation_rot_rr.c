/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operation_rot_rr.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yomin <yomin@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/18 17:29:25 by yomin             #+#    #+#             */
/*   Updated: 2022/09/18 17:29:27 by yomin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	_rot_a(t_deque *a)
{
	t_node	*tmp_head;

	tmp_head = a->head;
	if (!tmp_head)
	{
		write(2, "stack has a few value\n", 22);
		return ;
	}
	if (a->head->next == NULL)
		return ;
	a->head = tmp_head->next;
	tmp_head->next = NULL;
	insert_tail(a, tmp_head);
}

static void	_rot_b(t_deque *b)
{
	t_node	*tmp_head;

	tmp_head = b->head;
	if (!tmp_head)
	{
		write(2, "stack has a few value\n", 22);
		return ;
	}
	if (b->head->next == NULL)
		return ;
	b->head = tmp_head->next;
	tmp_head->next = NULL;
	insert_tail(b, tmp_head);
}

int	rot_rr(t_deque *a, t_deque *b)
{
	if (!a->head || !b->head)
	{
		write(2, "stack has a few value\n", 22);
		return (1);
	}
	_rot_a(a);
	_rot_b(b);
	write(1, "rr\n", 3);
	return (0);
}
