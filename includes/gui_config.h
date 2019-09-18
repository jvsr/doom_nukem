/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   gui_config.h                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: jvisser <jvisser@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/09/16 12:14:58 by jvisser        #+#    #+#                */
/*   Updated: 2019/09/18 17:15:59 by jvisser       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef GUI_CONFIG_H
# define GUI_CONFIG_H

typedef struct s_panel	t_panel;

typedef enum	e_token_type
{
	ID,
	NUM,
	PLAIN,
	DASH,
	COLON,
	COMMA,
	INDENT,
	DETENT,
	QUOTE,
	DQUOTE,
	SPACE,
	NEWLINE
}				t_token_type;

typedef	struct	s_token
{
	t_token_type	type;
	char			*token;
	struct s_token	*next;
}				t_token;

t_token			*lex_gui_config(const int fd);
int				open_gui_config(const char *file_name);
t_panel			*parse_gui_config(const char *state_name,
									const char *file_name);

#endif
