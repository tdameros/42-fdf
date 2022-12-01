/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdameros <tdameros@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/07 13:26:16 by tdameros          #+#    #+#             */
/*   Updated: 2022/11/06 17:09:46 by tdameros         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *s1, const char *s2, size_t n)
{
	size_t	len_s2;
	size_t	index_s1;

	len_s2 = ft_strlen(s2);
	index_s1 = 0;
	if (len_s2 == 0)
		return ((char *) s1);
	while (s1[index_s1] != '\0' && index_s1 + len_s2 <= n && index_s1 < n)
	{
		if (ft_strncmp(&s1[index_s1], s2, len_s2) == 0)
			return ((char *) &s1[index_s1]);
		index_s1++;
	}
	return (NULL);
}
