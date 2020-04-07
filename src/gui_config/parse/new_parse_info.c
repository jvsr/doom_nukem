/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   new_parse_info.c                                   :+:    :+:            */
/*                                                     +:+                    */
/*   By: pholster <pholster@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/09/30 15:41:15 by pholster      #+#    #+#                 */
/*   Updated: 2020/04/06 12:43:48 by euan          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft/ft_mem.h"
#include "libft/ft_str.h"

#include "parse.h"
#include "error.h"

static t_parse_info	*alloc(void)
{
	t_parse_info	*parse_info;

	parse_info = (t_parse_info *)ft_memalloc(sizeof(t_parse_info));
	if (parse_info == NULL)
		error_msg_errno("Failed to alloc parse_info");
	return (parse_info);
}

t_parse_info		*new_parse_info(void)
{
	t_parse_info	*parse_info;

	parse_info = alloc();
	parse_info->type = GUI_UNDEFINED;
	parse_info->dim = (t_coord){1, 1};
	parse_info->color = ft_strdup("FFFFFFFF");
	if (parse_info->color == NULL)
		error_msg_errno("Failed to alloc Color");
	parse_info->text_color = ft_strdup("FFFFFFFF");
	if (parse_info->text_color == NULL)
		error_msg_errno("Failed to alloc Text Color");
	parse_info->text_size = 1;
	parse_info->clickable = TRUE;
	parse_info->show = TRUE;
	return (parse_info);
}
