
ECHO	=	echo
RM		=	rm -fv
LN		=	ln -svf

CLIENT	=	./client
SERVER	=	./server

CLIENT_BIN	=	INF34207TP1_client
SERVER_BIN	=	INF34207TP1_server

NAME	=	INF34207TP1_TP
DEBUG	=	INF34207TP1_TP_debug

$(NAME):
			@$(ECHO) "\033[33m[RELEASE]\tCompiling client <"$(CLIENT)">\033[0m"
			@make -C $(CLIENT)
			@$(ECHO) ""
			@$(ECHO) "\033[33m[RELEASE]\tCompiling server <"$(SERVER)">\033[0m"
			@make -C $(SERVER)
			@$(ECHO) ""
			@$(ECHO) "\033[33m[RELEASE]\tCreating symlinks\033[0m"
			@$(LN) $(CLIENT)/$(CLIENT_BIN) .
			@$(LN) $(SERVER)/$(SERVER_BIN) .

$(DEBUG):
			@$(ECHO) "\033[33m[DEBUG]\t\tCompiling client <"$(CLIENT)">\033[0m"
			@make debug -C $(CLIENT)
			@$(ECHO) ""
			@$(ECHO) "\033[33m[DEBUG]\t\tCompiling server <"$(SERVER)">\033[0m"
			@make debug -C $(SERVER)
			@$(ECHO) ""
			@$(ECHO) "\033[33m[DEBUG]\t\tCreating symlinks\033[0m"
			@$(LN) $(CLIENT)/$(CLIENT_BIN)_debug .
			@$(LN) $(SERVER)/$(SERVER_BIN)_debug .

all:		$(NAME)

debug:		$(DEBUG)

clean:
			@$(ECHO) "\033[33m[CLEAN]\tCleaning client (removes all *.o files)\033[0m"
			@make clean -C $(CLIENT)
			@$(ECHO) ""
			@$(ECHO) "\033[33m[CLEAN]\tCleaning client (removes all *.o files)\033[0m"
			@make clean -C $(SERVER)

fclean:
			@$(ECHO) "\033[33m[FCLEAN]\tForce-cleaning client (removes all binary files)\033[0m"
			@make fclean -C $(CLIENT)
			@$(ECHO) ""
			@$(ECHO) "\033[33m[FCLEAN]\tForce-cleaning client (removes all binary files)\033[0m"
			@make fclean -C $(SERVER)
			@$(ECHO) ""
			@$(ECHO) "\033[33m[FCLEAN]\tRemoving symlinks\033[0m"
			@$(RM) ./$(CLIENT_BIN)
			@$(RM) ./$(SERVER_BIN)
			@$(RM) ./$(CLIENT_BIN)_debug
			@$(RM) ./$(SERVER_BIN)_debug

re: 		fclean all

re_debug:	fclean debug

.PHONY:		clean fclean all re debug
