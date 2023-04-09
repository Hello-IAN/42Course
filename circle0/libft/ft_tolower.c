/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tolower.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yomin <yomin@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/14 20:54:42 by yomin             #+#    #+#             */
/*   Updated: 2022/04/14 20:56:37 by yomin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

static int	_islower(int c)
{
	if ('a' <= c && c <= 'z')
		return (1);
	return (0);
}

static int	_isupper(int c)
{
	if ('A' <= c && c <= 'Z')
		return (1);
	return (0);
}

int	ft_tolower(int c)
{
	if (_isupper(c) && _islower(c + 32))
		return (c + 32);
	return (c);
}
