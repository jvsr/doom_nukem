/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_printf.h                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: pholster <pholster@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/02/02 14:13:30 by pholster       #+#    #+#                */
/*   Updated: 2019/08/23 11:05:51 by pholster      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include "ft_bool.h"
# include "ft_list.h"
# include "ft_color.h"
# include "ft_utf8.h"
# include <stdlib.h>
# include <string.h>
# include <stdarg.h>

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

# define PF_A_TYPE		"fdiuboxXcsp%"
# define PF_A_TYPE_L	"FDOUCS"
# define PF_A_FLAG		"#0-+ \'"
# define PF_A_SPACER	",;:_"
# define PF_A_LENGTH	"hlLjz"
# define PF_A_LENGTH_D	"hl"
# define PF_DOUBLE_H	208
# define PF_DOUBLE_L	216
# define PF_FLAG_HASH	info->flag[0]
# define PF_FLAG_ZERO	info->flag[1]
# define PF_FLAG_MIN	info->flag[2]
# define PF_FLAG_PLUS	info->flag[3]
# define PF_FLAG_SPACE	info->flag[4]
# define PF_FLAG_APOST	info->flag[5]
# define PF_BUFF_SIZE	256

typedef enum	e_type
{
	INT,
	INT_MAX,
	SHORT,
	LONG,
	DOUBLE,
	SIZE_T,
	CHAR_I,
	CHAR,
	STR,
	VOID,
	T_WCHAR,
	T_WCHAR_STR,
	LONG_LONG,
	LONG_DOUBLE,
	U_INT,
	U_INT_MAX,
	U_SHORT,
	U_LONG,
	U_LONG_LONG,
	U_CHAR_I
}				t_type;

typedef	struct	s_info
{
	va_list	args;
	t_bool	flag[7];
	char	type;
	char	width;
	int		length;
	ssize_t	precision;
	ssize_t	var_len;
	t_type	var_type;
	int		var_base;
	t_bool	iszero;
	t_bool	isnegative;
	char	*buff;
	t_list	*buff_list;
	size_t	buff_len;
	size_t	added;
	size_t	padadded;
	int		fd;
}				t_info;

/*
** ------------------------------"Face" Functions-------------------------------
*/

ssize_t			ft_printf(char *format, ...);
ssize_t			ft_dprintf(int fd, char *format, ...);
char			*ft_strformat(char *format, ...);
char			*ft_strformat_len(size_t *len, char *format, ...);

/*
** ----------------------------Distribute Functions-----------------------------
*/

size_t			pf_commands(t_info *info, char *str);
size_t			pf_distribute(t_info *info, char *start);
void			pf_formatdistribute(t_info *info);

/*
** -------------------------------Info Functions--------------------------------
*/

t_info			*pf_infonew(void);
void			pf_infosetdefault(t_info *info);
size_t			pf_getinfo(t_info *info, char *str);
size_t			pf_getflag(t_info *info, char *str);
size_t			pf_getprecision(t_info *info, char *str);
size_t			pf_getwidth(t_info *info, char *str);
int				pf_getlength(t_info *info, char *str);
int				pf_gettype(t_info *info, char *str);
void			pf_setvar_base(t_info *info);
void			pf_setvar_type(t_info *info);

/*
** ------------------------------Format Functions-------------------------------
*/

void			pf_formatbackpad(t_info *info);
void			pf_formatchar(t_info *info);
void			pf_formatdouble(t_info *info);
void			pf_formatnum(t_info *info);
void			pf_formatpad(t_info *info);
void			pf_formatstr(t_info *info);
void			pf_formatunum(t_info *info);
size_t			pf_formatcolor(t_info *info, char *start);

/*
** -------------------------Buffer Management Functions-------------------------
*/

t_bool			pf_addtobuff(t_info *info, char *str, size_t len);
size_t			pf_addstr(t_info *info, char *str);
void			pf_addchar(t_info *info, char c);
void			pf_addnstr(t_info *info, char *str, size_t n);
void			pf_addnum(t_info *info, intmax_t value);
void			pf_addunum(t_info *info, uintmax_t value, size_t len, int base);
void			pf_addwchar(t_info *info, t_wchar c);
void			pf_addwcharstr(t_info *info, t_wchar *str, size_t n);
void			pf_addcolor(t_info *info, int color);
void			pf_addcolorbg(t_info *info, int color);
void			pf_addrgbcolor(t_info *info, t_color r, t_color g, t_color b);
void			pf_addrgbcolorbg(t_info *info, t_color r, t_color g, t_color b);

/*
** --------------------------------Is Functions---------------------------------
*/

t_bool			pf_ispositiveint(t_info *info);
t_bool			pf_issignint(t_info *info);
t_bool			pf_isstr(t_info *info);
t_bool			pf_isunsignint(t_info *info);
t_bool			pf_iszeropad(t_info *info);

/*
** -----------------------------Overflow Functions------------------------------
*/

intmax_t		pf_overflowsigned(t_info *info);
uintmax_t		pf_overflowunsigned(t_info *info);

#endif
