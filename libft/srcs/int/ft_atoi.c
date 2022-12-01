/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdameros <tdameros@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/07 15:44:18 by tdameros          #+#    #+#             */
/*   Updated: 2022/11/22 17:11:52 by tdameros         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <limits.h>

static size_t	count_white_spaces(const char *s);
static int		check_overflow(const char *str, size_t index,
					long result, int sign);

int	ft_atoi(const char *str)
{
	long	result;
	int		overflow;
	int		sign;
	size_t	index;

	result = 0;
	sign = 1;
	str += count_white_spaces(str);
	index = 0;
	if (str[index] == '-')
	{
		sign = -1;
		str++;
	}
	else if (str[index] == '+')
		str++;
	while (ft_isdigit(str[index]))
	{
		overflow = check_overflow(str, index, result, sign);
		if (overflow)
			return (overflow);
		result = result * 10 + (str[index] - '0');
		index++;
	}
	return ((int) result * sign);
}

static size_t	count_white_spaces(const char *s)
{
	size_t	index;

	index = 0;
	while (s[index] == ' ' || s[index] == '\f' || s[index] == '\n'
		|| s[index] == '\r' || s[index] == '\t' || s[index] == '\v')
		index++;
	return (index);
}

static int	check_overflow(const char *str, size_t index, long result, int sign)
{	
	if (LONG_MAX / 10 < result * sign
		|| LONG_MAX - (str[index] - '0') < result * 10 * sign)
		return ((int) LONG_MAX);
	if (LONG_MIN / 10 > result * sign
		|| LONG_MIN + (str[index] - '0') > result * 10 * sign)
		return ((int) LONG_MIN);
	return (0);
}
