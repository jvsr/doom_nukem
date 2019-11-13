# **************************************************************************** #
#                                                                              #
#                                                         ::::::::             #
#    Makefile                                           :+:    :+:             #
#                                                      +:+                     #
#    By: pholster <pholster@student.codam.nl>         +#+                      #
#                                                    +#+                       #
#    Created: 2019/01/07 20:00:45 by pholster       #+#    #+#                 #
#    Updated: 2019/11/13 11:29:43 by jvisser       ########   odam.nl          #
#                                                                              #
# **************************************************************************** #

# Sublib folder names
SUBLIBS = main color sdl_extra tga_reader gui gametime gui_config sdl_thread \
			audio keymap serializer renderer eventstate init

# Executable name
NAME = doom-nukem
PARENTNAME = $(NAME)

# Compile settings
CCSILENT = FALSE
CCSTRICT = -Wall -Werror -Wextra
CCOPTIMISE = -O1

# Gcov settings
GCOV = FALSE
GCOVSILENT = TRUE
GCOVFLAGS = -f -b -c
LIBFT_DISABLE_GCOV = TRUE

# Mafile includes
MAKEINCLUDES = includes/libft
include $(MAKEINCLUDES)/Makefile.color

# Tests info
TESTPATH = tests
TESTNAME = doomtest
TEST = $(TESTPATH)/$(TESTNAME)

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

# Resource Folders
DATAPATH = resources/data
DATAPATH := $(DATAPATH)/map $(DATAPATH)/map/custom $(DATAPATH)/map/campaign \
	$(DATAPATH)/settings/

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
$(NAME): $(DATAPATH) $(LIB) $(SUBLIBS)
	@$(call FNC_PRINT_EQUAL,$(NAME),$(NAME))
	@rm -f $(NAME)
	@gcc -coverage -o $(NAME) $(OBJS) $(LIBS)

# Run test and gcov if $(GCOV)==TRUE
test: $(LIB) $(SUBLIBS) FORCE
ifeq ($(wildcard $(TESTPATH)),)
	@echo "Error: $(TESTPATH) not present"
else
	@$(MAKE) -s -e -C $(TESTPATH) NAME=$(TESTNAME) OBJS="$(OBJS:src/%=../src/%)"
	@./$(TEST)
ifeq ($(GCOV), TRUE)
	@$(SUBLIBS_GCOV)
endif
endif

# Create required $(DATAPATH)
$(DATAPATH):
	@mkdir -p $(DATAPATH)

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

# Clean all .content files
fclean: clean
ifneq ($(wildcard $(TESTPATH)),)
	@$(MAKE) -s -e -C $(TESTPATH) NAME=$(TESTNAME) fclean
endif
ifneq ($(FCLEAN),)
	@$(call FNC_PRINT_DEL,$(NAME),fclean $(FCLEAN:src/$(SUBLIBSPATH)/%=%))
	@rm -f $(NAME) $(SUBLIBS)
endif

# Clean $(LIB)
clean_lib:
	@$(MAKE) -s -e -C $(LIBPATH) clean

# Fclean $(LIB)
fclean_lib: clean_lib
	@$(MAKE) -s -e -C $(LIBPATH) fclean

# Recompile only the project
re: fclean
	@$(MAKE)

# Recompile the $(LIB) and project
re_all: fclean_lib fclean
	@$(MAKE)

FORCE: ;

.PHONY: all test clean fclean re FORCE
