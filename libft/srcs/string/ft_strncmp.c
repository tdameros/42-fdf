/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdameros <tdameros@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/06 23:42:57 by tdameros          #+#    #+#             */
/*   Updated: 2022/11/09 14:39:44 by tdameros         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t			index;
	unsigned char	*s1_ptr;
	unsigned char	*s2_ptr;

	s1_ptr = (unsigned char *) s1;
	s2_ptr = (unsigned char *) s2;
	if (n == 0)
		return (0);
	index = 0;
	while (*s1_ptr == *s2_ptr && *s1_ptr != '\0' && *s2_ptr != '\0'
		&& index < n)
	{
		s1_ptr++;
		s2_ptr++;
		index++;
	}
	if (index == n)
		return (0);
	return (*s1_ptr - *s2_ptr);
}
