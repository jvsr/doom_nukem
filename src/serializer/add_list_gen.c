/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   add_list_gen.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: ehollidg <ehollidg@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/10/11 16:33:41 by ehollidg       #+#    #+#                */
/*   Updated: 2019/10/11 16:33:41 by ehollidg      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft/ft_list.h"
#include "libft/ft_mem.h"
#include "serializer.h"

static void	add_lst_data(unsigned char **bytes,
								size_t *b_size, void *val, size_t v_size)
{
	unsigned char *n_bytes;

	n_bytes = ft_memalloc(*b_size + v_size);
	ft_memcpy(n_bytes, *bytes, *b_size);
	ft_memcpy(n_bytes + (unsigned long)*b_size, val, v_size);
	ft_memdel((void**)bytes);
	*bytes = n_bytes;
	*b_size += v_size;
}

void		add_list_gen(t_list *lst, t_binary *bin)
{
	t_convert	con;
	size_t		pre_h_size;
	long		pre_c_size;

	con.l = (long)bin->c_size;
	add_type(&bin->header, &bin->h_size, &con, sizeof(long));
	pre_h_size = bin->h_size;
	con.l = 0;
	add_type(&bin->header, &bin->h_size, &con, sizeof(long));
	pre_c_size = (long)bin->c_size;
	add_lst_data(&bin->content, &bin->c_size, lst->content, lst->content_size);
	if (lst->next != NULL)
		add_list_gen(lst->next, bin);
	pre_c_size = (long)bin->c_size - pre_c_size;
	ft_memcpy(bin->header + pre_h_size, &pre_c_size, sizeof(long));
}
