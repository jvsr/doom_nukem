# **************************************************************************** #
#                                                                              #
#                                                         ::::::::             #
#    makefile                                           :+:    :+:             #
#                                                      +:+                     #
#    By: pholster <pholster@student.codam.nl>         +#+                      #
#                                                    +#+                       #
#    Created: 2019/01/07 20:00:45 by pholster       #+#    #+#                 #
#    Updated: 2019/08/27 15:55:28 by jvisser       ########   odam.nl          #
#                                                                              #
# **************************************************************************** #

# Input values for test
NAME =
OBJS =
PARENTNAME =
FRAMEWORKPATH =
FRAMEWORKINCLUDES =
SDL2LIB =
SDL2TTF =
SDL2MIX =

# Compile settings
CCSILENT = FALSE

# Includes
INCLUDES = ../includes
MAKEINCLUDES = $(INCLUDES)/libft
include $(MAKEINCLUDES)/Makefile.color

# Compile flags
CCFLAGS = -g -I$(INCLUDES) -I$(FRAMEWORKINCLUDES)

ifeq ($(shell uname -s), Linux)
CCFLAGS += -w
endif

# Get source files
include Makefile.testSrcs

# Lib dependency
LIBPATH = ../libft
LIBNAME = libft
LIB = $(LIBPATH)/$(LIBNAME).a

# Criterion dependency
CRITERIONLIB = -L$(FRAMEWORKPATH)/lib -lcriterion

# All libs for compilation
LIBS = $(LIB) $(SDL2LIB) $(SDL2TTF) $(SDL2MIX) $(CRITERIONLIB)

ifeq ($(shell uname -s), Linux)
LIBS += -lm
endif

# Dependency prefix
SRCS := $(SRCS:%=src/test_ft_%.c)
SRCS := $(sort $(SRCS))

TESTOBJS = $(SRCS:.c=.o)
LIBOBJS = $(filter-out ../src/main/main.o, $(OBJS))
TESTDEPS = $(OBJS:.o=.d)

TESTCOMPILE_FILES = $(TESTOBJS) $(TESTDEPS)


# Trash files
TEMPS = $(SRCS:.c=.c~)
TESTCLEAN_FILES = $(TESTOBJS) $(DEPS) $(TEMPS)

all: $(NAME)

# Create $(NAME)
$(NAME): $(TESTCOMPILE_FILES) $(LIB)
	@$(call FNC_PRINT_EQUAL,$(PARENTNAME)-$(NAME),$(NAME))
	@$(CC) -coverage $(CCFLAGS) -o $(NAME) $(TESTOBJS) $(LIBOBJS) $(LIBS)
	#-Wl,-alias,_wrap_malloc,_malloc -Wl,-alias,_wrap_free,_free

# Include all existing header dependencies files
include $(wildcard $(DEPS))

# Compile .o or .d
%.o %.d: %.c
ifeq ($(CCSILENT), FALSE)
	@$(call FNC_PRINT_PLUS,$(PARENTNAME)-$(NAME),$(@:src/%=%))
endif
	@$(CC) -MMD $(CCFLAGS) -o $@ -c $<

# Create $(LIB)
$(LIB):
	@make -s -C $(LIBPATH)

# Clean all non $(NAME) files
clean:
ifneq ($(wildcard $(TESTCLEAN_FILES)),)
	@$(call FNC_PRINT_MIN,$(PARENTNAME)-$(NAME),clean)
	@rm -f $(TESTCLEAN_FILES)
endif

# Clean $(NAME) files
fclean: clean
ifneq ($(wildcard $(NAME)),)
	@$(call FNC_PRINT_DEL,$(PARENTNAME)-$(NAME),fclean $(NAME))
	@rm -f $(NAME)
endif

# Recompile
re: fclean
	@$(MAKE)

FORCE: ;

.PHONY: all clean fclean re FORCE
