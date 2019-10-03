/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   lex.h                                              :+:    :+:            */
/*                                                     +:+                    */
/*   By: jvisser <jvisser@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/09/19 12:34:15 by jvisser        #+#    #+#                */
/*   Updated: 2019/09/24 13:09:18 by jvisser       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEX_H
# define LEX_H

typedef enum	e_token_type
{
	ID,
	NUM,
	PLAIN,
	DASH,
	SLASH,
	COLON,
	COMMA,
	INDENT,
	DEDENT,
	NODENT,
	QUOTE,
	DQUOTE,
	OBRACKET,
	CBRACKET,
	SPACE,
	CR,
	LF,
	CRLF,
}				t_token_type;

typedef	struct	s_token
{
	t_token_type	type;
	size_t			token_amount;
	char			*token;
	struct s_token	*next;
}				t_token;

t_token	*lex_gui_config(const int fd);
t_token	*lex_create_token(t_token_type type, const size_t token_amount);
void	lex_add_token(t_token **tokens, t_token *new);
void	lex_set_token_value(t_token *token, const char *const file,
							size_t *const index, const size_t content_size);
void	lex_check_dash(t_token **tokens, const char *file, size_t *index);
void	lex_check_space(t_token **tokens, const char *file, size_t *index);
void	lex_check_eol(t_token **tokens, const char *file, size_t *index);
void	lex_check_indent(t_token **tokens, const char *file, size_t *index);
void	lex_check_alnum(t_token **tokens, const char *file, size_t *index);

#endif
