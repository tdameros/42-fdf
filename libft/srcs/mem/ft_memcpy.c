/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdameros <tdameros@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/06 23:40:58 by tdameros          #+#    #+#             */
/*   Updated: 2022/10/08 22:26:57 by tdameros         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	size_t			index;
	unsigned char	*dest_char_ptr;
	unsigned char	*src_char_ptr;

	dest_char_ptr = (unsigned char *) dest;
	src_char_ptr = (unsigned char *) src;
	index = 0;
	while (index < n)
	{
		dest_char_ptr[index] = src_char_ptr[index];
		index++;
	}
	return (dest_char_ptr);
}
