/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_form.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yomin <yomin@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/20 02:16:57 by yomin             #+#    #+#             */
/*   Updated: 2022/04/20 02:16:58 by yomin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int	find_form(va_list ap, const char c)
{
	if (c == 'c')
		return (p_put_char(va_arg(ap, int)));
	else if (c == 's')
		return (p_put_str(va_arg(ap, char *)));
	else if (c == 'p')
		return (p_put_addr(va_arg(ap, void *)));
	else if (c == 'd' || c == 'i')
		return (p_put_nbr(va_arg(ap, int)));
	else if (c == 'u')
		return (p_put_nbr(va_arg(ap, unsigned int)));
	else if (c == 'x' || c == 'X')
		return (p_put_hex(va_arg(ap, unsigned long), c));
	else
		return (0);
}
