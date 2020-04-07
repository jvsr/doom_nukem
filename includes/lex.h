/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   lex.h                                              :+:    :+:            */
/*                                                     +:+                    */
/*   By: jvisser <jvisser@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/09/19 12:34:15 by jvisser       #+#    #+#                 */
/*   Updated: 2019/09/25 15:37:15 by jvisser       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEX_H
# define LEX_H

# define UI_CONFIG_PATH "resources/config/ui/"

# include <sys/types.h>

typedef enum	e_token_type
{
	ID,
	NUM,
	PLAIN,
	DASH,
	HASH,
	SLASH,
	COLON,
	COMMA,
	PERIOD,
	INDENT,
	DEDENT,
	NODENT,
	DQUOTE,
	SQUOTE,
	OBRACKET,
	CBRACKET,
	SPACE,
	CR,
	LF,
	CRLF,
	EOC,
}				t_token_type;

typedef	struct	s_token
{
	t_token_type	type;
	size_t			token_amount;
	char			*token;
	struct s_token	*next;
}				t_token;

t_token			*create_lex_token(t_token_type type, const size_t token_amount);
void			add_lex_token(t_token **t, t_token *new);
void			set_lex_token_value(t_token *t, const char *const file,
								size_t *const index, const size_t content_size);
void			check_lex_dash(t_token **t, const char *file, size_t *index);
void			check_lex_hash(t_token **t, const char *file, size_t *index);
void			check_lex_space(t_token **t, const char *file, size_t *index);
void			check_lex_colon(t_token **t, const char *file, size_t *index);
void			check_lex_comma(t_token **t, const char *file, size_t *index);
void			check_lex_quote(t_token **t, const char *file, size_t *index);
void			check_lex_eol(t_token **t, const char *file, size_t *index);
void			check_lex_indent(t_token **t, const char *file, size_t *index);
void			check_lex_period(t_token **t, const char *file, size_t *index);
void			check_lex_alnum(t_token **t, const char *file, size_t *index);

#endif
