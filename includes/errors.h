/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdameros <tdameros@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/01 23:08:19 by tdameros          #+#    #+#             */
/*   Updated: 2022/12/01 23:08:20 by tdameros         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef ERRORS_H
# define ERRORS_H

# include <stdlib.h>
# include "../libft/incs/ft_libc.h"

void	*raise_allocation_error(void);
void	*raise_invalid_map_error(void);
void	*raise_file_error(void);

#endif
