/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operation_swap.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yomin <yomin@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/18 17:29:36 by yomin             #+#    #+#             */
/*   Updated: 2022/09/18 17:29:37 by yomin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	swap_a(t_deque *a)
{
	t_node	*tmp_head;
	t_node	*tmp_node;

	tmp_head = a->head;
	if (!tmp_head || !tmp_head->next)
	{
		write(2, "stack has a few value\n", 22);
		return (1);
	}
	tmp_node = tmp_head->next;
	tmp_head->next = tmp_node->next;
	insert_head(a, tmp_node);
	if (tmp_head->next)
		tmp_head->next->prev = tmp_head;
	write(1, "sa\n", 3);
	return (0);
}

int	swap_b(t_deque *b)
{
	t_node	*tmp_head;
	t_node	*tmp_node;

	tmp_head = b->head;
	if (!tmp_head || !tmp_head->next)
	{
		write(2, "stack has a few value\n", 22);
		return (1);
	}
	tmp_node = tmp_head->next;
	tmp_head->next = tmp_node->next;
	insert_head(b, tmp_node);
	if (tmp_head->next)
		tmp_head->next->prev = tmp_head;
	write(1, "sb\n", 3);
	return (0);
}
