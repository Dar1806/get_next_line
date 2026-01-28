This project has been created as part of the 42 curriculum by nmeunier.

## get_next_line

A C library project from the 42 school curriculum that implements a function to read a line from a file descriptor.

### Description

The `get_next_line` project provides a function that reads and returns one line at a time from a file descriptor. This is a fundamental project that teaches memory management, file I/O operations, and efficient buffering in C.

### Features

- Read lines from file descriptors sequentially
- Handle multiple file descriptors simultaneously
- Efficient memory usage with configurable buffer size
- Support for files without newlines

### Functions

- `get_next_line()` - Main function to read the next line from a file descriptor
- `fill_line()` - Helper function to fill buffer and build the line
- `ft_strchr()` - Locate character in string
- `ft_strdup()` - Duplicate string
- `ft_strlen()` - Get string length
- `ft_strjoin()` - Concatenate strings
- `ft_memcpy()` - Copy memory

### Buffer Size

The buffer size can be configured at compilation time using the `BUFFER_SIZE` macro (default: 42).

### Compilation

```bash
gcc -Wall -Wextra -Werror get_next_line.c get_next_line_utils.c -o program
```

To use a custom buffer size:

```bash
gcc -Wall -Wextra -Werror -D BUFFER_SIZE=1024 get_next_line.c get_next_line_utils.c -o program
```

### Files

- `get_next_line.c` - Main implementation
- `get_next_line_utils.c` - Utility functions
- `get_next_line.h` - Header file with function declarations
