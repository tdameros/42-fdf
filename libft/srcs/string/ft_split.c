/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdameros <tdameros@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/09 16:15:44 by tdameros          #+#    #+#             */
/*   Updated: 2022/11/08 16:23:58 by tdameros         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	get_next_str(char const *s, char c, size_t index);
static int	get_next_delim(char const *s, char c, size_t index);
static void	*clear_tab(char **tab);
static int	count_strs(char const *s, char c);

char	**ft_split(char const *s, char c)
{
	char	**tab_strs;
	size_t	index_tab;
	size_t	index_str;
	size_t	index_delim;

	if (s == NULL)
		return (NULL);
	tab_strs = malloc(sizeof(char *) * (count_strs(s, c) + 1));
	if (tab_strs == NULL)
		return (NULL);
	index_tab = 0;
	index_str = get_next_str(s, c, 0);
	while (s[index_str] != '\0')
	{
		index_delim = get_next_delim(s, c, index_str);
		tab_strs[index_tab] = ft_substr(s, index_str, index_delim - index_str);
		if (tab_strs[index_tab] == NULL)
			return (clear_tab(tab_strs));
		index_str = get_next_str(s, c, index_delim);
		index_tab++;
	}
	tab_strs[index_tab] = NULL;
	return (tab_strs);
}

static int	count_strs(char const *s, char c)
{
	size_t	index;
	size_t	count;

	index = 0;
	count = 0;
	index = get_next_str(s, c, index);
	while (s[index] != '\0')
	{
		index = get_next_delim(s, c, index);
		index = get_next_str(s, c, index);
		count++;
	}
	return (count);
}

static int	get_next_str(char const *s, char c, size_t index)
{
	while (s[index] == c && s[index] != '\0')
		index++;
	return (index);
}

static int	get_next_delim(char const *s, char c, size_t index)
{
	while (s[index] != c && s[index] != '\0')
		index++;
	return (index);
}

static void	*clear_tab(char **tab)
{
	size_t	index;

	index = 0;
	while (tab[index] != NULL)
	{
		free(tab[index]);
		index++;
	}
	free(tab);
	return (NULL);
}
