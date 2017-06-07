# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: snicolet <snicolet@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2015/08/17 10:20:32 by snicolet          #+#    #+#              #
#*   Updated: 2017/06/07 19:56:07 by snicolet         ###   ########.fr       *#
#                                                                              #
# **************************************************************************** #

EXTRA_FLAGS=-pipe -Ofast
FLAGS=-Wall -Werror -Wextra -Wno-unused-result
#CC=clang
ifeq ($(CC),clang)
	EXTRA_FLAGS+=-Weverything
else
	FLAGS += -Wno-strict-aliasing
endif
COMPILE=$(CC) $(FLAGS) -I. $(EXTRA_FLAGS)
RANLIB=ranlib
AR=ar
LIBSO=libft.so
NAME=libft.a
INC=

LIST_DIR=list
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
	 ft_lststrtotab.o \
	 ft_lstissort.o \
	 ft_lstunlink.o \
	 ft_lstat.o \
	 ft_lstprintf.o \
	 ft_lstdupsort.o \
	 ft_lstmin.o \
	 ft_lstissort_circular.o

BTREE_DIR=btree
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

MEMORY_DIR=memory
MEMORY=ft_memset.o \
	   ft_memcpy.o \
	   ft_memccpy.o \
	   ft_memmove.o \
	   ft_memchr.o \
	   ft_memcmp.o \
	   ft_bzero.o \
	   ft_memalloc.o \
	   ft_memdel.o \
	   ft_memdup.o \
	   ft_realloc.o

PRINTF_DIR=printf
PRINTF=ft_printf.o \
	ft_snprintf.o \
	ft_vprintf.o \
	ft_aprintf.o \
	ft_printf_init.o \
	ft_printf_load.o \
	ft_printf_buffer.o \
	ft_printf_arg.o \
	ft_printf_conv.o \
	ft_printf_padding.o \
	conv/ft_printf_conv_int.o \
	conv/ft_printf_conv_str.o \
	conv/ft_printf_conv_percent.o \
	conv/ft_printf_conv_char.o \
	conv/ft_printf_conv_ptr.o \
	conv/ft_printf_conv_wchar.o \
	conv/ft_printf_conv_wstr.o \
	conv/ft_printf_conv_octal.o \
	conv/ft_printf_conv_hex.o \
	conv/ft_printf_conv_upd.o \
	conv/ft_printf_conv_uint.o \
	conv/ft_printf_conv_upud.o \
	conv/ft_printf_conv_unknow.o \
	conv/ft_printf_conv_bits.o \
	conv/ft_printf_conv_n.o \
	conv/ft_printf_conv_callback.o \
	conv/ft_printf_conv_double.o \
	conv/ft_printf_conv_file.o \
	conv/ft_printf_conv_puttab.o

SCANF_DIR=scanf
SCANF=ft_scanf.o \
	  ft_scanfq.o \
	  ft_scanf_load.o \
	  conv/ft_scanf_set_int.o \
	  conv/ft_scanf_set_str.o \
	  conv/ft_scanf_set_float.o \
	  conv/ft_scanf_set_word.o \
	  conv/ft_scanf_set_kernel.o \
	  conv/ft_scanf_set_hex.o \
	  conv/ft_scanf_set_octal.o \
	  conv/ft_scanf_set_percent.o \
	  conv/ft_scanf_set_upn.o \
	  conv/ft_scanf_set_n.o \
	  conv/ft_scanf_set_end.o \
	  conv/ft_scanf_set_vec.o

STRING_DIR=string
STRING=ft_putstr.o ft_putstr_fd.o ft_putstr_align_right.o \
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
	ft_strrev.o ft_strnrev.o \
	ft_strnew.o ft_strdel.o ft_striter.o ft_striteri.o \
	ft_strjoin.o \
	ft_strany.o ft_strany_string.o \
	ft_str_only.o ft_stronlystr.o ft_strnonly.o \
	ft_strdup.o ft_strndup.o \
	ft_putstr_list.o \
	ft_strtab_foreach.o \
	ft_putstrdata.o \
	ft_str_is_printable.o \
	ft_strremove.o \
	ft_strsplitstr_count.o \
	ft_strsublenstr.o \
	ft_strsplitstr.o \
	ft_stralign_right.o ft_stralign_left.o \
	ft_tabstrlen.o \
	ft_strcdup.o \
	ft_strseek.o \
	ft_strsep.o \
	ft_strchrany.o \
	ft_strforf.o \
	ft_strtoupper.o \

OBJ=ft_putchar.o ft_putchar_fd.o \
	ft_putull.o \
	ft_putendl.o ft_putendl_fd.o ft_putnendl.o \
	ft_swap.o \
	ft_pow.o \
	ft_crash.o \
	ft_itoa.o ft_itoa_base.o ft_itobuff.o \
	ft_itobase.o \
	ft_atoi.o \
	ft_atol.o \
	ft_putnbr.o ft_putnbr_fd.o \
	ft_swap_ptr.o \
	ft_free_tab.o \
	ft_sort_tab.o \
	ft_putbits.o \
	ft_putmem.o \
	ft_is_printable.o \
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
	ft_sqrt.o ft_sqrtup.o \
	ft_wsize.o \
	ft_abs.o \
	ft_tabcount.o \
	ft_mfree.o \
	ft_puttab.o \
	ft_atod.o ft_dtoa.o ft_basetoul.o \
	ft_ulltobuff.o \
	ft_freesplit.o \
	ft_get_next_line.o \
	ft_get_line.o \
	ft_putptr.o \
	ft_imaxtobuff.o \
	ft_bitstobuff.o \
	ft_digitlen.o \
	ft_atonum.o \
	ft_readfile.o

