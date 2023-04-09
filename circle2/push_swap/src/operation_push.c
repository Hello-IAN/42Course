/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operation_push.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yomin <yomin@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/18 17:29:14 by yomin             #+#    #+#             */
/*   Updated: 2022/09/18 17:29:15 by yomin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	push_a(t_deque *a, t_deque *b)
{
	t_node	*tmp_head;
	t_node	*tmp_node;

	tmp_head = b->head;
	if (!tmp_head)
	{
		write(2, "stack has a few value\n", 22);
		return (-1);
	}
	tmp_node = tmp_head->next;
	tmp_head->next = NULL;
	b->head = tmp_node;
	if (b->head)
		b->head->prev = NULL;
	insert_head(a, tmp_head);
	write(1, "pa\n", 3);
	return (0);
}

int	push_b(t_deque *a, t_deque *b)
{
	t_node	*tmp_head;
	t_node	*tmp_node;

	tmp_head = a->head;
	if (!tmp_head)
	{
		write(2, "stack has a few value\n", 22);
		return (-1);
	}
	tmp_node = tmp_head->next;
	tmp_head->next = NULL;
	a->head = tmp_node;
	if (a->head)
		a->head->prev = NULL;
	insert_head(b, tmp_head);
	write(1, "pb\n", 3);
	return (0);
}
