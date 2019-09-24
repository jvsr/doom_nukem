/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   gui_config.h                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: jvisser <jvisser@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/09/16 12:14:58 by jvisser        #+#    #+#                */
/*   Updated: 2019/09/24 13:14:27 by jvisser       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef GUI_CONFIG_H
# define GUI_CONFIG_H

typedef struct s_panel	t_panel;

int				open_gui_config(const char *file_name);
t_panel			*analyze_gui_config(const char *state_name,
									const char *file_name);

#endif
