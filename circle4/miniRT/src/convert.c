/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yomin <yomin@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/16 22:05:50 by yomin             #+#    #+#             */
/*   Updated: 2023/02/22 12:34:27 by mingylee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/parser.h"

int	ft_convert_to_i(const char *str)
{
	long	res;

	res = 0;
	if (*str < '0' && *str > '9')
		return (-1);
	while (*str && (*str >= '0' && *str <= '9'))
		res = (10 * res) + (*str++ - '0');
	if (*str != '\n' && *str != '\0')
		return (-1);
	else if (res > 2147483647)
		return (-1);
	return (res);
}

static int	get_sign(const char c)
{
	if (c == '-')
		return (-1);
	else
		return (1);
}

double	ft_atod(const char *str)
{
	int		sign;
	double	result;
	double	pow;

	sign = get_sign(*str);
	str += (*str == '+' || *str == '-');
	result = 0;
	while (*str && ('0' <= *str && *str <= '9'))
	{
		result = result * 10 + (double)(*str - '0');
		++str;
	}
	if (*str != '.')
		return (result * sign);
	pow = 0.1f;
	++str;
	while (*str && ('0' <= *str && *str <= '9'))
	{
		result = result + (((double)(*str - '0')) * pow);
		pow *= 0.1f;
		++str;
	}
	return (result * sign);
}
