/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yomin <yomin@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/18 17:13:21 by yomin             #+#    #+#             */
/*   Updated: 2022/09/18 17:13:24 by yomin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

static size_t	get_cnt(char const *s, char c)
{
	size_t	cnt;

	cnt = 0;
	while (*s)
	{
		if (*s != c)
		{
			++cnt;
			while (*s && *s != c)
				++s;
		}
		if (*s != '\0')
			++s;
	}
	return (cnt);
}

static void	s_sub_cpy(char *o_arr, char const *beg_ptr, char const *end_ptr)
{
	while (beg_ptr < end_ptr)
	{
		*o_arr = *beg_ptr;
		o_arr++;
		beg_ptr++;
	}
	*o_arr = 0;
}

static void	*free_arr(char **o_arr, size_t arr_idx)
{
	size_t	idx;

	idx = 0;
	while (idx < arr_idx)
	{
		free(o_arr[idx]);
		++idx;
	}
	free(o_arr);
	o_arr = NULL;
	return (NULL);
}	

char	**ft_split(char const *s, char c)
{
	char		**o_arr;
	char const	*beg_ptr;
	size_t		arr_idx;

	o_arr = (char **)malloc(sizeof(char *) * (get_cnt(s, c) + 1));
	if (!o_arr)
		return (NULL);
	arr_idx = 0;
	while (*s)
	{
		if (*s != c)
		{
			beg_ptr = s;
			while (*s && *s != c)
				++s;
			o_arr[arr_idx] = (char *)malloc(s - beg_ptr + 1);
			if (!o_arr[arr_idx])
				return (free_arr(o_arr, arr_idx));
			s_sub_cpy(o_arr[arr_idx++], beg_ptr, s);
		}
		if (*s != '\0')
			++s;
	}
	o_arr[arr_idx] = NULL;
	return (o_arr);
}
