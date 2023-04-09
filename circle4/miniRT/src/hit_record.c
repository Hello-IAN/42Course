/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hit_record.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mingylee <mingylee@student.42seoul.kr      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/18 18:44:06 by mingylee          #+#    #+#             */
/*   Updated: 2023/01/18 20:41:46 by mingylee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/vec.h"
#include "../includes/vars.h"
#include "../includes/object.h"
#include <math.h>

t_hit_record	init_record(void)
{
	t_hit_record	record;

	record.tmin = 1e-6;
	record.tmax = INFINITY;
	return (record);
}
