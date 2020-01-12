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

typedef struct s_gui		t_gui;
typedef struct s_token		t_token;
typedef struct s_transform	t_transform;
typedef struct s_parse_info	t_parse_info;

int				open_gui_config(const char *file_name, char const *exec_path);
t_transform		*analyze_gui_config(t_gui *gui, const char *file_name,
									char const *exec_path);
t_token			*lex_gui_config(const int fd);
t_parse_info	*parse_gui_config(t_token *tokens);
t_transform		*exec_gui_config(t_gui *ui, t_parse_info *parse_info,
									char const *exec_path);

#endif
