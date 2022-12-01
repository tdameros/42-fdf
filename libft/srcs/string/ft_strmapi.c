/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdameros <tdameros@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/11 12:48:29 by tdameros          #+#    #+#             */
/*   Updated: 2022/11/08 00:15:59 by tdameros         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	size_t	len_s;
	size_t	index;
	char	*str_map;

	if (s == NULL || f == NULL)
		return (NULL);
	len_s = ft_strlen(s);
	str_map = malloc(sizeof(char) * (len_s + 1));
	if (str_map == NULL)
		return (NULL);
	index = 0;
	while (index < len_s)
	{
		str_map[index] = f(index, s[index]);
		index++;
	}
	str_map[len_s] = '\0';
	return (str_map);
}
