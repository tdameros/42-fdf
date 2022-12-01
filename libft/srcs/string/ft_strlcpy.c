/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdameros <tdameros@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/06 23:41:34 by tdameros          #+#    #+#             */
/*   Updated: 2022/10/08 22:28:28 by tdameros         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t size)
{
	size_t	index;
	size_t	len;

	len = ft_strlen(src);
	index = 0;
	if (size == 0)
		return (len);
	while (src[index] != '\0' && (size - 1) > 0)
	{
		dst[index] = src[index];
		index++;
		size--;
	}
	dst[index] = '\0';
	return (len);
}
