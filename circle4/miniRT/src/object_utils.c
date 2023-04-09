/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   object_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mingylee <mingylee@student.42seoul.kr      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/18 12:15:31 by mingylee          #+#    #+#             */
/*   Updated: 2023/01/18 17:05:06 by mingylee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/vars.h"

void	object_add(t_object **list, t_object *new_object)
{
	t_object	*cur;

	if (*list == 0)
	{
		*list = new_object;
		return ;
	}
	cur = *list;
	while (cur->next)
		cur = cur->next;
	cur->next = new_object;
}

t_object	*object_last(t_object *list)
{
	if (list == 0)
		return (0);
	while (list->next)
		list = list->next;
	return (list);
}
