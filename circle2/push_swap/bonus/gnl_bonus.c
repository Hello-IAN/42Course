/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gnl_bonus.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yomin <yomin@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/18 17:13:31 by yomin             #+#    #+#             */
/*   Updated: 2022/09/18 17:13:32 by yomin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

int	find_nl(const char *buf, int size)
{
	while (size)
	{
		if (*buf == '\n')
			return (1);
		++buf;
		--size;
	}
	return (0);
}

t_lst	*clear_lst(t_lst *lst)
{
	t_lst	*tmp;

	while (lst != NULL)
	{
		tmp = lst;
		lst = lst->next;
		free(tmp);
	}
	return (NULL);
}

t_lst	*make_new_lst(int fd)
{
	t_lst	*node;

	node = (t_lst *)malloc(sizeof(t_lst));
	if (!node)
		return (NULL);
	node->data_len = read(fd, node->data, BUFFER_SIZE);
	if (node->data_len == -1)
	{
		free(node);
		return (NULL);
	}
	else if (node->data_len >= 0)
	{
		if (find_nl(node->data, node->data_len) && node->data_len >= 1)
			node->flag = 1;
		else if (node->data_len < BUFFER_SIZE || node->data_len == 0)
			node->flag = 2;
		else
			node->flag = -1;
	}
	node->next = NULL;
	return (node);
}

char	*get_next_line(int fd)
{
	static t_lst	*lst;
	t_lst			*tmp;
	char			*res;

	if (fd < 0 || BUFFER_SIZE < 0 || read(fd, NULL, 0) < 0)
		return (NULL);
	if (!lst)
		lst = make_new_lst(fd);
	tmp = lst;
	if (!tmp || (tmp->flag == 2 && tmp->data_len == 0))
	{
		lst = clear_lst(tmp);
		return (NULL);
	}
	while (tmp->flag < 0)
	{
		tmp->next = make_new_lst(fd);
		tmp = tmp->next;
	}
	res = cpy_string(lst);
	lst = reset_lst(lst);
	return (res);
}
