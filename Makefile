NAME = philo
CC = cc
CFLAGS = -Wall -Wextra -Werror -g
OBJ_DIR := ./obj
DEP_DIR := $(OBJ_DIR)/.deps
INC_DIRS := ./includes
SRC_DIRS := $(shell find ./srcs -type d)
vpath %.c $(SRC_DIRS)
vpath %.h $(INC_DIRS)
vpath %.d $(DEP_DIR)

SRCS :=	main.c \

# UTILS
SRCS += create_forks.c \
		get_time_in_ms.c \
		safe_atol.c \
		smart_sleep.c \
		timestamp.c \

# SRCS
SRCS += actions.c \
		cleanup.c \
		forks.c \
		init.c \
		monitor_routine.c \
		parsing.c \
		philo_routine.c \
		simulation.c \
		validate_input.c \

OBJS := $(addprefix $(OBJ_DIR)/, $(SRCS:%.c=%.o))
DEPS := $(addprefix $(DEP_DIR)/, $(SRCS:%.c=%.d))

all: $(NAME)

-include $(DEPS)

$(OBJ_DIR)/%.o: %.c
	@mkdir -p $(@D)
	@mkdir -p $(DEP_DIR)
	@$(CC) $(CFLAGS) -MMD -MP -MF $(DEP_DIR)/$*.d -I$(INC_DIRS) -c $< -o $@

$(NAME): $(OBJS)
	@$(CC) $(CFLAGS) -o $(NAME) $(OBJS)

clean:
	@rm -rf $(OBJ_DIR)

fclean: clean
	@rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re