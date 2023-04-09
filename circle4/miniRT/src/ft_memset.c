/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yomin <yomin@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/16 21:20:10 by yomin             #+#    #+#             */
/*   Updated: 2023/02/16 21:20:11 by yomin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/parser.h"

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
