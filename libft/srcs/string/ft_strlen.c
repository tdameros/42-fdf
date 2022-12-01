/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdameros <tdameros@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/06 23:37:05 by tdameros          #+#    #+#             */
/*   Updated: 2022/11/07 14:06:58 by tdameros         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlen(const char *s)
{
	char	*start_ptr;
	char	*end_ptr;

	start_ptr = (char *) s;
	end_ptr = (char *) s;
	while (*end_ptr != '\0')
		end_ptr++;
	return (end_ptr - start_ptr);
}
