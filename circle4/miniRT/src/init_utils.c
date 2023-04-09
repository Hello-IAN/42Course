/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mingylee <mingylee@student.42seoul.kr      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/18 10:21:32 by mingylee          #+#    #+#             */
/*   Updated: 2023/01/18 10:23:48 by mingylee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/vec.h"

double	pow_int(double base, int exp)
{
	double	result;

	result = 1;
	while (exp)
	{
		if (exp & 1)
			result *= base;
		exp >>= 1;
		base *= base;
	}
	return (result);
}

t_vec	init_vec(double x, double y, double z)
{
	t_vec	init;

	init.x = x;
	init.y = y;
	init.z = z;
	return (init);
}

t_point3	init_point(double x, double y, double z)
{
	t_point3	init;

	init.x = x;
	init.y = y;
	init.z = z;
	return (init);
}

t_color	init_color(double r, double g, double b)
{
	t_color	init;

	init.x = r;
	init.y = g;
	init.z = b;
	return (init);
}
