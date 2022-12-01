/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_string.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdameros <tdameros@student.42lyon.f>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/15 04:07:09 by tdameros          #+#    #+#             */
/*   Updated: 2022/11/15 04:07:09 by tdameros         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/**
 * Print string in stdout. Print (null) is pointer is NULL.
 * @return the number of characters printed or
 * a negative value if an error occurs.
 */
int	print_str(char *str)
{
	if (str == NULL)
		return (write(1, "(null)", 6));
	return (write(1, str, ft_strlen(str)));
}

/**
 * Print char in stdout.
 * @return the number of characters printed or
 * a negative value if an error occurs.
 */
int	print_char(char c)
{
	return (write(1, &c, 1));
}
