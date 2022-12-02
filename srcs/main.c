/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdameros <tdameros@student.42lyon.f>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/29 22:15:41 by tdameros          #+#    #+#             */
/*   Updated: 2022/11/29 22:16:43 by tdameros         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libx.h"
#include "parser.h"
#include "wireframe.h"
#include "drawer.h"

int	main(int argc, char **argv)
{
	t_map		*map;
	t_wireframe	*wireframe;

	if (argc == 2)
	{
		map = parse_map(argv[1]);
		if (map == NULL)
			exit(EXIT_FAILURE);
		wireframe = create_wireframe(map, argv[1]);
		if (wireframe == NULL)
		{
			free_map(map);
			exit(EXIT_FAILURE);
		}
		mlx_hook(wireframe->win_ptr, 2, (1L << 0), keyboard_loop, wireframe);
		mlx_hook(wireframe->win_ptr, 17, (1L << 3), close_icon, wireframe);
		mlx_mouse_hook(wireframe->win_ptr, mouse_hook, wireframe);
		if (!draw_map(wireframe))
			close_window(wireframe, EXIT_FAILURE);
		mlx_loop(wireframe->mlx_ptr);
	}
	else
		ft_putendl_fd("Please add param : ./fdf *.fdf", 1);
	exit(EXIT_FAILURE);
	return (0);
}

int	mouse_hook(int keycode, int x, int y, void *param)
{
	t_wireframe	*wireframe;

	(void) x;
	(void) y;
	wireframe = (t_wireframe *) param;
	if (keycode == MOUSE_SCROLL_UP)
		wireframe->properties.distance += 1;
	if (keycode == MOUSE_SCROLL_DOWN && wireframe->properties.distance >= 2)
		wireframe->properties.distance -= 1;
	if (!draw_map(wireframe))
		close_window(wireframe, EXIT_FAILURE);
	return (1);
}

int	keyboard_loop(int keycode, void *param)
{
	t_wireframe	*wireframe;

	wireframe = (t_wireframe *) param;
	if (keycode == ESC_KEY)
		close_window(wireframe, EXIT_SUCCESS);
	wireframe->properties.origin_point.x -= 10 * (keycode == LEFT_ARROW_KEY);
	wireframe->properties.origin_point.x += 10 * (keycode == RIGHT_ARROW_KEY);
	wireframe->properties.origin_point.y -= 10 * (keycode == UP_ARROW_KEY);
	wireframe->properties.origin_point.y += 10 * (keycode == DOWN_ARROW_KEY);
	wireframe->properties.altitude += 1 * (keycode == W_LOWER_KEY);
	wireframe->properties.altitude -= 1 * (keycode == S_LOWER_KEY);
	wireframe->properties.view -= 3 * (keycode == A_LOWER_KEY);
	wireframe->properties.view += 3 * (keycode == D_LOWER_KEY);
	if (keycode == F5_KEY)
		wireframe->properties = get_default_properties(wireframe->map);
	if (!draw_map(wireframe))
		close_window(wireframe, EXIT_FAILURE);
	return (1);
}

int	close_icon(void *param)
{
	close_window(param, EXIT_SUCCESS);
	return (1);
}

/**
 * Free all data in wireframe struct and exit this program.
 */
void	close_window(t_wireframe *wireframe, int exit_code)
{
	free_int_tab(wireframe->map->map, wireframe->map->height);
	free(wireframe->map);
	free_image(wireframe);
	mlx_destroy_window(wireframe->mlx_ptr, wireframe->win_ptr);
	free(wireframe);
	exit(exit_code);
}
