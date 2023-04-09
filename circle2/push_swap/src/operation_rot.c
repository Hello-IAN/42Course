/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operation_rot.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yomin <yomin@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/18 17:29:18 by yomin             #+#    #+#             */
/*   Updated: 2022/09/18 17:29:19 by yomin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	rot_a(t_deque *a)
{
	t_node	*tmp_head;

	tmp_head = a->head;
	if (!tmp_head)
	{
		write(2, "stack has a few value\n", 22);
		return (-1);
	}
	if (a->head->next == NULL)
		return (0);
	a->head = tmp_head->next;
	tmp_head->next = NULL;
	insert_tail(a, tmp_head);
	write(1, "ra\n", 3);
	return (0);
}

int	rot_b(t_deque *b)
{
	t_node	*tmp_head;

	tmp_head = b->head;
	if (!tmp_head)
	{
		write(2, "stack has a few value\n", 22);
		return (1);
	}
	if (b->head->next == NULL)
		return (0);
	b->head = tmp_head->next;
	tmp_head->next = NULL;
	insert_tail(b, tmp_head);
	write(1, "rb\n", 3);
	return (0);
}
