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
SUBLIBS := $(SUBLIBS:%=src/$(SUBLIBSPATH)/%.content)
SUBLIBMAKE = $(MAKE) -s -e -C src FOLDER=$(SUBLIBSPATH)

# Fclean target files
FCLEAN := $(wildcard $(NAME) $(SUBLIBS))

# Function - Get all objects of sublibs
GETOBJS = $(shell cat $(1) | grep '\.o' | sed 's,^,src/,g')
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
export LIBFT_DISABLE_GCOV

all: $(NAME)

# Create $(NAME)
$(NAME): $(SUBLIBS)
	@$(call FNC_PRINT_EQUAL,$(BASENAME),$(NAME))
	@rm -f $(NAME)
	@ar rcs $(NAME) $(OBJS)

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

# Compile $(SUBLIBS)
src/$(SUBLIBSPATH)/%.content: FORCE
	@$(SUBLIBMAKE) SUBLIB=$(@:src/$(SUBLIBSPATH)/%=%)

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
	@$(call FNC_PRINT_DEL,$(BASENAME),fclean $(FCLEAN:src/$(SUBLIBSPATH)/%=%))
	@rm -f $(NAME) $(SUBLIBS)
endif

# Recompile
re: fclean
	@$(MAKE)

FORCE: ;

.PHONY: all test clean fclean re FORCE
