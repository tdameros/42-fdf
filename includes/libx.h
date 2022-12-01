/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libx.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdameros <tdameros@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/01 23:08:33 by tdameros          #+#    #+#             */
/*   Updated: 2022/12/01 23:08:35 by tdameros         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBX_H
# define LIBX_H

# include <stdlib.h>
# include <math.h>
# include "mlx.h"

typedef struct s_point {
	int	x;
	int	y;
}			t_point;

typedef struct s_img {
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
	int		width;
	int		height;
}			t_img;

t_img	*libx_create_image(void *mlx_ptr, int width, int height);
void	libx_put_pixel(t_img *image, t_point point, int color);
void	libx_put_line(t_img *image, t_point point1, t_point point2, int color);
void	libx_put_line_dx_greater(t_img *image, t_point point1, t_point point2,
			int color);
void	libx_put_line_dy_greater(t_img *image, t_point point1, t_point point2,
			int color);

#endif
