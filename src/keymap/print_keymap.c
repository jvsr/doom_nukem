/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   print_keymap.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: pholster <pholster@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/08/29 15:53:13 by pholster       #+#    #+#                */
/*   Updated: 2019/09/03 13:51:49 by pholster      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <SDL2/SDL_mouse.h>

#include "libft/ft_printf.h"
#include "libft/ft_hash.h"
#include "libft/ft_str.h"

#include "keymap.h"

/*
** * print_keymap will take the keymap. (This function is for debug only)
** * It will then print the state of every monitored key.
*/

const t_keypair	g_keytable[] = {
	(const t_keypair){"UNKNOWN", SDLK_UNKNOWN},

	(const t_keypair){"BUTTON_LEFT", SDL_BUTTON_LEFT},
	(const t_keypair){"BUTTON_RIGHT", SDL_BUTTON_RIGHT},
	(const t_keypair){"BUTTON_MIDDLE", SDL_BUTTON_MIDDLE},

	(const t_keypair){"RETURN", SDLK_RETURN},
	(const t_keypair){"ESCAPE", SDLK_ESCAPE},
	(const t_keypair){"BACKSPACE", SDLK_BACKSPACE},
	(const t_keypair){"TAB", SDLK_TAB},
	(const t_keypair){"SPACE", SDLK_SPACE},
	(const t_keypair){"EXCLAIM", SDLK_EXCLAIM},
	(const t_keypair){"QUOTEDBL", SDLK_QUOTEDBL},
	(const t_keypair){"HASH", SDLK_HASH},
	(const t_keypair){"PERCENT", SDLK_PERCENT},
	(const t_keypair){"DOLLAR", SDLK_DOLLAR},
	(const t_keypair){"AMPERSAND", SDLK_AMPERSAND},
	(const t_keypair){"QUOTE", SDLK_QUOTE},
	(const t_keypair){"LEFTPAREN", SDLK_LEFTPAREN},
	(const t_keypair){"RIGHTPAREN", SDLK_RIGHTPAREN},
	(const t_keypair){"ASTERISK", SDLK_ASTERISK},
	(const t_keypair){"PLUS", SDLK_PLUS},
	(const t_keypair){"COMMA", SDLK_COMMA},
	(const t_keypair){"MINUS", SDLK_MINUS},
	(const t_keypair){"PERIOD", SDLK_PERIOD},
	(const t_keypair){"SLASH", SDLK_SLASH},
	(const t_keypair){"0", SDLK_0},
	(const t_keypair){"1", SDLK_1},
	(const t_keypair){"2", SDLK_2},
	(const t_keypair){"3", SDLK_3},
	(const t_keypair){"4", SDLK_4},
	(const t_keypair){"5", SDLK_5},
	(const t_keypair){"6", SDLK_6},
	(const t_keypair){"7", SDLK_7},
	(const t_keypair){"8", SDLK_8},
	(const t_keypair){"9", SDLK_9},
	(const t_keypair){"COLON", SDLK_COLON},
	(const t_keypair){"SEMICOLON", SDLK_SEMICOLON},
	(const t_keypair){"LESS", SDLK_LESS},
	(const t_keypair){"EQUALS", SDLK_EQUALS},
	(const t_keypair){"GREATER", SDLK_GREATER},
	(const t_keypair){"QUESTION", SDLK_QUESTION},
	(const t_keypair){"AT", SDLK_AT},
	(const t_keypair){"LEFTBRACKET", SDLK_LEFTBRACKET},
	(const t_keypair){"BACKSLASH", SDLK_BACKSLASH},
	(const t_keypair){"RIGHTBRACKET", SDLK_RIGHTBRACKET},
	(const t_keypair){"CARET", SDLK_CARET},
	(const t_keypair){"UNDERSCORE", SDLK_UNDERSCORE},
	(const t_keypair){"BACKQUOTE", SDLK_BACKQUOTE},
	(const t_keypair){"a", SDLK_a},
	(const t_keypair){"b", SDLK_b},
	(const t_keypair){"c", SDLK_c},
	(const t_keypair){"d", SDLK_d},
	(const t_keypair){"e", SDLK_e},
	(const t_keypair){"f", SDLK_f},
	(const t_keypair){"g", SDLK_g},
	(const t_keypair){"h", SDLK_h},
	(const t_keypair){"i", SDLK_i},
	(const t_keypair){"j", SDLK_j},
	(const t_keypair){"k", SDLK_k},
	(const t_keypair){"l", SDLK_l},
	(const t_keypair){"m", SDLK_m},
	(const t_keypair){"n", SDLK_n},
	(const t_keypair){"o", SDLK_o},
	(const t_keypair){"p", SDLK_p},
	(const t_keypair){"q", SDLK_q},
	(const t_keypair){"r", SDLK_r},
	(const t_keypair){"s", SDLK_s},
	(const t_keypair){"t", SDLK_t},
	(const t_keypair){"u", SDLK_u},
	(const t_keypair){"v", SDLK_v},
	(const t_keypair){"w", SDLK_w},
	(const t_keypair){"x", SDLK_x},
	(const t_keypair){"y", SDLK_y},
	(const t_keypair){"z", SDLK_z},
	(const t_keypair){"CAPSLOCK", SDLK_CAPSLOCK},
	(const t_keypair){"F1", SDLK_F1},
	(const t_keypair){"F2", SDLK_F2},
	(const t_keypair){"F3", SDLK_F3},
	(const t_keypair){"F4", SDLK_F4},
	(const t_keypair){"F5", SDLK_F5},
	(const t_keypair){"F6", SDLK_F6},
	(const t_keypair){"F7", SDLK_F7},
	(const t_keypair){"F8", SDLK_F8},
	(const t_keypair){"F9", SDLK_F9},
	(const t_keypair){"F10", SDLK_F10},
	(const t_keypair){"F11", SDLK_F11},
	(const t_keypair){"F12", SDLK_F12},
	(const t_keypair){"PRINTSCREEN", SDLK_PRINTSCREEN},
	(const t_keypair){"SCROLLLOCK", SDLK_SCROLLLOCK},
	(const t_keypair){"PAUSE", SDLK_PAUSE},
	(const t_keypair){"INSERT", SDLK_INSERT},
	(const t_keypair){"HOME", SDLK_HOME},
	(const t_keypair){"PAGEUP", SDLK_PAGEUP},
	(const t_keypair){"DELETE", SDLK_DELETE},
	(const t_keypair){"END", SDLK_END},
	(const t_keypair){"PAGEDOWN", SDLK_PAGEDOWN},
	(const t_keypair){"RIGHT", SDLK_RIGHT},
	(const t_keypair){"LEFT", SDLK_LEFT},
	(const t_keypair){"DOWN", SDLK_DOWN},
	(const t_keypair){"UP", SDLK_UP},
	(const t_keypair){"NUMLOCKCLEAR", SDLK_NUMLOCKCLEAR},
	(const t_keypair){"KP_DIVIDE", SDLK_KP_DIVIDE},
	(const t_keypair){"KP_MULTIPLY", SDLK_KP_MULTIPLY},
	(const t_keypair){"KP_MINUS", SDLK_KP_MINUS},
	(const t_keypair){"KP_PLUS", SDLK_KP_PLUS},
	(const t_keypair){"KP_ENTER", SDLK_KP_ENTER},
	(const t_keypair){"KP_1", SDLK_KP_1},
	(const t_keypair){"KP_2", SDLK_KP_2},
	(const t_keypair){"KP_3", SDLK_KP_3},
	(const t_keypair){"KP_4", SDLK_KP_4},
	(const t_keypair){"KP_5", SDLK_KP_5},
	(const t_keypair){"KP_6", SDLK_KP_6},
	(const t_keypair){"KP_7", SDLK_KP_7},
	(const t_keypair){"KP_8", SDLK_KP_8},
	(const t_keypair){"KP_9", SDLK_KP_9},
	(const t_keypair){"KP_0", SDLK_KP_0},
	(const t_keypair){"KP_PERIOD", SDLK_KP_PERIOD},
	(const t_keypair){"APPLICATION", SDLK_APPLICATION},
	(const t_keypair){"POWER", SDLK_POWER},
	(const t_keypair){"KP_EQUALS", SDLK_KP_EQUALS},
	(const t_keypair){"F13", SDLK_F13},
	(const t_keypair){"F14", SDLK_F14},
	(const t_keypair){"F15", SDLK_F15},
	(const t_keypair){"F16", SDLK_F16},
	(const t_keypair){"F17", SDLK_F17},
	(const t_keypair){"F18", SDLK_F18},
	(const t_keypair){"F19", SDLK_F19},
	(const t_keypair){"F20", SDLK_F20},
	(const t_keypair){"F21", SDLK_F21},
	(const t_keypair){"F22", SDLK_F22},
	(const t_keypair){"F23", SDLK_F23},
	(const t_keypair){"F24", SDLK_F24},
	(const t_keypair){"EXECUTE", SDLK_EXECUTE},
	(const t_keypair){"HELP", SDLK_HELP},
	(const t_keypair){"MENU", SDLK_MENU},
	(const t_keypair){"SELECT", SDLK_SELECT},
	(const t_keypair){"STOP", SDLK_STOP},
	(const t_keypair){"AGAIN", SDLK_AGAIN},
	(const t_keypair){"UNDO", SDLK_UNDO},
	(const t_keypair){"CUT", SDLK_CUT},
	(const t_keypair){"COPY", SDLK_COPY},
	(const t_keypair){"PASTE", SDLK_PASTE},
	(const t_keypair){"FIND", SDLK_FIND},
	(const t_keypair){"MUTE", SDLK_MUTE},
	(const t_keypair){"VOLUMEUP", SDLK_VOLUMEUP},
	(const t_keypair){"VOLUMEDOWN", SDLK_VOLUMEDOWN},
	(const t_keypair){"KP_COMMA", SDLK_KP_COMMA},
	(const t_keypair){"KP_EQUALSAS400", SDLK_KP_EQUALSAS400},
	(const t_keypair){"ALTERASE", SDLK_ALTERASE},
	(const t_keypair){"SYSREQ", SDLK_SYSREQ},
	(const t_keypair){"CANCEL", SDLK_CANCEL},
	(const t_keypair){"CLEAR", SDLK_CLEAR},
	(const t_keypair){"PRIOR", SDLK_PRIOR},
	(const t_keypair){"RETURN2", SDLK_RETURN2},
	(const t_keypair){"SEPARATOR", SDLK_SEPARATOR},
	(const t_keypair){"OUT", SDLK_OUT},
	(const t_keypair){"OPER", SDLK_OPER},
	(const t_keypair){"CLEARAGAIN", SDLK_CLEARAGAIN},
	(const t_keypair){"CRSEL", SDLK_CRSEL},
	(const t_keypair){"EXSEL", SDLK_EXSEL},
	(const t_keypair){"KP_00", SDLK_KP_00},
	(const t_keypair){"KP_000", SDLK_KP_000},
	(const t_keypair){"THOUSANDSSEPARATOR", SDLK_THOUSANDSSEPARATOR},
	(const t_keypair){"DECIMALSEPARATOR", SDLK_DECIMALSEPARATOR},
	(const t_keypair){"CURRENCYUNIT", SDLK_CURRENCYUNIT},
	(const t_keypair){"CURRENCYSUBUNIT", SDLK_CURRENCYSUBUNIT},
	(const t_keypair){"KP_LEFTPAREN", SDLK_KP_LEFTPAREN},
	(const t_keypair){"KP_RIGHTPAREN", SDLK_KP_RIGHTPAREN},
	(const t_keypair){"KP_LEFTBRACE", SDLK_KP_LEFTBRACE},
	(const t_keypair){"KP_RIGHTBRACE", SDLK_KP_RIGHTBRACE},
	(const t_keypair){"KP_TAB", SDLK_KP_TAB},
	(const t_keypair){"KP_BACKSPACE", SDLK_KP_BACKSPACE},
	(const t_keypair){"KP_A", SDLK_KP_A},
	(const t_keypair){"KP_B", SDLK_KP_B},
	(const t_keypair){"KP_C", SDLK_KP_C},
	(const t_keypair){"KP_D", SDLK_KP_D},
	(const t_keypair){"KP_E", SDLK_KP_E},
	(const t_keypair){"KP_F", SDLK_KP_F},
	(const t_keypair){"KP_XOR", SDLK_KP_XOR},
	(const t_keypair){"KP_POWER", SDLK_KP_POWER},
	(const t_keypair){"KP_PERCENT", SDLK_KP_PERCENT},
	(const t_keypair){"KP_LESS", SDLK_KP_LESS},
	(const t_keypair){"KP_GREATER", SDLK_KP_GREATER},
	(const t_keypair){"KP_AMPERSAND", SDLK_KP_AMPERSAND},
	(const t_keypair){"KP_DBLAMPERSAND", SDLK_KP_DBLAMPERSAND},
	(const t_keypair){"KP_VERTICALBAR", SDLK_KP_VERTICALBAR},
	(const t_keypair){"KP_DBLVERTICALBAR", SDLK_KP_DBLVERTICALBAR},
	(const t_keypair){"KP_COLON", SDLK_KP_COLON},
	(const t_keypair){"KP_HASH", SDLK_KP_HASH},
	(const t_keypair){"KP_SPACE", SDLK_KP_SPACE},
	(const t_keypair){"KP_AT", SDLK_KP_AT},
	(const t_keypair){"KP_EXCLAM", SDLK_KP_EXCLAM},
	(const t_keypair){"KP_MEMSTORE", SDLK_KP_MEMSTORE},
	(const t_keypair){"KP_MEMRECALL", SDLK_KP_MEMRECALL},
	(const t_keypair){"KP_MEMCLEAR", SDLK_KP_MEMCLEAR},
	(const t_keypair){"KP_MEMADD", SDLK_KP_MEMADD},
	(const t_keypair){"KP_MEMSUBTRACT", SDLK_KP_MEMSUBTRACT},
	(const t_keypair){"KP_MEMMULTIPLY", SDLK_KP_MEMMULTIPLY},
	(const t_keypair){"KP_MEMDIVIDE", SDLK_KP_MEMDIVIDE},
	(const t_keypair){"KP_PLUSMINUS", SDLK_KP_PLUSMINUS},
	(const t_keypair){"KP_CLEAR", SDLK_KP_CLEAR},
	(const t_keypair){"KP_CLEARENTRY", SDLK_KP_CLEARENTRY},
	(const t_keypair){"KP_BINARY", SDLK_KP_BINARY},
	(const t_keypair){"KP_OCTAL", SDLK_KP_OCTAL},
	(const t_keypair){"KP_DECIMAL", SDLK_KP_DECIMAL},
	(const t_keypair){"KP_HEXADECIMAL", SDLK_KP_HEXADECIMAL},
	(const t_keypair){"LCTRL", SDLK_LCTRL},
	(const t_keypair){"LSHIFT", SDLK_LSHIFT},
	(const t_keypair){"LALT", SDLK_LALT},
	(const t_keypair){"LGUI", SDLK_LGUI},
	(const t_keypair){"RCTRL", SDLK_RCTRL},
	(const t_keypair){"RSHIFT", SDLK_RSHIFT},
	(const t_keypair){"RALT", SDLK_RALT},
	(const t_keypair){"RGUI", SDLK_RGUI},
	(const t_keypair){"MODE", SDLK_MODE},
	(const t_keypair){"AUDIONEXT", SDLK_AUDIONEXT},
	(const t_keypair){"AUDIOPREV", SDLK_AUDIOPREV},
	(const t_keypair){"AUDIOSTOP", SDLK_AUDIOSTOP},
	(const t_keypair){"AUDIOPLAY", SDLK_AUDIOPLAY},
	(const t_keypair){"AUDIOMUTE", SDLK_AUDIOMUTE},
	(const t_keypair){"MEDIASELECT", SDLK_MEDIASELECT},
	(const t_keypair){"WWW", SDLK_WWW},
	(const t_keypair){"MAIL", SDLK_MAIL},
	(const t_keypair){"CALCULATOR", SDLK_CALCULATOR},
	(const t_keypair){"COMPUTER", SDLK_COMPUTER},
	(const t_keypair){"AC_SEARCH", SDLK_AC_SEARCH},
	(const t_keypair){"AC_HOME", SDLK_AC_HOME},
	(const t_keypair){"AC_BACK", SDLK_AC_BACK},
	(const t_keypair){"AC_FORWARD", SDLK_AC_FORWARD},
	(const t_keypair){"AC_STOP", SDLK_AC_STOP},
	(const t_keypair){"AC_REFRESH", SDLK_AC_REFRESH},
	(const t_keypair){"AC_BOOKMARKS", SDLK_AC_BOOKMARKS},
	(const t_keypair){"BRIGHTNESSDOWN", SDLK_BRIGHTNESSDOWN},
	(const t_keypair){"BRIGHTNESSUP", SDLK_BRIGHTNESSUP},
	(const t_keypair){"DISPLAYSWITCH", SDLK_DISPLAYSWITCH},
	(const t_keypair){"KBDILLUMTOGGLE", SDLK_KBDILLUMTOGGLE},
	(const t_keypair){"KBDILLUMDOWN", SDLK_KBDILLUMDOWN},
	(const t_keypair){"KBDILLUMUP", SDLK_KBDILLUMUP},
	(const t_keypair){"EJECT", SDLK_EJECT},
	(const t_keypair){"SLEEP", SDLK_SLEEP},
};

