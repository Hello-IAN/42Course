/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yomin <yomin@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/14 20:49:59 by yomin             #+#    #+#             */
/*   Updated: 2022/04/14 21:02:36 by yomin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	ret_len;

	ret_len = 0;
	while (*dst && ret_len < size)
	{
		++dst;
		++ret_len;
	}
	while (*src && ret_len + 1 < size)
	{
		*dst = *src;
		++dst;
		++src;
		++ret_len;
	}
	if (ret_len < size)
		*dst = 0;
	while (*src)
	{
		++src;
		++ret_len;
	}
	return (ret_len);
}
