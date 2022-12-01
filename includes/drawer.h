/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   drawer.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdameros <tdameros@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/01 23:07:14 by tdameros          #+#    #+#             */
/*   Updated: 2022/12/01 23:07:15 by tdameros         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef DRAWER_H
# define DRAWER_H

# include <math.h>
# include "libx.h"
# include "wireframe.h"

// draw_map
int		draw_map(t_wireframe *wireframe);
int		draw_properties_info(t_wireframe *wireframe);
void	draw_shortcuts_info(t_wireframe *wireframe);

// draw_map_utils
void	draw_column(t_map *map, t_properties properties,
			t_img *image, size_t x);
t_point	get_image_coord(size_t x, size_t y, size_t height,
			t_properties properties);
double	degree_to_radian(double degree);
int		draw_int(t_wireframe *wireframe, int x, int y, int number);
void	*free_image(t_wireframe *wireframe);

#endif
