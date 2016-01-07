/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snicolet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/08/17 10:32:34 by snicolet          #+#    #+#             */
/*   Updated: 2016/01/07 16:06:52 by snicolet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H
# include <string.h>
# include "get_next_line.h"

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
void				ft_putstr_fd(const char *s, int fd);
void				ft_putstr_align_right(char *str, char fill, size_t len);
void				ft_putptr(void *ptr);
int					ft_strcmp(const char *s1, const char *s2);
int					ft_strncmp(const char *s1, const char *s2, size_t n);
size_t				ft_strlen(const char *str);
void				ft_swap(int *a, int *b);
size_t				ft_strsublen(const char *str, char c);
char				*ft_strsub(const char *s, unsigned int start, size_t len);
char				*ft_strcpy(char *dest, const char *src);
char				*ft_strncpy(char *dest, const char *src, size_t n);
size_t				ft_strlcpy(char *dest, const char *src, size_t size);
char				*ft_strcat(char *dest, const char *src);
char				*ft_strncat(char *dest, const char *src, size_t n);
size_t				ft_strlcat(char *dest, const char *src, size_t n);
char				*ft_strstr(char *str, const char *item);
char				*ft_strrstr(char *str, const char *iten);
char				*ft_strnstr(char *s1, const char *s2, size_t n);
char				*ft_strmap(const char *s, char (*f)(char));
char				*ft_strmapi(const char *s, char (*f)(unsigned int, char));
char				*ft_strjoin(const char *s1, const char *s2);
char				**ft_strsplit(const char *str, char separator);
size_t				ft_strsplit_count(const char *str, char c);
char				*ft_strunsplit(char **tab, char separator);
char				*ft_strchr(char *s, int c);
int					ft_strchrpos(const char *s, const char c);
char				*ft_strrchr(char *s, int c);
void				ft_strclr(char *s);
char				*ft_strreplace(char *s, char what, char by);
size_t				ft_strcount(char *str, char c);
int					ft_strncount(char *str, char c, unsigned int n);
char				*ft_strnew(size_t size);
void				ft_striter(char *s, void (*f)(char *));
void				ft_striteri(char *s, void (*f)(unsigned int, char *));
int					ft_strequ(const char *s1, const char *s2);
int					ft_strnequ(char const *s1, char const *s2, size_t n);
void				ft_strdel(char **as);
char				*ft_strrev(char *str);
char				*ft_strnrev(char *str, size_t n);
char				*ft_strtrim(const char *s);
char				*ft_itoa(int nb);
char				*ft_itoa_base(int value, int base);
char				*ft_itobase(int nb, char *buffer, unsigned char base,
		const char *map);
void				ft_putnbr(int nb);
void				ft_putnbr_fd(int n, int fd);
int					ft_pow(int nb, int power);
int					ft_atoi(const char *str);
void				ft_swap_ptr(void **p1, void **p2);
void				*ft_memset(void *dest, int c, size_t n);
void				*ft_memcpy(void *dest, const void *src, size_t n);
void				*ft_memccpy(void *dest, const void *src, int c, size_t n);
void				*ft_memmove(void *dest, const void *src, size_t n);
void				*ft_memchr(const void *s, int c, size_t n);
int					ft_memcmp(const void *s1, const void *s2, size_t n);
void				*ft_memalloc(size_t size);
void				ft_memdel(void **ap);
void				*ft_memdup(const void *src, size_t size);
void				*ft_realloc(void *ptr, unsigned int size,
		unsigned int new_size);
int					ft_strany(char c, const char *list);
int					ft_strany_string(const char *str, const char *list);
int					ft_str_only(char c, char *list);
int					ft_strnonly(char *s, size_t n, char c);
int					ft_stronlystr(char *str, char *list);
char				*ft_strdup(const char *str);
char				*ft_strndup(const char *s, size_t n);
size_t				ft_tabstrlen(char **tab);
void				ft_putstr_list(char **list, int size, char c);
void				ft_free_tab(char **tab, unsigned int size);
void				ft_strtab_foreach(char **tab, int size, void (*f)(char*));
void				ft_putstrdata(void *data);
void				ft_sort_tab(int *tab, int size);
void				ft_putbits(void *data, size_t size);
void				ft_putmem(void *data, size_t size);
void				ft_puthex(void *data, size_t size);
int					ft_is_printable(char c);
int					ft_str_is_printable(char *str);
int					ft_is_sorted(void **tab, size_t size, int (*cmp)());
int					ft_match(char *s1, char *s2);
void				ft_bzero(void *s, size_t n);
int					ft_isalpha(int c);
int					ft_isdigit(int c);
int					ft_isalnum(int c);
int					ft_isascii(int c);
int					ft_isprint(int c);
int					ft_tolower(int c);
int					ft_toupper(int c);
void				ft_quicksort(void **tab, size_t start, size_t end,
		int (*cmp)());
void				ft_crash(void);
void				ft_rotx(char *s, int x);
t_list				*ft_lstnew(const void *content, size_t content_size);
t_list				*ft_lstnewstr(char *str);
void				ft_lstremove(t_list **item, t_list **root, void (*f)());
void				ft_lstdelone(t_list **alst, void (*del)(void *, size_t));
void				ft_lstdel(t_list **ast, void (*del)(void *, size_t));
void				ft_lstadd(t_list **alst, t_list *new);
void				ft_lstinsert(t_list **parent, t_list *item);
void				ft_lstiter(t_list *lst, void (*f)(t_list *elem));
size_t				ft_lststrlen(t_list *lst);
size_t				ft_lstsize(t_list *lst);
t_list				*ft_lstparent(t_list *lst, t_list *item);
void				ft_lstswap(t_list **lst, t_list *a, t_list *b);
t_list				*ft_lstlast(t_list *lst);
t_list				*ft_lstpush_back(t_list **lst, t_list *item);
t_list				*ft_lstpush_front(t_list **lst, t_list *item);
t_list				*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem));
void				ft_lstsort(t_list **lst, int (*cmp)(t_list *, t_list *));
void				ft_lstpush_sort(t_list **lst, void *data, size_t size,
		int (*cmp)());
void				ft_lstforeach(t_list *lst, void (*f)());
void				ft_lstforeachi(t_list *lst,
		void (*f)(size_t, size_t, void *));
void				ft_lstforeachi_suffix(t_list *lst,
		void (*f)(size_t, size_t, void *));
void				ft_lstforeach_suffix(t_list *lst, void (*f)());
void				ft_lstpulverisator(void *x, size_t size);
char				**ft_lststrmap(t_list *lst);
void				ft_btree_foreach_infix(t_btree *root, void (*f)(void *));
void				ft_btree_foreach_prefix(t_btree *root, void (*f)(void *));
void				ft_btree_foreach_suffix(t_btree *root, void (*f)(void *));
t_btree				*ft_btree_create_node(void *data);
void				ft_btree_add(t_btree **root, void *data, int (*f)());
t_btree				*ft_btree_search_mess(t_btree *root, void *val, int (*f)());
t_btree				*ft_btree_search(t_btree *root, void *data, int (*f)());
t_btree				*ft_btree_parent(t_btree *root, t_btree *item);
void				ft_btree_insert(t_btree **node, void *data, int (*f)());
int					ft_btree_level(t_btree *root, t_btree *item, int level);
size_t				ft_btree_level_max(t_btree *root);
void				ft_btee_free(t_btree **root);
void				ft_btree_free(t_btree **root);
char				*ft_brainfuck(char *str, unsigned char *ptr);
float				ft_sqrt(float nb);
int					ft_sqrtup(int nb);
char				*ft_strremove(char *s, const char *list);
int					ft_printf(const char *s, ...);

#endif
