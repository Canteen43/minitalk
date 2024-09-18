CC = cc
CFLAGS = -Wall -Wextra -Werror
NAME = flib.a
HEADER = flib.h

SRC_FILES = \
	f_lmt_check.c \
	f_strtoi.c \

OBJ_FILES = $(SRC_FILES:%.c=%.o)

all: $(NAME)

$(NAME): $(OBJ_FILES)
	ar rcs $(NAME) $(OBJ_FILES)

%.o: %.c $(HEADER)
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJ_FILES)

fclean: clean
	rm -f $(NAME)

re: fclean
	$(MAKE) all

.PHONY: clean fclean all re bonus
