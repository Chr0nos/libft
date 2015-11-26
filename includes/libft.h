/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snicolet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/08/17 10:32:34 by snicolet          #+#    #+#             */
/*   Updated: 2015/11/26 14:03:32 by snicolet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_H
# define FT_H
# include <unistd.h>
# include "ft_printf.h"

typedef	unsigned int	t_size;

void	ft_putchar(char c);
void	ft_putstr(char *str);
void	ft_putstr_error(char *str);
void	ft_putstr_align_right(char *str, char fill, t_size len);
int		ft_strcmp(char *s1, char *s2);
int		ft_strncmp(const char *s1, const char *s2, size_t n);
size_t	ft_strlen(char *str);
void	ft_swap(int *a, int *b);
size_t	ft_strsublen(char *str, char c);
char	*ft_strcpy(char *dest, char *src);
char	*ft_strncpy(char *dest, char *src, unsigned int n);
char	*ft_strlcpy(char *dest, char *src);
char	*ft_strcat(char *dest, const char *src);
char	*ft_strncat(char *dest, const char *src, size_t n);
char	*ft_strstr(const char *str, const char *item);
size_t	ft_strlcat(char *dest, const char *src, size_t n);
char	**ft_str_split(char *str, char separator);
char	*ft_strchr(const char *s, int c);
int		ft_strcount(char *str, char c);
int		ft_strncount(char *str, char c, unsigned int n);
int		ft_pow(int nb, int power);
char	*ft_strrev(char *str);
char	*ft_itoa(int nb, char *buffer);
char	*ft_itobase(int nb, char *buffer, unsigned char base, const char *map);
void	ft_putnbr(int nb);
int		ft_atoi(char *str);
void	ft_swap_ptr(void **p1, void **p2);
void	ft_memset(char *str, char c, size_t n);
void	*ft_memcpy(void *dest, void *src, size_t);
void	*ft_memmove(void *dest, const void *src, size_t n);
void	*ft_memchr(const void *s, int c, size_t n);
int		ft_memcmp(const void *s1, const void *s2, size_t n);
void	*ft_realloc(void *ptr, unsigned int size, unsigned int new_size);
int		ft_strany(char c, char *list);
int		ft_strany_string(char *str, char *list);
int		ft_str_only(char c, char *list);
int		ft_str_only_string(char *str, char *list);
char	*ft_strdup(char *str);
void	ft_putstr_list(char **list, int size, char c);
void	ft_free_strtab(char **tab, unsigned int size);
void	ft_strtab_foreach(char **tab, int size, void (*f)(char*));
void	ft_putstrdata(void *data);
int		ft_str_numeric(char *str);
void	ft_sort_integer_table(int *tab, int size);
void	ft_putobits(unsigned char *x);
void	ft_putbits(void *data, unsigned int size);
void	ft_putmem(void *data, unsigned int size);
void	ft_putmem_ascii(void *data, unsigned int size);
int		ft_is_printable(char c);
int		ft_str_is_printable(char *str);
int		ft_is_sorted(void **tab, t_size size, int (*cmp)());
char	*ft_convert_base(int nb, t_size base, char *pattern);
int     ft_match(char *s1, char *s2);
void	ft_bzero(void *s, size_t n);
int		ft_isalpha(const char *str);
int		ft_isdigit(const char *str);

#endif
