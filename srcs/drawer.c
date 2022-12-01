/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   drawer.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdameros <tdameros@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/29 18:12:39 by tdameros          #+#    #+#             */
/*   Updated: 2022/12/01 22:03:40 by tdameros         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "drawer.h"

int	draw_map(t_wireframe *wireframe)
{
	t_map			*map;
	t_img			*image;
	t_properties	properties;
	size_t			x;

	x = 0;
	map = wireframe->map;
	properties = wireframe->properties;
	image = libx_create_image(wireframe->mlx_ptr,
			properties.win_width, properties.win_height);
	if (image == NULL)
		return (0);
	free_image(wireframe);
	wireframe->image = image;
	while (x < map->width)
	{
		draw_column(map, properties, image, x);
		x++;
	}
	mlx_put_image_to_window(wireframe->mlx_ptr,
		wireframe->win_ptr, image->img, 0, 0);
	draw_shortcuts_info(wireframe);
	if (!draw_properties_info(wireframe))
		return (0);
	return (1);
}

int	draw_properties_info(t_wireframe *wireframe)
{
	const t_properties	properties = wireframe->properties;
	int					count;

	count = 0;
	count += draw_int(wireframe, 900, 50, properties.origin_point.x);
	count += draw_int(wireframe, 950, 50, properties.origin_point.y);
	mlx_string_put(wireframe->mlx_ptr, wireframe->win_ptr, 820, 50,
		0x00FFFFFF, "Origin:");
	mlx_string_put(wireframe->mlx_ptr, wireframe->win_ptr, 820, 80,
		0x00FFFFFF, "Altitude:");
	count += draw_int(wireframe, 950, 80, properties.altitude);
	mlx_string_put(wireframe->mlx_ptr, wireframe->win_ptr, 820, 110,
		0x00FFFFFF, "Distance:");
	count += draw_int(wireframe, 950, 110, properties.distance);
	mlx_string_put(wireframe->mlx_ptr, wireframe->win_ptr, 820, 140,
		0x00FFFFFF, "View:");
	count += draw_int(wireframe, 950, 140, properties.view);
	if (count != 5)
	{
		raise_allocation_error();
		return (0);
	}
	return (1);
}

void	draw_shortcuts_info(t_wireframe *wireframe)
{
	mlx_string_put(wireframe->mlx_ptr, wireframe->win_ptr,
		40, 50, FONT_COLOR, "| Keyboard Shortcuts |");
	mlx_string_put(wireframe->mlx_ptr, wireframe->win_ptr,
		40, 80, FONT_COLOR, "Translation : arrows");
	mlx_string_put(wireframe->mlx_ptr, wireframe->win_ptr,
		40, 110, FONT_COLOR, "Zoom : mouse scroll");
	mlx_string_put(wireframe->mlx_ptr, wireframe->win_ptr,
		40, 140, FONT_COLOR, "Modify altitude : w and s");
	mlx_string_put(wireframe->mlx_ptr, wireframe->win_ptr,
		40, 170, FONT_COLOR, "Change View : a and b");
	mlx_string_put(wireframe->mlx_ptr, wireframe->win_ptr,
		40, 200, FONT_COLOR, "Reset View : F5");
	mlx_string_put(wireframe->mlx_ptr, wireframe->win_ptr,
		40, 230, FONT_COLOR, "Close Window : ESC");
}
