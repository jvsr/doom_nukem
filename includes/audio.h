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

# define SOUND_EFFECT_PATH "resources/sounds/effects/"
# define MUSIC_PATH "resources/sounds/music/"

typedef struct s_game		t_game;

typedef enum	e_music
{
	MUSIC_LONELY_TROUTMAN,
	MUSIC_ASKING_QUESTIONS,
	MUSIC_HIT_N_SMASH,
	MUSIC_COUNT
}				t_music;

typedef enum	e_sounds
{
	SOUND_EXPLOSION,
	SOUND_COUNT
}				t_sounds;

typedef struct	s_audio_man
{
	Mix_Music	*tracks[MUSIC_COUNT];
	Mix_Chunk	*effects[SOUND_COUNT];
}				t_audio_man;

void			load_audio(t_game *game);
Mix_Chunk		*get_chunk_from_wav(char *file, char const *exec_path);
Mix_Music		*get_music_from_mp3(char *file, char const *exec_path);
void			play_music(t_audio_man *man, t_music music);
void			pause_music(void);
void			resume_music(void);
void			stop_music(void);
void			play_sound(t_audio_man *man, t_sounds sound);
void			play_sound_repeat(t_audio_man *man, t_sounds sound,
					int times);
void			stop_all_sounds(void);
void			pause_all_sounds(void);
void			resume_all_sounds(void);
void			effect_sounds(t_audio_man *man, t_sounds sound,
					int (*func)(int));
void			pause_sounds(t_audio_man *man, t_sounds sound);
void			stop_sounds(t_audio_man *man, t_sounds sound);
void			resume_sounds(t_audio_man *man, t_sounds sound);
void			fade_in_music(t_audio_man *man, t_music music, int time);
void			fade_out_music(int time);
void			effect_all_sounds(int(*func)(int));
void			set_music_volume(float volume);
void			set_sound_volume(float volume);
void			free_audio(t_game *game);

#endif
