# **************************************************************************** #
#                                                                              #
#                                                         ::::::::             #
#    Makefile                                           :+:    :+:             #
#                                                      +:+                     #
#    By: pholster <pholster@student.codam.nl>         +#+                      #
#                                                    +#+                       #
#    Created: 2019/01/07 20:00:45 by pholster       #+#    #+#                 #
#    Updated: 2019/08/22 13:37:54 by pholster      ########   odam.nl          #
#                                                                              #
# **************************************************************************** #

#Sublib folder names of libft
SUBLIBS = printf threadpool unsignednumber number numberarray float character \
	string stringarray utf8 memory list hash color terminal bool

#Libft name
NAME = libft.a
BASENAME = $(NAME:%.a=%)

#Compile settings
CCSILENT = FALSE
CCSTRICT = -Wall -Werror -Wextra
CCOPTIMISE =

#Gcov settings
GCOV = FALSE
GCOVSILENT = TRUE
GCOVFLAGS = -f -b -c

#Mafile includes
MAKEINCLUDES = includes/
include $(MAKEINCLUDES)/Makefile.color

#Tests info
TESTPATH = tests
TEST = $(TESTPATH)/libtest

#Sublib info
SUBLIBSPATH = .sublibs
SUBLIBS := $(sort $(SUBLIBS))
SUBLIBS := $(SUBLIBS:%=src/$(SUBLIBSPATH)/%.a)
SUBLIBMAKE = $(MAKE) -s -e -C src LIBNAME=$(BASENAME) FOLDER=$(SUBLIBSPATH)

#Fclean target files
FCLEAN := $(wildcard $(NAME) $(SUBLIBS))

#Function - Get all objects of sublibs
SEDESCAPE = $(1:src/$(SUBLIBSPATH)/%.a=src\/%\/)
GETOBJS = $(shell ar -t $(1) | grep '\.o' | sed 's/^/$(call SEDESCAPE,$(1))/g')
OBJS = $(foreach DIR,$(SUBLIBS),$(call GETOBJS,$(DIR)))

#Function - Clean all sublib .a
CLEANSUBLIB = $(SUBLIBMAKE) SUBLIB=$(1:src/$(SUBLIBSPATH)/%=%) clean &&
SUBLIBS_CLEAN = $(foreach DIR,$(SUBLIBS),$(call CLEANSUBLIB,$(DIR))) :

#Function - Clean all sublib .a
GCOVSUBLIB = $(SUBLIBMAKE) SUBLIB=$(1:src/$(SUBLIBSPATH)/%=%) gcovreport &&
SUBLIBS_GCOV = $(foreach DIR,$(SUBLIBS),$(call GCOVSUBLIB,$(DIR))) :

#Export vars to sublib makefile
export GCOV
export GCOVSILENT
export GCOVFLAGS
export CCSILENT
export CCSTRICT
export CCOPTIMISE

all: $(NAME)

#Create $(NAME)
$(NAME): $(SUBLIBS)
	@$(call FNC_PRINT_EQUAL,$(BASENAME),$(NAME))
	@rm -f $(NAME)
	@ar rcs $(NAME) $(OBJS)

#Run test and gcov if $(GCOV)==TRUE
test: $(NAME) FORCE
ifeq ($(wildcard $(TESTPATH)),)
	@echo "Error: $(TESTPATH) not present"
else
	@$(MAKE) -s -e -C $(TESTPATH)
	@./$(TEST)
ifeq ($(GCOV), TRUE)
	@$(SUBLIBS_GCOV)
endif
endif

#Compile $(SUBLIBS)
src/$(SUBLIBSPATH)/%.a: src/$(SUBLIBSPATH) FORCE
	@$(SUBLIBMAKE) SUBLIB=$(@:src/$(SUBLIBSPATH)/%=%)

src/$(SUBLIBSPATH):
	@mkdir src/$(SUBLIBSPATH)

#Clean all non .a files
clean:
ifneq ($(wildcard $(TESTPATH)),)
	@$(MAKE) -s -C $(TESTPATH) clean
endif
	@$(SUBLIBS_CLEAN)

#Clean all .a files
fclean: clean
ifneq ($(wildcard $(TESTPATH)),)
	@$(MAKE) -s -C $(TESTPATH) fclean
endif
ifneq ($(FCLEAN),)
	@$(call FNC_PRINT_DEL,$(BASENAME),fclean $(FCLEAN:src/$(SUBLIBSPATH)/%=%))
	@rm -f $(NAME) $(SUBLIBS)
endif

#Recompile
re: fclean $(NAME)

FORCE: ;

.PHONY: all test clean fclean re
