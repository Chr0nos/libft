/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snicolet <snicolet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/08/17 10:32:34 by snicolet          #+#    #+#             */
/*   Updated: 2017/06/05 15:32:13 by snicolet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H
# define LOMAGIC 0x1010101010101010lu
# define HIMAGIC 0x8080808080808080lu
# define LONGCHR_NULL(x) (((x - LOMAGIC) & HIMAGIC) != 0)
# define LONGCHR(l, b) (((((l ^ b) - LOMAGIC) & ~(l ^ b)) & (LOMAGIC << 7)) !=0)
# define IFRET__(x, y) if (x) return (y)
# define EIFRET__(x, y)	else if (x) return (y)
# define ERET__(y) else return (y)
# define SHORTIFY(x) ((unsigned short)x | (unsigned short)x << 8)
# define INTIFY(x) ((unsigned int)x | (unsigned int)x << 16)
# define LONGIFY(x) ((unsigned long)x | (unsigned long)x << 32)
# define FT_MIN(x, y) ((x < y) ? x : y)
# define _
# include <string.h>
# include "get_next_line.h"
# include "ft_printf.h"
# include "ft_scanf.h"

# ifndef GNL_BUFF_SIZE
#  define GNL_BUFF_SIZE 80
# endif

# if GNL_BUFF_SIZE < 64
#  define GNL_GROW_SIZE 64
# else
#  define GNL_GROW_SIZE GNL_BUFF_SIZE
# endif
# if GNL_BUFF_SIZE > 128
#  define GNL_START_SIZE GNL_BUFF_SIZE
# else
#  define GNL_START_SIZE 128
# endif

typedef struct		s_gnl_buffer
{
	int				fd;
	int				padding;
	size_t			buf_size;
	size_t			cursor;
	char			*strb;
}					t_gnlb;

typedef struct		s_list
{
	void			*content;
	size_t			content_size;
	struct s_list	*next;
}					t_list;

typedef struct		s_btree
{
	struct s_btree	*left;
	struct s_btree	*right;
	void			*data;
}					t_btree;

void				ft_putchar(int c);
void				ft_putchar_fd(int c, int fd);
void				ft_putendl(const char *s);
void				ft_putendl_fd(const char *s, int fd);
void				ft_putnendl(const char *s, size_t n);
void				ft_putull(unsigned long long n);
void				ft_putstr(const char *str);
void				ft_putfloat(float nb);
void				ft_putstr_fd(const char *s, int fd);
void				ft_putstr_align_right(char *str, char fill, size_t len);
void				ft_putptr(void *ptr);
void				ft_puttab(const char **tab);
void				ft_swap(int *a, int *b);
void				ft_strclr(char *s);
void				ft_striter(char *s, void (*f)(char *));
void				ft_striteri(char *s, void (*f)(unsigned int, char *));
void				ft_strdel(char **as);
void				ft_putnbr(int nb);
void				ft_putnbr_fd(int n, int fd);
void				ft_swap_ptr(void **p1, void **p2);
void				ft_putstr_list(char **list, int size, char c);
void				ft_free_tab(char **tab, size_t size);
void				ft_strtab_foreach(char **tab, int size, void (*f)(char*));
void				ft_putstrdata(void *data);
void				ft_sort_tab(int *tab, int size);
void				ft_putbits(void *data, size_t size);
void				ft_putmem(void *data, size_t size);
void				ft_puthex(void *data, size_t size);
void				ft_bzero(void *s, size_t n);
void				ft_quicksort(void **tab, size_t start, size_t end,
	int (*cmp)(void *, void *));
void				ft_crash(void);
void				ft_rotx(char *s, int x);
char				*ft_strsub(const char *s, unsigned int start, size_t len);
char				*ft_strcpy(char *dest, const char *src);
char				*ft_strncpy(char *dest, const char *src, size_t n);
char				*ft_strcat(char *dest, const char *src);
char				*ft_strncat(char *dest, const char *src, size_t n);
char				*ft_strstr(char *str, const char *item);
char				*ft_strrstr(char *str, const char *iten);
char				*ft_strnstr(char *s1, const char *s2, size_t n);
char				*ft_strmap(const char *s, char (*f)(char));
char				*ft_strmapi(const char *s, char (*f)(unsigned int, char));
char				*ft_strjoin(const char *s1, const char *s2);
char				**ft_strsplit(const char *str, char separator);
char				*ft_strunsplit(const char **tab, char separator);
char				*ft_strmjoin(const size_t n, ...);
char				*ft_strchr(char *s, int c);
char				*ft_strchr_old(char *s, int c);
char				*ft_strrchr(char *s, int c);
char				*ft_strreplace(char *s, char what, char by);
char				*ft_strrev(char *str);
char				*ft_strnrev(char *str, size_t n);
char				*ft_strtrim(const char *s);
char				*ft_itoa(int nb);
char				*ft_itoa_base(int value, int base);
char				*ft_itobase(int nb, char *buffer, unsigned char base,
	const char *map);
int					ft_strcmp(const char *s1, const char *s2);
char				*ft_strnew(size_t size);
int					ft_strncmp(const char *s1, const char *s2, size_t n);
int					ft_strcasecmp(const char *s1, const char *s2);
int					ft_strchrpos(const char *s, const char c);
int					ft_strchrrpos(const char *str, const char c);
int					ft_strncount(char *str, char c, unsigned int n);
int					ft_strequ(const char *s1, const char *s2);
int					ft_strnequ(char const *s1, char const *s2, size_t n);
int					ft_itobuff(char *buffer, int nb, unsigned int base,
	const char *map);
int					ft_pow(int nb, int power);
int					ft_atoi(const char *str);
long				ft_atol(const char *str);
int					ft_memcmp(const void *s1, const void *s2, size_t n);
int					ft_strany(char c, const char *list);
int					ft_strany_string(const char *str, const char *list);
int					ft_str_only(const char c, const char *list);
int					ft_strnonly(char *s, size_t n, char c);
int					ft_stronlystr(char *str, char *list);
int					ft_isalpha(int c);
int					ft_isdigit(int c);
int					ft_isalnum(int c);
int					ft_isascii(int c);
int					ft_isprint(int c);
int					ft_tolower(int c);
int					ft_toupper(int c);
int					ft_is_printable(char c);
int					ft_str_is_printable(char *str);
int					ft_is_sorted(void **tab, size_t size,
	int (*cmp)(void *, void *));
int					ft_match(char *s1, const char *s2);
char				*ft_strdup(const char *str);
char				*ft_strndup(const char *s, size_t n);
size_t				ft_strlen(const char *str);
size_t				ft_strsublen(const char *str, char c);
size_t				ft_strlcpy(char *dest, const char *src, size_t size);
size_t				ft_strlcat(char *dest, const char *src, size_t n);
size_t				ft_strsplit_count(const char *str, char c);
size_t				ft_strcount(const char *str, char c);
size_t				ft_tabstrlen(const char **tab);
double				ft_atod(const char *s);
const char			*ft_strforf(const char *str, const char *sep, int *len);
size_t				ft_strplen(const char *str, const char *maxptr);

/*
** memory usage functions
*/

