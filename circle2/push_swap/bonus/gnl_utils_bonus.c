/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gnl_utils_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yomin <yomin@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/18 17:13:34 by yomin             #+#    #+#             */
/*   Updated: 2022/09/18 17:13:35 by yomin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

int	reset_buf(char *buf, const char *src, int size)
{
	int	idx;
	int	line_idx;

	idx = 0;
	line_idx = 0;
	while (line_idx < size)
	{
		if (src[line_idx++] == '\n')
			break ;
	}
	size -= line_idx;
	while (idx < size)
	{
		buf[idx] = src[line_idx];
		++idx;
		++line_idx;
	}
	buf[idx] = 0;
	return (idx);
}

t_lst	*reset_lst(t_lst *lst)
{
	t_lst	*tmp;

	tmp = lst;
	while (tmp->flag < 0)
		tmp = tmp->next;
	if (tmp->flag == 1)
		lst->data_len = reset_buf(lst->data, tmp->data, tmp->data_len);
	else if (tmp->flag == 2)
	{
		return (clear_lst(lst));
	}
	if (find_nl(lst->data, lst->data_len))
		lst->flag = 1;
	else
	{
		lst->flag = -1;
		tmp = clear_lst(lst->next);
		lst->next = tmp;
	}
	return (lst);
}

char	*get_total_buf(t_lst *lst)
{
	char	*ret_str;
	int		size;
	int		idx;

	size = 0;
	while (lst->flag < 0)
	{
		size += lst->data_len;
		lst = lst->next;
	}
	idx = 0;
	while (lst->data_len > idx)
	{
		if (lst->data[idx++] == '\n')
			break ;
	}
		size += idx;
	if (size == 0)
		return (NULL);
	ret_str = (char *)malloc(size + 1);
	if (!ret_str)
		return (NULL);
	return (ret_str);
}

char	*cpy_string(t_lst *lst)
{
	char	*sub_ret;
	char	*tmp;
	int		idx;

	sub_ret = get_total_buf(lst);
	if (!sub_ret)
		return (NULL);
	tmp = sub_ret;
	while (lst != NULL)
	{
		idx = 0;
		while (idx < lst->data_len)
		{
			*tmp++ = lst->data[idx];
			if (lst->data[idx++] == '\n')
			{
				*tmp = 0;
				return (sub_ret);
			}
		}
		lst = lst->next;
	}
	*tmp = 0;
	return (sub_ret);
}
