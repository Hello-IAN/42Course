/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalpha.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yomin <yomin@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/14 20:34:21 by yomin             #+#    #+#             */
/*   Updated: 2022/04/14 20:34:22 by yomin            ###   ########.fr       */
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

int	ft_isalpha(int c)
{
	if (_islower(c) || _isupper(c))
		return (1);
	return (0);
}
