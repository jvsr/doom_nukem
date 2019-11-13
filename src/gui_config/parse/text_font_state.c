/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   text_font_state.c                                  :+:    :+:            */
/*                                                     +:+                    */
/*   By: pholster <pholster@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/10/11 16:50:23 by pholster       #+#    #+#                */
/*   Updated: 2019/10/11 16:50:23 by pholster      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft/ft_str.h"

#include "lex.h"
#include "parse.h"
#include "error.h"

static void		set_text_font(t_parse_info *parse_info, const char *text_font)
{
	const char	*name = parse_info->name;

	ft_strdel(&parse_info->text_font);
	parse_info->text_font = ft_strdup(text_font);
	if (parse_info->text_font == NULL)
		error_msg_errno(ft_strformat("Failed to alloc text font in %s", name));
}

t_return_code	colon_text_font_state(t_parse_manager *manager)
{
	return (check_next(manager->token, SPACE));
}

t_return_code	space_text_font_state(t_parse_manager *manager)
{
	return (check_next_str(manager->token));
}

t_return_code	str_text_font_state(t_parse_manager *manager)
{
	set_text_font(manager->parse_info, manager->token->token);
	return (check_next_newline(manager->token));
}
