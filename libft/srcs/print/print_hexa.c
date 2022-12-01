/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hexa_conversion.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdameros <tdameros@student.42lyon.f>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/17 16:29:40 by tdameros          #+#    #+#             */
/*   Updated: 2022/11/17 16:29:41 by tdameros         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/**
 * Print a pointer in stdout.
 * @return the number of characters printed or
 * a negative value if an error occurs.
 */
int	print_pointer(void *pointer)
{
	char	*conversion;
	int		len;

	conversion = pointer_to_hexa((unsigned long long) pointer, HEXA_BASE_LOWER);
	if (conversion == NULL)
		return (-1);
	len = print_str(conversion);
	free(conversion);
	return (len);
}

/**
 * Convert an unsigned long long number in hexa.
 */
char	*pointer_to_hexa(unsigned long long number, char *base)
{
	char	*conversion;
	int		conversion_len;

	conversion_len = conversion_hexa_len(number) + 2;
	conversion = malloc(sizeof(char) * (conversion_len + 1));
	if (conversion == NULL)
		return (NULL);
	conversion[0] = '0';
	conversion[1] = 'x';
	conversion[conversion_len--] = '\0';
	while (number >= 16)
	{
		conversion[conversion_len] = base[number % 16];
		number /= 16;
		conversion_len--;
	}
	conversion[conversion_len] = base[number];
	return (conversion);
}

/**
 * @return len of the hexa conversion.
 */
int	conversion_hexa_len(unsigned long long number)
{
	int	len;

	len = 0;
	while (number >= 16)
	{
		number /= 16;
		len++;
	}
	return (len + 1);
}

/**
 * Print hexa conversion of number in stdout.
 * @return the number of characters printed or
 * a negative value if an error occurs.
 */
int	print_hexa(unsigned int number, char *base)
{
	char	*conversion;
	int		len;

	conversion = int_to_hexa(number, base);
	if (conversion == NULL)
		return (-1);
	len = print_str(conversion);
	free(conversion);
	return (len);
}

/**
 * Convert an unsigned int or int number in hexa.
 */
char	*int_to_hexa(unsigned int number, char *base)
{
	char	*conversion;
	int		conversion_len;

	conversion_len = conversion_hexa_len(number);
	conversion = malloc(sizeof(char) * (conversion_len + 1));
	if (conversion == NULL)
		return (NULL);
	conversion[conversion_len--] = '\0';
	while (number >= 16)
	{
		conversion[conversion_len] = base[number % 16];
		number /= 16;
		conversion_len--;
	}
	conversion[conversion_len] = base[number];
	return (conversion);
}
