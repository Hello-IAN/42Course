/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_toupper.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yomin <yomin@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/14 20:54:55 by yomin             #+#    #+#             */
/*   Updated: 2022/04/14 20:55:09 by yomin            ###   ########.fr       */
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

int	ft_toupper(int c)
{
	if (_islower(c) && _isupper(c - 32))
		return (c - 32);
	return (c);
}
