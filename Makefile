# **************************************************************************** #
#                                                                              #
#                                                         ::::::::             #
#    Makefile                                           :+:    :+:             #
#                                                      +:+                     #
#    By: vbusekru <vbusekru@student.codam.nl>         +#+                      #
#                                                    +#+                       #
#    Created: 2024/01/23 14:23:35 by vbusekru      #+#    #+#                  #
#    Updated: 2024/03/15 18:30:06 by vbusekru      ########   odam.nl          #
#                                                                              #
# **************************************************************************** #

NAME = push_swap

LIBFT = Libft/libft.a
LIBFTDIR = Libft

CC = cc

CFLAGS = -Wall -Wextra -Werror -g #-fsanitize=address

RM = rm -f

SOURCE =	1_push_swap.c \
			2_input_check.c \
			2.1_convert_input.c \
			3_pre_sort.c \
			4_sort_small_stack.c \
			5_radix_sort.c \
			stack_utils1.c \
			stack_utils2.c \
			stack_utils3.c \
			operations_rotate.c \
			operations_push_swap.c \

OBJECTS = $(SOURCE:%.c=$(OBJS_DIR)/%.o)

OBJS_DIR = objects

all: $(NAME)

$(LIBFT):
	$(MAKE) -C $(LIBFTDIR)
	
$(NAME): $(LIBFT) $(OBJS_DIR) $(OBJECTS)
	$(CC) $(CFLAGS) $(OBJECTS) $(LIBFT) -o $(NAME)

$(OBJS_DIR):
	mkdir -p $(OBJS_DIR)

$(OBJS_DIR)/%.o:%.c 
	$(CC) $(CFLAGS) -c -o $@ $^

clean: 
	$(MAKE) clean -C $(LIBFTDIR)
	$(RM) -rf $(OBJS_DIR)

fclean: clean
	$(MAKE) fclean -C $(LIBFTDIR)
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re