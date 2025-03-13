/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apregitz <apregitz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/12 22:54:05 by apregitz          #+#    #+#             */
/*   Updated: 2025/03/12 22:56:56 by apregitz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include "get_next_line.h"

int main(void)
{
    int fd;
    char *line;
    int line_count;

    // Test 1: Reading from a regular file
    printf("\n=== Test 1: Reading from a regular file ===\n");
    fd = open("test.txt", O_RDONLY);
    if (fd == -1)
    {
        printf("Error opening file\n");
        return (1);
    }
    
    line_count = 1;
    while ((line = get_next_line(fd)) != NULL)
    {
        printf("Line %d: %s", line_count++, line);
        free(line); // Don't forget to free the allocated memory
    }
    
    close(fd);
    
    // Test 2: Reading from stdin
    printf("\n=== Test 2: Reading from stdin ===\n");
    printf("Type some lines (Ctrl+D to end on Unix, Ctrl+Z on Windows):\n");
    
    line_count = 1;
    while ((line = get_next_line(STDIN_FILENO)) != NULL)
    {
        printf("Line %d: %s", line_count++, line);
        free(line);
    }
    
    // Test 3: Reading from multiple files alternately
    printf("\n=== Test 3: Reading from multiple files alternately ===\n");
    int fd1 = open("test1.txt", O_RDONLY);
    int fd2 = open("test2.txt", O_RDONLY);
    
    if (fd1 == -1 || fd2 == -1)
    {
        printf("Error opening one of the test files\n");
        return (1);
    }
    
    // Read alternately from both files
    for (int i = 0; i < 5; i++)
    {
        line = get_next_line(fd1);
        if (line)
        {
            printf("File 1, iteration %d: %s", i + 1, line);
            free(line);
        }
        
        line = get_next_line(fd2);
        if (line)
        {
            printf("File 2, iteration %d: %s", i + 1, line);
            free(line);
        }
    }
    
    close(fd1);
    close(fd2);
    
    // Test 4: Error handling with invalid file descriptor
    printf("\n=== Test 4: Error handling with invalid file descriptor ===\n");
    line = get_next_line(99999); // Invalid file descriptor
    if (line == NULL)
        printf("Correctly returned NULL for invalid file descriptor\n");
    else
    {
        printf("Unexpected non-NULL return: %s\n", line);
        free(line);
    }
    
    printf("\nAll tests completed!\n");
    return (0);
}
