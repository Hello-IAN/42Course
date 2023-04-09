/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yomin <yomin@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/14 20:41:06 by yomin             #+#    #+#             */
/*   Updated: 2022/04/14 20:41:55 by yomin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

void	*ft_memchr(const void *s, int c, size_t n)
{
	const unsigned char	*s_ptr = (const unsigned char *)s;
	unsigned char		_target;

	_target = (unsigned char)c;
	while (n--)
	{
		if (_target == *s_ptr)
			return ((void *)s_ptr);
		++s_ptr;
	}
	return (0);
}
