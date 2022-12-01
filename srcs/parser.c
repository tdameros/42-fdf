/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdameros <tdameros@student.42lyon.f>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/20 14:38:37 by tdameros          #+#    #+#             */
/*   Updated: 2022/11/20 14:38:38 by tdameros         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

/**
 * Parse only .fdf file.
 * @param file name or path of the file
 * @return a map structure or NULL if there is an error
 */
t_map	*parse_map(char *file)
{
	int		fd;
	t_list	*split_lines;
	t_map	*map;

	fd = open(file, O_DIRECTORY);
	if (fd > 0)
		return (close(fd), raise_file_error());
	fd = open(file, O_RDONLY);
	if (fd < 0)
		return (raise_file_error());
	split_lines = read_file_with_split_lines(fd);
	close(fd);
	if (split_lines == NULL)
		return (raise_invalid_map_error());
	map = generate_map(split_lines);
	ft_lstclear(&split_lines, free_split);
	return (map);
}

/**
 * Reads an entire file from a file descriptor.
 * Each line is separated on space characters
 * and then stored in a list.
 * @return a list or NULL if there is an error
 */
t_list	*read_file_with_split_lines(int fd)
{
	t_list	*list;
	t_list	*new_node;
	char	*line;
	char	**split_line;

	list = NULL;
	line = get_next_line(fd);
	split_line = ft_split(line, ' ');
	free(line);
	while (line != NULL)
	{
		new_node = ft_lstnew(split_line);
		if (new_node == NULL)
		{
			free_split(split_line);
			raise_allocation_error();
			return (ft_lstclear(&list, free_split));
		}
		ft_lstadd_back(&list, new_node);
		line = get_next_line(fd);
		split_line = ft_split(line, ' ');
		free(line);
	}
	return (list);
}

/**
 * Generate map structure.
 * @param split_lines a list with each line separated by spaces
 * @return map structure or NULL if there is an error
 */
t_map	*generate_map(t_list *split_lines)
{
	t_map	*map;
	int		**tab_of_int_tab;

	map = malloc(sizeof(t_map));
	if (map == NULL)
		return (raise_allocation_error());
	if (!get_map_size(split_lines, map))
	{
		free(map);
		return (raise_invalid_map_error());
	}
	tab_of_int_tab = convert_split_lines_to_int_tab(split_lines, map);
	if (tab_of_int_tab == NULL)
	{
		free(map);
		return (raise_allocation_error());
	}
	map->map = tab_of_int_tab;
	return (map);
}

/**
 * Recover the size of a map and save it in the map structure.
 * @param split_lines a list with each line separated by spaces
 * @return 1 if all lines have the same length else 0
 */
int	get_map_size(t_list *split_lines, t_map *map)
{
	size_t	width;

	map->width = tab_len(split_lines->content);
	map->height = 1;
	split_lines = split_lines->next;
	while (split_lines != NULL)
	{
		width = tab_len(split_lines->content);
		if (width != map->width)
			return (0);
		split_lines = split_lines->next;
		map->height += 1;
	}
	return (1);
}

/**
 * @param tab with NULL delimiter
 * @return length of the split tab.
 */
size_t	tab_len(char **tab)
{
	size_t	len;

	len = 0;
	while (*tab != NULL)
	{
		tab++;
		len++;
	}
	return (len);
}
