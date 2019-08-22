/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_memory.h                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: pholster <pholster@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/01/08 16:12:36 by pholster       #+#    #+#                */
/*   Updated: 2019/08/21 23:47:07 by pholster      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_MEMORY_H
# define FT_MEMORY_H

# include "ft_bool.h"
# include <string.h>
# include <stdint.h>
# include <stdlib.h>

void		ft_memdel(void **ap);
void		*ft_memalloc(size_t size);
void		ft_bzero(void *str, size_t len);
int			ft_memcmp(void *str1, void *str2, size_t len);
ssize_t		ft_memindex(void *str, int c, size_t len);
t_bool		ft_memequ(void *str1, void *str2, size_t len);
void		*ft_memccpy(void *dst, void *src, int c, size_t len);
void		*ft_memchr(void *str, int c, size_t len);
void		*ft_memcpy(void *dst, void *src, size_t len);
void		*ft_memdup(void *src, size_t len);
void		*ft_memmove(void *dst, void *src, size_t len);
void		*ft_memrchr(void *str, int c, size_t len);
void		*ft_memrcpy(void *dst, void *src, size_t len);
void		*ft_memreplace(void **str1, void *str2);
void		*ft_memset(void *str, int c, size_t len);
void		ft_swap(void **a, void **b);
t_bool		ft_putmemory(void *addr, size_t size);
t_bool		ft_putbytes(void *bytes, size_t n);
t_bool		ft_putpointer(void *pointer);

#endif
