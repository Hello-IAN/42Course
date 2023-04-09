/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_objects_optionfree.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yomin <yomin@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/16 21:17:55 by yomin             #+#    #+#             */
/*   Updated: 2023/02/16 21:17:56 by yomin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/parser.h"

/* free if a success to convert */
void	free_input_objects(t_info *info, t_options *options)
{
	int	i;
	int	j;

	i = options->option_cnt;
	while (0 < i--)
	{
		j = -1;
		while (options->option[i][++j])
			free(options->option[i][j]);
		free(options->option[i]);
	}
	free(options);
	free(info);
}
