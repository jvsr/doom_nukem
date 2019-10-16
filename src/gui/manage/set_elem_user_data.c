/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   set_elem_user_data.c                               :+:    :+:            */
/*                                                     +:+                    */
/*   By: pholster <pholster@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/09/21 01:25:04 by pholster       #+#    #+#                */
/*   Updated: 2019/09/21 01:25:04 by pholster      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "gui.h"

void	set_elem_user_data(t_transform *elem, void *user_data)
{
	elem->user_data = user_data;
}
