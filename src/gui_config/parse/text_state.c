/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   text_state.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: jvisser <jvisser@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/10/11 17:14:39 by jvisser        #+#    #+#                */
/*   Updated: 2019/10/11 17:14:39 by jvisser       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft/ft_str.h"

#include "lex.h"
#include "parse.h"

t_return_code	colon_text_state(t_parse_manager *manager)
{
	return (check_next(manager->token, SPACE));
}

t_return_code	space_text_state(t_parse_manager *manager)
{
	return (check_next(manager->token, DQUOTE));
}

t_return_code	dquote_start_text_state(t_parse_manager *manager)
{
	manager->parse_info->text = ft_strnew(0);
	return (check_next(manager->token, DQUOTE));
}

t_return_code	dquote_end_text_state(t_parse_manager *manager)
{
	return (check_next_newline(manager->token));
}

t_return_code	text_text_state(t_parse_manager *manager)
{
	t_return_code	rc;

	ft_strappend(&manager->parse_info->text, manager->token->token);
	if (check_next(manager->token, DQUOTE) == ok)
		rc = ok;
	else if (get_next_token_type(manager->token) == EOC)
		rc = fail;
	else
		rc = repeat;
	return (rc);
}
