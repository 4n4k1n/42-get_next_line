/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apregitz <apregitz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/12 22:54:28 by apregitz          #+#    #+#             */
/*   Updated: 2025/03/18 14:21:55 by apregitz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 4
# endif

# include <unistd.h>
# include <stdlib.h>
# include <limits.h>
# include <stdio.h>

int		ft_remove_garbage(char *buffer);
int		ft_read_file(int fd, char *buffer);
char	*ft_alloc_str(int fd, char *buffer);
char	*get_next_line(int fd);

char	*ft_strcjoin(const char *s1, const char *s2);
int		ft_strclen(const char *str, int ch);
void	*ft_calloc(size_t count, size_t size);
char	*ft_strcpy(char *dst, const char *src);

#endif