/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdameros <tdameros@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/08 23:56:58 by tdameros          #+#    #+#             */
/*   Updated: 2022/11/08 00:11:53 by tdameros         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	is_in_set(char c, char const *set);

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t	index_start;
	size_t	index_end;

	if (s1 == NULL || set == NULL)
		return (NULL);
	index_start = 0;
	index_end = ft_strlen(s1) - 1;
	while (s1[index_start] != '\0' && is_in_set(s1[index_start], set))
		index_start++;
	while (index_end > index_start && is_in_set(s1[index_end], set))
		index_end--;
	return (ft_substr(s1, index_start, index_end - index_start + 1));
}

static int	is_in_set(char c, char const *set)
{
	size_t	index;

	index = 0;
	while (set[index] != '\0')
	{
		if (c == set[index])
			return (1);
		index++;
	}
	return (0);
}
