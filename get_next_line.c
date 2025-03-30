/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anakin <anakin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/06 17:13:40 by apregitz          #+#    #+#             */
/*   Updated: 2025/03/29 22:27:25 by anakin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void	ft_remove_garbage(char *buffer)
{
	int	i;
	int	check;

	check = ft_strclen(buffer, '\n');
	if (check == -1)
	{
		buffer[0] = '\0';
		return ;
	}
	i = -1;
	while (buffer[++i + check + 1])
		buffer[i] = buffer[i + check + 1];
	buffer[i] = '\0';
}

int	ft_read_in_buffer(int fd, char *buffer)
{
	int	check;

	check = read(fd, buffer, BUFFER_SIZE);
	if (check >= 0)
		buffer[check] = '\0';
	else
		buffer[0] = '\0';
	return (check);
}

char	*ft_alloc_str(int len, int cpy_len)
{
	char	*str;

	str = malloc(len + 1);
	if (!str)
		return (NULL);
	str[len] = '\0';
	return (str);
}

char	*ft_fill_str(char *str, char *buffer, int str_start, int len)
{
	int	i;

	if (!str)
		return (NULL);
	i = 0;
	while (i < len)
	{
		str[str_start +i] = buffer[i];
		i++;
	}
	return (str);
}

char	*ft_search_newline(int	fd, char *buffer, int len)
{
	int	bytes;
	int	check;
	char	buf[BUFFER_SIZE + 1];

	bytes = ft_read_in_buffer(fd, buf);
	if (bytes == -1)
		return (NULL);
	check = ft_strclen(buf, '\n');
	if (check == -1 && bytes == BUFFER_SIZE)
		return (ft_fill_str(ft_search_newline(fd, buf, len + bytes), buf, len, bytes));
	ft_strcpy(buffer, buf);
	if (check >= 0)
		bytes = check;
	return (ft_fill_str(ft_alloc_str(len + bytes), buffer, len, bytes));
}

char	*get_next_line(int fd)
{
	static char	buffer[BUFFER_SIZE + 1];
	char		*str;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	str = ft_search_newline(fd, buffer, 0);
	if (!str)
		return (NULL);
	ft_remove_garbage(buffer);
	return (str);
}
