# **************************************************************************** #
#                                                                              #
#                                                         ::::::::             #
#    Makefile                                           :+:    :+:             #
#                                                      +:+                     #
#    By: pholster <pholster@student.codam.nl>         +#+                      #
#                                                    +#+                       #
#    Created: 2019/01/07 20:00:45 by pholster      #+#    #+#                  #
#    Updated: 2019/08/29 14:04:57 by ehollidg      ########   odam.nl          #
#                                                                              #
# **************************************************************************** #

# Input values for sublib (From parent makefile)
SUBLIB =
FOLDER =
PARENTNAME =
FRAMEWORKPATH =
FRAMEWORKINCLUDES =
SDL2LIB =
SDL2TTF =
SDL2MIX =

# Input values for compile (From parent makefile)
CCSILENT =
CCSTRICT =
CCOPTIMISE =

# Input values for gcov (From parent makefile)
GCOV =
GCOVSILENT =
GCOVFLAGS =

# Own names
SRCFOLDER = $(SUBLIB:%.content=%)
NAME = $(FOLDER)/$(SUBLIB)

# Misc setup
SILENCE = 2>/dev/null 1>/dev/null

# Includes
INCLUDES = ../includes
MAKEINCLUDES = $(INCLUDES)/libft
include $(MAKEINCLUDES)/Makefile.color

# Compile flags
CCFLAGS = -g $(CCSTRICT) -I$(INCLUDES) -I$(FRAMEWORKINCLUDES) $(CCOPTIMISE)

ifeq ($(GCOV), TRUE)
CCFLAGS += -coverage
endif

# Get correct srcs variable
include Makefile.$(SRCFOLDER)Srcs

# Dependency prefix
SRCS := $(SRCS:%=$(SRCFOLDER)/$(PREFIX)%.c)
SRCS := $(sort $(SRCS))

# Compile dependencies
OBJS = $(SRCS:.c=.o)
GCNOS = $(OBJS:.o=.gcno)
DEPS = $(OBJS:.o=.d)

COMPILE_FILES = $(OBJS) $(DEPS)
ifeq ($(GCOV), TRUE)
COMPILE_FILES += $(GCNOS)
endif

# Trash files
GCDAS = $(OBJS:.o=.gcda)
TEMPS = $(SRCS:.c=.c~)
GCOVS = $(OBJS:.o=.c.gcov)
CLEAN_FILES = $(OBJS) $(DEPS) $(TEMPS) $(GCOVS) $(GCDAS) $(GCNOS)

# Function - Gcov report
BASE_GCOVS = $(GCOVS:$(SRCFOLDER)/%=%)
MOVE_GCOVS = mv -f $(BASE_GCOVS) $(SRCFOLDER) || true
GCOVREPORT = (gcov $(GCOVFLAGS) $(SRCS) && $(MOVE_GCOVS))
ifeq ($(GCOVSILENT), TRUE)
GCOVREPORT += $(SILENCE)
endif

all: $(NAME)

# Create $(NAME)
$(NAME): $(COMPILE_FILES)
	@$(call FNC_PRINT_EQUAL,$(PARENTNAME)-$(SRCFOLDER),$(SUBLIB))
	@echo $(OBJS:%=\\n%) > $(NAME)

# Run gcov
gcovreport: $(NAME)
	@$(GCOVREPORT)

# Include all existing header dependencies files
include $(wildcard $(DEPS))

# Compile .o, .d or .gcno if $(GCOV)==TRUE
%.o %.d %.gcno: %.c
ifeq ($(CCSILENT), FALSE)
	@$(call FNC_PRINT_PLUS,$(PARENTNAME)-$(SRCFOLDER),$(@:$(SRCFOLDER)/%=%))
endif
	@rm -f $(<:.c=.o)
	@$(CC) -MMD $(CCFLAGS) -o $(<:.c=.o) -c $<

# Clean all non .content files
clean:
ifneq ($(wildcard $(CLEAN_FILES)),)
	@$(call FNC_PRINT_MIN,$(PARENTNAME)-$(SRCFOLDER),clean)
	@rm -f $(CLEAN_FILES)
endif

# Norm fclean
fclean: clean

# Recompile
re: fclean
	@$(MAKE)

FORCE: ;

.PHONY: gcovreport all clean fclean re FORCE
