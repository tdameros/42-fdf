/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdameros <tdameros@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/06 23:06:10 by tdameros          #+#    #+#             */
/*   Updated: 2022/10/08 22:28:13 by tdameros         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	len_src;
	size_t	len_dst;
	size_t	index_dst;
	size_t	index_src;

	len_src = ft_strlen(src);
	len_dst = ft_strlen(dst);
	index_src = 0;
	index_dst = 0;
	if (len_dst + 1 > size)
		return (len_src + size);
	index_dst = len_dst;
	while (src[index_src] != '\0' && index_dst + 1 < size)
	{
		dst[index_dst] = src[index_src];
		index_dst++;
		index_src++;
	}
	dst[index_dst] = '\0';
	return (len_dst + len_src);
}
