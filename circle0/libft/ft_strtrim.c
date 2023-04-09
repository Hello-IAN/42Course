/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yomin <yomin@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/14 20:53:31 by yomin             #+#    #+#             */
/*   Updated: 2022/04/14 20:58:46 by yomin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	is_set(char const *set, char c)
{
	while (*set)
	{
		if (*set == c)
			return (1);
		++set;
	}
	return (0);
}

static size_t	get_idx(char const *s1, char const *set)
{
	size_t	cnt;

	cnt = 0;
	while (*s1 && is_set(set, *s1))
	{
			++cnt;
			++s1;
	}
	return (cnt);
}

static size_t	get_ridx(char const *s1, char const *set, size_t len)
{
	size_t	cnt;

	cnt = 0;
	while (is_set(set, *s1) && len)
	{
		++cnt;
		--s1;
		--len;
	}
	return (cnt);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t	beg_idx;
	size_t	end_idx;
	size_t	tmp_len;
	char	*ret_str;

	tmp_len = ft_strlen(s1);
	beg_idx = get_idx(s1, set);
	end_idx = tmp_len - get_ridx((s1 + tmp_len - 1), set, tmp_len - 1);
	if (beg_idx >= end_idx)
		return (ft_strdup(""));
	tmp_len = end_idx - beg_idx + 1;
	ret_str = (char *)malloc(tmp_len);
	if (!ret_str)
		return (NULL);
	ft_strlcpy(ret_str, (s1 + beg_idx), (tmp_len));
	return (ret_str);
}
