/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operation_rrot_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yomin <yomin@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/18 17:14:23 by yomin             #+#    #+#             */
/*   Updated: 2022/09/18 17:14:26 by yomin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

int	rrot_a(t_deque *a)
{
	t_node	*tmp_head;

	tmp_head = a->tail;
	if (!a->head)
		return (1);
	if (tmp_head->prev == NULL)
		return (0);
	a->tail = tmp_head->prev;
	tmp_head->prev = NULL;
	a->tail->next = NULL;
	insert_head(a, tmp_head);
	return (0);
}

int	rrot_b(t_deque *b)
{
	t_node	*tmp_head;

	tmp_head = b->tail;
	if (!b->head)
		return (1);
	if (tmp_head->prev == NULL)
		return (0);
	b->tail = tmp_head->prev;
	tmp_head->prev = NULL;
	b->tail->next = NULL;
	insert_head(b, tmp_head);
	return (0);
}

int	rrot_rr(t_deque *a, t_deque *b)
{
	if (!a->head || !b->head)
		return (1);
	rrot_a(a);
	rrot_b(b);
	return (0);
}
