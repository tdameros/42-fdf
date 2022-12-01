/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdameros <tdameros@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/08 23:31:20 by tdameros          #+#    #+#             */
/*   Updated: 2022/11/09 12:47:19 by tdameros         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	len_s1;
	size_t	len_s2;
	char	*s;

	if (s1 == NULL || s2 == NULL)
		return (NULL);
	len_s1 = ft_strlen(s1);
	len_s2 = ft_strlen(s2);
	s = malloc(sizeof(char) * (len_s1 + len_s2 + 1));
	if (s == NULL)
		return (NULL);
	ft_memcpy(s, s1, len_s1 * sizeof(char));
	ft_strlcpy(s + len_s1, s2, len_s2 + 1);
	return (s);
}
