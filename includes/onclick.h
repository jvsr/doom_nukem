/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   onclick.h                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: jvisser <jvisser@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/10/15 17:08:10 by jvisser        #+#    #+#                */
/*   Updated: 2019/10/15 17:08:10 by jvisser       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef ONCLICK_H
# define ONCLICK_H

typedef struct s_game		t_game;
typedef struct s_setting	t_setting;
typedef struct s_transform	t_transform;

void	mainmenu_options(t_game *game, t_transform *gui);
void	mainmenu_quit(t_game *game, t_transform *gui);

void	options_sensitivity_up(t_game *game, t_transform *gui);
void	options_sensitivity_down(t_game *game, t_transform *gui);
void	options_volume_up(t_game *game, t_transform *gui);
void	options_volume_down(t_game *game, t_transform *gui);
void	options_fov_up(t_game *game, t_transform *gui);
void	options_fov_down(t_game *game, t_transform *gui);
void	options_resolution_up(t_game *game, t_transform *gui);
void	options_resolution_down(t_game *game, t_transform *gui);
void	options_resolutiontype_up(t_game *game, t_transform *gui);
void	options_resolutiontype_down(t_game *game, t_transform *gui);
void	options_return(t_game *game, t_transform *gui);

void	confirmation_return(t_game *game, t_transform *gui);

void	restart_game(t_game *game, t_transform *gui);

void	set_sensitivity(t_setting *setting, t_transform *parent);
void	set_volume(t_setting *setting, t_transform *parent);
void	set_fov(t_setting *setting, t_transform *parent);
void	set_resolution(t_setting *setting, t_transform *parent);
void	set_resolutiontype(t_setting *setting, t_transform *parent);

#endif
