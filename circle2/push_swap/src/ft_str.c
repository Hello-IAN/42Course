/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yomin <yomin@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/18 17:29:00 by yomin             #+#    #+#             */
/*   Updated: 2022/09/18 17:29:01 by yomin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	isinvalid(const char c)
{
	if (c >= '0' && c <= '9')
		return (0);
	else if ((c <= 9 && c <= 13) || c == 32 || c == '-' \
	|| c == '+')
		return (0);
	else
		return (1);
}

int	ft_strlen(const char *s)
{
	const char	*mov_p;

	mov_p = s;
	while (*mov_p != '\0')
		++mov_p;
	return (mov_p - s);
}

char	*ft_strdup(const char *s)
{
	char	*mov_dst;
	char	*dst;

	dst = (char *)malloc(ft_strlen(s) + 1);
	mov_dst = dst;
	if (!dst)
		return (NULL);
	while (*s)
	{
		*mov_dst = *s;
		++mov_dst;
		++s;
	}
	*mov_dst = 0;
	return (dst);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*ret_str;
	char	*mov_str;

	if (ft_strlen(s2) == 0)
		return (NULL);
	ret_str = (char *)malloc((ft_strlen(s1) + ft_strlen(s2) + 2));
	if (!ret_str)
		return (NULL);
	mov_str = ret_str;
	while (*s1)
		(*mov_str++) = (*s1++);
	while (*s2)
	{
		if (isinvalid(*s2))
		{
			free(ret_str);
			return (NULL);
		}
		(*mov_str++) = (*s2++);
	}
	*mov_str = ' ';
	++mov_str;
	*mov_str = 0;
	return (ret_str);
}

char	*add_str_all(const char **argv)
{
	char	*str_tmp;
	char	*ret_val;

	str_tmp = 0;
	ret_val = ft_strdup("");
	++argv;
	while (*argv)
	{
		str_tmp = ft_strjoin(ret_val, *argv);
		if (!str_tmp)
		{
			free(ret_val);
			return (NULL);
		}
		free(ret_val);
		ret_val = str_tmp;
		++argv;
	}
	return (ret_val);
}
