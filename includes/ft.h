/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft.h                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snicolet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/08/17 10:32:34 by snicolet          #+#    #+#             */
/*   Updated: 2015/10/08 12:11:08 by snicolet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_H
# define FT_H

typedef	unsigned int	t_size;

void	ft_putchar(char c);
void	ft_putstr(char *str);
void	ft_putstr_error(char *str);
void	ft_putstr_align_right(char *str, char fill, t_size len);
int		ft_strcmp(char *s1, char *s2);
int		ft_strlen(char *str);
void	ft_swap(int *a, int *b);
int		ft_strsublen(char *str, char c);
char	*ft_strcpy(char *dest, char *src);
char	*ft_strncpy(char *dest, char *src, unsigned int n);
char	*ft_strlcpy(char *dest, char *src);
char	**ft_str_split(char *str, char separator);
int		ft_strcount(char *str, char c);
int		ft_strncount(char *str, char c, unsigned int n);
int		ft_pow(int nb, int power);
char	*ft_strrev(char *str);
char	*ft_itoa(int nb, char *buffer, unsigned char base);
void	ft_putnbr(int nb);
int		ft_atoi(char *str);
void	ft_swap_ptr(void **p1, void **p2);
void	ft_memset(char *str, char c, unsigned int n);
void	*ft_memcpy(void *dest, void *src, unsigned int size);
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

#endif
