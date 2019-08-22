/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_bool.h                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: pholster <pholster@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/01/08 16:12:36 by pholster       #+#    #+#                */
/*   Updated: 2019/08/22 13:10:20 by pholster      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_BOOL_H
# define FT_BOOL_H

typedef enum			e_bool
{
	FALSE,
	TRUE
}						t_bool;

t_bool		ft_putbool_fd(t_bool boolean, int fd);
t_bool		ft_putbool(t_bool boolean);

#endif
