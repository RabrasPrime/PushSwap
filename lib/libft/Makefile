# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tjooris <tjooris@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/01/20 14:10:16 by tjooris           #+#    #+#              #
#    Updated: 2025/02/03 08:54:09 by tjooris          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

# ================FILES================ #

MAKE_DIR		:=	.make/
BUILD_DIR		:=	$(MAKE_DIR)build_$(shell git branch --show-current)/
BASE_BUILD_DIR	:= normal/

SRC_DIR			=	src/

OBJS			=	$(patsubst %.c, $(BUILD_DIR)%.o, $(SRC))

DEPS			=	$(patsubst %.c, $(BUILD_DIR)%.d, $(SRC))

# ================ROOT================= #

SRC 		=

#=-=-=-=-=-=-IS-=-=-=-=-=#

SRC	+= $(addprefix $(IS_DIR), $(IS_SRC))

IS_DIR	=	is/
IS_SRC	=	ft_isalnum.c \
			ft_isalpha.c \
			ft_isascii.c \
			ft_isdigit.c \
			ft_isprint.c \

#=-=-=-=-=-=-LST-=-=-=-=-=#

SRC	+=	$(addprefix $(LST_DIR), $(LST_SRC))

LST_DIR	=	lst/
LST_SRC	=	ft_lstadd_back_bonus.c \
			ft_lstdelone_bonus.c \
			ft_lstadd_front_bonus.c \
			ft_lstclear_bonus.c \
			ft_lstiter_bonus.c \
			ft_lstlast_bonus.c \
			ft_lstmap_bonus.c \
			ft_lstnew_bonus.c \
			ft_lstsize_bonus.c \

#=-=-=-=-=-=-MEM-=-=-=-=-=#

SRC	+=	$(addprefix $(MEM_DIR), $(MEM_SRC))

MEM_DIR =	mem/
MEM_SRC =	ft_bzero.c \
			ft_memchr.c \
			ft_memcpy.c \
			ft_memset.c \
			ft_calloc.c \
			ft_memcmp.c \
			ft_memmove.c \

#=-=-=-=-=-=-PRINTF-=-=-=-=-=#

SRC	+=	$(addprefix $(PRINTF_DIR), $(PRINTF_SRC))

PRINTF_DIR	=	printf/
PRINTF_DIR	=	ft_char.c \
				ft_integer.c \
				ft_printf.c \
				ft_printstr.c \
				ft_unsigned.c \
				ft_hexa.c \
				ft_pointer.c \
				ft_printflen.c \
				ft_str.c \
				ft_utils.c \

#=-=-=-=-=-=-PUT-=-=-=-=-=#

SRC	+=	$(addprefix $(PUT_DIR), $(PUT_SRC))

PUT_DIR	=	put/
PUT_SRC	=	ft_putchar_fd.c \
			ft_putendl_fd.c \
			ft_putnbr_fd.c \
			ft_putstr_fd.c \

#=-=-=-=-=-=-STRINT-=-=-=-=-=#

SRC	+=	$(addprefix $(STRINT_DIR), $(STRINT_SRC))

STRINT_DIR	=	strint/
STRINT_SRC	=	ft_atoi.c \
				ft_strdup.c \
				ft_strlcpy.c \
				ft_strnstr.c \
				ft_itoa.c \
				ft_striteri.c \
				ft_strlen.c \
				ft_strrchr.c \
				ft_split.c \
				ft_strjoin.c \
				ft_strmapi.c \
				ft_strtrim.c \
				ft_strchr.c \
				ft_strlcat.c \
				ft_strncmp.c \
				ft_substr.c \
				ft_swap.c \
				ft_freestr.c \
				ft_tablen.c \

#=-=-=-=-=-=-TO-=-=-=-=-=#

SRC	+=	$(addprefix $(INTO_DIR), $(INTO_SRC))

INTO_DIR	=	into/
INTO_SRC	=	ft_tolower.c \
				ft_toupper.c \

#=-=-=-=-=-=-ERROR-=-=-=-=-=#

SRC	+=	$(addprefix $(ERROR_DIR), $(ERROR_SRC))

ERROR_DIR	=	error/
ERROR_SRC	=	ft_error.c \

# ==========LIBS / INCLUDES============ #

LIBS_DIR	=
LIBS_PATH	=
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

$(NAME): $(OBJS)
	@echo $(MODE) > $(MODE_TRACE)
	$(AR) $(ARFLAGS) $(NAME) $(OBJS)

$(BUILD_DIR)%.o: $(SRC_DIR)%.c
	@mkdir -p $(@D)
	$(CC) $(CPPFLAGS) $(CFLAGS) -c $< -o $@

$(LIBS_PATH): force
	$(MAKE) -C $(@D)

.PHONY: $(MODES)
$(MODES):
	$(MAKE) MODE=$@

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
	$(MAKE)

# ================MISC================= #

.PHONY: print-%
print-%:
	@echo $(patsubst print-%,%,$@)=
	@echo $($(patsubst print-%,%,$@))

.PHONY: force
force:

-include $(DEPS)

.DEFAULT_GOAL := all
