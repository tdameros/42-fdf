/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wireframe.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdameros <tdameros@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/01 22:56:47 by tdameros          #+#    #+#             */
/*   Updated: 2022/12/01 23:03:25 by tdameros         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef WIREFRAME_H
# define WIREFRAME_H

# include "libx.h"
# include "parser.h"

/* Inputs */
# ifdef __APPLE__
#  define LEFT_ARROW_KEY 123
#  define RIGHT_ARROW_KEY 124
#  define UP_ARROW_KEY 126
#  define DOWN_ARROW_KEY 125
#  define W_LOWER_KEY 13
#  define S_LOWER_KEY 1
#  define A_LOWER_KEY 0
#  define D_LOWER_KEY 2
#  define ESC_KEY 53
#  define F5_KEY 96
# else
#  define LEFT_ARROW_KEY 65361
#  define RIGHT_ARROW_KEY 65363
#  define UP_ARROW_KEY 65362
#  define DOWN_ARROW_KEY 65364
#  define W_LOWER_KEY 119
#  define S_LOWER_KEY 115
#  define A_LOWER_KEY 97
#  define D_LOWER_KEY 100
#  define ESC_KEY 65307
#  define F5_KEY 65474
# endif

# define MOUSE_SCROLL_UP 5
# define MOUSE_SCROLL_DOWN 4

/* Properties */
# define WINDOW_HEIGHT 1000
# define WINDOW_WIDTH 1000
# define ORIGIN_POINT_X 500
# define ORIGIN_POINT_Y 500
# define DISTANCE 10
# define VIEW 120

# define FONT_COLOR 0x00FFFFFF
# define MAP_COLOR 0x0013ebe7

typedef struct s_properties {
	size_t	win_width;
	size_t	win_height;
	t_point	origin_point;
	int		altitude;
	size_t	distance;
	double	view;
	int		color;
	double	zoom;
}			t_properties;

typedef struct s_wireframe {
	void			*mlx_ptr;
	void			*win_ptr;
	t_img			*image;
	t_properties	properties;
	t_map			*map;

}			t_wireframe;

/* Main */
void			close_window(t_wireframe *manager, int exit_code);
int				mouse_hook(int keycode, int x, int y, void *param);
int				keyboard_loop(int keycode, void *param);
int				close_icon(void *param);

/* Utils */
t_properties	get_default_properties(t_map *map);
int				get_max_altitude(t_map *map);
t_wireframe		*create_wireframe(t_map *map, char *name_window);

#endif
