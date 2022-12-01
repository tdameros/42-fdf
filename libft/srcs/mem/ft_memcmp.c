/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdameros <tdameros@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/06 23:42:33 by tdameros          #+#    #+#             */
/*   Updated: 2022/10/08 22:26:43 by tdameros         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	size_t			index;
	unsigned char	*s1_char_ptr;
	unsigned char	*s2_char_ptr;

	s1_char_ptr = (unsigned char *) s1;
	s2_char_ptr = (unsigned char *) s2;
	if (n == 0)
		return (0);
	index = 0;
	while (s1_char_ptr[index] == s2_char_ptr[index] && index < n)
		index++;
	if (index == n)
		return (0);
	return (s1_char_ptr[index] - s2_char_ptr[index]);
}
