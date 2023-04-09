/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yomin <yomin@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/14 20:42:17 by yomin             #+#    #+#             */
/*   Updated: 2022/04/14 20:43:14 by yomin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

void	*ft_memcpy(void *s, const void *s2, size_t n)
{
	const unsigned char	*mov_s2 = (const unsigned char *)s2;
	unsigned char		*mov_s;

	mov_s = s;
	if (!s && !s2)
		return (s);
	while (n--)
	{
		*mov_s = *mov_s2;
		++mov_s;
		++mov_s2;
	}
	return (s);
}
