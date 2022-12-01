/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdameros <tdameros@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/01 22:49:26 by tdameros          #+#    #+#             */
/*   Updated: 2022/12/01 22:49:27 by tdameros         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "wireframe.h"

t_properties	get_default_properties(t_map *map)
{
	t_properties	properties;

	properties.win_height = WINDOW_HEIGHT;
	properties.win_width = WINDOW_WIDTH;
	properties.origin_point.x = ORIGIN_POINT_X;
	properties.origin_point.y = ORIGIN_POINT_Y;
	properties.altitude = 100 / (get_max_altitude(map) + 1);
	if (properties.altitude == 0)
		properties.altitude = 1;
	properties.distance = DISTANCE;
	properties.view = VIEW;
	properties.color = MAP_COLOR;
	return (properties);
}

int	get_max_altitude(t_map *map)
{
	size_t	x;
	size_t	y;
	int		max;

	x = 0;
	y = 0;
	max = map->map[0][0];
	while (y < map->height)
	{
		x = 0;
		while (x < map->width)
		{
			if (map->map[y][x] > max)
				max = map->map[y][x];
			x++;
		}
		y++;
	}
	return (max);
}

t_wireframe	*create_wireframe(t_map *map, char *name_window)
{
	t_wireframe		*manager;
	t_properties	properties;

	properties = get_default_properties(map);
	manager = malloc(sizeof(t_wireframe));
	if (manager == NULL)
		return (raise_allocation_error());
	manager->properties = properties;
	manager->mlx_ptr = mlx_init();
	manager->win_ptr = mlx_new_window(manager->mlx_ptr,
			properties.win_width, properties.win_height, name_window);
	manager->image = libx_create_image(manager->mlx_ptr,
			properties.win_width, properties.win_height);
	manager->map = map;
	return (manager);
}
