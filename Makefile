# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: snicolet <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2015/08/17 10:20:32 by snicolet          #+#    #+#              #
#*   Updated: 2015/11/26 14:56:26 by snicolet         ###   ########.fr       *#
#                                                                              #
# **************************************************************************** #

EXTRA_FLAGS=
FLAGS=-Wall -Werror -Wextra -Ofast -Wno-unused-result
GCC=gcc $(FLAGS) -I./includes $(EXTRA_FLAGS)
RANLIB=ranlib
AR=ar
LIB=libft.a
LIST_ROOT=./srcs/list/
LIST=ft_list.o \
	 ft_list_swap.o \
	 ft_list_sort.o \
	 ft_list_push.o \
	 ft_list_free.o \
	 ft_list_foreach.o \
	 ft_list_to.o \
	 ft_list_map.o \
	 ft_list_strlen.o \
	 ft_list_insert.o \
	 ft_list_remove.o \
	 ft_list_search.o \
	 ft_list_at.o \
	 ft_list_push_params.o
BTREE_ROOT=./srcs/btree/
BTREE=ft_btree_foreach.o \
	  ft_btree.o \
	  ft_btree_add.o \
	  ft_btree_search.o \
	  ft_btree_insert.o \
	  ft_btree_level.o \
	  ft_btree_parent.o \
	  ft_btree_level_max.o
MEMORY_ROOT=./srcs/mem/
MEMORY=ft_memset.o \
	   ft_memcpy.o \
	   ft_memccpy.o \
	   ft_memmove.o \
	   ft_memchr.o \
	   ft_memcmp.o \
	   ft_bzero.o
PRINTF_ROOT=./srcs/printf/
PRINTF=ft_printf.o \
	   ft_vprintf.o
OBJ=ft_putchar.o \
	ft_putstr.o \
	ft_swap.o \
	ft_strcmp.o ft_strncmp.o \
	ft_strcat.o ft_strncat.o ft_strlcat.o \
	ft_strlen.o \
	ft_strchr.o ft_strrchr.o \
	ft_strstr.o \
	ft_str_split.o \
	ft_strcount.o \
	ft_strcpy.o \
	ft_pow.o \
	ft_strrev.o \
	ft_itoa.o \
	ft_atoi.o \
	ft_putnbr.o \
	ft_swap_ptr.o \
	ft_strany.o \
	ft_str_only.o \
	ft_strdup.o \
	ft_putstr_list.o \
	ft_free_tab.o \
	ft_strtab_foreach.o \
	ft_putstrdata.o \
	ft_str_numeric.o \
	ft_sort_tab.o \
	ft_putbits.o \
	ft_putmem.o \
	ft_is_printable.o \
	ft_puthex.o \
	ft_quicksort.o \
	ft_is_sorted.o \
	ft_convert_base.o \
	ft_match.o \
	ft_isalpha.o \
	ft_isdigit.o \
	ft_isalnum.o
LIB_CONTENT=$(OBJ) $(MEMORY) $(LIST) $(BTREE) $(PRINTF)
all: static
lib: $(LIB_CONTENT)
static: lib
	@echo "Linking libft"
	$(AR) rc $(LIB) $(OBJ) $(MEMORY) $(LIST) $(BTREE)
	@echo "done, now making lib index..."
	$(RANLIB) $(LIB)
	@echo "Done."
%.o: $(LIST_ROOT)%.c
	$(GCC) -c $<
%.o: $(BTREE_ROOT)%.c
	$(GCC) -c $<
%.o: $(MEMORY_ROOT)%.c
	$(GCC) -c $<
%.o: $(PRINTF_ROOT)%.c
	$(GCC) -c $<
%.o: ./srcs/%.c
	$(GCC) -c $<
clean:
	rm -f $(LIB_CONTENT)
fclean: clean
	rm -f $(LIB) libft.so
re: fclean all
dll:
	make GCC="mingw32-gcc -I./includes -Wall -Werror -Wextra \
		-Wno-ununsed-result -Ofast" AR="mingw32-ar" RANLIB="mingw32-ranlib" \
		LIB="libft.dll"
so:
	make FLAGS="-fpic -Werror -Wall -Wextra -Wno-unused-result -Ofast" lib
	$(GCC) -shared $(LIB_CONTENT) -o libft.so
mrproper: fclean
	find . -name ".*.swp" -print -delete
