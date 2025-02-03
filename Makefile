# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tjooris <tjooris@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/01/20 14:10:16 by tjooris           #+#    #+#              #
#    Updated: 2025/02/03 08:51:49 by tjooris          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap

# ================FILES================ #

MAKE_DIR		:=	.make/
BUILD_DIR		:=	$(MAKE_DIR)build_$(shell git branch --show-current)/
BASE_BUILD_DIR	:= normal/

SRC_DIR			=	src/

OBJS			=	$(patsubst %.c, $(BUILD_DIR)%.o, $(SRC))

DEPS			=	$(patsubst %.c, $(BUILD_DIR)%.d, $(SRC))

#=-=-=-=-=-=-ROOT-=-=-=-=-=#

SRC =   main.c \

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

# ==========LIBS / INCLUDES============ #

LIBS_DIR	=	lib/
LIBS_PATH	=	libft/libft.a
LIBS_PATH	:=	$(addprefix $(LIBS_DIR), $(LIBS_PATH))
LIBS		=	$(patsubst lib%.a, %, $(notdir $(LIBS_PATH)))

INCS_DIR	=	includes/
INCLUDES	=	$(INCS_DIR) \
				$(dir $(LIBS_PATH))$(INCS_DIR)

# ===============CONFIGS=============== #

CC			=	cc
CFLAGS		+=	-Wall -Wextra -Werror
CPPFLAGS	+=	$(addprefix -I, $(INCLUDES)) \
			-MMD -MP

LDFLAGS		+=	$(addprefix -L, $(dir $(LIBS_PATH)))
LDLIBS		+=	$(addprefix -l, $(LIBS))

AR			=	ar
ARFLAGS		=	-rcs

MAKEFLAGS	+=	--no-print-directory

# ================MODES================ #

MODES		:= debug fsanitize optimize full-optimize

MODE_TRACE	:= $(BUILD_DIR).mode_trace
LAST_MODE	:= $(shell cat $(MODE_TRACE) 2>/dev/null)

MODE ?=

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

ifneq ($(LAST_MODE), $(MODE))
$(NAME): force
endif

# ================TARGETS============== #

.PHONY: all
all: $(NAME)

show:
	@echo $(SRC_TEST)

$(NAME): $(LIBS_PATH) $(OBJS)
	@echo $(MODE) > $(MODE_TRACE)
	$(CC) $(CFLAGS) $(OBJS) $(LDFLAGS) $(LDLIBS) -o $(NAME)

$(BUILD_DIR)%.o: $(SRC_DIR)%.c
	@mkdir -p $(@D)
	$(CC) $(CPPFLAGS) $(CFLAGS) -c $< -o $@

$(LIBS_PATH): force
	@$(MAKE) -C $(@D)

.PHONY: $(MODES)
$(MODES):
	@$(MAKE) MODE=$@

.PHONY: clean
clean:
	-for lib in $(dir $(LIBS_PATH)); do $(MAKE) -s -C $$lib $@; done
	rm -rf $(MAKE_DIR)

.PHONY: fclean
fclean:
	-for lib in $(dir $(LIBS_PATH)); do $(MAKE) -s -C $$lib $@; done
	rm -rf $(MAKE_DIR) $(NAME)

.PHONY: re
re: fclean
	@$(MAKE)

# ================MISC================= #

.PHONY: print-%
print-%:
	@echo $(patsubst print-%,%,$@)=
	@echo $($(patsubst print-%,%,$@))

.PHONY: force
force:

-include $(DEPS)

.DEFAULT_GOAL := all

