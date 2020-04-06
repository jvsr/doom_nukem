/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   error_state.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: jvisser <jvisser@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/10/11 16:20:33 by jvisser       #+#    #+#                 */
/*   Updated: 2020/04/06 12:43:57 by euan          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft/ft_str.h"

#include "lex.h"
#include "error.h"
#include "parse.h"

t_return_code	error_state(t_parse_manager *manager)
{
	const char		*message;

	if (manager->token == NULL)
		message = ft_strdup("Reached unexpected EOF");
	else
		message = ft_strformat("Line %zu: Unrecognized token '%s' in parser",
								manager->line, manager->token->token);
	error_msg("Failed to parse", 20, message);
	return (fail);
}
