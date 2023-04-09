/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yomin <yomin@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/03 19:49:18 by yomin             #+#    #+#             */
/*   Updated: 2022/08/03 19:49:20 by yomin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "server.h"

t_info	g_info;

void	rec_putnbr(int n, int fd)
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

void	ac_handler(int sig, siginfo_t *sip, void *ucp)
{
	static char		tmp;
	static int		bit;

	g_info.pid = sip->si_pid;
	if (sig == SIGUSR1)
	{
		tmp |= 0;
		if (bit < 7)
			tmp <<= 1;
	}
	else if (sig == SIGUSR2)
	{
		tmp |= 1;
		if (bit < 7)
			tmp <<= 1;
	}
	bit++;
	if (bit == 8)
	{
		write(1, &tmp, 1);
		bit = 0;
		tmp = 0;
	}
	g_info.flag = 1;
	ucp = (void *)ucp;
}

int	main(void)
{
	struct sigaction	s_sa;

	sigemptyset(&s_sa.sa_mask);
	sigaddset(&s_sa.sa_mask, SIGUSR1);
	sigaddset(&s_sa.sa_mask, SIGUSR2);
	s_sa.sa_sigaction = ac_handler;
	s_sa.sa_flags = SA_SIGINFO;
	write(1, "pid: ", 5);
	ft_putnbr_fd(getpid(), 1);
	write(1, "\n", 1);
	sigaction(SIGUSR1, &s_sa, 0);
	sigaction(SIGUSR2, &s_sa, 0);
	while (1)
	{
		if (g_info.flag)
		{
			g_info.flag = 0;
			kill(g_info.pid, SIGUSR1);
		}
	}
	return (0);
}
