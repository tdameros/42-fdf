/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdameros <tdameros@student.42lyon.f>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/15 05:04:07 by tdameros          #+#    #+#             */
/*   Updated: 2022/11/15 05:04:08 by tdameros         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdlib.h>
# include <stdarg.h>

# define HEXA_BASE_LOWER "0123456789abcdef"
# define HEXA_BASE_UPPER "0123456789ABCDEF"

// String functions
int		print_str(char *str);
int		print_char(char c);
size_t	ft_strlen(const char *s);

// Number functions
int		print_number(long number);
int		long_len(long number);
char	*int_to_str(long number);

// Hexa functions
int		print_hexa(unsigned int number, char *base);
int		print_pointer(void *pointer);
char	*int_to_hexa(unsigned int number, char *base);
char	*pointer_to_hexa(unsigned long long number, char *base);
int		conversion_hexa_len(unsigned long long number);

// Ft_printf function
int		ft_printf(const char *format, ...);
int		is_valid_type(char c);
int		print_conversion(char type, va_list args);

#endif
