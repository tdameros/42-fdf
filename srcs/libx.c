/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libx.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdameros <tdameros@student.42lyon.f>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/29 21:35:30 by tdameros          #+#    #+#             */
/*   Updated: 2022/11/29 21:38:13 by tdameros         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libx.h"

static void	libx_put_line_dx_greater(t_img *image,
				t_point point1, t_point point2, int color);
static void	libx_put_line_dy_greater(t_img *image,
				t_point point1, t_point point2, int color);

/**
 * Create mlx image in structure with all data.
 * @return t_img struct allocated or NULL if there is an error
 */
t_img	*libx_create_image(void *mlx_ptr, int width, int height)
{
	t_img	*image;

	image = malloc(sizeof(t_img));
	if (image == NULL)
		return (NULL);
	image->img = mlx_new_image(mlx_ptr, width, height);
	image->width = width;
	image->height = height;
	image->addr = mlx_get_data_addr(image->img, &image->bits_per_pixel,
			&image->line_length, &image->endian);
	return (image);
}

/**
 * Put a pixel in mlx image (protected if the pixel is outside the image).
 */
void	libx_put_pixel(t_img *image, t_point point, int color)
{
	char	*dst;

	if (point.x >= image->width || point.y >= image->height
		|| point.x < 0 || point.y < 0)
		return ;
	dst = image->addr + (point.y * image->line_length
			+ point.x * (image->bits_per_pixel / 8));
	*(unsigned int *) dst = color;
}

/**
 * Put a line between 2 points in mlx image.
 * (protected if there are pixels is outside the image)
 */
void	libx_put_line(t_img *image, t_point point1, t_point point2, int color)
{
	double	dx;
	double	dy;

	dx = fabs((double) point2.x - point1.x);
	dy = fabs((double) point2.y - point1.y);
	if (dx >= dy)
		libx_put_line_dx_greater(image, point1, point2, color);
	else
		libx_put_line_dy_greater(image, point1, point2, color);
}

/**
 * Put a line between 2 points in mlx image if dx is greater.
 * (protected if there are pixels is outside the image)
 */
static void	libx_put_line_dx_greater(t_img *image,
									t_point point1, t_point point2, int color)
{
	const double	dx = fabs((double) point2.x - point1.x);
	const double	dy = fabs((double) point2.y - point1.y);
	const double	m = dy / dx;
	double			e;
	int				i;

	i = 0;
	e = 0;
	while (i++ <= dx)
	{
		libx_put_pixel(image, point1, color);
		if (point1.x > point2.x)
			point1.x--;
		else
			point1.x++;
		e -= m;
		if (e <= -0.5)
		{
			if (point1.y > point2.y)
				point1.y--;
			else
				point1.y++;
			e += 1;
		}
	}
}

/**
 * Put a line between 2 points in mlx image if dy is greater.
 * (protected if there are pixels is outside the image)
 */
static void	libx_put_line_dy_greater(t_img *image,
									t_point point1, t_point point2, int color)
{
	const double	dx = fabs((double) point2.x - point1.x);
	const double	dy = fabs((double) point2.y - point1.y);
	const double	m = dx / dy;
	double			e;
	int				i;

	i = 0;
	e = 0;
	while (i++ <= dy)
	{
		libx_put_pixel(image, point1, color);
		if (point1.y > point2.y)
			point1.y--;
		else
			point1.y++;
		e -= m;
		if (e <= -0.5)
		{
			if (point1.x > point2.x)
				point1.x--;
			else
				point1.x++;
			e += 1;
		}
	}
}
