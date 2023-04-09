/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yomin <yomin@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/14 20:52:27 by yomin             #+#    #+#             */
/*   Updated: 2022/04/14 21:00:06 by yomin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	const char	*mov_p = s;
	char		_target;

	_target = (char)c;
	while (*mov_p != '\0')
		++mov_p;
	if (_target == '\0')
		return ((char *)mov_p);
	else
	{
		while (s <= mov_p)
		{
			if (_target == *mov_p)
				return ((char *)mov_p);
			--mov_p;
		}
	}
	return (0);
}
