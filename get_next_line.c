/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apregitz <apregitz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/06 17:13:40 by apregitz          #+#    #+#             */
/*   Updated: 2025/03/13 01:08:14 by apregitz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	ft_alloc_str(int fd, char *buffer, char *str)
{
	while (read(fd, buffer, BUFFER_SIZE) > 0)
	{
		if ()
	}
}

char	*get_next_line(int fd)
{
	static char		buffer[BUFFER_SIZE + 1];
	char			*str;
	int				check;

	ft_read_buffer(buffer, fd);
}
