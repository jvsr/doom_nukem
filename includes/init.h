/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   init.h                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: jvisser <jvisser@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/08/27 14:39:20 by jvisser        #+#    #+#                */
/*   Updated: 2019/09/03 13:43:26 by pholster      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef INIT_H
# define INIT_H

# define INIT_WIDTH	1080
# define INIT_HEIGHT 720
# define INIT_KEYMAP_SIZE 20
# define INIT_KEYMAP_ALGO ft_hashdjb2a

typedef struct s_game	t_game;

t_game	*init(void);

#endif
