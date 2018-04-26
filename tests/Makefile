#* ************************************************************************** *#
#*                                                                            *#
#*                                                        :::      ::::::::   *#
#*   Makefile                                           :+:      :+:    :+:   *#
#*                                                    +:+ +:+         +:+     *#
#*   By: snicolet <marvin@student.42.fr>            +#+  +:+       +#+        *#
#*                                                +#+#+#+#+#+   +#+           *#
#*   Created: 2018/02/11 21:18:42 by snicolet          #+#    #+#             *#
#*   Updated: 2018/02/11 21:29:16 by snicolet         ###   ########.fr       *#
#*                                                                            *#
#* ************************************************************************** *#

malloc:
	clang -Weverything -Werror malloc.c -o malloc -I../include -L.. -lft -lpthread

gl:
	make -C ../
	clang -Weverything -Wno-padded -Werror test_getline.c -o getline -I../include -L.. -lft
	./getline test_getline.c

clean:
	$(RM) malloc
