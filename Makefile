# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tjooris <tjooris@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/01/20 14:10:16 by tjooris           #+#    #+#              #
#    Updated: 2025/01/21 01:08:19 by tjooris          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = prog.a


#=-=-=-=-=-=-FILES-=-=-=-=-=-=#

MAKE_DIR	:=	.file/
BUILD_DIR	:=	$(MAKE_DIR)build_$(or $(shell git branch --show-current),default)/
BASE_DIR	:=	normal/

SRC_DIR		=	src/

OBJ			=	$(patsubst	%.c, $(BUILD_DIR)%.o, $(SRC))

DEP			=	$(patsubst	%.c, $(BUILD_DIR)%.d, $(SRC)


#=-=-=-=-=-=-ROOT-=-=-=-=-=#

SRC	=

#=-=-=-=-=-=-FONCTIONS-=-=-=-=-=#

SRC	+= $(addprefix $(IS_DIR), $(IS_SRC))

IS_DIR	=	fonction/
IS_SRC	=	ft_fonction1.c \
			ft_fonction1.c \


#=-=-=-=-=-=-INCLUDES-=-=-=-=-=#

LIB_DIR		=	lib/
LIB_PATH	=	libft/lib1.a \
				libft/lib2.a \

LIB_PATH	:=	$(addprefix $(LIB_DIR),$(LIB_PATH))
LIB			=	$(patsubst lib%.a, %, $(notdir $(LIB_PATH)))

INC_DIR		=	include/
INCLUDES	=	$(INC_DIR) \
				$(dir $(LIB_PATH))$(INC_DIR)
			
#=-=-=-=-=-=-COMPIL-=-=-=-=-=#

CC			=	cc

FLAGS		+=	-Wall -Wextra -Werror
PPFLAGS		+=	$(addprefix -I, $(INCLUDES)) -MMD -MP

LDFLAGS		+=	$(addprefix -L, $(dir $(LIB_PATH)))
LDLIB		+=	$(addprefix -l, $(LIB))

AR			=	ar
ARFLAF		=	-rcs

MAKEFLAG	+=	--no-print-directory

#=-=-=-=-=-=-MODES-=-=-=-=-=#

MODES		:=	debug fsanitize optimize full-optimize

MODES_TRACE	:=	$(BUILD_DIR).modes_trace
LAST_MOD	:= $(shell cat $(MODES_TRACE) 2>/dev/null)

MODE	?=

ifneq ($(MODE), )
	BUILD_DIR := $(BUILD_DIR)$(MODE)/
else
	BUILD_DIR := $(BUILD_DIR)$(BASE_BUILD_DIR)
endif

ifeq ($(MODE), debug)
	CFLAGS = -g3
else ifeq ($(MODE), fsanitize)
	CFLAGS = -g3 -fsanitize=address
else ifeq ($(MODE), optimize)
	CFLAGS += -O2
else ifeq ($(MODE), full-optimize)
	CFLAGS += -O3
else ifneq ($(MODE),)
	ERROR = MODE
endif

ifneq ($(LAST_MOD), $(MODE))
$(NAME): force
endif

#=-=-=-=-=-=-CAST-=-=-=-=-=#

.PHONY: all clean fclean $(MODE) re help

all: $(NAME)

$(NAME): $(LIBS_PATH) $(OBJS)
	@echo $(MODE) > $(MODES_TRACE)
	$(CC) $(CFLAGS) $(OBJS) $(LDFLAGS) $(LDLIBS) -o $(NAME)

$(BUILD_DIR)%.o: $(SRC_DIR)%.c
	@mkdir -p $(@D)
	$(CC) $(CPPFLAGS) $(CFLAGS) -c $< -o $@

clean fclean:
	-@for lib in $(LIBS_DIRS); do $(MAKE) -s -C $$lib $@; done
	rm -rf $(BUILD_DIR)
	@if [ "$@" = "fclean" ]; then rm -f $(NAME) $(MODE_TRACE); fi

re: fclean all

help:
	@echo "Usage: make [target]"
	@echo "Targets:"
	@echo "  all       Build the project"
	@echo "  clean     Remove object files and dependencies"
	@echo "  fclean    Remove all build files, binary, and mode trace"
	@echo "  re        Clean and rebuild"

	.PHONY: print-%
print-%:
	@echo $(patsubst print-%,%,$@)=
	@echo $($(patsubst print-%,%,$@))

.PHONY: force
force:

-include $(DEPS)

.DEFAULT_GOAL := all