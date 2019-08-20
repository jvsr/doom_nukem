/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   libft.h                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: pholster <pholster@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/01/08 16:12:36 by pholster       #+#    #+#                */
/*   Updated: 2019/08/10 11:18:55 by pholster      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_LIBFT_H
# define FT_LIBFT_H

# include <stdarg.h>
# include "typedefs.h"

char		**ft_lsttostrarr(t_list *lst);
char		**ft_strarrcpy_var(char **dst, size_t count, ...);
char		**ft_strarrcpy(char **dst, const char **src);
char		**ft_strarrdup_var(size_t count, ...);
char		**ft_strarrdup(const char **arr);
char		**ft_strarrnew(size_t size);
char		**ft_strdsplit(const char *str, const char *dlm);
char		**ft_strfldnew(size_t x, size_t y, char c);
char		**ft_strsplit(const char *str, char c);
char		*ft_chrtostr(char c);
char		*ft_colorstr(int color);
char		*ft_itoa_base(intmax_t value, int base);
char		*ft_itoa_cbase(intmax_t value, int base, t_bool up);
char		*ft_itoa(intmax_t value);
char		*ft_strcat(char *str1, const char *str2);
char		*ft_strchr(const char *str, int c);
char		*ft_strcpy(char *dst, const char *src);
char		*ft_strdtrim(const char *str, const char *dlm);
char		*ft_strdup(const char *str);
char		*ft_strjoin_arr(const char **arr);
char		*ft_strjoin_var(size_t count, ...);
char		*ft_strjoin(const char *str1, const char *str2);
char		*ft_strmap(const char *str, char (*f)(char));
char		*ft_strmapi(const char *str, char (*f)(size_t, char));
char		*ft_strncat(char *str1, const char *str2, size_t n);
char		*ft_strncpy(char *dst, const char *src, size_t n);
char		*ft_strndup(const char *str, size_t n);
char		*ft_strnew(size_t size);
char		*ft_strnstr(const char *str, const char *needle, size_t len);
char		*ft_strrchr(const char *str, int c);
char		*ft_strreplace(char *str, char *find, char *replace);
char		*ft_strstr(const char *str, const char *needle);
char		*ft_strsub(const char *str, size_t start, size_t len);
char		*ft_strtolower(char *str);
char		*ft_strtoupper(char *str);
char		*ft_strtrim(const char *str);
float		ft_normalize(intmax_t value, intmax_t *range, intmax_t *outrange);
int			ft_getchar(void);
int			ft_memcmp(const void *str1, const void *str2, size_t len);
int			ft_strcmp_nocase(const char *str1, const char *str2);
int			ft_strcmp(const char *str1, const char *str2);
int			ft_strncmp_nocase(const char *str1, const char *str2, size_t n);
int			ft_strncmp(const char *str1, const char *str2, size_t n);
int			ft_tolower(int c);
int			ft_toupper(int c);
intmax_t	*ft_lsttonumarr(t_list *lst);
intmax_t	ft_abs(intmax_t num);
intmax_t	ft_atoi_base(const char *str, int base);
intmax_t	ft_atoi(const char *str);
intmax_t	ft_constrain(intmax_t value, intmax_t min, intmax_t max);
intmax_t	ft_max(intmax_t num1, intmax_t num2);
intmax_t	ft_min(intmax_t num1, intmax_t num2);
intmax_t	ft_nearestnum(intmax_t value, intmax_t num1, intmax_t num2);
intmax_t	ft_overflow(intmax_t num, intmax_t min, intmax_t max);
intmax_t	ft_percentage(intmax_t num, intmax_t centage);
intmax_t	ft_pow(intmax_t num, intmax_t pow);
intmax_t	ft_sqrt(intmax_t nb);
size_t		ft_count_if(const char **str, t_bool (*f)(char *));
size_t		ft_lstlen(t_list *lst);
size_t		ft_lstnlen(t_list *lst, size_t n);
size_t		ft_numlen_base(intmax_t value, int base);
size_t		ft_numlen(intmax_t value);
size_t		ft_strarrlen(const char **arr);
size_t		ft_strarrnlen(const char **arr, size_t n);
size_t		ft_strdlen(const char *str, const char *dlm);
size_t		ft_strislen(const char *str, t_bool (*f)(int));
size_t		ft_strlcat(char *dst, const char *src, size_t size);
size_t		ft_strlen(const char *str);
size_t		ft_strmatchlen_nocase(const char *str1, const char *str2);
size_t		ft_strmatchlen(const char *str1, const char *str2);
size_t		ft_strnlen(const char *str, size_t n);
size_t		ft_unumlen_base(uintmax_t value, int base);
size_t		ft_unumlen(uintmax_t value);
size_t		ft_utf8len(t_wchar c);
size_t		ft_utf8strlen(const t_wchar *str);
size_t		ft_utf8strnlen(const t_wchar *str, size_t n);
size_t		ft_wrddcount(const char *str, const char *dlm);
ssize_t		ft_chrdindex(const char *str, const char *dlm);
ssize_t		ft_chrindex(const char *str, int c);
ssize_t		ft_colorcode(const char *str);
ssize_t		ft_colorlcode(const char *str);
ssize_t		ft_colorncode(const char *str, size_t n);
ssize_t		ft_getnextdline(const int fd, char **line, char dlm);
ssize_t		ft_getnextline(const int fd, char **line);
ssize_t		ft_memindex(const void *str, int c, size_t len);
ssize_t		ft_readfile(int fd, char **str);
ssize_t		ft_strindex(const char **arr, const char *str);
ssize_t		ft_strnindex(const char **arr, const char *str, size_t n);
t_bool		ft_chrdin(const char *str, const char *dlm);
t_bool		ft_chrin(const char *str, int c);
t_bool		ft_chrinbytes(long long *bytes, char c);
t_bool		ft_chrnin(const char *str, int c, size_t n);
t_bool		ft_inrange(intmax_t value, intmax_t min, intmax_t max);
t_bool		ft_isalnum(int c);
t_bool		ft_isalpha(int c);
t_bool		ft_isascii(int c);
t_bool		ft_isblank(int c);
t_bool		ft_isdigit(int c);
t_bool		ft_isdigitstr(const char *str);
t_bool		ft_islower(int c);
t_bool		ft_isprint(int c);
t_bool		ft_isspace(int c);
t_bool		ft_isupper(int c);
t_bool		ft_lstsortstrac(t_list *sortlst, t_list *lst);
t_bool		ft_memequ(const void *str1, const void *str2, size_t len);
t_bool		ft_numarrsortac(intmax_t current, intmax_t num);
t_bool		ft_numin(const intmax_t *arr, intmax_t num, size_t len);
t_bool		ft_putbool_fd(t_bool boolean, int fd);
t_bool		ft_putbool(t_bool boolean);
t_bool		ft_putbytes(void *bytes, size_t n);
t_bool		ft_putchar_fd(char c, int fd);
t_bool		ft_putchar(char c);
t_bool		ft_putdouble_fd(long double value, size_t n, int fd);
t_bool		ft_putdouble(long double value, size_t n);
t_bool		ft_putendl_fd(const char *str, int fd);
t_bool		ft_putendl(const char *str);
t_bool		ft_puterror(const char *str);
t_bool		ft_putline_fd(const char *str, int fd);
t_bool		ft_putline(const char *str);
t_bool		ft_putlstsize(t_list *lst);
t_bool		ft_putnchar_fd(char c, size_t n, int fd);
t_bool		ft_putnchar(char c, size_t n);
t_bool		ft_putnstr_fd(const char *str, size_t n, int fd);
t_bool		ft_putnstr(const char *str, size_t n);
t_bool		ft_putnum_base_fd(intmax_t value, int base, int fd);
t_bool		ft_putnum_base(intmax_t value, int base);
t_bool		ft_putnum_cbase_fd(intmax_t value, int base, t_bool up, int fd);
t_bool		ft_putnum_cbase(intmax_t value, int base, t_bool up);
t_bool		ft_putnum_fd(intmax_t value, int fd);
t_bool		ft_putnum(intmax_t value);
t_bool		ft_putnumarr(const intmax_t *arr, size_t len);
t_bool		ft_putnumlst(t_list *lst);
t_bool		ft_putnutf8str (const t_wchar *str, size_t n);
t_bool		ft_putnutf8str_fd(const t_wchar *str, size_t n, int fd);
t_bool		ft_putpointer(const void *pointer);
t_bool		ft_putstr_fd(const char *str, int fd);
t_bool		ft_putstr(const char *str);
t_bool		ft_putstrarr(const char **arr);
t_bool		ft_putstrlst(t_list *lst);
t_bool		ft_putunum_base_fd(uintmax_t value, int base, int fd);
t_bool		ft_putunum_base(uintmax_t value, int base);
t_bool		ft_putunum_cbase_fd(uintmax_t value, int base, t_bool up, int fd);
t_bool		ft_putunum_cbase(uintmax_t value, int base, t_bool up);
t_bool		ft_putunum_fd(uintmax_t value, int fd);
t_bool		ft_putunum(uintmax_t value);
t_bool		ft_pututf8_fd(t_wchar c, int fd);
t_bool		ft_pututf8(t_wchar c);
t_bool		ft_pututf8str_fd(const t_wchar *str, int fd);
t_bool		ft_pututf8strconst (t_wchar *str);
t_bool		ft_strarrsortac(char *current, char *str);
t_bool		ft_strequ_nocase(const char *str1, const char *str2);
t_bool		ft_strequ(const char *str1, const char *str2);
t_bool		ft_strin(const char **arr, const char *str);
t_bool		ft_strmatch(const char *str, const char *needle);
t_bool		ft_strnequ_nocase(const char *str1, const char *str2, size_t n);
t_bool		ft_strnequ(const char *str1, const char *str2, size_t n);
t_bool		ft_strnin(const char **arr, const char *str, size_t n);
t_color		*ft_colorhextorgba(t_color color);
t_color		ft_colorrgbatohex(t_color r, t_color g, t_color b, t_color a);
t_list		*ft_lstdup(t_list *lst);
t_list		*ft_lstdupone(t_list *lst);
t_list		*ft_lstfind_content(t_list *lst, void *content, size_t size);
t_list		*ft_lstfind_size(t_list *lst, size_t size);
t_list		*ft_lstfindadd_content(t_list *lst, void *content, size_t size);
t_list		*ft_lstfindadd_size(t_list *lst, size_t size);
t_list		*ft_lstindex(t_list *lst, size_t index);
t_list		*ft_lstlast(t_list *lst);
t_list		*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem));
t_list		*ft_lstnew(const void *content, size_t content_size);
t_list		*ft_lstunlink(t_list *head, t_list *lst);
t_list		*ft_numarrtolst(const intmax_t *arr, size_t len);
t_list		*ft_strarrtolst(const char **arr);
void		*ft_memalloc(size_t size);
void		*ft_memccpy(void *dst, const void *src, int c, size_t len);
void		*ft_memchr(const void *str, int c, size_t len);
void		*ft_memcpy(void *dst, const void *src, size_t len);
void		*ft_memdup(const void *src, size_t len);
void		*ft_memmove(void *dst, const void *src, size_t len);
void		*ft_memrchr(const void *str, int c, size_t len);
void		*ft_memrcpy(void *dst, const void *src, size_t len);
void		*ft_memreplace(void **str1, const void *str2);
void		*ft_memset(void *str, int c, size_t len);
void		ft_bzero(void *str, size_t len);
void		ft_chrsetbytes(long long *bytes, char *str);
void		ft_lstadd(t_list **head, t_list *new);
void		ft_lstaddbck(t_list **head, t_list *new);
void		ft_lstdel(t_list **head, void (*del)(void *, size_t));
void		ft_lstdelmem(void *content, size_t size);
void		ft_lstdelone(t_list **head, void (*del)(void *, size_t));
void		ft_lstinsert(t_list *head, t_list *lst);
void		ft_lstiter(t_list *lst, void (*f)(t_list *elem));
void		ft_lstrev(t_list **head);
void		ft_lstsort(t_list **head, t_bool (*f)(t_list *, t_list *));
void		ft_lstsortrev(t_list **head, t_bool (*f)(t_list *, t_list *));
void		ft_memdel(void **ap);
void		ft_print_memory(const void *addr, size_t size);
void		ft_strappend(char **dst, const char *src);
void		ft_strarrdel(char ***arr);
void		ft_strarrrev(char **arr);
void		ft_strarrsort(char **arr, t_bool (*f)(char *, char *));
void		ft_strarrsortrev(char **arr, t_bool (*f)(char *, char *));
void		ft_strarrtolower(char **arr);
void		ft_strarrtoupper(char **arr);
void		ft_strclr(char *str);
void		ft_strdel(char **as);
void		ft_striter(const char *str, void (*f)(char *));
void		ft_striteri(const char *str, void (*f)(size_t, char *));
void		ft_strrev(char *str);
void		ft_swap(void **a, void **b);
void		ft_termclr_fd(int fd);
void		ft_termclr(void);
void		ft_termcommand_fd(int command, int fd);
void		ft_termcommand(int command);
void		ft_termresetcolor_fd(int fd);
void		ft_termresetcolor(void);
void		ft_termresetcolorbg_fd(int fd);
void		ft_termresetcolorbg(void);
void		ft_termsetcolor_fd(t_color color, int fd);
void		ft_termsetcolor(t_color color);
void		ft_termsetcolorbg_fd(t_color color, int fd);
void		ft_termsetcolorbg(t_color color);
void		ft_termsetrgbcolor_fd(t_color r, t_color g, t_color b, int fd);
void		ft_termsetrgbcolor(t_color r, t_color g, t_color b);
void		ft_termsetrgbcolorbg_fd(t_color r, t_color g, t_color b, int fd);
void		ft_termsetrgbcolorbg(t_color r, t_color g, t_color b);
void		ft_strarrnsort(char **arr,
				t_bool (*f)(char *, char *), size_t n);
void		ft_strarrnsortrev(char **arr,
				t_bool (*f)(char *, char *), size_t n);
void		ft_numarrsort(intmax_t *arr,
				t_bool (*f)(intmax_t, intmax_t), size_t len);
void		ft_numarrsortrev(intmax_t *arr,
				t_bool (*f)(intmax_t, intmax_t), size_t len);
t_bool		ft_strfldvalid(const char **arr, size_t x, size_t y,
				const char *dlm);

#endif
