/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yomin <yomin@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/14 20:44:55 by yomin             #+#    #+#             */
/*   Updated: 2022/04/14 21:04:20 by yomin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

static void	rec_putnbr(int n, int fd)
{
	char	tmp;

	tmp = 0;
	if (n / 10)
		rec_putnbr((n / 10), fd);
	tmp = n % 10 + '0';
	write(fd, &tmp, 1);
}

void	ft_putnbr_fd(int n, int fd)
{
	if (n == -2147483648)
	{
		write(fd, "-2147483648", 11);
		return ;
	}
	else if (n < 0)
	{
		write(fd, "-", 1);
		ft_putnbr_fd((n * -1), fd);
	}
	else
		rec_putnbr(n, fd);
}
