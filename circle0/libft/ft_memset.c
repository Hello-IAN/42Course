/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yomin <yomin@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/14 20:44:28 by yomin             #+#    #+#             */
/*   Updated: 2022/04/14 21:04:29 by yomin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

void	*ft_memset(void *s, int c, size_t n)
{
	unsigned char	*s_ptr;
	unsigned char	_target;

	s_ptr = (unsigned char *)s;
	_target = (unsigned char)c;
	while (n--)
	{
		*s_ptr = _target;
		s_ptr++;
	}
	return (s);
}
