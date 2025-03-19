/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   new.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apregitz <apregitz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/19 11:18:25 by apregitz          #+#    #+#             */
/*   Updated: 2025/03/19 12:00:34 by apregitz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void	ft_remove_garbage(char *buffer)
{
	int	i;
	int	check;

	check = ft_strclen(buffer, '\n');
	if (check == NOT_FOUND)
	{
		buffer[0] = '\0';
		return ;
	}
	i = -1;
	while (buffer[++i + check + 1])
		buffer[i] = buffer[i + check + 1];
	buffer[i] = '\0';
}

char	*ft_check_buffer(char *buffer)
{
	int	check;

	check = ft_strclen(buffer, '\n');
	if (check != NOT_FOUND)
		return (ft_strdup(buffer, '\n'));
	return (ft_strdup(buffer, '\0'));
}

char	*ft_read_line(int fd, char *buffer)
{
	char	*str;
	int		check;

	str = ft_check_buffer(buffer);
	if (!str)
		return (NULL);
	while (if ())
	{
		if (ft_strclen(buffer, ))
		{

		}
	}
	return (str);
}

char	*get_next_line(int fd);
