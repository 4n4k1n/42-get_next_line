/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apregitz <apregitz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/17 23:51:59 by apregitz          #+#    #+#             */
/*   Updated: 2025/03/18 14:25:02 by apregitz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>
#include <fcntl.h>    // For open() flags
#include <unistd.h>   // For close()
#include <errno.h>    // For error handling

int	main(void)
{
	int		fd;
	char	*str;

	fd = open("test_idk_ka.txt", O_RDONLY);
	if (fd == -1)
	{
		printf("Error: Unable to open the file. Error code: %d\n", errno);
		return (1);
	}
	str = get_next_line(fd);
	if (!str)
	{
		printf("can not read file!\n");
		close(fd);
		return (1);
	}
	printf(">> %s <<\n", str);
	free(str);
	close(fd);
	printf("File was successfully opened and closed.\n");
	return (0);
}
