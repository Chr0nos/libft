[![Build Status](https://travis-ci.org/Chr0nos/libft.svg?branch=master)](https://travis-ci.org/Chr0nos/libft)

Tache               | A faire | En cours | Fait
--------------------|:-------:|:--------:|-----
Partie 1            |         |          | x
Partie 2            |         |          | x
Bonus               |         |          | x
Fonctions perso     |         |          | x
Passage moulinette  |         |          | x
Corrections         |         |          | x
Printf              |         |          | x
Sscanf              |         |          | x
Malloc				|		  |          | x
Free				|		  |          | x
Realloc				|	 	  |			 | x


# About the project

This is a 42 school project, all function extep malloc/free/read are explictly prohibed by the school and flagued as cheat is used resulting by a grade -42, this library allow me to use function like ft_memcpy or ft_printf.

Some functions here are not present in the libc but are just usefull in my school projects.


# About me
I'm a student from school 42, i started my cursus in 2015.

# Operating systems
This library is compilable on Mac OS and Linux with both clang and gcc.

In the future i will make it compatible with ARM but for now only x86_64 and x86 architectures are supported. 

# Compilation flags
The folowing flags are imposed by the school
> -Wall -Werror -Wextra

And because i like rigor, when i compile with clang i add:

> -Weveything

# Compilation using this lib
Let's take a sample file name test.c in the parent directory of libft

> make -C libft -j

> cc -Wall -Werror -Wextra test.c -Ilibft/include -Llibft -lft

# The lib itself
By default a static librarie is done, but you can compile a dynamic one (shared object) by typing:

> make fclean

> make -j so

# Bugs ?
If you find bugs or just wan to ask me questions you can open issues in this project, i will answer as soon as possible.
