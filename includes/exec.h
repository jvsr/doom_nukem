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

typedef struct s_gui		t_gui;
typedef struct s_transform	t_transform;
typedef struct s_parse_info	t_parse_info;

t_transform	*exec_new_elem(t_gui *ui, t_parse_info *parse_info);

#endif
