/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yomin <yomin@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/14 20:54:35 by yomin             #+#    #+#             */
/*   Updated: 2022/04/14 20:57:18 by yomin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*substring;
	char	*mov_sub;
	size_t	need_len;

	if (start > ft_strlen(s))
		return (ft_strdup(""));
	need_len = ft_strlen(s + start);
	if (len < need_len)
		substring = (char *)malloc(sizeof(char) * (len + 1));
	else
		substring = (char *)malloc(sizeof(char) * (need_len + 1));
	if (!substring)
		return (NULL);
	mov_sub = substring;
	s = s + start;
	while (*s && len--)
	{
		*mov_sub = *s;
		++mov_sub;
		++s;
	}
	*mov_sub = 0;
	return (substring);
}
