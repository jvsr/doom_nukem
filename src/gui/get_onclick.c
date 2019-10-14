/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   get_onclick.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: pholster <pholster@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/10/07 17:27:29 by pholster       #+#    #+#                */
/*   Updated: 2019/10/07 17:27:29 by pholster      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft/ft_mem.h"
#include "libft/ft_str.h"

#include "gui.h"

static const t_onclickpair	g_onclicks[] = {
	{"button_menu_missions", NULL},
	{"button_menu_options", NULL},
	{"button_menu_quit", NULL},
};

const char	*get_onclick_name(t_onclick *onclick)
{
	const size_t	size = sizeof(g_onclicks) / sizeof(t_onclickpair);
	size_t			i;

	if (onclick == NULL)
		return (NULL);
	i = 0;
	while (i < size)
	{
		if (g_onclicks[i].f != NULL &&
		ft_memequ(onclick, g_onclicks[i].f, sizeof(t_onclick)))
			return (g_onclicks[i].name);
		i++;
	}
	return (NULL);
}

t_onclick	*get_onclick_f(const char *name)
{
	const size_t	size = sizeof(g_onclicks) / sizeof(t_onclickpair);
	size_t			i;

	if (name == NULL)
		return (NULL);
	i = 0;
	while (i < size)
	{
		if (ft_strequ_nocase(name, g_onclicks[i].name))
			return (g_onclicks[i].f);
		i++;
	}
	return (NULL);
}
