/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yomin <yomin@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/20 02:16:46 by yomin             #+#    #+#             */
/*   Updated: 2022/04/20 02:16:49 by yomin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int	ft_printf(const char *s, ...)
{
	int		ret;
	va_list	ap;

	va_start(ap, s);
	ret = 0;
	while (*s != '\0')
	{
		if (*s == '%')
		{
			++s;
			if (*s == '%')
			{
				ret += write(1, "%", 1);
			}
			ret += find_form(ap, *s);
		}
		else
		{
			write(1, s, 1);
			++ret;
		}
		++s;
	}
	va_end(ap);
	return (ret);
}