/*
** *	(const t_keypair){"APP1", SDLK_APP1},
** *	(const t_keypair){"APP2", SDLK_APP2},
** *	(const t_keypair){"AUDIOREWIND", SDLK_AUDIOREWIND},
** *	(const t_keypair){"AUDIOFASTFORWARD", SDLK_AUDIOFASTFORWARD},
*/

static const char	*getname(void *key)
{
	const size_t	size = sizeof(g_keytable) / sizeof(t_keypair);
	SDL_Keycode		*sdl_key;
	size_t			i;

	i = 0;
	sdl_key = key;
	while (i < size)
	{
		if (g_keytable[i].key == *sdl_key)
			return (g_keytable[i].name);
		i++;
	}
	return (NULL);
}

static void			print_list(t_hashlist *lst)
{
	size_t			pos;
	t_hashlist		*cur;
	t_keystate		value;

	pos = 0;
	cur = lst;
	while (cur != NULL)
	{
		value = *((t_keystate *)cur->value);
		ft_printf("Name: %s - state: %hhu (List pos: %zu)\n",
			getname(cur->key),
			value,
			pos);
		pos++;
		cur = cur->next;
	}
}

void				print_keymap(const t_hashmap *keymap)
{
	size_t			i;

	i = 0;
	ft_putline(" Keymap ");
	while (i < keymap->size)
	{
		print_list(keymap->arr[i]);
		i++;
	}
	ft_putline("");
}
