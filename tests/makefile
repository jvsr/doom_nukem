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
LIBS = $(LIB) $(SDL2LIB) $(CRITERIONLIB)

# Header dependency
HEADERS := $(HEADERS:%=$(INCLUDES)/%)
HEADERS := $(sort $(HEADERS))

# Dependency prefix
SRCS := $(SRCS:%=src/test_ft_%.c)
SRCS := $(sort $(SRCS))
TESTOBJS = $(SRCS:.c=.o)
LIBOBJS = $(filter-out ../src/main/main.o, $(OBJS))

# Trash files
TEMPS = $(SRCS:.c=.c~)

all: $(NAME)

# Create $(NAME)
$(NAME): $(TESTOBJS) $(LIB)
	@$(call FNC_PRINT_EQUAL,$(PARENTNAME)-$(NAME),$(NAME))
	@$(CC) -coverage $(CCFLAGS) -o $(NAME) $(TESTOBJS) $(LIBOBJS) $(LIBS)
	#-Wl,-alias,_wrap_malloc,_malloc -Wl,-alias,_wrap_free,_free

# Compile .o
%.o: %.c $(HEADERS)
ifeq ($(CCSILENT), FALSE)
	@$(call FNC_PRINT_PLUS,$(PARENTNAME)-$(NAME),$(shell basename $<))
endif
	@$(CC) $(CCFLAGS) -o $@ -c $<

# Create $(LIB)
$(LIB):
	@make -s -C $(LIBPATH)

# Clean all non $(NAME) files
clean:
ifneq ($(wildcard $(TESTOBJS) $(TEMPS)),)
	@$(call FNC_PRINT_MIN,$(PARENTNAME)-$(NAME),clean)
	@rm -f $(TESTOBJS) $(TEMPS)
endif

# Clean $(NAME) files
fclean: clean
ifneq ($(wildcard $(NAME)),)
	@$(call FNC_PRINT_DEL,$(PARENTNAME)-$(NAME),fclean $(NAME))
	@rm -f $(NAME)
endif

# Recompile
re: fclean $(NAME)

FORCE: ;

.PHONY: all clean fclean re
