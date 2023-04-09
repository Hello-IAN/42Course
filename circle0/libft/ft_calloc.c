/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yomin <yomin@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/14 21:08:54 by yomin             #+#    #+#             */
/*   Updated: 2022/04/14 21:09:09 by yomin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t nmemb, size_t size)
{
	unsigned char	*ret_arr;

	ret_arr = (unsigned char *)malloc(nmemb * size);
	if (!ret_arr)
		return (NULL);
	ft_bzero(ret_arr, (nmemb * size));
	return ((void *)ret_arr);
}
