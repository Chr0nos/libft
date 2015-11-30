# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: snicolet <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2015/08/17 10:20:32 by snicolet          #+#    #+#              #
#*   Updated: 2015/11/30 15:52:27 by snicolet         ###   ########.fr       *#
#                                                                              #
# **************************************************************************** #

EXTRA_FLAGS=
FLAGS=-Wall -Werror -Wextra -Ofast -Wno-unused-result
COMPILER=gcc
GCC=$(COMPILER) $(FLAGS) -I./includes $(EXTRA_FLAGS)
RANLIB=ranlib
AR=ar
LIBSO=libft.so
NAME=libft.a
LIST_ROOT=./srcs/list/
LIST=ft_list_create_elem.o \
	 ft_list_parent.o \
	 ft_list_size.o \
	 ft_list_last.o \
	 ft_list_swap.o \
	 ft_list_sort.o \
	 ft_list_push_back.o ft_list_push_front.o ft_list_push_sort.o \
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
	   ft_bzero.o \
	   ft_memalloc.o \
	   ft_memdel.o
PRINTF_ROOT=./srcs/printf/
PRINTF=ft_printf.o \
	   ft_vprintf.o
OBJ=ft_putchar.o ft_putchar_fd.o \
	ft_putstr.o ft_putstr_fd.o ft_putstr_align_right.o \
	ft_putendl.o ft_putendl_fd.o \
	ft_swap.o \
	ft_strcmp.o ft_strncmp.o \
	ft_strcat.o ft_strncat.o ft_strlcat.o \
	ft_strlen.o ft_strsublen.o \
	ft_strchr.o ft_strrchr.o \
	ft_strstr.o ft_strrstr.o ft_strnstr.o \
	ft_str_split.o \
	ft_strcount.o ft_strncount.o \
	ft_strcpy.o ft_strncpy.o ft_strlcpy.o \
	ft_strclr.o \
	ft_strmap.o ft_strmapi.o \
	ft_strequ.o ft_strnequ.o \
	ft_strsub.o \
	ft_strtrim.o \
	ft_pow.o \
	ft_strrev.o ft_strnrev.o \
	ft_strnew.o ft_strdel.o ft_striter.o ft_striteri.o \
	ft_strjoin.o \
	ft_itoa.o \
	ft_itobase.o \
	ft_atoi.o \
	ft_putnbr.o ft_putnbr_fd.o \
	ft_swap_ptr.o \
	ft_strany.o ft_strany_string.o \
	ft_str_only.o ft_stronlystr.o \
	ft_strdup.o \
	ft_putstr_list.o \
	ft_free_tab.o \
	ft_strtab_foreach.o \
	ft_putstrdata.o \
	ft_str_numeric.o \
	ft_sort_tab.o \
	ft_putbits.o \
	ft_putmem.o \
	ft_is_printable.o ft_str_is_printable.o \
	ft_puthex.o \
	ft_quicksort.o \
	ft_is_sorted.o \
	ft_convert_base.o \
	ft_match.o \
	ft_isalpha.o \
	ft_isdigit.o \
	ft_isalnum.o \
	ft_isascii.o \
	ft_isprint.o \
	ft_tolower.o \
	ft_toupper.o

################################################################################
##                                                                            ##
##                   COMPILATION RULES : DONT TOUCH: IT'S MAGIC               ##
##                                                                            ##
################################################################################
LIB_CONTENT=$(OBJ) $(MEMORY) $(LIST) $(BTREE) $(PRINTF)

all: $(NAME)
$(NAME): $(LIB_CONTENT)
	@echo "Linking libft"
	$(AR) rc $(NAME) $(LIB_CONTENT)
	@echo "done, now making lib index..."
	$(RANLIB) $(NAME)
	@echo "Done."

#windows dll cross compill rule
dll:
	make COMPILER="mingw32-gcc" AR="mingw32-ar" RANLIB="mingw32-ranlib" \
		NAME="libft.dll"

#linker for libft.so
$(LIBSO): $(LIB_CONTENT)
	$(GCC) -shared $(LIB_CONTENT) -o $(LIBSO)
so:
	make FLAGS="-fpic $(FLAGS)" $(LIBSO)

#cleaners
mrproper: fclean
	find . -name ".*.swp" -print -delete
clean:
	rm -f $(LIB_CONTENT)
fclean: clean
	rm -f $(NAME) $(LIBSO)
re: fclean all
rendu:
	mkdir rendu
	find ./srcs/ -name "*.c" -exec cp {} ./rendu/ \;
	find ./includes/ -name "*.h" -exec cp {} ./rendu/ \;
	cp Makefile ./rendu/
	cp auteur ./rendu/

################################################################################
##                                                                            ##
##                               IMPLICIT RULES                               ##
##                                                                            ##
################################################################################
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
%.o: %.c
	$(GCC) -c $<
