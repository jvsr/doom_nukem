/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   set_elem_onclick.c                                 :+:    :+:            */
/*                                                     +:+                    */
/*   By: pholster <pholster@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/09/18 17:02:37 by pholster      #+#    #+#                 */
/*   Updated: 2020/04/06 12:12:41 by euan          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "gui.h"

void	set_elem_onclick(t_transform *elem, t_onclick *onclick)
{
	elem->onclick = onclick;
}
