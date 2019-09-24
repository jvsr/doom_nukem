/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   pf_setvar_type.c                                   :+:    :+:            */
/*                                                     +:+                    */
/*   By: pholster <pholster@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/02/12 16:04:27 by pholster       #+#    #+#                */
/*   Updated: 2019/08/21 21:29:33 by pholster      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "ft_char.h"

/*
** TYPES: (% followed by:)
** d or i = int
** u = unsigned int
** b = unsigned binary (base 2)
** o = unsigned octal (base 8)
** x = unsigned hexadecimal (base 16, lowercase)
** X = unsigned hexadecimal (base 16, uppercase)
** f = double
** a = hexdouble (base 16, lowercase)
** A = hexdouble (base 16, uppercase)
** c = unsigned int (If an l modifier is present, wint_t (wide char))
** s = char * (If an l modifier is present, T_WCHAR *)
** p = void *
*/

static void	int_type(t_info *info)
{
	if (info->length == PF_DOUBLE_H)
		info->var_type = CHAR_I;
	else if (info->length == 'h')
		info->var_type = SHORT;
	else if (info->length == PF_DOUBLE_L)
		info->var_type = LONG_LONG;
	else if (info->length == 'l' || info->length == 'z')
		info->var_type = LONG;
	else if (info->length == 'j')
		info->var_type = INT_MAX;
	else
		info->var_type = INT;
}

static void	uint_type(t_info *info)
{
	if (info->length == PF_DOUBLE_H)
		info->var_type = U_CHAR_I;
	else if (info->length == 'h')
		info->var_type = U_SHORT;
	else if (info->length == PF_DOUBLE_L)
		info->var_type = U_LONG_LONG;
	else if (info->length == 'l')
		info->var_type = U_LONG;
	else if (info->length == 'j')
		info->var_type = U_INT_MAX;
	else if (info->length == 'z')
		info->var_type = SIZE_T;
	else
		info->var_type = U_INT;
}

static void	double_type(t_info *info)
{
	if (info->length == 'L')
		info->var_type = LONG_DOUBLE;
	else
		info->var_type = DOUBLE;
}

void		pf_setvar_type(t_info *info)
{
	if (ft_chrin("di", info->type))
		int_type(info);
	else if (ft_chrin("uboxX", info->type))
		uint_type(info);
	else if (info->type == 'f')
		double_type(info);
	else if (info->type == '%')
		info->var_type = CHAR;
	else if (info->type == 'c')
		info->var_type = (info->length == 'l') ? T_WCHAR : CHAR;
	else if (info->type == 's')
		info->var_type = (info->length == 'l') ? T_WCHAR_STR : STR;
	else if (info->type == 'p')
		info->var_type = VOID;
	else
		info->var_type = CHAR;
}
