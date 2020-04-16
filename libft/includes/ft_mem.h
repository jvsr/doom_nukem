/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_mem.h                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: pholster <pholster@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/01/08 16:12:36 by pholster      #+#    #+#                 */
/*   Updated: 2019/08/21 23:47:07 by pholster      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_MEM_H
# define FT_MEM_H

# include "ft_bool.h"
# include <string.h>
# include <stdint.h>
# include <stdlib.h>

void		ft_memdel(void **ap);
void		*ft_memalloc(size_t size);
void		ft_bzero(void *str, size_t len);
int			ft_memcmp(const void *str1, const void *str2, size_t len);
ssize_t		ft_memindex(const void *str, char c, size_t len);
t_bool		ft_memequ(const void *str1, const void *str2, size_t len);
void		*ft_memccpy(void *dst, const void *src, char c, size_t len);
void		*ft_memchr(const void *str, char c, size_t len);
void		*ft_memcpy(void *dst, const void *src, size_t len);
void		*ft_memdup(const void *src, size_t len);
void		*ft_memmove(void *dst, const void *src, size_t len);
void		*ft_memrchr(const void *str, char c, size_t len);
void		*ft_memrcpy(void *dst, const void *src, size_t len);
void		*ft_memset(void *str, char c, size_t len);
void		*ft_memset4(void *str, int c, size_t len);
void		ft_swap(void **a, void **b);
t_bool		ft_putmemory(const void *addr, size_t size);
t_bool		ft_putbytes(const void *bytes, size_t n);
t_bool		ft_putpointer(const void *ptr);
void		*ft_pointerreplace(void **ptr1, const void *ptr2);

#endif
