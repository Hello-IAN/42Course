/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yomin <yomin@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/14 20:50:59 by yomin             #+#    #+#             */
/*   Updated: 2022/04/14 21:02:14 by yomin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

size_t	ft_strlen(const char *s)
{
	const char	*mov_p;

	mov_p = s;
	while (*mov_p != '\0')
		++mov_p;
	return (mov_p - s);
}