void				*ft_memset(void *dest, int c, size_t n);
void				*ft_memcpy(void *dest, const void *src, size_t n);
void				*ft_memccpy(void *dest, const void *src, int c, size_t n);
void				*ft_memmove(void *dest, const void *src, size_t n);
void				*ft_memchr(const void *s, int c, size_t n);
void				*ft_memalloc(size_t size);
void				ft_memdel(void **ap);
void				*ft_memdup(const void *src, size_t size);
void				*ft_realloc(void *ptr, size_t size, size_t new_size);

/*
** function for chained lists
*/

char				**ft_lststrmap(t_list *lst);
char				**ft_lststrtotab(t_list *lst);
void				ft_lstremove(t_list **item, t_list **root,
	void (*f)(void *));
void				ft_lstdelone(t_list **alst, void (*del)(void *, size_t));
void				ft_lstdel(t_list **ast, void (*del)(void *, size_t));
void				ft_lstinsert(t_list **parent, t_list *item);
void				ft_lstiter(t_list *lst, void (*f)(t_list *elem));
void				ft_lstsort(t_list **lst, int (*cmp)(t_list *, t_list *));
void				ft_lstpush_sort(t_list **lst, t_list *item,
	int (*cmp)(t_list *, t_list *));
void				ft_lstforeach(t_list *lst, void (*f)(void *));
void				ft_lstforeachi(t_list *lst,
	void (*f)(size_t, size_t, void *));
void				ft_lstforeachi_suffix(t_list *lst,
	void (*f)(size_t, size_t, void *));
