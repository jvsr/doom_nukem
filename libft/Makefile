# **************************************************************************** #
#                                                                              #
#                                                         ::::::::             #
#    Makefile                                           :+:    :+:             #
#                                                      +:+                     #
#    By: pholster <pholster@student.codam.nl>         +#+                      #
#                                                    +#+                       #
#    Created: 2019/01/07 20:00:45 by pholster       #+#    #+#                 #
#    Updated: 2019/08/18 20:22:02 by pholster      ########   odam.nl          #
#                                                                              #
# **************************************************************************** #

SYNCOPTIMISE = TRUE
GCOVSILENT = TRUE
CCSILENT = FALSE
GCOV = FALSE

GCOVFLAGS = -f -b -c

SILENCE = &>/dev/null
GET_OBJS = $(shell ar -t $(1) | grep '\.o' | sed 's/^/$(2:%=%\/src\/)/g')
GET_GCOV = (gcov $(GCOVFLAGS) $(1) && mv $(shell basename $(1:%=%.gcov)) src)
ifeq ($(GCOVSILENT), TRUE)
GET_GCOV += $(SILENCE)
endif

PRINTFPATH = ft_printf
PRINTF = $(PRINTFPATH)/libftprintf.a
PRINTF_OBJS = $(call GET_OBJS,$(PRINTF),$(PRINTFPATH))
PRINTF_SRCS = $(PRINTF_OBJS:%.o=%.c)

THREADPOOLPATH = threadpool
THREADPOOL = $(THREADPOOLPATH)/threadpool.a
THREADPOOL_OBJS = $(call GET_OBJS,$(THREADPOOL),$(THREADPOOLPATH))
THREADPOOL_SRCS = $(THREADPOOL_OBJS:%.o=%.c)

TESTPATH = tests
TEST = $(TESTPATH)/libtest

NAME = libft.a
INCLUDES = includes
HEADERS = libft.h typedefs.h
HEADERS := $(HEADERS:%=$(INCLUDES)/%)

include $(INCLUDES)/Makefile.color

PREFIX = lf
FT_SRCS = putchar putnum putstr sqrt strcmp strdup strlen swap isalpha isalnum \
	isascii isprint toupper tolower putendl putchar_fd putstr_fd putendl_fd \
	putnum_fd strnew strclr strdel striter striteri strmap strmapi isspace \
	itoa pow atoi strncmp strcpy strcat strequ strnequ strncat strlcat strchr \
	strrchr strstr strnstr strsub strjoin strtrim strsplit memset bzero memcpy \
	memdel memalloc memccpy memmove memcmp strncpy lstnew lstdelone lstdel \
	lstadd lstiter lstmap memchr isdigit count_if puterror strtoupper \
	strtolower putline chrin chrnin numin strin strnin putstrarr putnumarr \
	strndup strdlen wrddcount chrtostr lstaddbck lstdelmem lsttostrarr \
	strarrtolst lstlen strmatch strrev lstdup lstdupone putstrlst putbool \
	numarrtolst putnumlst lsttonumarr min max constrain abs memreplace \
	getnextline termclr strarrnew strarrdel itoa_base atoi_base \
	isdigitstr strfldnew chrindex putpointer strdsplit putnum_base strdtrim \
	putnum_base_fd putline_fd isupper islower chrdin numlen_base numlen \
	unumlen unumlen_base strappend memdup lstunlink getchar putnstr putnstr_fd \
	strnlen strjoin_var strarrlen getnextdline chrdindex putnum_cbase_fd \
	putnum_cbase lstfind_content lstfind_size memrcpy lstlast strjoin_arr \
	lstfindadd_content lstrev lstfindadd_size strfldvalid memequ lstnlen \
	strarrnlen strislen putlstsize strarrrev numarrsort numarrsortrev lstsort \
	lstsortrev strarrsort lstinsert lstindex termsetcolor termsetcolorbg \
	termresetcolor termresetcolorbg strnequ_nocase strequ_nocase colorcode \
	strncmp_nocase strmatchlen strcmp_nocase strarrcpy colorncode colorlcode \
	strmatchlen_nocase colorstr termcommand termsetrgbcolorbg termsetrgbcolor \
	pututf8 utf8len utf8strlen utf8strnlen putnutf8str pututf8str putunum_base \
	putunum_cbase putunum_fd putunum_base_fd putunum_cbase_fd putunum memindex \
	strarrnsortrev strarrnsort strarrsortrev numarrsortac strarrsortac inrange \
	lstsortstrac strarrcpy_var strarrdup itoa_cbase putbytes chrsetbytes \
	chrinbytes putdouble isblank putdouble_fd putnutf8str_fd pututf8_fd \
	pututf8str termcommand_fd termclr_fd termresetcolorbg_fd termresetcolor_fd \
	termsetrgbcolorbg_fd termsetrgbcolor_fd termsetcolorbg_fd termsetcolor_fd \
	putbool_fd readfile print_memory putnchar putnchar_fd pututf8str_fd \
	memrchr strarrdup_var strarrtolower strarrtoupper strindex strnindex \
	normalize nearestnum strreplace colorrgbatohex colorhextorgba percentage \
	overflow
