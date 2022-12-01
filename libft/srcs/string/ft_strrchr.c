/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdameros <tdameros@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/06 23:42:47 by tdameros          #+#    #+#             */
/*   Updated: 2022/11/07 21:38:02 by tdameros         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	size_t	index;

	index = ft_strlen(s);
	while (index > 0)
	{
		if (s[index] == (char) c)
			return ((char *) s + index);
		index--;
	}
	if (s[index] == (char) c)
		return ((char *) s + index);
	return (NULL);
}
