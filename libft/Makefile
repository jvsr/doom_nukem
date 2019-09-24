# **************************************************************************** #
#                                                                              #
#                                                         ::::::::             #
#    Makefile                                           :+:    :+:             #
#                                                      +:+                     #
#    By: pholster <pholster@student.codam.nl>         +#+                      #
#                                                    +#+                       #
#    Created: 2019/01/07 20:00:45 by pholster       #+#    #+#                 #
#    Updated: 2019/08/24 14:25:13 by pholster      ########   odam.nl          #
#                                                                              #
# **************************************************************************** #

# Sublib folder names of libft
SUBLIBS = printf threadpool unum num numarr float char str strarr utf8 mem \
	list hash color term bool

# Libft name
NAME = libft.a
BASENAME = $(NAME:%.a=%)
PARENTNAME = $(BASENAME)

# Compile settings
CCSILENT = FALSE
CCSTRICT = -Wall -Werror -Wextra
CCSTRICT += -Wpedantic -Wmissing-prototypes -Wmissing-noreturn
CCOPTIMISE =

# Gcov settings
GCOV = FALSE
GCOVSILENT = TRUE
GCOVFLAGS = -f -b -c
LIBFT_DISABLE_GCOV = FALSE

# Libft info
LIBPATH =
LIB =

# Mafile includes
MAKEINCLUDES = includes/
include $(MAKEINCLUDES)/Makefile.color

# Tests info
TESTPATH = tests
TESTNAME = libtest
TEST = $(TESTPATH)/$(TESTNAME)

# Sublib info
SUBLIBSPATH = .sublibs
SUBLIBS := $(sort $(SUBLIBS))
SUBLIBS := $(SUBLIBS:%=src/$(SUBLIBSPATH)/%.a)
SUBLIBMAKE = $(MAKE) -s -e -C src FOLDER=$(SUBLIBSPATH)

# Fclean target files
FCLEAN := $(wildcard $(NAME) $(SUBLIBS))

# Function - Get all objects of sublibs
SEDESCAPE = $(1:src/$(SUBLIBSPATH)/%.a=src\/%\/)
GETOBJS = $(shell ar -t $(1) | grep '\.o' | sed 's/^/$(call SEDESCAPE,$(1))/g')
OBJS = $(foreach DIR,$(SUBLIBS),$(call GETOBJS,$(DIR)))

# Function - Clean all sublib .a
CLEANSUBLIB = $(SUBLIBMAKE) SUBLIB=$(1:src/$(SUBLIBSPATH)/%=%) clean &&
SUBLIBS_CLEAN = $(foreach DIR,$(SUBLIBS),$(call CLEANSUBLIB,$(DIR))) :

# Function - Clean all sublib .a
GCOVSUBLIB = $(SUBLIBMAKE) SUBLIB=$(1:src/$(SUBLIBSPATH)/%=%) gcovreport &&
SUBLIBS_GCOV = $(foreach DIR,$(SUBLIBS),$(call GCOVSUBLIB,$(DIR))) :

# Export vars to sublib makefile
export GCOV
export GCOVSILENT
export GCOVFLAGS
export CCSILENT
export CCSTRICT
export CCOPTIMISE
export PARENTNAME
export LIBFT_DISABLE_GCOV

all: $(NAME)

# Create $(NAME)
$(NAME): $(SUBLIBS) $(LIB)
	@$(call FNC_PRINT_EQUAL,$(BASENAME),$(NAME))
	@rm -f $(NAME)
	@ar rcs $(NAME) $(OBJS) $(LIB)

# Run test and gcov if $(GCOV)==TRUE
test: $(NAME) FORCE
ifeq ($(wildcard $(TESTPATH)),)
	@echo "Error: $(TESTPATH) not present"
else
	@$(MAKE) -s -e -C $(TESTPATH) NAME=$(TESTNAME) OBJS="$(OBJS:src/%=../src/%)"
	@./$(TEST)
ifeq ($(GCOV)_$(LIBFT_DISABLE_GCOV), TRUE_FALSE)
	@$(SUBLIBS_GCOV)
endif
endif

# Compile $(LIB)
$(LIB): FORCE
	@$(MAKE) -s -e -C $(LIBPATH)

# Compile $(SUBLIBS)
src/$(SUBLIBSPATH)/%.a: src/$(SUBLIBSPATH) FORCE
	@$(SUBLIBMAKE) SUBLIB=$(@:src/$(SUBLIBSPATH)/%=%)

# Create $(SUBLIBSPATH) if it doesnt exsist
src/$(SUBLIBSPATH):
	@mkdir src/$(SUBLIBSPATH)

# Clean all non .a files
clean:
ifneq ($(wildcard $(TESTPATH)),)
	@$(MAKE) -s -e -C $(TESTPATH) NAME=$(TESTNAME) clean
endif
	@$(SUBLIBS_CLEAN)
	#@$(MAKE) -s -e -C $(LIBPATH) clean

# Clean all .a files
fclean: clean
ifneq ($(wildcard $(TESTPATH)),)
	@$(MAKE) -s -e -C $(TESTPATH) NAME=$(TESTNAME) fclean
endif
ifneq ($(FCLEAN),)
	@$(call FNC_PRINT_DEL,$(BASENAME),fclean $(FCLEAN:src/$(SUBLIBSPATH)/%=%))
	@rm -f $(NAME) $(SUBLIBS)
endif
	#@$(MAKE) -s -e -C $(LIBPATH) fclean

# \1ecompile
re: fclean $(NAME)

FORCE: ;

.PHONY: all test clean fclean re
