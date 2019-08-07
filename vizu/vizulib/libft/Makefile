NAME = libft.a

NAMESRC = libsource

HEAD = ./

PATH_SRC = ./

SRC = $(PATH_SRC)ft_strlen.c \
	$(PATH_SRC)ft_strdup.c \
	$(PATH_SRC)ft_strcpy.c \
	$(PATH_SRC)ft_strncpy.c \
	$(PATH_SRC)ft_strcat.c \
	$(PATH_SRC)ft_strncat.c \
	$(PATH_SRC)ft_strlcat.c \
	$(PATH_SRC)ft_strchr.c \
	$(PATH_SRC)ft_strrchr.c \
	$(PATH_SRC)ft_isalpha.c \
	$(PATH_SRC)ft_isdigit.c \
	$(PATH_SRC)ft_isalnum.c \
	$(PATH_SRC)ft_isascii.c \
	$(PATH_SRC)ft_isprint.c \
	$(PATH_SRC)ft_toupper.c \
	$(PATH_SRC)ft_tolower.c \
	$(PATH_SRC)ft_strstr.c \
	$(PATH_SRC)ft_memset.c \
	$(PATH_SRC)ft_bzero.c \
	$(PATH_SRC)ft_memcpy.c \
	$(PATH_SRC)ft_memccpy.c \
	$(PATH_SRC)ft_memmove.c \
	$(PATH_SRC)ft_memchr.c \
	$(PATH_SRC)ft_memcmp.c \
	$(PATH_SRC)ft_strcmp.c \
	$(PATH_SRC)ft_strncmp.c \
	$(PATH_SRC)ft_strnstr.c \
	$(PATH_SRC)ft_atoi.c \
	$(PATH_SRC)ft_memalloc.c \
	$(PATH_SRC)ft_memdel.c \
	$(PATH_SRC)ft_strnew.c \
	$(PATH_SRC)ft_strdel.c \
	$(PATH_SRC)ft_striter.c \
	$(PATH_SRC)ft_striteri.c \
	$(PATH_SRC)ft_strmap.c \
	$(PATH_SRC)ft_strmapi.c \
	$(PATH_SRC)ft_strequ.c \
	$(PATH_SRC)ft_strnequ.c \
	$(PATH_SRC)ft_strsub.c \
	$(PATH_SRC)ft_strjoin.c \
	$(PATH_SRC)ft_strtrim.c \
	$(PATH_SRC)ft_strsplit.c \
	$(PATH_SRC)ft_itoa.c \
	$(PATH_SRC)ft_putchar.c \
	$(PATH_SRC)ft_putstr.c \
	$(PATH_SRC)ft_putendl.c \
	$(PATH_SRC)ft_putnbr.c \
	$(PATH_SRC)ft_putchar_fd.c \
	$(PATH_SRC)ft_putstr_fd.c \
	$(PATH_SRC)ft_putendl_fd.c \
	$(PATH_SRC)ft_putnbr_fd.c \
	$(PATH_SRC)ft_lstnew.c \
	$(PATH_SRC)ft_count_char.c \
	$(PATH_SRC)ft_strclr.c \
	$(PATH_SRC)ft_strlenc.c \
	$(PATH_SRC)ft_lstadd.c \
	$(PATH_SRC)ft_lstdelone.c \
	$(PATH_SRC)ft_lstdel.c \
	$(PATH_SRC)ft_lstiter.c \
	$(PATH_SRC)ft_lstmap.c \
	$(PATH_SRC)ft_dellst.c \
	$(PATH_SRC)ft_arraydel.c \
	$(PATH_SRC)ft_len2.c \
	$(PATH_SRC)ft_len3.c \
	$(PATH_SRC)ft_err.c \
	$(PATH_SRC)get_next_line.c \
	$(PATH_SRC)check_number.c \
	$(PATH_SRC)cnt_char.c

CFLAGS = -Wall -Wextra -Werror


AR = ar rc


$(NAME):
	@gcc $(CFLAGS) -c $(SRC) -I $(HEAD)
	@$(AR) $@ *.o
	@ranlib $@

all : $(NAME)

clean :
	@rm -rf *.o

fclean: clean
	@rm -f $(NAME)

re : fclean all
