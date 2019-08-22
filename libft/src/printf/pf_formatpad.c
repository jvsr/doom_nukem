/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   pf_formatpad.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: pholster <pholster@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/02/07 14:15:04 by pholster       #+#    #+#                */
/*   Updated: 2019/08/21 21:27:47 by pholster      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "ft_character.h"
#include "ft_string.h"
#include "ft_number.h"

static size_t	addprefix(t_info *info, char *str, size_t n)
{
	if (n == 0)
		return (0);
	pf_addnstr(info, str, n);
	if (info->var_type == VOID && info->width <= info->precision)
		return (0);
	if (info->precision > info->width && ft_strequ(str, "0") == FALSE)
		return (0);
	return (n);
}

static void		addpad(t_info *info, intmax_t len, char c)
{
	intmax_t	i;

	i = 0;
	while (i < len)
	{
		pf_addtobuff(info, &c, 1);
		i++;
	}
}

static void		addzero(t_info *info, intmax_t len, intmax_t space, char *prfx)
{
	size_t	prelen;
	char	c;

	prelen = ft_strlen(prfx);
	c = (pf_iszeropad(info)) ? '0' : ' ';
	len = len - ft_max(0, space);
	if (info->var_type == VOID || info->iszero == FALSE)
		len -= addprefix(info, prfx, prelen);
	else if (ft_tolower(prfx[1]) != 'x' && info->type != 'o')
		len -= addprefix(info, prfx, prelen);
	if (len > 0 && (PF_FLAG_MIN == FALSE || c != ' '))
		addpad(info, len, c);
}

static char		*getprefix(t_info *info)
{
	if (info->isnegative)
		return ("-");
	if (PF_FLAG_PLUS && pf_ispositiveint(info))
		return ("+");
	if (PF_FLAG_SPACE && pf_ispositiveint(info))
		return (" ");
	if ((PF_FLAG_HASH && ft_chrin("xX", info->type))
		|| info->var_type == VOID)
		return ((info->type == 'X') ? "0X" : "0x");
	if (PF_FLAG_HASH && info->type == 'o' && info->iszero == FALSE &&
		info->precision <= info->var_len)
		return ("0");
	return ("");
}

void			pf_formatpad(t_info *info)
{
	char		*prfx;
	size_t		prelen;
	intmax_t	len;
	intmax_t	space;

	prfx = getprefix(info);
	prelen = ft_strlen(prfx);
	info->padadded = info->added;
	if (info->precision > info->width && pf_isstr(info) == FALSE)
		len = ft_max(0, info->precision) - info->var_len;
	else
		len = ft_max(0, info->width) - info->var_len;
	space = ft_max(0, info->width) - ft_max(info->var_len, info->precision);
	if (info->var_type == VOID || info->iszero == FALSE)
		space -= prelen;
	else if (ft_tolower(prfx[1]) != 'x' && info->type != 'o')
		space -= prelen;
	if (PF_FLAG_ZERO && (info->precision == -1 ||
		(info->precision == 0 && PF_FLAG_HASH == FALSE)))
		space = 0;
	if (space > 0 && PF_FLAG_MIN == FALSE)
		addpad(info, space, ' ');
	addzero(info, len, space, prfx);
	info->padadded = info->added - info->padadded;
}
