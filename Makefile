# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: snicolet <snicolet@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2015/08/17 10:20:32 by snicolet          #+#    #+#              #
#    Updated: 2016/07/15 13:36:19 by snicolet         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

EXTRA_FLAGS=-Weverything -pipe
FLAGS=-Wall -Werror -Wextra -Wno-unused-result
COMPILER=clang
GCC=$(COMPILER) $(FLAGS) -I. $(EXTRA_FLAGS)
RANLIB=ranlib
AR=ar
LIBSO=libft.so
NAME=libft.a
LIST=ft_lstnew.o ft_lstnewstr.o ft_lstnewlink.o \
	 ft_lstpush_sort.o ft_lstpush_back.o ft_lstpush_front.o \
	 ft_lstdelone.o \
	 ft_lstdel.o \
	 ft_lstinsert.o \
	 ft_lstadd.o \
	 ft_lstiter.o \
	 ft_lstlast.o \
	 ft_lstmap.o \
	 ft_lstparent.o \
	 ft_lstswap.o \
	 ft_lstsort.o \
	 ft_lststrlen.o \
	 ft_lstsize.o \
	 ft_lstremove.o \
	 ft_lstforeach.o ft_lstforeachi.o \
	 ft_lstforeach_suffix.o ft_lstforeachi_suffix.o \
	 ft_lstpulverisator.o \
	 ft_lststrmap.o \
	 ft_lststrcmp.o \
	 ft_lstdup.o \
	 ft_lststrtotab.o
BTREE=ft_btree_create_node.o \
	  ft_btree_add.o \
	  ft_btree_search.o \
	  ft_btree_search_mess.o \
	  ft_btree_insert.o \
	  ft_btree_level.o \
	  ft_btree_parent.o \
	  ft_btree_level_max.o \
	  ft_btree_foreach_infix.o \
	  ft_btree_foreach_prefix.o \
	  ft_btree_foreach_suffix.o \
	  ft_btree_free.o
MEMORY=ft_memset.o \
	   ft_memcpy.o \
	   ft_memccpy.o \
	   ft_memmove.o \
	   ft_memchr.o \
	   ft_memcmp.o \
	   ft_bzero.o \
	   ft_memalloc.o \
	   ft_memdel.o \
	   ft_memdup.o
PRINTF=ft_printf.o
GNL=ft_get_next_line.o
OBJ=ft_putchar.o ft_putchar_fd.o \
	ft_putstr.o ft_putstr_fd.o ft_putstr_align_right.o \
	ft_putptr.o \
	ft_putull.o ft_putfloat.o \
	ft_putendl.o ft_putendl_fd.o ft_putnendl.o \
	ft_swap.o \
	ft_strcmp.o ft_strncmp.o ft_strcasecmp.o \
	ft_strcat.o ft_strncat.o ft_strlcat.o \
	ft_strlen.o ft_strsublen.o \
	ft_strchr.o ft_strrchr.o ft_strchrpos.o ft_strchrrpos.o \
	ft_strstr.o ft_strrstr.o ft_strnstr.o \
	ft_strsplit.o ft_strsplit_count.o ft_strunsplit.o \
	ft_strcount.o ft_strncount.o \
	ft_strcpy.o ft_strncpy.o ft_strlcpy.o \
	ft_strclr.o \
	ft_strmap.o ft_strmapi.o \
	ft_strequ.o ft_strnequ.o \
	ft_strsub.o \
	ft_strtrim.o \
	ft_strreplace.o \
	ft_strmjoin.o \
	ft_pow.o \
	ft_crash.o \
	ft_strrev.o ft_strnrev.o \
	ft_strnew.o ft_strdel.o ft_striter.o ft_striteri.o \
	ft_strjoin.o \
	ft_itoa.o ft_itoa_base.o ft_itobuff.o ft_ftobuff.o \
	ft_itobase.o \
	ft_atoi.o \
	ft_putnbr.o ft_putnbr_fd.o \
	ft_swap_ptr.o \
	ft_strany.o ft_strany_string.o \
	ft_str_only.o ft_stronlystr.o ft_strnonly.o \
	ft_strdup.o ft_strndup.o \
	ft_putstr_list.o \
	ft_free_tab.o \
	ft_strtab_foreach.o \
	ft_putstrdata.o \
	ft_sort_tab.o \
	ft_putbits.o \
	ft_putmem.o \
	ft_is_printable.o ft_str_is_printable.o \
	ft_puthex.o \
	ft_quicksort.o \
	ft_is_sorted.o \
	ft_match.o \
	ft_isalpha.o \
	ft_isdigit.o \
	ft_isalnum.o \
	ft_isascii.o \
	ft_isprint.o \
	ft_tolower.o \
	ft_toupper.o \
	ft_rotx.o \
	ft_brainfuck.o \
	ft_tabstrlen.o \
	ft_sqrt.o ft_sqrtup.o \
	ft_strremove.o \
	ft_wsize.o \
	ft_abs.o \
	ft_stralign_right.o ft_stralign_left.o \
	ft_tabtoconst.o ft_tabcount.o \
	ft_mfree.o \
	ft_puttab.o \
	ft_strsplitstr_count.o \
	ft_strsublenstr.o \
	ft_strsplitstr.o \
	ft_atod.o ft_dtoa.o ft_basetoul.o \
	ft_strtoupper.o \
	ft_ulltobuff.o

################################################################################
##                                                                            ##
##                   COMPILATION RULES : DONT TOUCH: IT'S MAGIC               ##
##                                                                            ##
################################################################################
LIB_CONTENT=$(OBJ) $(MEMORY) $(LIST) $(BTREE) $(GNL) $(PRINTF)

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
	make FLAGS="-fPIC $(FLAGS)" $(LIBSO)

#cleaners
mrproper: fclean
	find . -name ".*.swp" -print -delete
	find . -name "\#*\#" -print -delete
clean:
	rm -f $(LIB_CONTENT)
fclean: clean
	rm -f $(NAME) $(LIBSO)
re: fclean all

norminette:
	norminette *.[ch]

install: so
	cp libft.h /usr/include/
	cp libft.so /usr/lib/

.PHONY: norminette re clean fclean so dll all mrproper

################################################################################
##                                                                            ##
##                               IMPLICIT RULES                               ##
##                                                                            ##
################################################################################
%.o: %.c
	$(GCC) -c $<
