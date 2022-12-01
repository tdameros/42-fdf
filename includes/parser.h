/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdameros <tdameros@student.42lyon.f>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/20 14:36:27 by tdameros          #+#    #+#             */
/*   Updated: 2022/11/20 14:36:32 by tdameros         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSER_H
# define PARSER_H

# include <fcntl.h>
# include <stdlib.h>
# include "../libft/incs/ft_libc.h"
# include "errors.h"

typedef struct s_map {
	size_t	width;
	size_t	height;
	int		**map;
}				t_map;

t_map	*parse_map(char *file);
t_list	*read_file_with_split_lines(int fd);
t_map	*generate_map(t_list *split_lines);
int		get_map_size(t_list *split_lines, t_map *map);
size_t	tab_len(char **tab);

int		**convert_split_lines_to_int_tab(t_list *split_lines, t_map *map);
int		*convert_split_line_to_int_tab(char **line, size_t len);
void	free_map(t_map *map);
void	free_split(void *tab);
int		**free_int_tab(int **int_tab, size_t len);

#endif
