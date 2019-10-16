/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   render_text.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: pholster <pholster@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/10/16 18:29:06 by pholster       #+#    #+#                */
/*   Updated: 2019/10/16 18:29:06 by pholster      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <errno.h>
#include <SDL2/SDL_rect.h>
#include <SDL2/SDL_ttf.h>

#include "libft/ft_mem.h"

#include "gui_internal.h"
#include "sdl_extra.h"
#include "error.h"

/*
** * Gui internal function
*/

static void		set_color(t_uint32 *pixel, t_uint32 alpha_mask, t_uint32 value)
{
	*pixel &= alpha_mask;
	*pixel |= value;
}

static void		set_alpha(t_uint32 *pixel, t_uint32 value)
{
	*pixel = value;
}

static t_uint32	prepare_value(SDL_Color *color, SDL_PixelFormat *format)
{
	t_uint32	value;
	t_uint32	temp;

	value = 0;
	ft_memset(&temp, color->r, sizeof(temp));
	value |= temp & format->Rmask;
	ft_memset(&temp, color->g, sizeof(temp));
	value |= temp & format->Gmask;
	ft_memset(&temp, color->b, sizeof(temp));
	value |= temp & format->Bmask;
	return (value);
}

static void		set_text_color(SDL_Surface *text, SDL_Color *color)
{
	const t_uint32	alpha_mask = text->format->Amask;
	const t_uint32	value = prepare_value(color, text->format);
	const size_t	px_size = text->w * text->h;
	t_uint32		*pixels;
	size_t			i;

	i = 0;
	pixels = (t_uint32*)text->pixels;
	while (i < px_size)
	{
		if ((pixels[i] & alpha_mask) < TEXT_ALPHA_ROUND)
			set_alpha(&pixels[i], 0);
		else
			set_alpha(&pixels[i], alpha_mask);
		set_color(&pixels[i], alpha_mask, value);
		i++;
	}
}

SDL_Surface		*render_text(const char *str, TTF_Font *font, SDL_Color *color)
{
	SDL_Surface	*text;

	text = TTF_RenderText_Blended(font, str, *color);
	if (text == NULL)
		error_msg_sdl(ENOMEM, "Failed to render text");
	set_text_color(text, color);
	return (text);
}
