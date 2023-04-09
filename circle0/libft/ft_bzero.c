/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yomin <yomin@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/14 20:56:14 by yomin             #+#    #+#             */
/*   Updated: 2022/04/14 21:08:01 by yomin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

void	ft_bzero(void *s, size_t n)
{
	unsigned char	*mov_s;

	mov_s = (unsigned char *)s;
	while (n--)
	{
		*mov_s = 0;
		++mov_s;
	}
	return ;
}
