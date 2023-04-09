/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yomin <yomin@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/18 17:29:49 by yomin             #+#    #+#             */
/*   Updated: 2022/09/18 17:29:50 by yomin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	isntinteger(long long res)
{
	if (res < -2147483648 || res > 2147483647)
		return (1);
	return (0);
}

int	ft_atoi(const char *nptr)
{
	long long	res;
	int			sign;

	sign = 1;
	res = 0;
	if ((9 <= *nptr && *nptr <= 13) || *nptr == 32)
		++nptr;
	if (*nptr == '-' || *nptr == '+')
	{
		if (*nptr == '-')
			sign *= -1;
		++nptr;
	}
	if (*nptr < '0' || *nptr > '9')
		print_error("invalid_input_error, value is not number\n");
	while (*nptr && '0' <= *nptr && *nptr <= '9')
	{
		res = res * 10 + *nptr - '0';
		++nptr;
	}
	if (isntinteger(res * sign))
		print_error("argument(s) exceeds integer range\n");
	return (res * sign);
}

void	free_values(char *s1, char **s2, t_deque *deque)
{
	int		i;
	t_node	*node;

	if (s1)
		free(s1);
	if (s2)
	{
		i = 0;
		while (s2[i])
			free(s2[i++]);
		free(s2);
	}
	if (deque)
	{
		i = 0;
		while (deque->head)
		{
			node = deque->head->next;
			free(deque->head);
			deque->head = node;
		}
		free(deque);
	}
}

void	print_error(const char *str)
{
	while (*str)
		write(2, str++, 1);
	exit(1);
}
