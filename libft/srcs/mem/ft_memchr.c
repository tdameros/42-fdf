/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdameros <tdameros@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/06 23:41:18 by tdameros          #+#    #+#             */
/*   Updated: 2022/11/08 16:14:41 by tdameros         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t			index;
	unsigned char	*char_ptr;

	char_ptr = (unsigned char *) s;
	index = 0;
	while (index < n)
	{
		if (char_ptr[index] == (unsigned char) c)
			return (char_ptr + index);
		index++;
	}
	return (NULL);
}
