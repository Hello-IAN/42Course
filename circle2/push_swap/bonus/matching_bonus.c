/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matching_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yomin <yomin@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/18 17:13:40 by yomin             #+#    #+#             */
/*   Updated: 2022/09/18 17:13:41 by yomin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

void	match_idx(t_deque *deque, int *arr)
{
	t_node	*tmp;
	int		idx;
	int		size;

	idx = 0;
	size = deque->size;
	while (size)
	{
		tmp = deque->head;
		while (tmp)
		{
			if (tmp->data == arr[idx])
			{
				tmp->idx = idx;
				break ;
			}
			tmp = tmp->next;
		}
		--size;
		++idx;
	}
	free(arr);
}