UNICODE_DIR=unicode
UNICODE=ft_buffwchar.o \
	ft_wcharlen.o \
	ft_wstrlen.o

OPENGL_ENABLED=no
ifeq ($(OPENGL_ENABLED), yes)
	OPENGL_DIR=opengl
	OPENGL=ft_shader_compile.o \
		ft_opengl_buffer.o
	BREW_DIR=$(HOME)/.brew/include
	INC += -I/usr/local/include -I$(BREW_DIR)
	FLAGS+=-Wno-reserved-id-macro
else
	OPENGL=
	OPENGL_DIR=
endif

################################################################################
##                                                                            ##
##                   COMPILATION RULES : DONT TOUCH: IT'S MAGIC               ##
##                                                                            ##
################################################################################
OBJBUILDDIR=./build
ALLDIR=$(OBJBUILDDIR) \
	$(OBJBUILDDIR)/$(MEMORY_DIR) \
	$(OBJBUILDDIR)/$(LIST_DIR) \
	$(OBJBUILDDIR)/$(BTREE_DIR) \
	$(OBJBUILDDIR)/$(PRINTF_DIR) \
	$(OBJBUILDDIR)/$(PRINTF_DIR)/conv \
	$(OBJBUILDDIR)/$(STRING_DIR) \
	$(OBJBUILDDIR)/$(UNICODE_DIR) \
	$(OBJBUILDDIR)/$(SCANF_DIR) \
	$(OBJBUILDDIR)/$(SCANF_DIR)/conv \
	$(OBJBUILDDIR)/$(OPENGL_DIR)

# all .obj listed with directories
ALLOBJ=$(OBJ:%.o=$(OBJBUILDDIR)/%.o) \
	$(MEMORY:%.o=$(OBJBUILDDIR)/$(MEMORY_DIR)/%.o) \
	$(LIST:%.o=$(OBJBUILDDIR)/$(LIST_DIR)/%.o) \
	$(BTREE:%.o=$(OBJBUILDDIR)/$(BTREE_DIR)/%.o) \
	$(PRINTF:%.o=$(OBJBUILDDIR)/$(PRINTF_DIR)/%.o) \
	$(STRING:%.o=$(OBJBUILDDIR)/$(STRING_DIR)/%.o) \
	$(UNICODE:%.o=$(OBJBUILDDIR)/$(UNICODE_DIR)/%.o) \
	$(SCANF:%.o=$(OBJBUILDDIR)/$(SCANF_DIR)/%.o) \
	$(OPENGL:%.o=$(OBJBUILDDIR)/$(OPENGL_DIR)/%.o)

# all .c files listes with directories
ALLSRC=$(OBJ:%.o=%.c) \
	$(MEMORY:%.o=$(MEMORY_DIR)/%.c) \
	$(LIST:%.o=$(LIST_DIR)/%.c) \
	$(BTREE:%.o=$(BTREE_DIR)/%.c) \
	$(PRINTF:%.o=$(PRINTF_DIR)/%.c) \
	$(STRING:%.o=$(STRING_DIR)/%.c) \
	$(UNICODE:%.o=$(UNICODE_DIR)/%.c) \
	$(SCANF:%.o=$(SCANF_DIR)/%.c) \
	$(OPENGL:%.o=$(OPENGL_DIR)/%.c)

all: $(NAME)

alldir: $(ALLDIR)

$(ALLDIR):
	mkdir -p $@

%.c:

$(NAME): $(ALLDIR) $(ALLOBJ)
	#@$(MAKE) $(ALLOBJ) | grep "$(COMPILE)"
	@echo "Linking libft"
	$(AR) rc $(NAME) $(ALLOBJ)
	@echo "done, now making lib index..."
	$(RANLIB) $(NAME)
	@echo "Done."

$(OBJBUILDDIR)/%.o: %.c
	$(COMPILE) -c $< -o $@ $(INC)

#windows dll cross compill rule
dll:
	make COMPILER="mingw32-gcc" AR="mingw32-ar" RANLIB="mingw32-ranlib" \
		NAME="libft.dll"

#linker for libft.so
$(LIBSO): $(ALLDIR) $(ALLOBJ)
	$(COMPILE) -shared $(ALLOBJ) -o $(LIBSO)
so:
	make FLAGS="-fPIC $(FLAGS)" $(LIBSO)

#cleaners
mrproper: fclean
	find . -name ".*.swp" -print -delete
	find . -name "\#*\#" -print -delete

clean:
	rm -rf $(OBJBUILDDIR)

fclean: clean
	$(RM) $(NAME) $(LIBSO)

re: fclean
	$(MAKE)

norminette:
	norminette $(ALLSRC) libft.h ft_printf.h ft_scanf.h

install: so
	cp libft.h /usr/include/
	cp libft.so /usr/lib/

# normal rule
#.PHONY: norminette so dll re all clean install

# 42file f***ing checker rule

.PHONY: re all clean fclean
