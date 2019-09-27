/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   exec_gui_config.c                                  :+:    :+:            */
/*                                                     +:+                    */
/*   By: pholster <pholster@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/09/26 17:23:44 by pholster       #+#    #+#                */
/*   Updated: 2019/09/26 17:23:44 by pholster      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "exec.h"
#include "parse.h"
#include "gui.h"

t_transform		*exec_gui_config(t_parse_info *parse_info)
{
	t_transform	*panel;

	panel = exec_new_elem(parse_info);
	(void)parse_info;
	return (panel);
}
