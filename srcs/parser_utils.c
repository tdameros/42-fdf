/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdameros <tdameros@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/23 15:03:23 by tdameros          #+#    #+#             */
/*   Updated: 2022/11/23 15:14:08 by tdameros         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

/**
 * @param split_lines a list with each line separated by spaces
 * @return two-dimensional integer tab (allocate)
 */
int	**convert_split_lines_to_int_tab(t_list *split_lines, t_map *map)
{
	int		**tab_of_int_tab;
	size_t	index;

	index = 0;
	tab_of_int_tab = malloc(sizeof(int *) * map->height);
	if (tab_of_int_tab == NULL)
		return (raise_allocation_error());
	while (split_lines != NULL)
	{
		tab_of_int_tab[index] = convert_split_line_to_int_tab(
				split_lines->content, map->width);
		if (tab_of_int_tab[index] == NULL)
			return (free_int_tab(tab_of_int_tab, map->width));
		index++;
		split_lines = split_lines->next;
	}
	return (tab_of_int_tab);
}

/**
 * @param line split
 * @return allocate int tab
 */
int	*convert_split_line_to_int_tab(char **line, size_t len)
{
	int		*int_tab;
	size_t	index;

	index = 0;
	int_tab = malloc(sizeof(int) * len);
	if (int_tab == NULL)
		return (raise_allocation_error());
	while (line[index] != NULL)
	{
		int_tab[index] = ft_atoi(line[index]);
		index++;
	}
	return (int_tab);
}

/**
 * @return NULL pointer
 */
int	**free_int_tab(int **int_tab, size_t len)
{
	size_t	index;

	index = 0;
	while (index < len)
	{
		free(int_tab[index]);
		index++;
	}
	free(int_tab);
	return (NULL);
}

/**
 * @param map with a defined height to free the int tab
 */
void	free_map(t_map *map)
{
	size_t	index;

	index = 0;
	while (index < map->height)
	{
		free(map->map[index]);
		index++;
	}
	free(map->map);
	free(map);
}

/**
 * @param tab of char * (line).
 */
void	free_split(void *tab)
{
	char	**split_tab;

	split_tab = (char **) tab;
	while (*split_tab != NULL)
	{
		free(*split_tab);
		split_tab++;
	}
	free(tab);
}
