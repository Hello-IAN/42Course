/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   p_put_nbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yomin <yomin@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/20 02:17:24 by yomin             #+#    #+#             */
/*   Updated: 2022/04/20 02:17:26 by yomin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

static int	get_len(long n)
{
	int	len;

	len = 1;
	while (n / 10)
	{
		++len;
		n /= 10;
	}
	return (len);
}

static int	write_nbr(long n)
{
	char	tmp;
	char	tmp_arr[10];
	int		len;
	int		idx;
	int		size;

	tmp = 0;
	idx = -1;
	len = get_len(n);
	size = len;
	while (++idx < len)
	{
		tmp = (n % 10) + '0';
		tmp_arr[idx] = tmp;
		n /= 10;
	}
	idx = -1;
	while (++idx < len--)
	{
		tmp = tmp_arr[idx];
		tmp_arr[idx] = tmp_arr[len];
		tmp_arr[len] = tmp;
	}
	len = write(1, tmp_arr, size);
	return (len);
}

int	p_put_nbr(long n)
{
	if (n == -2147483648)
	{
		write(1, "-2147483648", 11);
		return (11);
	}
	else if (n < 0)
	{
		write(1, "-", 1);
		n *= -1;
		return ((write_nbr(n) + 1));
	}
	else
		return (write_nbr(n));
}
