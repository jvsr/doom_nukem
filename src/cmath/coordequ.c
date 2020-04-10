/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   coordequ.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: euan <euan@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/04/10 17:58:47 by euan          #+#    #+#                 */
/*   Updated: 2020/04/10 18:08:42 by euan          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft/ft_mem.h"
#include "libft/ft_bool.h"
#include "coord.h"

t_bool		coordequ(t_coord *v0, t_coord *v1)
{
	return (ft_memequ(v0, v1, sizeof(t_coord)));
}
