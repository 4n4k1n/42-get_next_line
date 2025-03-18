/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apregitz <apregitz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/06 17:13:40 by apregitz          #+#    #+#             */
/*   Updated: 2025/03/18 23:50:38 by apregitz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void	ft_remove_garbage(char *buffer)
{
	int	i;
	int	check;

	check = ft_strclen(buffer, '\n');
	if (check == NOT_FOUND)
		return ;
	i = 0;
	while (buffer[i + check + 1])
	{
		buffer[i] = buffer[i + check + 1];
		i++;
	}
	buffer[i] = '\0';
}

char	*ft_check_buffer(char *buffer)
{
	int		check;

	check = ft_strclen(buffer, '\n');
	if (check != NOT_FOUND)
		return (ft_strdup(buffer, '\n'));
	return (ft_strdup(buffer, '\0'));
}

char	*ft_read_file(int fd, char *buffer)
{
	char	*str;
	int		len;

	len = read(fd, buffer, BUFFER_SIZE);
	if (len <= 0)
	{
		buffer[0] = '\0';
		return (NULL);
	}
	buffer[len] = '\0';
	str = ft_check_buffer(buffer);
	if (!str)
		return (NULL);
	if (ft_strclen(str, '\n') == NOT_FOUND && len == BUFFER_SIZE)
		return (ft_strjoin(str, ft_read_file(fd, buffer)));
	return (str);
}

char	*get_next_line(int fd)
{
	static char	buffer[BUFFER_SIZE + 1] = {0};
	char		*str;

	if (fd < 0 || !BUFFER_SIZE)
		return (NULL);
	str = ft_check_buffer(buffer);
	if (!str)
		return (NULL);
	if (ft_strclen(buffer, '\n') != NOT_FOUND)
	{
		ft_remove_garbage(buffer);
		return (str);
	}
	str = ft_strjoin(str, ft_read_file(fd, buffer));
	if (!str || !*str)
	{
		free(str);
		return (NULL);
	}
	ft_remove_garbage(buffer);
	return (str);
}
