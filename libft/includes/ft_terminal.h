/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_terminal.h                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: pholster <pholster@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/01/08 16:12:36 by pholster       #+#    #+#                */
/*   Updated: 2019/08/21 21:01:03 by pholster      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_TERMINAL_H
# define FT_TERMINAL_H

# include "ft_bool.h"
# include "ft_color.h"

t_bool		ft_termclr(void);
t_bool		ft_termclr_fd(int fd);
t_bool		ft_termcommand(int command);
t_bool		ft_termcommand_fd(int command, int fd);
t_bool		ft_termresetcolor(void);
t_bool		ft_termresetcolor_fd(int fd);
t_bool		ft_termresetcolorbg(void);
t_bool		ft_termresetcolorbg_fd(int fd);
t_bool		ft_termsetcolor(t_color color);
t_bool		ft_termsetcolor_fd(t_color color, int fd);
t_bool		ft_termsetcolorbg(t_color color);
t_bool		ft_termsetcolorbg_fd(t_color color, int fd);
t_bool		ft_termsetrgbcolor(t_color r, t_color g, t_color b);
t_bool		ft_termsetrgbcolor_fd(t_color r, t_color g, t_color b, int fd);
t_bool		ft_termsetrgbcolorbg(t_color r, t_color g, t_color b);
t_bool		ft_termsetrgbcolorbg_fd(t_color r, t_color g, t_color b, int fd);

#endif
