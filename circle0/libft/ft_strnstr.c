/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yomin <yomin@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/14 20:51:55 by yomin             #+#    #+#             */
/*   Updated: 2022/04/14 21:00:58 by yomin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	const char	*h_ptr = haystack;
	const char	*n_ptr = needle;
	size_t		remain_len;

	if (!needle[0])
		return ((char *)haystack);
	remain_len = 0;
	while (*haystack && len)
	{
		h_ptr = haystack;
		n_ptr = needle;
		remain_len = len;
		while (*h_ptr && *n_ptr == *h_ptr && remain_len > 0)
		{	
			++h_ptr;
			++n_ptr;
			--remain_len;
		}
		if (*n_ptr == 0)
			return ((char *)haystack);
		++haystack;
		--len;
	}
	return (0);
}
