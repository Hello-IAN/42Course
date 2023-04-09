/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operation_rot_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yomin <yomin@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/18 17:14:18 by yomin             #+#    #+#             */
/*   Updated: 2022/09/18 17:14:21 by yomin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

int	rot_a(t_deque *a)
{
	t_node	*tmp_head;

	tmp_head = a->head;
	if (!tmp_head)
		return (1);
	if (a->head->next == NULL)
		return (0);
	a->head = tmp_head->next;
	tmp_head->next = NULL;
	insert_tail(a, tmp_head);
	return (0);
}

int	rot_b(t_deque *b)
{
	t_node	*tmp_head;

	tmp_head = b->head;
	if (!tmp_head)
		return (1);
	if (b->head->next == NULL)
		return (0);
	b->head = tmp_head->next;
	tmp_head->next = NULL;
	insert_tail(b, tmp_head);
	return (0);
}

int	rot_rr(t_deque *a, t_deque *b)
{
	rot_a(a);
	rot_b(b);
	return (0);
}
