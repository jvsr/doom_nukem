/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   error_state.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: jvisser <jvisser@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/10/11 16:20:33 by jvisser        #+#    #+#                */
/*   Updated: 2019/10/11 16:20:33 by jvisser       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft/ft_str.h"
#include "libft/ft_printf.h"

#include "lex.h"
#include "error.h"
#include "parse.h"

t_return_code	error_state(t_token **token, t_parse_info **parse_info)
{
	const char		*message;

	(void)parse_info;
	if (*token)
		message = ft_strformat("Unrecognized token '%s' in parser",
								(*token)->token);
	else
		message = ft_strdup("Reached unexpected EOF");
	error_msg("Failed to parse", 20, message);
	return (fail);
}
