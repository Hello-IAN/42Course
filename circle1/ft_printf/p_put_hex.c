/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   p_put_hex.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yomin <yomin@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/20 02:17:21 by yomin             #+#    #+#             */
/*   Updated: 2022/04/20 02:17:23 by yomin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

static int	get_size(unsigned int n)
{
	int	size;

	size = 0;
	while (n / 16)
	{
		++size;
		n /= 16;
	}
	return (size);
}

static void	write_hex(unsigned int n, char c, int size)
{
	const char	*lower_hex = "0123456789abcdef";
	const char	*upper_hex = "0123456789ABCDEF";
	int			shifter;

	shifter = size * 4;
	if (c == 'x')
	{
		while (shifter >= 0)
		{
			write(1, lower_hex + ((n >> shifter) & 15), 1);
			shifter -= 4;
		}
	}
	else if (c == 'X')
	{
		while (shifter >= 0)
		{
			write(1, upper_hex + ((n >> shifter) & 15), 1);
			shifter -= 4;
		}
	}
}

int	p_put_hex(unsigned int n, char c)
{
	int	size;

	size = get_size(n);
	write_hex(n, c, size);
	return (size + 1);
}
