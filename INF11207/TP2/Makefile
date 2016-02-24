
RM			=	rm -vf
CXX			=	g++
GXX			=	g++ -g

INCLUDE		=	./include
SOURCE		=	./source

NAME		=	INF11207TP2
DEBUG		=	INF11207TP2_debug

## Release
SRC			=	$(SOURCE)/main.cpp

OBJS		=	$(SRC:.cpp=.o)
## !Release

## Debug
D_SRC		=	$(SOURCE)/main.cpp

D_OBJS		=	$(D_SRC:.cpp=_debug.o)
## !Debug

CXXFLAGS	+=	-W -Wall -Wextra
CXXFLAGS	+=	-std=c++11 -O3
CXXFLAGS	+=	-I$(INCLUDE)


%.o : 			%.cpp
				$(CXX) $(CXXFLAGS) -c -o $@ $<

%_debug.o : 	%.cpp
				$(CXX) $(CXXFLAGS) -c -o $@ $<

$(NAME):		CXXFLAGS += -Werror
$(NAME):		$(OBJS)
				$(CXX) $(OBJS) -o $(NAME)

$(DEBUG):		$(D_OBJS)
				$(GXX) $(D_OBJS) -o $(DEBUG)

all:			$(NAME)

debug:			CXXFLAGS += -DDEBUG=1
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
