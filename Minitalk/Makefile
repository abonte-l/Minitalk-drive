
SERVER			=	server
SERVER_SRC		=	./sources/server.c
SERVER_OBJ		=	$(SERVER_SRC:.c=.o)

CLIENT			=	client
CLIENT_SRC		=	./sources/client.c 
CLIENT_OBJ		=	$(CLIENT_SRC:.c=.o)

UTILS_SRC		=	./sources/utils.c 
UTILS_OBJ		=	$(UTILS_SRC:.c=.o)

CC				=	gcc
RM 				=	rm -f
FLAGS			= 	-Wall -Werror -Wextra -g

all : $(SERVER) $(CLIENT)

$(SERVER) : $(SERVER_OBJ) $(UTILS_OBJ)
	@echo "\x1B[38;2;216;195;151mPreparing for $(SERVER)...\033[0m"
	$(CC) $(FLAGS) $(SERVER_SRC) $(UTILS_SRC) -o $(SERVER)
	@echo "\x1B[38;2;216;195;151m$(SERVER) created!\033[0m"

$(CLIENT) : $(CLIENT_OBJ) $(UTILS_OBJ)
	@echo "\x1B[38;2;216;195;151mPreparing for $(CLIENT)...\033[0m"
	$(CC) $(FLAGS) $(CLIENT_SRC) $(UTILS_SRC) -o $(CLIENT)
	@echo "\x1B[38;2;216;195;151m$(CLIENT) created!\033[0m"
clean :
	$(RM) $(SERVER_OBJ) $(CLIENT_OBJ) $(UTILS_OBJ) $(SERVER_OBJ_BNS) $(CLIENT_OBJ_BNS) $(UTILS_OBJ_BNS)
	@echo "\x1B[38;2;216;195;151mAll .o deleted.\033[0m"

fclean : clean
	$(RM) $(SERVER) $(CLIENT) $(SERVER_BNS) $(CLIENT_BNS)
	@echo "\x1B[38;2;216;195;151m$(SERVER) and $(CLIENT) deleted.\033[0m"

re : fclean all

.PHONY: all clean fclean re