# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: snicolet <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2015/08/17 10:20:32 by snicolet          #+#    #+#              #
#*   Updated: 2015/10/11 13:53:20 by snicolet         ###   ########.fr       *#
#                                                                              #
# **************************************************************************** #

FLAGS=-Wall -Werror -Wextra -Ofast -Wno-unused-result
GCC=gcc $(FLAGS) -I./includes
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
	 ft_list_at.o
BTREE_ROOT=./srcs/btree/
BTREE=ft_btree_foreach.o \
	  ft_btree.o \
	  ft_btree_add.o \
	  ft_btree_search.o \
	  ft_btree_insert.o \
	  ft_btree_level.o \
	  ft_btree_parent.o
OBJ=ft_putchar.o \
	ft_putstr.o \
	ft_swap.o \
	ft_strcmp.o \
	ft_strlen.o \
	ft_str_split.o \
	ft_strcount.o \
	ft_strcpy.o \
	ft_pow.o \
	ft_strrev.o \
	ft_itoa.o \
	ft_atoi.o \
	ft_putnbr.o \
	ft_swap_ptr.o \
	ft_mem.o \
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
	ft_is_sorted.o
lib: $(OBJ) $(LIST) $(BTREE)
all: lib
	@echo "Linking libft"
	$(AR) rc $(LIB) $(OBJ) $(LIST) $(BTREE)
	@echo "done, now making lib index..."
	$(RANLIB) $(LIB)
	@echo "Done."
%.o: $(LIST_ROOT)%.c
	$(GCC) -c $<
%.o: $(BTREE_ROOT)%.c
	$(GCC) -c $<
%.o: ./srcs/%.c
	$(GCC) -c $<
clean:
	rm -f $(OBJ) $(LIST) $(BTREE)
fclean: clean
	rm -f $(LIB) libft.so
re: fclean all
dll:
	make GCC="mingw32-gcc -I./includes -Wall -Werror -Wextra \
		-Wno-ununsed-result -Ofast" AR="mingw32-ar" RANLIB="mingw32-ranlib" \
		LIB="libft.dll"
so:
	make FLAGS="-fpic -Werror -Wall -Wextra -Wno-unused-result -Ofast" lib
	$(GCC) -shared $(OBJ) $(LIST) $(BTREE) -o libft.so
