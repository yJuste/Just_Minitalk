NAME = minitalk

SERVER = server
CLIENT = client

CC = cc
CFLAGS = -Wall -Wextra -Werror

SRC_SERVER =	ft_server.c		\
		ft_server_next.c	\
		ft_server_lib.c

SRC_CLIENT =	ft_client.c		\
		ft_client_lib.c

OBJ_SERVER = $(SRC_SERVER:.c=.o)
OBJ_CLIENT = $(SRC_CLIENT:.c=.o)

RESET		= "\033[0m"
GREEN		= "\033[32m"	# Green
RED		= "\033[91m"	# Red

all: $(NAME)

$(NAME): $(OBJ_SERVER) $(OBJ_CLIENT)
	@$(CC) $(CFLAGS) -o $(SERVER) $(OBJ_SERVER)
	@$(CC) $(CFLAGS) -o $(CLIENT) $(OBJ_CLIENT)
	@echo $(GREEN)"--- EXECUTABLE ./$(SERVER) is ready ---`make help_server`"$(RESET)
	@echo $(GREEN)"--- EXECUTABLE ./$(CLIENT) is ready ---`make help_client`"$(RESET)

bonus: $(NAME)

$(SERVER): $(OBJ_SERVER)
	@$(CC) $(CFLAGS) -o $(SERVER) $(OBJ_SERVER)
	@echo $(GREEN)"--- EXECUTABLE ./$(SERVER) is ready ---`make help_server`"$(RESET)

$(CLIENT): $(OBJ_CLIENT)
	@$(CC) $(CFLAGS) -o $(CLIENT) $(OBJ_CLIENT)
	@echo $(GREEN)"--- EXECUTABLE ./$(CLIENT) is ready ---`make help_client`"$(RESET)

clean:
	@rm -f $(OBJ_SERVER) $(OBJ_CLIENT)

fclean: clean
	@rm -f $(SERVER) $(CLIENT)
	@echo $(RED)"--- EXECUTABLE ./$(SERVER) is removed ---"$(RESET)
	@echo $(RED)"--- EXECUTABLE ./$(CLIENT) is removed ---"$(RESET)

re: fclean all

rf: re
	@rm -f $(SERVER) $(CLIENT)
	@rm -f $(OBJ_SERVER) $(OBJ_CLIENT)
	@echo $(RED)"--- EXECUTABLE ./$(SERVER) is removed ---"$(RESET)
	@echo $(RED)"--- EXECUTABLE ./$(CLIENT) is removed ---"$(RESET)

s:
	ls -lh $(SERVER) $(CLIENT)

help_server:
	@echo $(GREEN)
	@head -n 16 ft_server.c
	@echo $(RESET)

help_client:
	@echo $(GREEN)
	@head -n 16 ft_client.c
	@echo $(RESET)

.PHONY: all clean fclean re rf s help
