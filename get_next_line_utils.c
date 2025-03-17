/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apregitz <apregitz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/13 00:21:05 by apregitz          #+#    #+#             */
/*   Updated: 2025/03/17 13:36:39 by apregitz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_strcpy(char *dst, const char *src)
{
	int	i;
	int	dst_len;

	if (!dst || !src)
		return (NULL);
	i = 0;
	while (dst[dst_len])
		dst_len++;
	while (src[i])
	{
		dst[dst_len + i] = src[i];
		i++;
	}
	return (dst);
}

void	*ft_calloc(size_t count, size_t size)
{
	size_t	i;
	void	*arr;

	if (size != 0 && count > ~(size_t)0 / size)
		return (NULL);
	arr = malloc(count * size);
	if (!arr)
		return (NULL);
	i = 0;
	while (i < (size * count))
	{
		((unsigned char *)arr)[i] = 0;
		i++;
	}
	return (arr);
}

ssize_t	ft_strclen(const char *str, ssize_t ch)
{
	ssize_t	i;

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
	return (-1);
}

char	*ft_strcjoin(char const *s1, char const *s2)
{
	int		len_s1;
	int		len_s2;
	char	*arr;
	int		i;

	if (!s1 || ! s2)
		return (NULL);
	len_s1 = ft_strclen(s1, 0);
	len_s2 = ft_strclen(s2, 0);
	arr = (char *)ft_calloc(len_s1 + len_s2 + 1, 1);
	if (!arr)
		return (NULL);
	i = -1;
	while (++i < len_s1 + len_s2)
	{
		if (i < len_s1)
			arr[i] = s1[i];
		else
			arr[i] = s2[i - len_s1];
	}
	free(s2);
	arr[i] = '\0';
	return (arr);
}
