/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cam.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mingylee <mingylee@student.42seoul.kr      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/01 12:57:12 by mingylee          #+#    #+#             */
/*   Updated: 2023/02/02 08:45:58 by mingylee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CAM_H
# define CAM_H

# include "vars.h"

void		set_cam_dir(t_vars *vars, t_camera *cam);
t_camera	*init_camera(t_point3 camera_origin, \
					t_point3 camera_dir, int image_width, int image_height);
void		control_camera(t_vars *vars);

#endif
