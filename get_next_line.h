/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anakin <anakin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/12 22:54:28 by apregitz          #+#    #+#             */
/*   Updated: 2025/03/20 01:58:30 by anakin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 4
# endif

# include <unistd.h>
# include <stdlib.h>

char	*get_next_line(int fd);

int		ft_strclen(const char *str, int ch);
void	ft_cpy_buffer(char *buffer, char *buf);
char	*ft_strcpy(char *dst, const char *src);

#endif
