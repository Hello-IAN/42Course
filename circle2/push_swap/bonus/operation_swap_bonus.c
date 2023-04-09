/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operation_swap_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yomin <yomin@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/18 17:14:27 by yomin             #+#    #+#             */
/*   Updated: 2022/09/18 17:14:28 by yomin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

int	swap_a(t_deque *a)
{
	t_node	*tmp_head;
	t_node	*tmp_node;

	tmp_head = a->head;
	if (!tmp_head || !tmp_head->next)
		return (1);
	tmp_node = tmp_head->next;
	tmp_head->next = tmp_node->next;
	insert_head(a, tmp_node);
	if (tmp_head->next)
		tmp_head->next->prev = tmp_head;
	return (0);
}

int	swap_b(t_deque *b)
{
	t_node	*tmp_head;
	t_node	*tmp_node;

	tmp_head = b->head;
	if (!tmp_head || !tmp_head->next)
		return (1);
	tmp_node = tmp_head->next;
	tmp_head->next = tmp_node->next;
	insert_head(b, tmp_node);
	if (tmp_head->next)
		tmp_head->next->prev = tmp_head;
	return (0);
}

int	swap_ss(t_deque *a, t_deque *b)
{
	if (!a->head || !a->head->next || \
	!b->head || !b->head->next)
		return (1);
	swap_a(a);
	swap_b(b);
	return (0);
}
