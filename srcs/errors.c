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

void	*raise_allocation_error(void)
{
	ft_putendl_fd("Error encountered during a memory allocation.", 1);
	return (NULL);
}

void	*raise_invalid_map_error(void)
{
	ft_putendl_fd("Error encountered during parsing. "
		"Please use *.fdf file with valid size.", 1);
	return (NULL);
}

void	*raise_file_error(void)
{
	ft_putendl_fd("Error encountered while reading the file. "
		"Please use *.fdf file with read permissions.", 1);
	return (NULL);
}
