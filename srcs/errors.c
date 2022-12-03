/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdameros <tdameros@student.42lyon.f>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/29 21:32:39 by tdameros          #+#    #+#             */
/*   Updated: 2022/11/29 21:34:14 by tdameros         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "errors.h"

/**
 * Print allocation error message in stderr.
 * @return NULL
 */
void	*raise_allocation_error(void)
{
	ft_putendl_fd("Error encountered during an allocation.", STDERR_FILENO);
	return (NULL);
}

/**
 * Print invalid map error message in stderr.
 * @return NULL
 */
void	*raise_invalid_map_error(void)
{
	ft_putendl_fd("Error encountered during parsing. "
		"Please use *.fdf file with valid size.", STDERR_FILENO);
	return (NULL);
}

/**
 * Print file error message in stderr.
 * @return NULL
 */
void	*raise_file_error(void)
{
	ft_putendl_fd("Error encountered while reading the file. "
		"Please use *.fdf file with read permissions.", STDERR_FILENO);
	return (NULL);
}
