/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdameros <tdameros@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/08 22:53:32 by tdameros          #+#    #+#             */
/*   Updated: 2022/11/08 23:52:07 by tdameros         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	index_substr;
	size_t	len_s;
	char	*substr;

	if (s == NULL)
		return (NULL);
	index_substr = 0;
	len_s = ft_strlen(s);
	if (start >= len_s)
		return (ft_strdup(""));
	if (len_s <= len)
		substr = malloc(sizeof(char) * (len_s - start + 1));
	else
		substr = malloc(sizeof(char) * (len + 1));
	if (substr == NULL)
		return (NULL);
	while (s[start] != '\0' && index_substr < len)
	{
		substr[index_substr] = s[start];
		start++;
		index_substr++;
	}
	substr[index_substr] = '\0';
	return (substr);
}
