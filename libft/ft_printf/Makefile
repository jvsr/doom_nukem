# **************************************************************************** #
#                                                                              #
#                                                         ::::::::             #
#    Makefile                                           :+:    :+:             #
#                                                      +:+                     #
#    By: pholster <pholster@student.codam.nl>         +#+                      #
#                                                    +#+                       #
#    Created: 2019/01/07 20:00:45 by pholster       #+#    #+#                 #
#    Updated: 2019/08/19 13:51:53 by pholster      ########   odam.nl          #
#                                                                              #
# **************************************************************************** #

GCOVSILENT = TRUE
CCSILENT = FALSE
GCOV = FALSE

GCOVFLAGS = -f -b -c

SILENCE = &>/dev/null
GET_GCOV = (gcov $(GCOVFLAGS) $(1) && mv $(shell basename $(1:%=%.gcov)) src)
ifeq ($(GCOVSILENT), TRUE)
GET_GCOV += $(SILENCE)
endif

NAME = libftprintf.a
INCLUDES = ../includes
HEADERS = ft_printf.h typedefs.h
HEADERS := $(HEADERS:%=$(INCLUDES)/%)

include $(INCLUDES)/Makefile.color

PREFIX = pf
FT_SRCS = strformat strformat_len dprintf printf
SRCS = getinfo infosetdefault formatpad formatbackpad addchar iszeropad addstr \
	isunsignint issignint setvar_type setvar_base infonew format formatnum \
	formatunum overflowsigned overflowunsigned addnstr addtobuff addnum \
	formatchar formatcolor addwchar formatstr addwcharstr getprecision \
	getwidth getflag getlength gettype ispositiveint isstr formatdouble \
	distribute setrgbcolorbg setrgbcolor commands setcolorbg setcolor addunum
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

all: $(NAME)

ifeq ($(GCOV), TRUE)
$(NAME): $(OBJS) $(GCNOS)
else
$(NAME): $(OBJS)
endif
	@printf '$(PRINT_EQUAL) $(NAME:%.a=%): $(NAME)\n'
	@ar rcs $(NAME) $(OBJS)

%.o %.gcno: %.c $(HEADERS)
ifeq ($(CCSILENT), FALSE)
	@printf '$(PRINT_PLUS) $(NAME:%.a=%): $(shell basename $@)\n'
endif
	@rm -f $(<:.c=.o)
	@gcc $(CCFLAGS) -o $(<:.c=.o) -c $<

getgcov: $(NAME) FORCE
	@$(call GET_GCOV,$(SRCS))

clean:
ifneq ($(wildcard $(OBJS) $(SRCS:.c=.c~) $(GCOVS) $(GCDAS) $(GCNOS)),)
	@printf '$(PRINT_MIN) $(NAME:%.a=%): cleaning\n'
	@rm -f $(OBJS) $(SRCS:.c=.c~) $(GCOVS) $(GCDAS) $(GCNOS)
endif

fclean: clean
ifneq ($(wildcard $(NAME)),)
	@printf '$(PRINT_MIN) $(NAME:%.a=%): deleting $(NAME)\n'
	@rm -f $(NAME)
endif

re: fclean $(NAME)

FORCE: ;

.PHONY: test clean fclean re
