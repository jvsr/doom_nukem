/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   onclick.h                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: jvisser <jvisser@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/10/15 17:08:10 by jvisser       #+#    #+#                 */
/*   Updated: 2020/04/09 12:27:14 by jvisser       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef ONCLICK_H
# define ONCLICK_H

# include <SDL2/SDL_keycode.h>
# include <SDL2/SDL_surface.h>

# include "types.h"

# define PAGE_ITEMS 8

# define MISSION_PATH "resources/data/map"
# define TMP "resources/data/map/tmp_list"
# define CAMPAIGN_PATH "./resources/data/map/campaign"
# define SELECT_CAMPAIGN_PATH "./map/campaign"
# define CUSTOM_PATH "./resources/data/map/custom"
# define SELECT_CUSTOM_PATH "./map/custom"

typedef struct s_game		t_game;
typedef struct s_setting	t_setting;
typedef struct s_transform	t_transform;

void	mainmenu_missions(t_game *game, t_transform *gui);
void	mainmenu_options(t_game *game, t_transform *gui);
void	mainmenu_mapeditor(t_game *game, t_transform *gui);
void	mainmenu_quit(t_game *game, t_transform *gui);

void	map_editor_select_return(t_game *game, t_transform *gui);
void	map_editor_select_new(t_game *game, t_transform *gui);
void	load_editor_map(t_game *game, t_transform *gui);
void	load_editor_map_ok(t_game *game, t_transform *gui);
void	load_editor_map_next(t_game *game, t_transform *gui);
void	load_editor_map_prv(t_game *game, t_transform *gui);
void	load_editor_map_cancel(t_game *game, t_transform *gui);

void	map_editor_object_next(t_game *game, t_transform *gui);
void	map_editor_object_prv(t_game *game, t_transform *gui);
void	map_editor_object_select(t_game *game, t_transform *gui);
void	map_editor_confirmation_return(t_game *game, t_transform *gui);
void	map_editor_remove_confirmation(t_game *game);
void	map_editor_add_confirmation(t_game *game);
void	map_editor_object_next(t_game *game, t_transform *gui);
void	map_editor_object_prv(t_game *game, t_transform *gui);
void	map_editor_object_select(t_game *game, t_transform *gui);
void	save_map(t_game *game, t_transform *gui);

void	options_sensitivity_up(t_game *game, t_transform *gui);
void	options_hud_sensitivity_up(t_game *game, t_transform *gui);
void	options_sensitivity_down(t_game *game, t_transform *gui);
void	options_hud_sensitivity_down(t_game *game, t_transform *gui);
void	options_music_volume_up(t_game *game, t_transform *gui);
void	options_hud_music_volume_up(t_game *game, t_transform *gui);
void	options_music_volume_down(t_game *game, t_transform *gui);
void	options_hud_music_volume_down(t_game *game, t_transform *gui);
void	options_sound_volume_up(t_game *game, t_transform *gui);
void	options_hud_sound_volume_up(t_game *game, t_transform *gui);
void	options_sound_volume_down(t_game *game, t_transform *gui);
void	options_hud_sound_volume_down(t_game *game, t_transform *gui);
void	options_fov_up(t_game *game, t_transform *gui);
void	options_hud_fov_up(t_game *game, t_transform *gui);
void	options_fov_down(t_game *game, t_transform *gui);
void	options_hud_fov_down(t_game *game, t_transform *gui);
void	options_resolution_up(t_game *game, t_transform *gui);
void	options_resolution_down(t_game *game, t_transform *gui);
void	options_resolutiontype_up(t_game *game, t_transform *gui);
void	options_resolutiontype_down(t_game *game, t_transform *gui);

void	options_open_controls(t_game *game, t_transform *gui);
void	options_return(t_game *game, t_transform *gui);
void	hudoptions_return(t_game *game, t_transform *gui);

void	confirmation_return(t_game *game, t_transform *gui);

void	load_missions(t_game *game);
void	remove_maps(t_game *game);
void	set_page_number(t_game *game);
void	missions_left_page(t_game *game, t_transform *gui);
void	missions_right_page(t_game *game, t_transform *gui);
void	missions_focus_campaign(t_game *game, t_transform *gui);
void	missions_focus_custom(t_game *game, t_transform *gui);
void	mission_return(t_game *game, t_transform *gui);

void	controls_set_forward(t_game *game, t_transform *gui);
void	controls_set_backward(t_game *game, t_transform *gui);
void	controls_set_left(t_game *game, t_transform *gui);
void	controls_set_right(t_game *game, t_transform *gui);
void	controls_set_shoot(t_game *game, t_transform *gui);
void	controls_set_interact(t_game *game, t_transform *gui);
void	controls_set_crouch(t_game *game, t_transform *gui);
void	controls_set_jump(t_game *game, t_transform *gui);
void	controls_return(t_game *game, t_transform *gui);

void	restart_game(t_game *game, t_transform *gui);

void	set_sensitivity(t_setting *setting, t_transform *parent);
void	set_hudsensitivity(t_setting *setting, t_transform *parent);
void	set_music(t_setting *setting, t_transform *parent);
void	set_hudmusic(t_setting *setting, t_transform *parent);
void	set_sound(t_setting *setting, t_transform *parent);
void	set_hudsound(t_setting *setting, t_transform *parent);
void	set_fov(t_setting *setting, t_transform *parent, SDL_Surface *surf);
void	set_hudfov(t_setting *setting, t_transform *parent, SDL_Surface *surf);
void	set_resolution(t_setting *setting, t_transform *parent);
void	set_resolution_type(t_setting *setting, t_transform *parent);

void	set_key_str(SDL_Keycode keycode, t_transform *self);

void	set_int(int setting, t_transform *location);
void	set_float(float setting, t_transform *location, int precision);
void	incr_float_max(float *loc, float incr, float max);
void	decr_float_min(float *loc, float decr, float min);
void	incr_uint16_max(t_uint16 *loc, t_uint16 incr, t_uint16 max);
void	decr_uint16_min(t_uint16 *loc, t_uint16 decr, t_uint16 min);

void	remove_options(t_game *game);
void	add_confirmation(t_game *game);
void	remove_confirmation(t_game *game);

void	load_level(t_game *game, t_transform *gui);
void	go_to_game(t_game *game, t_transform *gui);
void	hud_diedmainmenu(t_game *game, t_transform *gui);

#endif
