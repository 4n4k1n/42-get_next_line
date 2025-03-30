/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anakin <anakin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/13 00:21:05 by apregitz          #+#    #+#             */
/*   Updated: 2025/03/20 01:58:14 by anakin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	ft_strclen(const char *str, int ch)
{
	int	i;

	if (!str)
		return (-1);
	if (ch == -1)
		ch = '\0';
	i = 0;
	while (str[i])
	{
		if (str[i] == (char)ch)
			return (i);
		i++;
	}
	if (str[i] == ch)
		return (i);
	return (-1);
}

void	ft_cpy_buffer(char *buffer, char *buf)
{
	int	i;

	i = 0;
	while (buf[i])
	{
		buffer[i] = buf[i];
		i++;
	}
	buffer[i] = '\0';
}

char	*ft_strcpy(char *dst, const char *src)
{
	int	len;
	int	i;

	len = 0;
	while (src[len])
		len++;
	i = 0;
	while (i < len)
	{
		dst[i] = src[i];
		i++;
	}
	dst[i] = '\0';
	return (dst);
}

