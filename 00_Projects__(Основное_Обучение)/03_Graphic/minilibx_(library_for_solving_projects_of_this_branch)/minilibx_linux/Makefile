#* ************************************************************************** *#
#*                                                                            *#
#*                                                        :::      ::::::::   *#
#*   Makefile                                           :+:      :+:    :+:   *#
#*                                                    +:+ +:+         +:+     *#
#*   By: wescande <wescande@student.42.fr>          +#+  +:+       +#+        *#
#*                                                +#+#+#+#+#+   +#+           *#
#*   Created: 2016/08/29 21:32:58 by wescande          #+#    #+#             *#
#*   Updated: 2017/02/15 21:08:25 by wescande         ###   ########.fr       *#
#*                                                                            *#
#* ************************************************************************** *#
INC=/usr/include
HT=Linux
DOCP=do_cp

NAME		=	libmlx.a

CC			=	gcc
FLAGS		=	-O3 -w

DELTA		=	$$(echo "$$(tput cols)-47"|bc)

SRC_DIR		=	srcs/
INC_DIR		=	includes/
OBJ_DIR		=	objs/

SRC_BASE	= \
mlx_new_window.c\
mlx_destroy_window.c\
mlx_flush_event.c\
mlx_put_image_to_window.c\
mlx_int_anti_resize_win.c\
mlx_int_get_visual.c\
mlx_int_do_nothing.c\
mlx_hook.c\
mlx_loop.c\
mlx_get_data_addr.c\
mlx_clear_window.c\
mlx_int_wait_first_expose.c\
mlx_expose_hook.c\
mlx_xpm.c\
mlx_string_put.c\
mlx_pixel_put.c\
mlx_destroy_image.c\
mlx_rgb.c\
mlx_get_color_value.c\
mlx_loop_hook.c\
mlx_init.c\
mlx_int_set_win_event_mask.c\
mlx_mouse_hook.c\
mlx_int_param_event.c\
mlx_new_image.c\
mlx_int_str_to_wordtab.c\
mlx_key_hook.c

SRCS		=	$(addprefix $(SRC_DIR), $(SRC_BASE))
OBJS		=	$(addprefix $(OBJ_DIR), $(SRC_BASE:.c=.o))
NB			=	$(words $(SRC_BASE))
INDEX		=	0

all	: do_configure

do_configure	:
	@./configure

clean	:
	@./configure clean

fclean	:
	@./configure fclean

re	: clean all

lib :
	@$(MAKE) -j $(NAME)

$(NAME) :		$(OBJ_DIR) $(OBJS)
	@ar rc $(NAME) $(OBJS)
	@ranlib $(NAME)
	@printf '\033[33m[ 100%% ] %s\n\033[0m' "Compilation of $(NAME) is done ---"

$(OBJ_DIR) :
	@mkdir -p $(OBJ_DIR)
	@mkdir -p $(dir $(OBJS))

$(OBJ_DIR)%.o :	$(SRC_DIR)%.c | $(OBJ_DIR)
	@$(eval DONE=$(shell echo $$(($(INDEX)*20/$(NB)))))
	@$(eval PERCENT=$(shell echo $$(($(INDEX)*100/$(NB)))))
	@$(eval TO_DO=$(shell echo "$@"))
	@$(CC) -MMD -c $< -o $@\
		-I$(INC_DIR) \
		-I$(INC) \
		$(FLAGS)
	@printf "[ %d%% ] %s :: %s                               \r" $(PERCENT) $(NAME) $@
	@$(eval INDEX=$(shell echo $$(($(INDEX)+1))))

libclean :
	@rm -rf $(OBJ_DIR)
	@printf '\033[33m[ KILL ] %s\n\033[0m' "Clean of $(NAME) is done ---"

libfclean :		clean
	@rm -rf $(NAME)
	@printf '\033[33m[ KILL ] %s\n\033[0m' "Fclean of $(NAME) is done ---"

.PHONY :		fclean clean re lib libclean libfclean

-include $(OBJS:.o=.d)
