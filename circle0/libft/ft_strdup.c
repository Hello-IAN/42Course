/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yomin <yomin@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/14 20:48:40 by yomin             #+#    #+#             */
/*   Updated: 2022/04/14 20:49:16 by yomin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s)
{
	char	*mov_dst;
	char	*dst;
	size_t	src_len;

	src_len = ft_strlen(s);
	dst = (char *)malloc(src_len + 1);
	mov_dst = dst;
	if (!dst)
		return (NULL);
	while (*s)
	{
		*mov_dst = *s;
		++mov_dst;
		++s;
	}
	*mov_dst = 0;
	return (dst);
}
