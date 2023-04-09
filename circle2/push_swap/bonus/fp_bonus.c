/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fp_bonus.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yomin <yomin@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/18 17:13:15 by yomin             #+#    #+#             */
/*   Updated: 2022/09/18 17:13:17 by yomin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

int	case_rot(char *str, t_deque *a, t_deque *b)
{
	if (*str == 'a' && *(str + 1) == '\n')
		return (rot_a(a));
	else if (*str == 'b' && *(str + 1) == '\n')
		return (rot_b(b));
	else if (*(str++) == 'r')
	{
		if (*str == '\n')
			return (rot_rr(a, b));
		else if (*str == 'a' && *(str + 1) == '\n')
			return (rrot_a(a));
		else if (*str == 'b' && *(str + 1) == '\n')
			return (rrot_b(b));
		else if (*str == 'r' && *(str + 1) == '\n')
			return (rrot_rr(a, b));
	}
	return (ERROR);
}

int	select_func(char *str, t_deque *a, t_deque *b)
{
	if (*(str) == 's')
	{
		if (*(++str) == 'a' && *(str + 1) == '\n')
			return (swap_a(a));
		else if (*str == 'b' && *(str + 1) == '\n')
			return (swap_b(b));
		else if (*str == 's' && *(str + 1) == '\n')
			return (swap_ss(a, b));
	}
	else if (*(str) == 'p')
	{
		if (*(++str) == 'a' && *(str + 1) == '\n')
			return (push_a(a, b));
		else if (*str == 'b' && *(str + 1) == '\n')
			return (push_b(a, b));
	}
	else if (*(str) == 'r')
		return (case_rot(++str, a, b));
	return (ERROR);
}

int	calling_op(char *str, t_deque *a, t_deque *b)
{	
	if (select_func(str, a, b) == ERROR)
		print_error("Error\n");
	return (0);
}
