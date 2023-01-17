/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jurenaul <jurenaul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/11 23:37:29 by jurenaul          #+#    #+#             */
/*   Updated: 2022/12/11 14:09:03 by jurenaul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

// gnl
# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 10
# endif
// printf
# include <stdarg.h>
# include <stdlib.h>
# include <unistd.h>
# include <stdint.h>
// libft
# include <unistd.h>
# include <stdlib.h>
# include <string.h>
# include <stdio.h>

// ## -- gnl -- ##
char	*get_next_line(int fd);
// int		ft_strlen(const char *str);
// char	*ft_strjoin(const char *dest, const char *src);
// char	*ft_strchr(const char *s, int i);
// char	*ft_strdup(const char *s);
// char	*ft_substr(char const *s, unsigned int start, size_t len);

// ## -- printf -- ##
int		ft_printf(const char *str, ...);

int		ft_print_str(char *str);
int		ft_print_char(int c);
int		ft_print_ptr(unsigned long long ptr);
int		ft_print_nbr(int num);
int		ft_print_unsigned(unsigned int num);
int		ft_print_hex(unsigned int num, const char format);
int		ft_print_percent(void);

// ## -- libft -- ##
typedef struct s_list
{
	void			*content;
	struct s_list	*next;
}					t_list;

// ft-is
int		ft_isalnum(int c);
int		ft_isalpha(int c);
int		ft_isascii(int c);
int		ft_isdigit(int c);
int		ft_isprint(int c);

// ft_lst
void	ft_lstadd_back(t_list **alst, t_list *new);
void	ft_lstadd_front(t_list **alst, t_list *new);
void	ft_lstclear(t_list **lst, void (*del)(void*));
void	ft_lstdelone(t_list *lst, void (*del)(void*));
void	ft_lstiter(t_list *lst, void (*f)(void *));
t_list	*ft_lstlast(t_list *lst);
t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *));
t_list	*ft_lstnew(void *content);
int		ft_lstsize(t_list *lst);

// ft_mem
void	ft_bzero(void *s, size_t n);
void	*ft_calloc(size_t count, size_t size);
void	*ft_memchr(const void *s, int c, size_t n);
int		ft_memcmp(const void *s1, const void *s2, size_t n);
void	*ft_memcpy(void *dest, const void *src, size_t n);
void	*ft_memmove(void *dest, const void *src, size_t n);
void	*ft_memset(void *p, int c, size_t len);

// ft_put
void	ft_putchar_fd(char c, int fd);
void	ft_putendl_fd(char *s, int fd);
void	ft_putnbr_fd(int n, int fd);
void	ft_putstr_fd(char *s, int fd);

// ft_str
char	**ft_split(char const *s, char c);
char	*ft_strchr(const char *s, int c);
char	*ft_strdup(const char *s1);
char	*ft_strjoin(char const *s1, char const *s2);
size_t	ft_strlcat(char *dest, const char *src, size_t dest_size);
size_t	ft_strlcpy(char *dest, const char *src, size_t dest_size);
size_t	ft_strlen(const char *s);
size_t	ft_strarrlen(char **arr);
char	*ft_strmapi(char const *s, char (*f)(unsigned int, char));
int		ft_strncmp(const char *s1, const char *s2, size_t n);
char	*ft_strnstr(const char *haystack, const char *needle, size_t len);
char	*ft_strrchr(const char *s, int c);
char	*ft_strtrim(char const *s1, char const *set);
char	*ft_substr(char const *s, unsigned int start, size_t len);

// ft_to
int		ft_atoi(const char *str);
char	*ft_itoa(int n);
int		ft_tolower(int c);
int		ft_toupper(int c);

#endif
