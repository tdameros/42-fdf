/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdameros <tdameros@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/06 23:42:27 by tdameros          #+#    #+#             */
/*   Updated: 2022/11/06 16:36:18 by tdameros         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	*memmove_dest_greater_src(char *dest, char *src, size_t n);
static void	*memmove_src_greater_dest(char *dest, char *src, size_t n);

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	char	*dest_char_ptr;
	char	*src_char_ptr;

	dest_char_ptr = (char *) dest;
	src_char_ptr = (char *) src;
	if (dest >= src)
		return (memmove_dest_greater_src(dest_char_ptr, src_char_ptr, n));
	else
		return (memmove_src_greater_dest(dest_char_ptr, src_char_ptr, n));
}

static void	*memmove_dest_greater_src(char *dest, char *src, size_t n)
{
	while (n)
	{
		dest[n - 1] = src[n - 1];
		n--;
	}
	return ((void *) dest);
}

static void	*memmove_src_greater_dest(char *dest, char *src, size_t n)
{
	size_t	index;

	index = 0;
	while (index < n)
	{
		dest[index] = src[index];
		index++;
	}
	return ((void *) dest);
}
