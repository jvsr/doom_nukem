/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_list.h                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: pholster <pholster@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/01/08 16:12:36 by pholster       #+#    #+#                */
/*   Updated: 2019/08/22 13:06:33 by pholster      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_LIST_H
# define FT_LIST_H

# include "ft_bool.h"
# include <stdint.h>
# include <string.h>

typedef struct	s_list
{
	void			*content;
	size_t			content_size;
	struct s_list	*next;
}				t_list;

t_list			*ft_lstdup(t_list *lst);
t_list			*ft_lstdupone(t_list *lst);
t_list			*ft_lstfind_content(t_list *lst, void *content, size_t size);
t_list			*ft_lstfind_size(t_list *lst, size_t size);
t_list			*ft_lstfindadd_content(t_list *lst, void *content, size_t size);
t_list			*ft_lstfindadd_size(t_list *lst, size_t size);
t_list			*ft_lstindex(t_list *lst, size_t index);
t_list			*ft_lstlast(t_list *lst);
t_list			*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem));
t_list			*ft_lstnew(void *content, size_t content_size);
t_list			*ft_lstunlink(t_list *head, t_list *lst);
size_t			ft_lstlen(t_list *lst);
size_t			ft_lstnlen(t_list *lst, size_t n);
void			ft_lstadd(t_list **head, t_list *new);
void			ft_lstaddbck(t_list **head, t_list *new);
void			ft_lstdel(t_list **head, void (*del)(void *, size_t));
void			ft_lstdelmem(void *content, size_t size);
void			ft_lstdelone(t_list **head, void (*del)(void *, size_t));
void			ft_lstinsert(t_list *head, t_list *lst);
void			ft_lstiter(t_list *lst, void (*f)(t_list *elem));
void			ft_lstrev(t_list **head);
char			**ft_lsttostrarr(t_list *lst);
intmax_t		*ft_lsttonumarr(t_list *lst);
t_bool			ft_lstsortstrac(t_list *sortlst, t_list *lst);
void			ft_lstsort(t_list **head, t_bool (*f)(t_list *, t_list *));
void			ft_lstsortrev(t_list **head, t_bool (*f)(t_list *, t_list *));
t_bool			ft_putlstsize(t_list *lst);
t_bool			ft_putnumlst(t_list *lst);
t_bool			ft_putstrlst(t_list *lst);

#endif