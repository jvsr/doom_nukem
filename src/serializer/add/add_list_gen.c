/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   add_list_gen.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: ehollidg <ehollidg@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/10/11 16:33:41 by ehollidg      #+#    #+#                 */
/*   Updated: 2020/04/06 11:55:39 by euan          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft/ft_list.h"
#include "libft/ft_mem.h"
#include "serializer.h"
#include "error.h"

static void	add_lst_data(unsigned char **bytes,
								size_t *b_size, void *val, size_t v_size)
{
	unsigned char *n_bytes;

	n_bytes = ft_memalloc(*b_size + v_size);
	if (n_bytes == NULL)
		error_msg_errno("Failed to alloc n_bytes");
	ft_memcpy(n_bytes, *bytes, *b_size);
	ft_memcpy(n_bytes + (t_uint64)*b_size, val, v_size);
	ft_memdel((void**)bytes);
	*bytes = n_bytes;
	*b_size += v_size;
}

void		add_list_gen(t_list *lst, t_binary *bin)
{
	t_convert	con;
	t_uint64	pre_h_size;
	t_uint64	pre_c_size;

	con.l = bin->c_size;
	add_type(&bin->header, &bin->h_size, &con, sizeof(t_uint64));
	pre_h_size = bin->h_size;
	con.l = 0;
	add_type(&bin->header, &bin->h_size, &con, sizeof(t_uint64));
	pre_c_size = bin->c_size;
	add_lst_data(&bin->content, &bin->c_size, lst->content, lst->content_size);
	if (lst->next != NULL)
		add_list_gen(lst->next, bin);
	pre_c_size = bin->c_size - pre_c_size;
	ft_memcpy(bin->header + pre_h_size, &pre_c_size, sizeof(t_uint64));
}
