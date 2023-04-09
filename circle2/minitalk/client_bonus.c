/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yomin <yomin@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/03 19:49:11 by yomin             #+#    #+#             */
/*   Updated: 2022/08/03 19:49:14 by yomin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <signal.h>
#include <unistd.h>
#include <stdlib.h>

int	g_flag = 1;

void	get_sig(int pid, siginfo_t *sip, void *ucp)
{
	void	*tmp;
	int		using_pid;

	using_pid = pid;
	g_flag = sip->si_pid;
	tmp = ucp;
}

int	ft_atoi(char *nptr)
{
	int	res;
	int	sign;

	sign = 1;
	res = 0;
	if ((9 <= *nptr && *nptr <= 13) || *nptr == 32)
		return (0);
	if (*nptr == '-' || *nptr == '+')
		return (0);
	while ('0' <= *nptr && *nptr <= '9')
	{
		res = res * 10 + *nptr - '0';
		++nptr;
	}
	if (*nptr != '\0')
		return (0);
	return (res * sign);
}

void	sending_sig(int pid, char *str)
{
	int	bit_cnt;
	int	bit_tmp;
	int	sig_chk;

	sig_chk = 0;
	while (*str)
	{
		bit_cnt = 0;
		while (bit_cnt < 8)
		{
			if (g_flag)
			{
				g_flag = 0;
				bit_tmp = *str >> (7 - bit_cnt) & 1;
				if (bit_tmp == 0)
					sig_chk = kill(pid, SIGUSR1);
				else if (bit_tmp == 1)
					sig_chk = kill(pid, SIGUSR2);
				if (sig_chk == -1)
					exit (1);
				++bit_cnt;
			}
		}
		++str;
	}
}

void	sending_str(int pid, char *str)
{
	struct sigaction	s_sa;

	if (!str)
		exit (1);
	sigemptyset(&s_sa.sa_mask);
	sigaddset(&s_sa.sa_mask, SIGUSR1);
	sigaddset(&s_sa.sa_mask, SIGUSR2);
	s_sa.sa_sigaction = get_sig;
	s_sa.sa_flags = SA_SIGINFO;
	sigaction(SIGUSR1, &s_sa, NULL);
	sending_sig(pid, str);
	exit (0);
}

int	main(int argc, char *argv[])
{
	pid_t	pid;

	if (argc != 3)
	{
		write(1, "Wrong Argument\n", 16);
		exit (1);
	}
	pid = ft_atoi(argv[1]);
	if (pid < 100 || pid > 99998)
	{
		write(1, "invalid PID\n", 12);
		exit (1);
	}
	sending_str(pid, argv[2]);
	return (0);
}
