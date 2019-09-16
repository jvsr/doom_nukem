/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   gui_config.h                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: jvisser <jvisser@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/09/16 12:14:58 by jvisser        #+#    #+#                */
/*   Updated: 2019/09/16 16:12:16 by jvisser       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef GUI_CONFIG_H
# define GUI_CONFIG_H

typedef struct s_panel	t_panel;

typedef	struct	s_token
{
	size_t			indent;
	char			*token;
	struct s_token	*next;
}				t_token;

t_token		*lex_gui_config(const int fd);
int			open_gui_config(const char *file_name);
t_panel		*parse_gui_config(const char *state_name, const char *file_name);

#endif
