NAME= vizu-hex

HEAD = vizulib/

WWW = -Wall -Wextra -Werror

LFT = vizulib/libft/

VIZL = vizulib/

VIZU = vizu.c

VIZUO = vizu.o

SRC = $(LFT) $(VIZL)

LMLX = vizulib/.libmlx/

SRC_LMLX = -framework OpenGL -framework AppKit -L $(LMLX) -lmlx

all: $(NAME)

$(NAME):
	@echo "(ﾉ◕ヮ◕)ﾉ*:・ﾟ✧ $@ is compiling... Wait a sec."
	@make -C vizulib re
	@gcc $(WWW) -c $(VIZU) -I $(VIZL) -I $(LFT)
	@gcc -o $@ $(VIZUO) -L $(VIZL) -lvizu -L $(LFT) -lft $(SRC_LMLX)
	@echo "(•̀ᴗ•́)و $@ generated!".

clean:
	@rm -rf *.o
	@make -C vizulib fclean

fclean: clean
	@rm -rf $(NAME)

re: fclean all
