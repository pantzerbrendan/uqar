
RM			=	rm -vf
CXX			=	g++
GXX			=	g++ -g

INCLUDE		=	./include
SOURCE		=	./source

NAME		=	INF36207_Q2A
DEBUG		=	INF36207_Q2A_debug

SRC			=	./main.cpp \
				$(SOURCE)/DictAttack.cpp \
				$(SOURCE)/MD5.cpp \
				$(SOURCE)/data/Password.cpp

OBJS		=	$(SRC:.cpp=.o)

CXXFLAGS	+=	-W -Wall -Wextra
CXXFLAGS	+=	-std=c++11
#CXXFLAGS	+=	-Werror
CXXFLAGS	+=	-I$(INCLUDE)


%.o : 			%.cpp
				$(CXX) $(CXXFLAGS) -c -o $@ $<

$(NAME):		$(OBJS)
				$(CXX) $(OBJS) -o $(NAME)

$(DEBUG):		$(OBJS)
				$(GXX) $(OBJS) -o $(DEBUG)

all:			$(NAME)

debug:			CXXFLAGS += -DDEBUG=1
debug:			$(DEBUG)

clean:
				@$(RM) $(OBJS)

fclean:			clean
				@$(RM) $(NAME)
				@$(RM) $(DEBUG)

re:				fclean all

.PHONY:			clean fclean all re