SRCS =
SRCS := $(FT_SRCS:%=src/ft_%.c) $(SRCS:%=src/$(PREFIX)_%.c)

SRCS := $(sort $(SRCS))
OBJS = $(SRCS:.c=.o)
GCOVS = $(OBJS:.o=.c.gcov)
GCDAS = $(OBJS:.o=.gcda)
GCNOS = $(OBJS:.o=.gcno)

CCOPTIMISE =
CCSTRICT = -Wall -Werror -Wextra
CCFLAGS = -g $(CCSTRICT) -I$(INCLUDES) $(CCOPTIMISE)
ifeq ($(GCOV), TRUE)
CCFLAGS += -coverage
endif

export GCOV
export CCSILENT
export CCSTRICT

ifeq ($(SYNCOPTIMISE), TRUE)
export CCOPTIMISE
endif

all: $(NAME)

ifeq ($(GCOV), TRUE)
$(NAME): $(PRINTF) $(THREADPOOL) $(OBJS) $(GCNOS)
else
$(NAME): $(PRINTF) $(THREADPOOL) $(OBJS)
endif
	@printf '$(PRINT_EQUAL) $(NAME:%.a=%): $(NAME)\n'
	@ar rcs $(NAME) $(OBJS) $(PRINTF_OBJS) $(THREADPOOL_OBJS)

%.o %.gcno: %.c $(HEADERS)
ifeq ($(CCSILENT), FALSE)
	@printf '$(PRINT_PLUS) $(NAME:%.a=%): $(shell basename $@)\n'
endif
	@rm -f $(<:.c=.o)
	@gcc $(CCFLAGS) -o $(<:.c=.o) -c $<

$(PRINTF): FORCE
	@$(MAKE) -s -e -C $(PRINTFPATH)

$(THREADPOOL): FORCE
	@$(MAKE) -s -e -C $(THREADPOOLPATH)

test: $(NAME) FORCE
ifneq ($(wildcard $(TESTPATH)),)
	@$(MAKE) -s -e -C $(TESTPATH)
	@./$(TEST)
ifeq ($(GCOV), TRUE)
	@$(call GET_GCOV,$(SRCS))
	@$(MAKE) -s -e -C $(PRINTFPATH) getgcov
	@$(MAKE) -s -e -C $(THREADPOOLPATH) getgcov
endif
else
	@echo "Error: $(TESTPATH) not present"
endif

clean:
ifneq ($(wildcard $(OBJS) $(SRCS:.c=.c~) $(GCOVS) $(GCDAS) $(GCNOS)),)
	@printf '$(PRINT_MIN) $(NAME:%.a=%): cleaning\n'
	@rm -f $(OBJS) $(SRCS:.c=.c~) $(GCOVS) $(GCDAS) $(GCNOS)
endif
	@$(MAKE) -s -C $(PRINTFPATH) clean
	@$(MAKE) -s -C $(THREADPOOLPATH) clean
ifneq ($(wildcard $(TESTPATH)),)
	@$(MAKE) -s -C $(TESTPATH) fclean
endif

fclean: clean
ifneq ($(wildcard $(NAME)),)
	@printf '$(PRINT_MIN) $(NAME:%.a=%): deleting $(NAME)\n'
	@rm -f $(NAME)
endif
	@$(MAKE) -s -C $(PRINTFPATH) fclean
	@$(MAKE) -s -C $(THREADPOOLPATH) fclean
ifneq ($(wildcard $(TESTPATH)),)
	@$(MAKE) -s -C $(TESTPATH) fclean
endif

re: fclean $(NAME)

FORCE: ;

.PHONY: test clean fclean re
