# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: snicolet <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2015/08/17 10:20:32 by snicolet          #+#    #+#              #
#*   Updated: 2015/09/10 19:55:04 by snicolet         ###   ########.fr       *#
#                                                                              #
# **************************************************************************** #

NAME=libft.a
GCC=gcc -Wall -Werror -Wextra -Ofast -Wno-unused-result -I./includes
LIST_ROOT=./srcs/list/
LIST=ft_list.o \
	 ft_list_sort.o \
	 ft_list_push.o \
	 ft_list_free.o \
	 ft_list_foreach.o \
	 ft_list_to.o \
	 ft_list_map.o \
	 ft_list_strlen.o \
	 ft_list_insert.o \
	 ft_list_remove.o
BTREE_ROOT=./srcs/btree/
BTREE=ft_btree_foreach.o
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
	ft_str_numeric.o ft_sort_tab.o

all: ft_lib

ft_lib: ft_base ft_list ft_btree
	@echo "Linking libft"
	ar rc $(NAME) $(OBJ) $(LIST) $(BTREE)
	@echo "done, now making lib index..."
	ranlib $(NAME)
	@echo "Done."
ft_base: $(OBJ)
	@echo "ft_lib base ok"
ft_list: ft_base
	@echo "Compiling chained lists parts..."
	$(foreach i, $(LIST), \
		$(GCC) -c $(LIST_ROOT)$(shell echo $i | sed -e "s/\.o/\.c/1"); \
	)
	@echo "Done"
ft_btree: ft_base
	@echo "Compiling btree support"
	$(foreach i, $(BTREE), \
		$(GCC) -c $(BTREE_ROOT)$(shell echo $i | sed -e "s/\.o/\.c/1"); \
	)
	@echo "done"
%.o: ./srcs/%.c
	$(GCC) -c $<
clean:
	rm -f $(OBJ) $(LIST) $(BTREE)
fclean: clean
	rm -f $(NAME)
re: fclean all

