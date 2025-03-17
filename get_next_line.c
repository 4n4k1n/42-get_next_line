/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apregitz <apregitz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/06 17:13:40 by apregitz          #+#    #+#             */
/*   Updated: 2025/03/17 14:08:49 by apregitz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	ft_remove_garbage(char **buffer)
{
	int	i;
	int	len;

	len = ft_strclen(*buffer, '\n');
	if (len == -1)
		return (0);
	i = -1;
	while (*buffer[++i + len])
		*buffer[i] = *buffer[i + len];
	*buffer[i] = *buffer[i + len];
	return (1);
}

int	ft_read_file(int fd, char **buffer)
{
	int	check;

	check = read(fd, *buffer, BUFFER_SIZE);
	*buffer[check] = '\0';
	return (check);
}

char	*ft_alloc_str(int fd, char **buffer)
{
	char	*str;
	char	buf[BUFFER_SIZE + 1];
	int		i;

	if (ft_strclen(*buffer, '\n') != -1)
	{
		ft_strcpy(buf, *buffer);
		*buffer[0] = '\0';
	}
	else if (ft_read_file(fd, &buf) == -1)
		return (NULL);
	if (ft_strclen(buf, '\n') == -1)
		str = ft_strcjoin(buf, ft_alloc_str(fd, *buffer));
	else
	{
		i = 0;
		while (buf[++i])
			*buffer[i] = buf[i];
		*buffer[i] = '\0';
		str = ft_strcjoin(buf, (char *)ft_calloc(ft_strclen(buf, '\0') + 1, 1));
	}
	if (!str)
		return (NULL);
	return (str);
}

char	*get_next_line(int fd)
{
	static char	buffer[BUFFER_SIZE + 1] = {0};
	char		*str;

	if (BUFFER_SIZE < 1 || fd < 0)
		return (NULL);
	str = ft_alloc_str(fd, &buffer);
	if (!str)
		return (NULL);
	if (ft_strclen(buffer, '\n') != -1)
		ft_remove_garbage(&buffer);
	return (str);
}

// check = ft_strclen(buffer, '\n');
// 	if (check == -1)
// 	{
// 		check = BUFFER_SIZE;
// 		while (check == BUFFER_SIZE)
// 		{
// 			str = (char *)ft_calloc(ft_strclen(buffer, '\0') + 1, 1);
// 			if (!str)
// 				return (NULL);
// 			str = ft_strcjoin(str, buffer, '\0');
// 			if (!str)
// 				return (NULL);
// 			check = ft_read_file(fd, buffer);
// 		}
// 	}