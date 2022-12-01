/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_number.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdameros <tdameros@student.42lyon.f>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/15 04:07:05 by tdameros          #+#    #+#             */
/*   Updated: 2022/11/15 04:07:05 by tdameros         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	print_number(long number)
{
	char	*conversion;
	int		len;

	conversion = int_to_str(number);
	if (conversion == NULL)
		return (-1);
	len = print_str(conversion);
	free(conversion);
	return (len);
}

char	*int_to_str(long number)
{
	int		number_len;
	int		index;
	char	*conversion;

	number_len = long_len(number);
	conversion = malloc(sizeof(char) * (number_len + 1));
	if (conversion == NULL)
		return (NULL);
	conversion[number_len--] = '\0';
	index = 0;
	if (number < 0)
	{
		conversion[0] = '-';
		index++;
		number = -number;
	}
	while (number_len >= index)
	{
		conversion[number_len--] = (number % 10) + '0';
		number /= 10;
	}
	return (conversion);
}

int	long_len(long number)
{
	int	len;

	len = 1;
	if (number < 0)
		len++;
	while (!(number > -10 && number < 10))
	{
		number /= 10;
		len++;
	}
	return (len);
}
