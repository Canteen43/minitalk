# The compiler
CC = cc

# Compiler flags
CFLAGS := -Wall -Wextra -Werror

# Debugging (DEBUG=1)
ifeq ($(DEBUG), 1)
	CFLAGS += -g3 -O0
endif

# Targets
SERVER = server
CLIENT = client
SERVER_BONUS = server_bonus
CLIENT_BONUS = client_bonus

# Directories
SRC_DIR = src_alt/
OBJ_DIR = obj/
SRC_BONUS_DIR = src_bonus/
OBJ_BONUS_DIR = obj_bonus/
LIB_DIR1 = lib/Libft/
LIB_DIR2 = lib/FLib/

# Libraries
LIB1 = $(LIB_DIR1)libft.a
LIB2 = $(LIB_DIR2)flib.a

# Source files for server and client
CLIENT_SRC_FILES += client.c
CLIENT_SRC_FILES += f_send_char.c

SERVER_SRC_FILES += server.c
SERVER_SRC_FILES += f_receive_char.c

# Source files for bonus server and client
CLIENT_BONUS_SRC_FILES += client.c
CLIENT_BONUS_SRC_FILES += f_send_char.c

SERVER_BONUS_SRC_FILES += server.c
SERVER_BONUS_SRC_FILES += f_receive_char.c

# Object files for server and client
CLIENT_OBJ_FILES = $(CLIENT_SRC_FILES:%.c=$(OBJ_DIR)%.o)
SERVER_OBJ_FILES = $(SERVER_SRC_FILES:%.c=$(OBJ_DIR)%.o)

# Object files for bonus server and client
CLIENT_BONUS_OBJ_FILES = $(CLIENT_BONUS_SRC_FILES:%.c=$(OBJ_BONUS_DIR)%.o)
SERVER_BONUS_OBJ_FILES = $(SERVER_BONUS_SRC_FILES:%.c=$(OBJ_BONUS_DIR)%.o)

# Rules
all: $(SERVER) $(CLIENT)

bonus: $(SERVER_BONUS) $(CLIENT_BONUS)

$(LIB1):
	$(MAKE) -C $(LIB_DIR1) all

$(LIB2):
	$(MAKE) -C $(LIB_DIR2) all

$(OBJ_DIR):
	mkdir -p $(OBJ_DIR)

$(OBJ_BONUS_DIR):
	mkdir -p $(OBJ_BONUS_DIR)

$(OBJ_DIR)%.o: $(SRC_DIR)%.c | $(OBJ_DIR)
	$(CC) $(CFLAGS) -c $< -o $@

$(OBJ_BONUS_DIR)%.o: $(SRC_BONUS_DIR)%.c | $(OBJ_BONUS_DIR)
	$(CC) $(CFLAGS) -c $< -o $@

$(SERVER): $(SERVER_OBJ_FILES) $(LIB1) $(LIB2)
	$(CC) $(SERVER_OBJ_FILES) -o $(SERVER) $(LIB2) $(LIB1)

$(CLIENT): $(CLIENT_OBJ_FILES) $(LIB1) $(LIB2)
	$(CC) $(CLIENT_OBJ_FILES) -o $(CLIENT) $(LIB2) $(LIB1)

$(SERVER_BONUS): $(SERVER_BONUS_OBJ_FILES) $(LIB1) $(LIB2)
	$(CC) $(SERVER_BONUS_OBJ_FILES) -o $(SERVER_BONUS) $(LIB2) $(LIB1)

$(CLIENT_BONUS): $(CLIENT_BONUS_OBJ_FILES) $(LIB1) $(LIB2)
	$(CC) $(CLIENT_BONUS_OBJ_FILES) -o $(CLIENT_BONUS) $(LIB2) $(LIB1)

clean:
	rm -rf $(OBJ_DIR) $(OBJ_BONUS_DIR)
	$(MAKE) -C $(LIB_DIR1) clean
	$(MAKE) -C $(LIB_DIR2) clean

fclean: clean
	rm -f $(SERVER) $(CLIENT) $(SERVER_BONUS) $(CLIENT_BONUS)
	$(MAKE) -C $(LIB_DIR1) fclean
	$(MAKE) -C $(LIB_DIR2) fclean

re: fclean all

.PHONY: clean fclean all re bonus
