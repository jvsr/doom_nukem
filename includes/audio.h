/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   audio.h                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: ehollidg <ehollidg@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/09/25 17:22:43 by ehollidg       #+#    #+#                */
/*   Updated: 2019/09/25 17:22:43 by ehollidg      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef AUDIO_H
# define AUDIO_H

typedef struct _Mix_Music	t_mix_music;
typedef struct Mix_Chunk	t_mix_chunk;
typedef struct s_game		t_game;

# define AUDIO_FREQ 22050
# define AUDIO_CHANNELS 2
# define AUDIO_BUFFER 4096
# define SOUND_EFFECT_LOC "./resources/sounds/effects/"
# define MUSIC_LOC "./resources/sounds/music/"

typedef enum	e_music
{
	MUSIC_ASKING_QUESTIONS,
	MUSIC_COUNT
}				t_music;

typedef enum	e_sounds
{
	SOUND_EXPLOSION,
	SOUND_COUNT
}				t_sounds;

typedef struct	s_audio_manager
{
	t_mix_music	*tracks[MUSIC_COUNT];
	t_mix_chunk	*effects[SOUND_COUNT];
}				t_audio_manager;

void			load_audio(t_game *game);
t_mix_chunk		*get_chunk_from_wav(char *file);
t_mix_music		*get_music_from_mp3(char *file);
void			play_music(t_audio_manager *man, t_music music);
void			pause_music(void);
void			resume_music(void);
void			stop_music(void);
void			play_sound(t_audio_manager *man, t_sounds sound);
void			play_sound_repeat(t_audio_manager *man, t_sounds sound,
					int times);
void			stop_all_sounds(void);
void			pause_all_sounds(void);
void			resume_all_sounds(void);
void			effect_sounds(t_audio_manager *man, t_sounds sound,
					int (*func)(int));
void			pause_sounds(t_audio_manager *man, t_sounds sound);
void			stop_sounds(t_audio_manager *man, t_sounds sound);
void			resume_sounds(t_audio_manager *man, t_sounds sound);
void			fade_in_music(t_audio_manager *man, t_music music, int time);
void			fade_out_music(int time);
void			effect_all_sounds(int(*func)(int));
void			set_music_volume(float volume);
void			set_sound_volume(float volume);
void			free_audio(t_game *game);
void			init_audio(t_game *game);

#endif
