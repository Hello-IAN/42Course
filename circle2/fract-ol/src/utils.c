/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yomin <yomin@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/29 18:09:18 by yomin             #+#    #+#             */
/*   Updated: 2022/08/29 18:09:20 by yomin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	ft_strcmp(char *s1, char *s2)
{
	while (*s1 && *s2)
	{
		if (*s1 != *s2)
			return (*s1 - *s2);
		++s1;
		++s2;
	}
	return (*s1 - *s2);
}

int	isvalidname(char *name)
{
	if (ft_strcmp(name, "Mandelbrot") == 0)
		return (1);
	else if (ft_strcmp(name, "mandelbrot") == 0)
		return (1);
	else if (ft_strcmp(name, "mandel") == 0)
		return (1);
	else if (ft_strcmp(name, "julia") == 0)
		return (2);
	else if (ft_strcmp(name, "Julia") == 0)
		return (2);
	else if (ft_strcmp(name, "JULIA") == 0)
		return (2);
	else
		return (-1);
}

int	isvalid(int argc, char *name)
{
	int	ret_val;

	ret_val = 0;
	if (!(argc == 2))
	{
		return (-1);
	}
	ret_val = isvalidname(name);
	if (ret_val == 1)
		return (1);
	else if (ret_val == 2)
		return (2);
	else
		return (-1);
}
