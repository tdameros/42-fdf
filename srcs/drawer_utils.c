/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_map_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdameros <tdameros@student.42lyon.f>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/30 16:17:38 by tdameros          #+#    #+#             */
/*   Updated: 2022/11/30 16:22:40 by tdameros         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "drawer.h"

/**
 * Draw wireframe map column in the mlx image.
 * @param x index of the column
 */
void	draw_column(t_map *map, t_properties properties, t_img *image, size_t x)
{
	size_t	y;
	t_point	point1;
	t_point	point2;

	y = 0;
	while (y < map->height)
	{
		if (y + 1 < map->height)
		{
			point1 = get_image_coord(y, x, map->map[y][x], properties);
			point2 = get_image_coord(y + 1, x, map->map[y + 1][x], properties);
			libx_put_line(image, point1, point2, properties.color);
		}
		if (x + 1 < map->width)
		{
			point1 = get_image_coord(y, x, map->map[y][x], properties);
			point2 = get_image_coord(y, x + 1, map->map[y][x + 1], properties);
			libx_put_line(image, point1, point2, properties.color);
		}
		y++;
	}
}

/**
 * Get image coordinates with wireframe map index.
 * @param x column index
 * @param y row index
 */
t_point	get_image_coord(size_t x, size_t y, size_t height,
						t_properties properties)
{
	t_point	image_point;
	t_point	origin_point;
	double	radian;

	origin_point = properties.origin_point;
	radian = degree_to_radian(properties.view / 2);
	image_point.x = origin_point.x
		- (x * sin(radian) * properties.distance);
	image_point.y = origin_point.y
		+ (x * cos(radian) * properties.distance);
	image_point.x += (y * sin(radian) * properties.distance);
	image_point.y += (y * cos(radian) * properties.distance);
	image_point.y -= height * properties.altitude;
	return (image_point);
}

double	degree_to_radian(double degree)
{
	return (((2 * M_PI) / 360) * degree);
}

/**
 * Draw int value in window.
 * @return 1 if properties are correctly draw else 0
 */
int	draw_int(t_wireframe *wireframe, int x, int y, int number)
{
	char	*conversion;

	conversion = ft_itoa(number);
	if (conversion == NULL)
		return (0);
	mlx_string_put(wireframe->mlx_ptr, wireframe->win_ptr,
		x, y, FONT_COLOR, conversion);
	free(conversion);
	return (1);
}

void	*free_image(t_wireframe *wireframe)
{
	mlx_destroy_image(wireframe->mlx_ptr, wireframe->image->img);
	free(wireframe->image);
	return (NULL);
}
