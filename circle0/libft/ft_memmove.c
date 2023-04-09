/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yomin <yomin@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/14 20:43:16 by yomin             #+#    #+#             */
/*   Updated: 2022/04/14 21:05:04 by yomin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	const unsigned char	*src_arr = (const unsigned char *)src;
	unsigned char		*dst_arr;
	size_t				start_p;

	dst_arr = (unsigned char *)dst;
	if (dst_arr == src_arr || len == 0)
		return (dst);
	if (src_arr < dst_arr)
	{
		start_p = len;
		while (start_p--)
			dst_arr[start_p] = src_arr[start_p];
	}
	else if (src_arr > dst_arr)
	{
		start_p = -1;
		while (++start_p < len)
			dst_arr[start_p] = src_arr[start_p];
	}
	return (dst);
}
