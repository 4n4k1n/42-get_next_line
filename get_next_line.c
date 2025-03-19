/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apregitz <apregitz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/06 17:13:40 by apregitz          #+#    #+#             */
/*   Updated: 2025/03/19 11:29:41 by apregitz         ###   ########.fr       */
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

char	*ft_find_newline_recursive(int fd, char *buffer, char *str, int *error)
{
	char	*temp;
	char	*new;

	temp = ft_read_file_until_newline(fd, buffer, error);
	if (!temp)
	{
		if (*error)
		{
			free(str);
			return (NULL);
		}
		return (str);
	}
	new = ft_strjoin(str, temp);
	if (!new)
		*error = 1;
	return (new);
}

char	*ft_read_file_until_newline(int fd, char *buffer, int *error)
{
	char	*str;
	int		len;

	len = read(fd, buffer, BUFFER_SIZE);
	if (len == -1)
	{
		buffer[0] = '\0';
		*error = 1;
		return (NULL);
	}
	buffer[len] = '\0';
	str = ft_check_buffer(buffer);
	if (!str)
	{
		*error = 1;
		return (NULL);
	}
	if (ft_strclen(str, '\n') == NOT_FOUND && len == BUFFER_SIZE)
		return (ft_find_newline_recursive(fd, buffer, str, error));
	return (str);
}

char	*get_next_line(int fd)
{
	static char	buffer[BUFFER_SIZE + 1] = {0};
	char		*str;
	int			error_check;

	error_check = 0;
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
	str = ft_strjoin(str, ft_read_file_until_newline(fd, buffer, &error_check));
	if (!str)
		return (NULL);
	if (!*str || error_check)
		return (free(str), NULL);
	ft_remove_garbage(buffer);
	return (str);
}
