/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yomin <yomin@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/14 20:50:12 by yomin             #+#    #+#             */
/*   Updated: 2022/04/14 21:02:25 by yomin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

size_t	ft_strlcpy(char *dst, const char *src, size_t size)
{
	size_t	src_len;

	src_len = 0;
	while (*src && src_len + 1 < size)
	{
		*dst = *src;
		++dst;
		++src;
		++src_len;
	}
	if (size != 0)
		*dst = '\0';
	while (*src)
	{
		++src;
		++src_len;
	}
	return (src_len);
}
