/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   exec.h                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: pholster <pholster@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/09/26 17:21:51 by pholster       #+#    #+#                */
/*   Updated: 2019/09/26 17:21:51 by pholster      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef EXEC_H
# define EXEC_H

# include "gui.h"

typedef struct s_parse_info	t_parse_info;

t_transform		*new_exec_elem(t_gui *ui, t_parse_info *elem_info);
void			set_exec_gui_text(t_transform *elem, t_parse_info *elem_info);
void			set_exec_gui_image(t_transform *elem, t_parse_info *elem_info);
void			set_exec_gui_button(t_transform *elem, t_parse_info *elem_info);

#endif
