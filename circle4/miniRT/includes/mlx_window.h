/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_window.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yomin <yomin@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/16 21:27:19 by yomin             #+#    #+#             */
/*   Updated: 2023/02/16 21:27:20 by yomin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MLX_WINDOW_H
# define MLX_WINDOW_H

# include "../minilibx_mms_20200219/mlx.h"
# include "../minilibx_opengl_20191021/mlx.h"

# include "vars.h"

int		write_color(int a, t_color pixel_color);

int		camera_key_hook(int keycode, t_vars *vars);
int		light_key_hook(int keycode, t_vars *vars);
int		key_hook(int keycode, t_vars *vars);

void	draw_test(t_vars *vars);
void	put_pixel_to_window(t_img_data *img, int x, int y, int color);
void	camera_key_hook_org(int keycode, t_vars *vars);
void	camera_key_hook_dir(int keycode, t_vars *vars);
#endif
