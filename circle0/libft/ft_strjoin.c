/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yomin <yomin@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/14 20:49:32 by yomin             #+#    #+#             */
/*   Updated: 2022/04/14 21:03:19 by yomin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*ret_str;
	char	*mov_str;
	size_t	total_len;

	total_len = ft_strlen(s1) + ft_strlen(s2);
	ret_str = (char *)malloc(total_len + 1);
	if (!ret_str)
		return (NULL);
	mov_str = ret_str;
	while (*s1)
	{
		*mov_str = *s1;
		++mov_str;
		++s1;
	}
	while (*s2)
	{
		*mov_str = *s2;
		++mov_str;
		++s2;
	}
	*mov_str = 0;
	return (ret_str);
}
