/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdameros <tdameros@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/10 23:24:04 by tdameros          #+#    #+#             */
/*   Updated: 2022/11/08 16:24:27 by tdameros         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <limits.h>

static int	intlen(int n);

char	*ft_itoa(int n)
{
	int		len_n;
	int		index_stop;
	char	*str_n;

	if (n == INT_MIN)
		return (ft_strdup("-2147483648"));
	len_n = intlen(n);
	str_n = malloc(sizeof(char) * (len_n + 1));
	if (str_n == NULL)
		return (NULL);
	str_n[len_n--] = '\0';
	index_stop = 0;
	if (n < 0)
	{
		str_n[0] = '-';
		index_stop++;
		n = -n;
	}
	while (len_n >= index_stop)
	{
		str_n[len_n--] = (n % 10) + '0';
		n /= 10;
	}
	return (str_n);
}

static int	intlen(int n)
{
	int	len;

	len = 1;
	if (n < 0)
		len++;
	while (!(n > -10 && n < 10))
	{
		n /= 10;
		len++;
	}
	return (len);
}
