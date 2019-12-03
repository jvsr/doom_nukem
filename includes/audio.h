/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   audio.h                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: ehollidg <ehollidg@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/09/25 17:22:43 by ehollidg       #+#    #+#                */
/*   Updated: 2019/11/12 15:48:04 by jvisser       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef AUDIO_H
# define AUDIO_H

# include <SDL2/SDL_mixer.h>

# define AUDIO_MAX_CHUNKS MIX_CHANNELS
# define AUDIO_FREQ MIX_DEFAULT_FREQUENCY
# define AUDIO_CHANNELS MIX_DEFAULT_CHANNELS
# define AUDIO_BUFFER 4096

# define SOUND_MAP_SIZE 80
# define SOUND_PATH "resources/sounds/effect/"

# define MUSIC_MAP_SIZE 30
# define MUSIC_PATH "resources/sounds/music/"

# define TITLE_SONG "hit_n_smash"

typedef struct s_game		t_game;
typedef struct s_hashmap	t_hashmap;

typedef struct	s_audio_man
{
	t_hashmap	*music_map;
	t_hashmap	*sound_map;
}				t_audio_man;

void			load_audio(t_audio_man *man);
void			load_sound(t_hashmap *sound_map);
void			load_music(t_hashmap *music_map);
void			free_audio(t_game *game);
void			add_track_to_map(t_hashmap *map, void *track, char *const name);
void			*get_track_from_map(t_hashmap *map, char *const name);
Mix_Chunk		*get_chunk_from_wav(char *file);
Mix_Music		*get_music_from_mp3(char *file);
void			play_music(t_audio_man *man, char *const music);
void			stop_music(void);
void			pause_music(void);
void			resume_music(void);
void			fade_in_music(t_audio_man *man, char *const music, int time);
void			fade_out_music(int time);
void			set_music_volume(float volume);
void			play_sound(t_audio_man *man, char *const sound);
void			play_sound_repeat(t_audio_man *man, char *const sound,
									int times);
void			stop_all_sound(void);
void			pause_all_sound(void);
void			resume_all_sound(void);
void			effect_sound(t_audio_man *man, char *const sound,
								int(*func)(int));
void			pause_sound(t_audio_man *man, char *const sound);
void			stop_sound(t_audio_man *man, char *const sound);
void			resume_sound(t_audio_man *man, char *const sound);
void			effect_all_sound(int(*func)(int));
void			set_sound_volume(float volume);

#endif
