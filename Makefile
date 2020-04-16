# **************************************************************************** #
#                                                                              #
#                                                         ::::::::             #
#    Makefile                                           :+:    :+:             #
#                                                      +:+                     #
#    By: pholster <pholster@student.codam.nl>         +#+                      #
#                                                    +#+                       #
#    Created: 2019/01/07 20:00:45 by pholster      #+#    #+#                  #
#    Updated: 2020/03/06 17:50:43 by jvisser       ########   odam.nl          #
#                                                                              #
# **************************************************************************** #

# Sublib folder names
SUBLIBS = main color sdl_extra tga_reader gui game gui_config sdl_thread \
			audio keymap serializer eventstate map_parse table renderer init \
			cmath loop textures \
			player \
			enemy \
			map_editor \


# Executable name
NAME = doom-nukem
PARENTNAME = $(NAME)

# Compile settings
CCSILENT = FALSE
CCSTRICT = -Wall -Werror -Wextra
CCOPTIMISE = -O3

# Gcov settings
GCOV = FALSE
GCOVSILENT = TRUE
GCOVFLAGS = -f -b -c
LIBFT_DISABLE_GCOV = TRUE

# Mafile includes
MAKEINCLUDES = includes/libft
include $(MAKEINCLUDES)/Makefile.color

# Libft info
LIBPATH = libft
LIB = $(LIBPATH)/libft.a

# FrameWorkPaths
ifeq ($(shell uname -s), Linux)
FRAMEWORKPATH := /usr
else
FRAMEWORKPATH := $(shell brew --cellar)/..
endif

# Path to framework includes folder
FRAMEWORKINCLUDES = $(FRAMEWORKPATH)/include

# SDL2 dependency
SDL2LIB = -L$(FRAMEWORKPATH)/lib -lSDL2

# SDL2_TTF dependency
SDL2TTF = -L$(FRAMEWORKPATH)/lib -lSDL2_ttf

# SDL2_Mix dependency
SDL2MIX = -L$(FRAMEWORKPATH)/lib -lSDL2_mixer

# All libs for compilation
LIBS = $(LIB) $(SDL2LIB) $(SDL2TTF) $(SDL2MIX)

ifeq ($(shell uname -s), Linux)
LIBS += -lm
endif

# Sublib info
SUBLIBSPATH = .sublibs
SUBLIBS := $(sort $(SUBLIBS))
SUBLIBS := $(SUBLIBS:%=src/$(SUBLIBSPATH)/%.content)
SUBLIBMAKE = $(MAKE) -s -e -C src FOLDER=$(SUBLIBSPATH)

# Fclean target files
FCLEAN := $(wildcard $(NAME) $(SUBLIBS))

# Function - Get all objects of sublibs
GETOBJS = $(shell cat $(1) | grep '\.o' | sed 's/^/src\//g')
OBJS = $(foreach DIR,$(SUBLIBS),$(call GETOBJS,$(DIR)))

# Function - Clean all sublib .content
CLEANSUBLIB = $(SUBLIBMAKE) SUBLIB=$(1:src/$(SUBLIBSPATH)/%=%) clean &&
SUBLIBS_CLEAN := $(foreach DIR,$(SUBLIBS),$(call CLEANSUBLIB,$(DIR))) :

# Function - Clean all sublib .content
GCOVSUBLIB = $(SUBLIBMAKE) SUBLIB=$(1:src/$(SUBLIBSPATH)/%=%) gcovreport &&
SUBLIBS_GCOV := $(foreach DIR,$(SUBLIBS),$(call GCOVSUBLIB,$(DIR))) :

# Export vars to sublib makefile
export GCOV
export GCOVSILENT
export GCOVFLAGS
export CCSILENT
export CCSTRICT
export CCOPTIMISE
export PARENTNAME
export FRAMEWORKPATH
export FRAMEWORKINCLUDES
export SDL2LIB
export SDL2TTF
export SDL2MIX
export LIBFT_DISABLE_GCOV

all: $(NAME)

# Create $(NAME)
$(NAME): $(LIB) $(SUBLIBS)
	@$(call FNC_PRINT_EQUAL,$(NAME),$(NAME))
	@rm -f $(NAME)
	@gcc -g -coverage $(CCOPTIMISE) -o $(NAME) $(OBJS) $(LIBS)
	@bash pack_textures.bash

# Compile $(LIB)
$(LIB): FORCE
	@$(MAKE) -s -e -C $(LIBPATH)

# Compile $(SUBLIBS)
src/$(SUBLIBSPATH)/%.content: src/$(SUBLIBSPATH) FORCE
	@$(SUBLIBMAKE) SUBLIB=$(@:src/$(SUBLIBSPATH)/%=%)

# Create $(SUBLIBSPATH) if it doesnt exsist
src/$(SUBLIBSPATH):
	@mkdir src/$(SUBLIBSPATH)

# Clean all non .content files
clean:
ifneq ($(wildcard $(TESTPATH)),)
	@$(MAKE) -s -e -C $(TESTPATH) NAME=$(TESTNAME) clean
endif
	@$(SUBLIBS_CLEAN)
	@$(MAKE) -s -e -C $(LIBPATH) clean

# Clean all .content files
fclean: clean
ifneq ($(wildcard $(TESTPATH)),)
	@$(MAKE) -s -e -C $(TESTPATH) NAME=$(TESTNAME) fclean
endif
ifneq ($(FCLEAN),)
	@$(call FNC_PRINT_DEL,$(NAME),fclean $(FCLEAN:src/$(SUBLIBSPATH)/%=%))
	@rm -f $(NAME) $(SUBLIBS)
endif
	@$(MAKE) -s -e -C $(LIBPATH) fclean

# Recompile only the project
re: fclean
	@$(MAKE)

FORCE: ;

.PHONY: all clean fclean re FORCE
