/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snicolet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/08/17 10:32:34 by snicolet          #+#    #+#             */
/*   Updated: 2015/11/30 13:43:24 by snicolet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H
# include "list.h"
# include <string.h>

void	ft_putchar(int c);
void	ft_putendl(const char *s);
void	ft_putendl_fd(const char *s, int fd);
void	ft_putstr(const char *str);
void	ft_putstr_fd(const char *s, int fd);
void	ft_putstr_align_right(char *str, char fill, size_t len);
int		ft_strcmp(const char *s1, const char *s2);
int		ft_strncmp(const char *s1, const char *s2, size_t n);
size_t	ft_strlen(const char *str);
void	ft_swap(int *a, int *b);
size_t	ft_strsublen(char *str, char c);
char	*ft_strcpy(char *dest, char *src);
char	*ft_strncpy(char *dest, char *src, unsigned int n);
char	*ft_strlcpy(char *dest, char *src);
char	*ft_strcat(char *dest, const char *src);
char	*ft_strncat(char *dest, const char *src, size_t n);
size_t	ft_strlcat(char *dest, const char *src, size_t n);
char	*ft_strstr(const char *str, const char *item);
char	*ft_strrstr(const char *str, const char *iten);
char	*ft_strnstr(const char *str, const char *item, size_t n);
char	*ft_strmap(const char *s, char (*f)(char));
char	*ft_strmapi(const char *s, char (*f)(unsigned int, char));
char	*ft_strjoin(const char *s1, const char *s2);
char	**ft_str_split(char *str, char separator);
char	*ft_strchr(const char *s, int c);
char	*ft_strrchr(const char *s, int c);
void	ft_strclr(char *s);
int		ft_strcount(char *str, char c);
int		ft_strncount(char *str, char c, unsigned int n);
char	*ft_strnew(size_t size);
void	ft_striter(char *s, void (*f)(char *));
void	ft_striteri(char *s, void (*f)(unsigned int, char *));
int		ft_strequ(const char *s1, const char *s2);
int		ft_strnequ(char const *s1, char const *s2, size_t n);
void	ft_strdel(char **as);
char	*ft_strrev(char *str);
char	*ft_strnrev(char *str, size_t n);
char	*ft_strtrim(const char *s);
char	*ft_itoa(int nb);
char	*ft_itobase(int nb, char *buffer, unsigned char base, const char *map);
void	ft_putnbr(int nb);
int		ft_pow(int nb, int power);
int		ft_atoi(char *str);
void	ft_swap_ptr(void **p1, void **p2);
void	*ft_memset(void *dest, int c, size_t n);
void	*ft_memcpy(void *dest, const void *src, size_t n);
void	*ft_memccpy(void *dest, const void *src, int c, size_t n);
void	*ft_memmove(void *dest, const void *src, size_t n);
void	*ft_memchr(const void *s, int c, size_t n);
int		ft_memcmp(const void *s1, const void *s2, size_t n);
void	*ft_memalloc(size_t size);
void	ft_memdel(void *ap);
void	*ft_realloc(void *ptr, unsigned int size, unsigned int new_size);
int		ft_strany(char c, const char *list);
int		ft_strany_string(const char *str, const char *list);
int		ft_str_only(char c, char *list);
int		ft_str_only_string(char *str, char *list);
char	*ft_strdup(char *str);
void	ft_putstr_list(char **list, int size, char c);
void	ft_free_strtab(char **tab, unsigned int size);
void	ft_strtab_foreach(char **tab, int size, void (*f)(char*));
void	ft_putstrdata(void *data);
int		ft_str_numeric(char *str);
void	ft_sort_integer_table(int *tab, int size);
void	ft_putbits(void *data, unsigned int size);
void	ft_putmem(void *data, size_t size);
void	ft_puthex(void *data, size_t size);
int		ft_is_printable(char c);
int		ft_str_is_printable(char *str);
int		ft_is_sorted(void **tab, size_t size, int (*cmp)());
char	*ft_convert_base(int nb, size_t base, char *pattern);
int		ft_match(char *s1, char *s2);
void	ft_bzero(void *s, size_t n);
int		ft_isalpha(int c);
int		ft_isdigit(int c);
int		ft_isalnum(int c);
int		ft_isascii(int c);
int		ft_isprint(int c);
int		ft_tolower(int c);
int		ft_toupper(int c);
size_t	ft_quicksort_part(void **tab, size_t start, size_t end, int (*cmp)());
void	ft_quicksort(void **tab, size_t start, size_t end, int (*cmp)());

#endif
