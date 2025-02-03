# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tjooris <tjooris@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/01/20 14:10:16 by tjooris           #+#    #+#              #
#    Updated: 2025/02/03 13:41:30 by tjooris          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap

#=-=-=-=-=-=-FILES-=-=-=-=-=-=#

MAKE_DIR    :=  .make/
BUILD_DIR   :=  $(MAKE_DIR)build_$(or $(shell git branch --show-current),default)/
BASE_DIR    :=  normal/

SRC_DIR     =   src/

OBJS        =   $(patsubst %.c, $(BUILD_DIR)%.o, $(SRC))
DEPS        =   $(patsubst %.c, $(BUILD_DIR)%.d, $(SRC))

#=-=-=-=-=-=-ROOT-=-=-=-=-=#

SRC =   main.c

#=-=-=-=-=-=-3-=-=-=-=-=#

SRC +=  $(addprefix $(3_DIR), $(3_SRC))

3_DIR    =   3/
3_SRC    =   three_number.c

#=-=-=-=-=-=-5-=-=-=-=-=#

SRC +=  $(addprefix $(5_DIR), $(5_SRC))

5_DIR    =   5/
5_SRC    =   five_number.c

#=-=-=-=-=-=-ARG_HANDLER-=-=-=-=-=#

SRC +=  $(addprefix $(ARG_HANDLER_DIR), $(ARG_HANDLER_SRC))

ARG_HANDLER_DIR =   arg_handler/
ARG_HANDLER_SRC =   ft_arghandler.c

#=-=-=-=-=-=-OTHER_NUMBER-=-=-=-=-=#

SRC +=  $(addprefix $(OTHER_NUMBER_DIR), $(OTHER_NUMBER_SRC))

OTHER_NUMBER_DIR    =   other_number/
OTHER_NUMBER_SRC    =   sort.c \
                        find_best_push.c \
                        is_max_value.c \
                        move.c \
                        prepare_stack.c \
                        sequence.c

#=-=-=-=-=-=-FREE-=-=-=-=-=#

SRC +=  $(addprefix $(FREE_DIR), $(FREE_SRC))

FREE_DIR    =   free/
FREE_SRC    =   free.c

#=-=-=-=-=-=-STACK-=-=-=-=-=#

SRC +=  $(addprefix $(STACK_DIR), $(STACK_SRC))

STACK_DIR   =   stack/
STACK_SRC   =   utils.c \
                free_stack.c

#=-=-=-=-=-=-MOVE-=-=-=-=-=#

SRC +=  $(addprefix $(MOVE_DIR), $(MOVE_SRC))

MOVE_DIR    =   stack_move/
MOVE_SRC    =   push.c \
                rotate.c \
                reverse_rotate.c \
                swap.c

#=-=-=-=-=-=-INDEXING-=-=-=-=-=#

SRC +=  $(addprefix $(INDEXING_DIR), $(INDEXING_SRC))

INDEXING_DIR    =   indexing/
INDEXING_SRC    =   index_utils.c

#=-=-=-=-=-=-INCLUDES-=-=-=-=-=#

LIB_DIR     =   lib/
LIB_PATH    =   libft/libft.a

LIB_PATH    :=  $(addprefix $(LIB_DIR),$(LIB_PATH))
LIB         =   $(patsubst lib%.a, %, $(notdir $(LIB_PATH)))

INC_DIR     =   include/
INCLUDES    =   $(INC_DIR) \
                $(dir $(LIB_PATH))$(INC_DIR)

#=-=-=-=-=-=-COMPIL-=-=-=-=-=#

CC          =   cc

FLAGS       +=  -Wall -Wextra -Werror
PPFLAGS     +=  $(addprefix -I, $(INCLUDES)) -MMD -MP

LDFLAGS     +=  $(addprefix -L, $(dir $(LIB_PATH)))
LDLIB       +=  $(addprefix -l, $(LIB))

AR          =   ar
ARFLAGS     =   -rcs

MAKEFLAG    +=  --no-print-directory

#=-=-=-=-=-=-MODES-=-=-=-=-=#

MODES       :=  debug fsanitize optimize full-optimize

MODES_TRACE :=  $(BUILD_DIR).modes_trace
LAST_MOD    :=  $(shell cat $(MODES_TRACE) 2>/dev/null)

MODE    ?=

ifneq ($(MODE), )
    BUILD_DIR := $(BUILD_DIR)$(MODE)/
else
    BUILD_DIR := $(BUILD_DIR)$(BASE_BUILD_DIR)
endif

ifeq ($(MODE), debug)
    FLAGS = -g3
else ifeq ($(MODE), fsanitize)
    FLAGS = -g3 -fsanitize=address
else ifeq ($(MODE), optimize)
    FLAGS += -O2
else ifeq ($(MODE), full-optimize)
    FLAGS += -O3
else ifneq ($(MODE),)
    ERROR = MODE
endif

ifneq ($(LAST_MOD), $(MODE))
$(NAME): force
endif

#=-=-=-=-=-=-CAST-=-=-=-=-=#

.PHONY: all clean fclean $(MODE) re help

all: $(NAME)

$(NAME): $(OBJS) $(LIB_PATH)
	@echo $(MODE) > $(MODES_TRACE)
	$(CC) $(FLAGS) $(OBJS) $(LDFLAGS) $(LDLIB) -o $(NAME)

$(BUILD_DIR)%.o: $(SRC_DIR)%.c $(LIB_PATH)
	@mkdir -p $(@D)
	$(CC) $(PPFLAGS) $(FLAGS) -c $< -o $@


$(LIB_PATH): force
	@$(MAKE) -C $(@D)


.PHONY: clean
clean:
	-for lib in $(dir $(LIB_PATH)); do $(MAKE) -s -C $$lib $@; done
	rm -rf $(MAKE_DIR)

.PHONY: fclean
fclean:
	-for lib in $(dir $(LIB_PATH)); do $(MAKE) -s -C $$lib $@; done
	rm -rf $(MAKE_DIR) $(NAME)

.PHONY: re
re: fclean
	$(MAKE)

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
