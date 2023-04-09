/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yomin <yomin@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/02 18:02:23 by yomin             #+#    #+#             */
/*   Updated: 2022/06/13 17:12:07 by yomin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "get_next_line_bonus.h"

t_head	*make_head(int fd)
{
	t_head	*head;

	head = (t_head *)malloc(sizeof(t_head));
	if (!head)
		return (NULL);
	head->fd_n = fd;
	head->next_head = NULL;
	head->bridge = NULL;
	return (head);
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

char	*edit_lst(t_lst **lst, int fd)
{
	t_lst			*tmp;
	char			*res;

	if (!*lst)
		*lst = make_new_lst(fd);
	tmp = *lst;
	if (!tmp || (tmp->flag == 2 && tmp->data_len == 0))
	{
		*lst = clear_lst(tmp);
		return (NULL);
	}
	while (tmp->flag < 0 && tmp)
	{
		tmp->next = make_new_lst(fd);
		if (!tmp->next)
			tmp = clear_lst(*lst);
		else
			tmp = tmp->next;
	}
	res = cpy_string(*lst);
	*lst = reset_lst(*lst);
	return (res);
}

char	*get_next_line(int fd)
{
	static t_head	*head;
	t_head			*tmp;
	char			*res;

	if (fd < 0 || BUFFER_SIZE < 1 || read(fd, NULL, 0) < 0)
		return (NULL);
	if (!head)
		head = make_head(fd);
	tmp = head;
	while (tmp->next_head && tmp->fd_n != fd)
		tmp = tmp->next_head;
	if (tmp->fd_n != fd)
	{
		tmp->next_head = make_head(fd);
		tmp = tmp->next_head;
	}
	res = edit_lst(&(tmp->bridge), fd);
	while (head && !head->bridge)
	{
		tmp = head->next_head;
		free(head);
		head = tmp;
	}
	return (res);
}
