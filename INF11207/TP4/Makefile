
RM			=	rm -vf
CXX			=	g++
GXX			=	g++ -g

INCLUDE		=	./include
SOURCE		=	./source

NAME		=	TP4
DEBUG		=	TP4_debug

## Release
SRC			=	$(SOURCE)/main.cpp \
				$(SOURCE)/Dict.cpp \
				$(SOURCE)/Node.cpp \
				$(SOURCE)/MotLePlusLong.cpp

OBJS		=	$(SRC:.cpp=.o)
## !Release

## Debug
D_SRC		=	$(SRC)

D_OBJS		=	$(D_SRC:.cpp=_debug.o)
## !Debug

CXXFLAGS	+=	-W -Wall -Wextra
LDFLAGS		+=	-I$(INCLUDE)


%.o : 			%.cpp
				$(CXX) $(LDFLAGS) -c -o $@ $<

%_debug.o : 	%.cpp
				$(CXX) $(LDFLAGS) $(CXXFLAGS) -c -o $@ $<

$(NAME):		CXXFLAGS += -Werror
$(NAME):		$(OBJS)
				$(CXX) $(OBJS) -o $(NAME)

$(DEBUG):		$(D_OBJS)
				$(GXX) $(D_OBJS) -o $(DEBUG)

all:			$(NAME)

debug:			CXXFLAGS += -DDEBUG
debug:			$(DEBUG)

clean:
				@$(RM) $(OBJS)
				@$(RM) $(D_OBJS)

fclean:			clean
				@$(RM) $(NAME)
				@$(RM) $(DEBUG)

re:				fclean all
re_debug:		fclean debug

.PHONY:			clean fclean all re debug
