/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   gui_config.h                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: jvisser <jvisser@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/09/16 12:14:58 by jvisser        #+#    #+#                */
/*   Updated: 2019/09/25 15:41:16 by jvisser       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef GUI_CONFIG_H
# define GUI_CONFIG_H

typedef struct s_panel		t_panel;
typedef struct s_token		t_token;
typedef struct s_parse_info	t_parse_info;

int			open_gui_config(const char *file_name);
t_panel		*analyze_gui_config(const char *state_name, const char *file_name);
t_token		*lex_gui_config(const int fd);
void		parse_gui_config(const t_token *tokens, const char *state_name);
t_panel		*exec_gui_config(t_parse_info *parse_info);

#endif
