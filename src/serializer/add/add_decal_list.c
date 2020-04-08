/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   add_decal_list.c                                   :+:    :+:            */
/*                                                     +:+                    */
/*   By: euan <euan@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/03/27 17:26:55 by euan          #+#    #+#                 */
/*   Updated: 2020/04/08 16:07:20 by euan          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft/ft_list.h"
#include "libft/ft_mem.h"
#include "serializer.h"

void		add_decal_list(t_list *lst, t_binary *bin)
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
	add_decal(lst->content, bin);
	if (lst->next != NULL)
		add_decal_list(lst->next, bin);
	pre_c_size = bin->c_size - pre_c_size;
	ft_memcpy(bin->header + pre_h_size, &pre_c_size, sizeof(t_uint64));
}
