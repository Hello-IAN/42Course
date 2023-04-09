/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libftprintf.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yomin <yomin@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/20 02:18:19 by yomin             #+#    #+#             */
/*   Updated: 2022/04/20 02:18:24 by yomin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFTPRINTF_H
# define LIBFTPRINTF_H

# include <unistd.h>
# include <stdarg.h>

int	find_form(va_list ap, const char c);
int	ft_printf(const char *s, ...);
int	p_put_addr(void *addr);
int	p_put_char(int n);
int	p_put_hex(unsigned int n, char c);
int	p_put_nbr(long n);
int	p_put_str(char *_str);

#endif
