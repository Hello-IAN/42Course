/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrch.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yomin <yomin@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/16 21:19:55 by yomin             #+#    #+#             */
/*   Updated: 2023/02/16 21:19:56 by yomin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/parser.h"

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
