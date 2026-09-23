# libft

Libft is a project from **42 São Paulo** that consists of recreating a standard C library, containing various useful functions for handling strings, memory, linked lists, and other basic operations. This project is one of the pillars of the 42 curriculum, helping to solidify fundamental concepts and best practices.

## 🏗️ Project Structure
``` bash
├── 📂 bin/          # Will be created with the compiled libraries (.a) - see how 2 use below
│   ├── libft.a
│   ├── gnl.a
│   ├── printf.a
├── 📂 include/      # Header files (.h)
│   ├── libft.h
│   ├── get_next_line.h
│   ├── ft_printf.h
├── 📂 obj/          # Object files (.o) organized by project, created during comp. process
│   ├── libft/
│   ├── gnl/
│   ├── printf/
├── 📂 src/          # Source files (.c)
│   ├── libft/
│   │   ├── ctype/
│   │   ├── stdlib/
│   │   ├── string/
│   │   ├── memory/
│   │   ├── unistd/
│   │   ├── lists/
│   ├── gnl/
│   ├── printf/
└── Makefile
```

## 📌 Implemented Functions
The library includes functions divided into the following main categories:

| Library | Functions |
|---------|-----------|
|<ctype.h>|`ft_isalpha`, `ft_isdigit`, `ft_isalnum`, `ft_isascii`, `ft_isprint`, `ft_toupper`, `ft_tolower`.|
|<string.h>|`ft_strlen`, `ft_strchr`, `ft_strrchr`, `ft_strncmp`, `ft_strnstr`, `ft_strdup`, `ft_strlcpy`, `ft_strlcat`.|
|<stdlib.h>|`ft_atoi`, `ft_calloc`, `ft_itoa`.|
|unistd.h>|`ft_putchar_fd`, `ft_printf`, `ft_putendl_fd`, `ft_putnbr_fd`.|
|Memory management|`ft_memset`, `ft_memcpy`, `ft_memmove`, `ft_memchr`, `ft_memcmp`.|
|Bonus functions|Linked list operations (`t_list`):|
||- Creation and manipulation: `ft_lstnew`, `ft_lstadd_front`, `ft_lstadd_back`, `ft_lstsize`, `ft_lstlast`.|
||- Advanced operations: `ft_lstdelone`, `ft_lstclear`, `ft_lstiter`, `ft_lstmap`.|
|**V2**|Additionally, this project integrates the following projects:|
|**Get Next Line (`gnl.a`)**|Reads a line from a file descriptor. <br> To learn more about this project check out my full project [here](https://github.com/luizakormann/getnextline_42) |
|**Ft_printf (`printf.a`)**|My version of the `printf` output function. <br> To learn more about this project check out its page [here](https://github.com/luizakormann/printf_42) |

## ⚙️ Compilation and Usage
### Requirements
 - GCC or another compatible C compiler.
 - UNIX/Linux system recommended (tested in the 42 São Paulo environment).
### Available Commands
Use the `Makefile` to compile and manage the project:

| Command | Description |
|---------|-----------|
|`make all`|Compiles `libft.a`, `gnl.a`, and `printf.a`|
|`make libft`|Compiles only `libft.a`|
|`make gnl`|Compiles only `gnl.a`|
|`make printf`|Compiles only `printf.a`|
|`make clean`|Removes object files (`.o`).|
|`make fclean`|Remmoves obj files and the compiled libraries (`libft.a`).|
|`make re`|Recompiles everything from scratch.|

### How to Use
 1. Compile the library using a specific target like `make gnl` or `make all` to compile everything.
 2. Include the the necessary header files in your project (`libft.h`, `get_next_line.h`, or `ft_printf.h`).
 3. Link the compiled libraries when building your program
For instance, if you need the `gnl.a` library, after following the previous steps, you will link as needed:
``` bash
gcc -Wall -Wextra -Werror -I include/ -L bin/ -lgnl your_program.c -o your_program
```

## 🎓 Key Learnings (author's notes)
This project provided valuable insights into:

 - **Fundamentals of C Standard Library Functions**: Implementing core functions like `strlen`, `strnstr`, and `itoa` deepened my understanding of string manipulation, memory management, and numerical conversions.
 - **Segfault Handling & Defensive Programming**: Adapting `strnstr` to align with Francinette's expected behavior taught me how to anticipate segmentation faults and handle `NULL` pointers properly.
 - **Makefile & Compilation Process**: Creating and refining my `Makefile` to compile `libft.a` helped me gain fluency in automating builds, managing dependencies, and understanding static libraries.
 - **Criterion for Unit Testing**: Integrating the Criterion testing framework allowed me to validate my functions rigorously and reinforced the importance of writing modular and testable code.
 - **Project Structure & Code Organization**: This was my first project where I structured files into `include/`, `bin/`, and other standard directories, improving maintainability and scalability in a real-world development workflow.
 - **Project Structuring and Makefile Refinement**: Incorporating the `gnl` and `printf` projects into the `libft` repository further solidified my understanding of project structure. I learned to leverage the `wildcard` function in Makefile, which made the build process cleaner and more efficient. This experience emphasized the value of modularization and strengthened my skills in dependency management and automating compilation workflows.

## 👩‍💻 Author
This project was developed by Luiza Kormann (lukorman@student.42.fr) as part of the 42 São Paulo curriculum.
