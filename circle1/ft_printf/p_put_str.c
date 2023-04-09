/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   p_put_str.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yomin <yomin@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/20 02:17:28 by yomin             #+#    #+#             */
/*   Updated: 2022/04/20 02:17:29 by yomin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int	p_put_str(char *_str)
{
	int	len;

	len = 0;
	if (_str == NULL)
	{
		write (1, "(null)", 6);
		return (6);
	}
	while (_str[len])
		++len;
	write(1, _str, len);
	return (len);
}
