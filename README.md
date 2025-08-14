# Get Next Line

A C function that reads and returns one line at a time from a file descriptor, essential for efficient file processing and understanding static variables.

## Overview

Get Next Line (GNL) is a crucial project in the 42 curriculum that introduces the concept of reading files line by line efficiently. This project teaches important concepts about file descriptors, static variables, buffer management, and memory allocation in C.

## Function Prototype

```c
char *get_next_line(int fd);
```

## Parameters

- `fd`: The file descriptor from which to read

## Return Value

- Returns the line that was read from the file descriptor
- Returns `NULL` if there's nothing more to read or if an error occurs
- The returned line includes the terminating `\n` character (except for the last line if it doesn't end with `\n`)

## Key Features

### Core Implementation
- Reads from any valid file descriptor (files, stdin, etc.)
- Uses a configurable `BUFFER_SIZE` defined at compile time
- Maintains reading state between function calls using static variables
- Handles files with or without final newlines
- Efficient memory management with minimal memory usage

### Bonus Features
- **Multiple File Descriptors**: Can handle multiple file descriptors simultaneously
- **Static Variable Management**: Uses static variables to track state for each file descriptor
- **Edge Case Handling**: Properly handles various edge cases and error conditions

## Compilation

### Basic Version
```bash
gcc -Wall -Wextra -Werror -D BUFFER_SIZE=42 get_next_line.c get_next_line_utils.c
```

### Bonus Version
```bash
gcc -Wall -Wextra -Werror -D BUFFER_SIZE=42 get_next_line_bonus.c get_next_line_utils_bonus.c
```

## Usage Example

```c
#include "get_next_line.h"
#include <fcntl.h>
#include <stdio.h>

int main(void)
{
    int fd;
    char *line;
    
    fd = open("test.txt", O_RDONLY);
    if (fd == -1)
        return (1);
    
    while ((line = get_next_line(fd)) != NULL)
    {
        printf("%s", line);
        free(line);
    }
    
    close(fd);
    return (0);
}
```

## Technical Implementation

### Key Concepts Used
- **Static Variables**: Maintain state between function calls
- **Buffer Management**: Efficient reading using configurable buffer size
- **Memory Allocation**: Dynamic allocation for lines of varying lengths
- **String Manipulation**: Finding newlines and managing partial reads
- **File Descriptor Handling**: Working with different types of file descriptors

### Algorithm Overview
1. Check if there's leftover data from previous reads
2. Read from file descriptor in chunks of `BUFFER_SIZE`
3. Search for newline character in the accumulated data
4. Extract and return the line (up to and including `\n`)
5. Save any remaining data in static variable for next call
6. Handle end-of-file and error conditions

## Project Structure

### Core Files
- `get_next_line.c` - Main function implementation
- `get_next_line_utils.c` - Utility functions (string operations, memory management)
- `get_next_line.h` - Header file with function prototypes and includes

### Bonus Files
- `get_next_line_bonus.c` - Enhanced version supporting multiple file descriptors
- `get_next_line_utils_bonus.c` - Utility functions for bonus version
- `get_next_line_bonus.h` - Header file for bonus version

## Buffer Size Considerations

The `BUFFER_SIZE` can be defined at compile time:
- Small values (1-10): More system calls, less memory usage
- Large values (1000+): Fewer system calls, more memory usage
- Optimal range: Usually between 32-1024 depending on use case

## Key Learning Objectives

- Understanding static variables and their lifecycle
- File descriptor operations and system calls
- Efficient buffer management strategies
- Memory allocation and deallocation best practices
- String manipulation and searching algorithms
- Error handling with file operations
- Working with the read() system call

## Error Handling

The function handles various error conditions:
- Invalid file descriptors
- Read errors
- Memory allocation failures
- Compilation without BUFFER_SIZE defined

## Memory Management

- All allocated memory is properly managed
- No memory leaks under normal operation
- Caller is responsible for freeing returned strings
- Internal buffers are cleaned up appropriately

This project is fundamental for understanding file I/O in C and prepares students for more complex projects involving file processing and system programming.