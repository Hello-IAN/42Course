/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   index_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yomin <yomin@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/18 17:13:37 by yomin             #+#    #+#             */
/*   Updated: 2022/09/18 17:13:38 by yomin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

int	check_idx_vaild(int *arr, int size)
{
	int	i;
	int	j;

	i = 0;
	while (i < size)
	{
		j = i + 1;
		while (j < size)
		{
			if (arr[i] == arr[j])
				return (ERROR);
			++j;
		}
		++i;
	}
	return (0);
}

void	ft_swap(int *i, int *j)
{
	int	tmp;

	tmp = *i;
	*i = *j;
	*j = tmp;
}

int	get_size(t_deque *deque)
{
	int		i;
	t_node	*node;

	i = 0;
	node = deque->head;
	while (node)
	{
		++i;
		node = node->next;
	}
	return (i);
}

void	sort_arr(int *arr, int size)
{
	int	i;
	int	j;
	int	flag;

	flag = 1;
	i = 0;
	while (i < size)
	{
		j = i + 1;
		while (j < size)
		{
			if (arr[i] > arr[j])
			{
				ft_swap(&arr[i], &arr[j]);
				flag = -1;
			}
			++j;
		}
		++i;
	}
}

int	*make_idex(t_deque *deque)
{
	int		*arr;
	int		idx;
	t_node	*tmp;

	deque->size = get_size(deque);
	arr = malloc(sizeof(int) * deque->size);
	if (!arr)
		return (0);
	idx = 0;
	tmp = deque->head;
	while (idx < deque->size)
	{
		arr[idx++] = tmp->data;
		tmp = tmp->next;
	}
	sort_arr(arr, deque->size);
	if (check_idx_vaild(arr, deque->size) == ERROR)
	{
		free(arr);
		return (0);
	}
	return (arr);
}
