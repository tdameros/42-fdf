/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdameros <tdameros@student.42lyon.f>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/23 00:37:24 by tdameros          #+#    #+#             */
/*   Updated: 2022/11/23 00:37:26 by tdameros         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stdlib.h>
# include <limits.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 256
# endif

# if BUFFER_SIZE > 10000000
#  undef BUFFER_SIZE
#  define BUFFER_SIZE 10000000
# endif

# ifndef OPEN_MAX
#  define OPEN_MAX 1024
# endif

size_t	ft_strlen(const char *s);
char	*strjoin_free(char *s1, char *s2);

char	*sub_line_in_buf(char *buf, size_t start, size_t len);
size_t	start_line_in_buf(char *buf, size_t buf_size);
size_t	len_line_in_buf(char *buf, size_t buf_size, size_t start);
char	*extract_line_in_buf(char *buf, size_t buf_size, int *is_line);
int		is_empty_buf(char *buf, size_t buf_size);

char	*free_ret_null(void *ptr1, void *ptr2);
char	*get_next_line(int fd);

#endif
