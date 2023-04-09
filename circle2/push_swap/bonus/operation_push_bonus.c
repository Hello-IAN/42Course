/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operation_push_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yomin <yomin@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/18 17:14:12 by yomin             #+#    #+#             */
/*   Updated: 2022/09/18 17:14:13 by yomin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

int	push_a(t_deque *a, t_deque *b)
{
	t_node	*tmp_head;
	t_node	*tmp_node;

	tmp_head = b->head;
	if (!tmp_head)
		return (1);
	tmp_node = tmp_head->next;
	tmp_head->next = NULL;
	b->head = tmp_node;
	if (b->head)
		b->head->prev = NULL;
	insert_head(a, tmp_head);
	return (0);
}

int	push_b(t_deque *a, t_deque *b)
{
	t_node	*tmp_head;
	t_node	*tmp_node;

	tmp_head = a->head;
	if (!tmp_head)
		return (1);
	tmp_node = tmp_head->next;
	tmp_head->next = NULL;
	a->head = tmp_node;
	if (a->head)
		a->head->prev = NULL;
	insert_head(b, tmp_head);
	return (0);
}
