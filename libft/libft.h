/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dverbyts <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/21 20:49:09 by dverbyts          #+#    #+#             */
/*   Updated: 2016/12/21 22:22:05 by dverbyts         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <unistd.h>
# include <stdlib.h>
# include <string.h>
# include <fcntl.h>

# define BUFF_SIZE 100

typedef struct		s_line
{
	char			*l;
	int				n_fd;
	struct s_line	*next;
}					t_line;

typedef struct		s_list
{
	void			*content;
	size_t			content_size;
	struct s_list	*next;
}					t_list;

int					ft_toupper(int buf);
int					ft_tolower(int buf);
char				*ft_strncpy(char *dest, const char *sors, size_t n);
char				*ft_strcpy(char *dest, const char *sors);
void				ft_strclr(char *s);
size_t				ft_strlen(const char *string);
int					ft_strlenint(const char *string);
int					ft_strequ(char const *s1, char const *s2);
int					ft_strnequ(char const *s1, char const *s2, size_t n);
int					ft_strcmp(char const *s1, char const *s2);
int					ft_strncmp(char const *s1, char const *s2, size_t n);
char				*ft_strchr(const char *s, int c);
char				*ft_strrchr(const char *s, int c);
char				*ft_strstr(const char *big, const char *ltl);
char				*ft_strnstr(const char *big, const char *ltl, size_t len);
char				*ft_strcat(char *s1, const char *s2);
char				*ft_strncat(char *s1, const char *s2, size_t num);
size_t				ft_strlcat(char *dst, const char *src, size_t size);
void				ft_putstr_fd(char const *s, int fd);
void				ft_putstr(char const *s);
void				ft_putnbr_fd(int n, int fd);
void				ft_putnbr(int n);
void				ft_putendl_fd(char const *s, int fd);
void				ft_putendl(char const *s);
void				ft_putchar_fd(char c, int fd);
void				ft_putchar(char c);
int					ft_isprint(int test);
int					ft_isdigit(int test);
int					ft_isascii(int test);
int					ft_isalpha(int test);
int					ft_isalnum(int test);
char				*ft_strdup(const char *s1);
void				ft_bzero(void *s, size_t n);
void				*ft_memcpy(void *dst, const void *src, size_t n);
void				*ft_memccpy(void *dst, const void *src, int c, size_t n);
void				*ft_memset(void *b, int c, size_t len);
int					ft_memcmp(const void *s1, const void *s2, size_t n);
void				*ft_memmove(void *dst, const void *src, size_t len);
void				*ft_memnclr(void *s, size_t x);
void				*ft_memchr(const void *s, int c, size_t n);
int					ft_atoi(char *str);
void				*ft_memalloc(size_t size);
void				ft_memdel(void **ap);
char				*ft_strnew(size_t size);
void				ft_strdel(char **ap);
char				**ft_strsplit(char const *s, char c);
char				*ft_strtrim(char *s);
char				*ft_strsub(char const *s, unsigned int start, size_t len);
char				*ft_strjoin(char const *t, char const *y);
char				*ft_itoa(int n);
void				ft_striter(char *s, void (*f) (char *));
void				ft_striteri(char *s, void (*f) (unsigned int, char *));
char				*ft_strmap(char const *s, char (*f) (char));
char				*ft_strmapi(char const *s, char (*f) (unsigned int, char));
t_list				*ft_lstnew(void const *content, size_t content_size);
void				ft_lstdelone(t_list **alst, void (*del) (void *, size_t));
void				ft_lstdel(t_list **alst, void (*del) (void *, size_t));
void				ft_lstadd(t_list **alst, t_list *new);
void				ft_lstiter(t_list *lst, void (*f) (t_list *elem));
t_list				*ft_lstmap(t_list *lst, t_list *(*f) (t_list *elem));
void				ft_lstpush(t_list *cur, void *cont, size_t content_size);
int					ft_lstlen(t_list *lst);
int					ft_atoi_16(char *str);
int					get_next_line(const int fd, char **line);
char				*string(t_line **l);
t_line				*make_list(int fd, t_line **start);
int					read_file(t_line **lst, int fd);

#endif
