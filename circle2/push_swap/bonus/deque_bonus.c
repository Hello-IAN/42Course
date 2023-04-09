/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   deque_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yomin <yomin@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/18 17:13:05 by yomin             #+#    #+#             */
/*   Updated: 2022/09/18 17:13:10 by yomin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

void	insert_head(t_deque *deque, t_node *node)
{
	t_node	*tmp;

	if (!deque->head)
	{
		deque->head = node;
		deque->tail = node;
		return ;
	}
	tmp = deque->head;
	node->next = tmp;
	tmp->prev = node;
	deque->head = node;
	return ;
}

void	insert_tail(t_deque *deque, t_node *node)
{
	t_node	*tmp;

	if (!deque->tail && !deque->head)
	{
		deque->tail = node;
		deque->head = node;
		return ;
	}
	tmp = deque->tail;
	node->prev = tmp;
	tmp->next = node;
	deque->tail = node;
	return ;
}

t_deque	*create_deque(void)
{
	t_deque	*deque;

	deque = (t_deque *)malloc(sizeof(t_deque));
	if (!deque)
		return (NULL);
	deque->head = NULL;
	deque->tail = NULL;
	return (deque);
}

t_node	*make_node(int value)
{
	t_node	*node;

	node = (t_node *)malloc(sizeof(t_node));
	if (!node)
		return (NULL);
	node->data = value;
	node->idx = 0;
	node->next = NULL;
	node->prev = NULL;
	return (node);
}

t_deque	*input_values_a(char **values, t_deque *deque)
{
	int		tmp;
	int		idx;
	t_node	*node_tmp;

	idx = 0;
	while (values[idx])
	{
		tmp = ft_atoi(values[idx]);
		node_tmp = make_node(tmp);
		if (!node_tmp)
		{
			free_values(NULL, values, deque);
			return (NULL);
		}
		insert_tail(deque, node_tmp);
		++idx;
		node_tmp = node_tmp->next;
	}
	return (deque);
}