void				ft_lstforeach_suffix(t_list *lst, void (*f)(void *));
void				ft_lstpulverisator(void *x, size_t size);
int					ft_lststrcmp(t_list *a, t_list *b);
t_list				*ft_lstnew(const void *content, size_t content_size);
t_list				*ft_lstnewstr(const char *str);
t_list				*ft_lstnewlink(void *content, size_t content_size);
t_list				*ft_lstadd(t_list **alst, t_list *new);
t_list				*ft_lstparent(t_list *lst, t_list *item);
t_list				*ft_lstswap(t_list *root, t_list *a, t_list *b);
t_list				*ft_lstlast(t_list *lst);
t_list				*ft_lstpush_back(t_list **lst, t_list *item);
t_list				*ft_lstpush_front(t_list **lst, t_list *item);
t_list				*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem));
t_list				*ft_lstdup(t_list *lst, void *(*f)(void *));
t_list				*ft_lstndup(t_list *lst, size_t n, void *(*f)(void *));
t_list				*ft_lstat(t_list *lst, int p);
t_list				*ft_lstdupsort(t_list *lst, int (*cmp)(t_list *, t_list *));
t_list				*ft_lstmin(t_list *lst, int (*cmp)(t_list *, t_list *));
size_t				ft_lststrlen(t_list *lst);
size_t				ft_lstsize(t_list *lst);
int					ft_lstissort(t_list *lst, int (*cmp)(t_list *, t_list *));
int					ft_lstunlink(t_list **lst, t_list *item);
void				ft_lstprintf(t_printf *pf);
void				ft_lstprintf_numeric(t_printf *pf);
int					ft_lstissort_circular(t_list *lst,
		int (*cmp)(t_list *, t_list *));

/*
** binary trees
*/

void				ft_btree_foreach_infix(t_btree *root, void (*f)(void *));
void				ft_btree_foreach_prefix(t_btree *root, void (*f)(void *));
void				ft_btree_foreach_suffix(t_btree *root, void (*f)(void *));
void				ft_btee_free(t_btree **root);
void				ft_btree_free(t_btree **root);
void				ft_btree_add(t_btree **root, void *data,
	int (*f)(void *, void *));
void				ft_btree_insert(t_btree **node, void *data,
	int (*f)(void *, void *));
int					ft_btree_level(t_btree *root, t_btree *item, int level);
size_t				ft_btree_level_max(t_btree *root);
t_btree				*ft_btree_create_node(void *data);
t_btree				*ft_btree_search_mess(t_btree *root, void *val,
	int (*f)(void *, void *));
t_btree				*ft_btree_search(t_btree *root, void *data,
	int (*f)(void *, void *));
t_btree				*ft_btree_parent(t_btree *root, t_btree *item);

char				*ft_brainfuck(char *str, unsigned char *ptr);
float				ft_sqrt(float nb);
int					ft_sqrtup(int nb);
char				*ft_strremove(char *s, const char *list);
void				ft_wsize(unsigned long long size, char *buffer);
int					ft_abs(int x);
void				ft_stralign_right(char *buffer, unsigned int len);
void				ft_stralign_left(char *buffer, unsigned int len);
size_t				ft_tabcount(void **tab);
int					ft_mfree(unsigned int size, ...);
size_t				ft_strsplitstr_count(const char *str,
		const char *separators);
size_t				ft_strsublenstr(const char *str, const char *separators);
char				**ft_strsplitstr(const char *str, const char *separators);
char				*ft_dtoa(double nb, unsigned int precision);
unsigned long		ft_basetoul(const char *str, const char *map);
char				*ft_strtoupper(char *s);
int					ft_ulltobuff(char *buffer, unsigned long long nb,
	unsigned int base, const char *map);
char				*ft_strcdup(const char *src, char c);
const char			*ft_strseek(const char *src, char c, const int n);
void				ft_freesplit(char **split);
void				ft_freesplit_multi(char ***split, int size);
char				*ft_strchrany(char *str, const char *list);
char				*ft_strsep(char **str, const char *delim);
int					ft_buffwchar(const wchar_t c, char *buff);
int					ft_wcharlen(const wchar_t c);
size_t				ft_wstrlen(const wchar_t *s);
int					ft_imaxtobuff(char *buffer, intmax_t nb,
	int base, const char *map);
int					ft_bitstobuff(char *buff, unsigned long long x,
	const int n);
int					ft_udigit_len(uintmax_t nb, unsigned int base);
int					ft_digit_len(intmax_t nb, unsigned int base);
int					ft_atonum(const char *str, int *nb);
char				*ft_readfile(const char *filepath, size_t *usize);
int					ft_get_line(int const fd, char **line);

#endif
