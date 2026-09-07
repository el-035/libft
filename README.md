# Libft

Libft is a custom C library developed as part of the 42 curriculum. The project
reimplements a selection of standard C library functions and adds utilities for
string manipulation, memory management, file-descriptor output, and singly
linked lists.

The goal of the project is to build a reusable foundation for later C projects
while practising memory management, pointer arithmetic, defensive programming,
and static library creation.

## Features

### Character checks and conversion

`ft_isalpha`, `ft_isdigit`, `ft_isalnum`, `ft_isascii`, `ft_isprint`,
`ft_toupper`, and `ft_tolower`

### Memory operations

`ft_memset`, `ft_bzero`, `ft_memcpy`, `ft_memmove`, `ft_memchr`, `ft_memcmp`,
and `ft_calloc`

### String operations

`ft_strlen`, `ft_strlcpy`, `ft_strlcat`, `ft_strchr`, `ft_strrchr`,
`ft_strncmp`, `ft_strnstr`, `ft_strdup`, `ft_substr`, `ft_strjoin`,
`ft_strtrim`, `ft_split`, `ft_strmapi`, and `ft_striteri`

### Conversion and output

`ft_atoi`, `ft_itoa`, `ft_putchar_fd`, `ft_putstr_fd`, `ft_putendl_fd`, and
`ft_putnbr_fd`

### Linked-list utilities (bonus)

`ft_lstnew`, `ft_lstadd_front`, `ft_lstadd_back`, `ft_lstsize`, `ft_lstlast`,
`ft_lstdelone`, `ft_lstclear`, and `ft_lstiter`

## Build

The project requires a C compiler, `make`, and `ar`.

```sh
git clone <repository-url>
cd libft
make
```

This creates the static library `libft.a`. To include the bonus linked-list
functions, run:

```sh
make bonus
```

Other available targets are:

```sh
make clean   # remove object files
make fclean  # remove object files and libft.a
make re      # rebuild the library from scratch
```

## Usage

Include the header in your C source file:

```c
#include "libft.h"
```

Then compile your program and link it against the library:

```sh
cc -Wall -Wextra -Werror main.c -L. -lft -o my_program
```

Example:

```c
#include "libft.h"
#include <stdlib.h>

int main(void)
{
    char *message;

    message = ft_strjoin("Hello, ", "libft!");
    if (message == NULL)
        return (1);
    ft_putendl_fd(message, 1);
    free(message);
    return (0);
}
```

## Project structure

Each function is implemented in its own source file. Public declarations and
the `t_list` type are defined in `libft.h`, while the `Makefile` builds the
sources into a static archive.

## Notes

This project follows the constraints and coding standard used by 42. It is an
educational implementation and is not intended as a drop-in replacement for a
production C standard library.
