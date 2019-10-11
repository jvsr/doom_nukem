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

t_return_code	colon_text_state(t_token **token, t_parse_info **parse_info)
{
	(void)parse_info;
	return (check_next(token, SPACE));
}

t_return_code	space_text_state(t_token **token, t_parse_info **parse_info)
{
	(void)parse_info;
	return (check_next(token, DQUOTE));
}

t_return_code	dquote_start_text_state(t_token **token,
										t_parse_info **parse_info)
{
	(*parse_info)->text = ft_strnew(0);
	return (check_next(token, DQUOTE));
}

t_return_code	dquote_end_text_state(t_token **token,
										t_parse_info **parse_info)
{
	(void)parse_info;
	return (check_next_newline(token));
}

t_return_code	text_text_state(t_token **token, t_parse_info **parse_info)
{
	t_return_code	rc;

	ft_strappend(&(*parse_info)->text, (*token)->token);
	if (check_next(token, DQUOTE) == ok)
		rc = ok;
	else if (get_next_token_type(token) == EOC)
		rc = fail;
	else
		rc = repeat;
	return (rc);
}
