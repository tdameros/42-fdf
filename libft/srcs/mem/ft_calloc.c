/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdameros <tdameros@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/08 21:01:21 by tdameros          #+#    #+#             */
/*   Updated: 2022/11/08 23:06:45 by tdameros         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdint.h>

void	*ft_calloc(size_t nmemb, size_t size)
{
	void	*malloc_ptr;
	size_t	total_bytes;

	if (size == 0 || SIZE_MAX / size < nmemb)
		return (NULL);
	total_bytes = nmemb * size;
	malloc_ptr = malloc(total_bytes);
	if (malloc_ptr == NULL)
		return (NULL);
	ft_bzero(malloc_ptr, total_bytes);
	return (malloc_ptr);
}
