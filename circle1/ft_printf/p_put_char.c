/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   p_put_char.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yomin <yomin@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/20 02:17:15 by yomin             #+#    #+#             */
/*   Updated: 2022/04/20 02:17:18 by yomin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int	p_put_char(int n)
{
	write(1, &n, 1);
	return (1);
}
