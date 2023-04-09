/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yomin <yomin@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/14 20:47:23 by yomin             #+#    #+#             */
/*   Updated: 2022/04/14 21:03:53 by yomin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strchr(const char *s, int c)
{
	char	_target;

	_target = (char)c;
	while (*s != '\0')
	{
		if (_target == *s)
			return ((char *)s);
		++s;
	}
	if (_target == '\0')
		return ((char *)s);
	else
		return (0);
}
