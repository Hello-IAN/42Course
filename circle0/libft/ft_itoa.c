/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yomin <yomin@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/14 20:35:23 by yomin             #+#    #+#             */
/*   Updated: 2022/04/14 21:07:18 by yomin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	get_len(int n)
{
	int	len;

	len = 1;
	if (n < 0)
	{
		len += 1;
		n *= -1;
	}
	while (n / 10)
	{
		++len;
		n /= 10;
	}
	return (len);
}

static char	*get_edge_case(char *ret_arr, int n)
{
	if (n == 0)
	{
		ret_arr = ft_strdup("0");
	}
	else if (n == -2147483648)
	{
		ret_arr = ft_strdup("-2147483648");
	}
	return (ret_arr);
}

static char	*get_arr(char *ret_arr, int len, int idx, int n)
{
	char	tmp;

	tmp = 0;
	while (idx < len)
	{
		tmp = (n % 10) + '0';
		ret_arr[idx] = tmp;
		n /= 10;
		++idx;
	}
	ret_arr[len] = 0;
	if (ret_arr[0] == '-')
		idx = 0;
	else
		idx = -1;
	while (++idx < len--)
	{
		tmp = ret_arr[idx];
		ret_arr[idx] = ret_arr[len];
		ret_arr[len] = tmp;
	}
	return (ret_arr);
}

char	*ft_itoa(int n)
{
	char	*ret_arr;
	int		len;
	int		idx;

	ret_arr = NULL;
	if (n == 0 || n == -2147483648)
	{
		return (get_edge_case(ret_arr, n));
	}
	len = get_len(n);
	ret_arr = (char *)malloc(len + 1);
	if (!ret_arr)
		return (NULL);
	idx = 0;
	if (n < 0)
	{
		n *= -1;
		ret_arr[idx] = '-';
		++idx;
	}
	ret_arr = get_arr(ret_arr, len, idx, n);
	return (ret_arr);
}
