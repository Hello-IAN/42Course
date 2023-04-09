/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   p_put_addr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yomin <yomin@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/20 02:17:09 by yomin             #+#    #+#             */
/*   Updated: 2022/04/20 02:17:13 by yomin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

static int	get_size(unsigned long n)
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

static int	write_addr(unsigned long ptr)
{
	const char	*lower_hex = "0123456789abcdef";
	int			shifter;
	int			size;

	size = 0;
	size = get_size(ptr);
	shifter = 4 * size;
	size += write(1, "0x", 2);
	while (shifter >= 0)
	{
		write(1, lower_hex + ((ptr >> shifter) & 15), 1);
		shifter -= 4;
	}
	size += 1;
	return (size);
}

int	p_put_addr(void *addr)
{
	int				size;
	unsigned long	ptr;

	size = 0;
	ptr = (unsigned long)addr;
	size = write_addr(ptr);
	return (size);
}
