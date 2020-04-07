/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   new_parse_manager.c                                :+:    :+:            */
/*                                                     +:+                    */
/*   By: jvisser <jvisser@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/10/14 14:11:38 by jvisser       #+#    #+#                 */
/*   Updated: 2020/04/06 12:43:47 by euan          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft/ft_mem.h"

#include "lex.h"
#include "parse.h"
#include "error.h"

static t_parse_manager	*alloc(void)
{
	t_parse_manager	*manager;

	manager = (t_parse_manager *)ft_memalloc(sizeof(t_parse_manager));
	if (manager == NULL)
		error_msg_errno("Failed to alloc parse_info");
	return (manager);
}

t_parse_manager			*new_parse_manager(t_token *token)
{
	t_parse_manager	*manager;

	manager = alloc();
	manager->line = 1;
	manager->token = token;
	manager->parse_info = new_parse_info();
	return (manager);
}
