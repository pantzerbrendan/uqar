
RM			=	rm -vf
CXX			=	g++
GXX			=	g++ -g

INCLUDE		=	./include
SOURCE		=	./source

NAME		=	INF36207_Q2B
DEBUG		=	INF36207_Q2B_debug

SRC			=	$(SOURCE)/main.cpp \
				$(SOURCE)/Configuration.cpp \
				$(SOURCE)/sys/Thread.cpp

OBJS		=	$(SRC:.cpp=.o)

CXXFLAGS	+=	-W -Wall -Wextra
CXXFLAGS	+=	-std=c++11 -lpthread
#CXXFLAGS	+=	-Werror
CXXFLAGS	+=	-I$(INCLUDE)


%.o : 			%.cpp
				$(CXX) $(CXXFLAGS) -c -o $@ $<

$(NAME):		$(OBJS)
				$(CXX) $(OBJS) $(CXXFLAGS) -o $(NAME)

$(DEBUG):		$(OBJS)
				$(GXX) $(OBJS) $(CXXFLAGS) -o $(DEBUG)

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
