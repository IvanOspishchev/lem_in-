# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ivan <ivan@student.42.fr>                  +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/08/07 22:02:52 by ivan              #+#    #+#              #
#    Updated: 2019/08/07 22:05:35 by ivan             ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libvizu.a

LFT = $(LFT)

SRC = ft_newmlx.c run_window.c bresenham.c circle.c mappaint.c \
	ft_rec.c ft_newlst.c split_free.c utils.c path.c adj_list.c \
	free_lem.c link_make.c key_press.c mouse_press.c mouse_move.c \
	mouse_release.c mappaint_tools.c dijkstra_shortest_path_.c groups.c \
	intersection_handling.c queue.c rec_tools.c recursive_pathfinder.c \
	run_ants.c give_color.c switch_links.c

OBJECT = ft_newmlx.o run_window.o bresenham.o circle.o mappaint.o \
	ft_rec.o ft_newlst.o split_free.o utils.o path.o adj_list.o \
	free_lem.o link_make.o key_press.o mouse_press.o mouse_move.o \
	mouse_release.o mappaint_tools.o dijkstra_shortest_path_.o groups.o \
	intersection_handling.o queue.o rec_tools.o recursive_pathfinder.o \
	run_ants.o give_color.o switch_links.o

INCLUDES = libft/

FLAGS = -Wall -Wextra -Werror

LMLX = ./.libmlx/

all: $(NAME)

$(NAME):
	@make -C $(INCLUDES) re
	@gcc $(FLAGS) -c $(SRC) -I $(INCLUDES) -I $(LMLX)
	@ar -r -c -s $(NAME) $(OBJECT)
	@mkdir obj && mv $(OBJECT) obj/

norm:
	norminette *.c
	norminette *.h

clean:
	@rm -rf obj
	@make -C libft fclean

fclean: clean
	@rm -f $(NAME)

re: fclean all
