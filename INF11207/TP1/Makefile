
RM			=	rm -vf
CXX			=	g++ -g

INCLUDE		=	./include
SOURCE		=	./source

NAME		=	INF11207TP1

SRC			=	$(SOURCE)/main.cpp \
				$(SOURCE)/Application.cpp \
				$(SOURCE)/Commands.cpp \
				$(SOURCE)/data/User.cpp \
				$(SOURCE)/data/Birthdate.cpp \
				$(SOURCE)/data/Address.cpp \
				$(SOURCE)/data/Acronyms.cpp \
				$(SOURCE)/utils/my_string.cpp \
				$(SOURCE)/utils/io.cpp

OBJS		=	$(SRC:.cpp=.o)

CXXFLAGS	+=	-W -Wall -Wextra
CXXFLAGS	+=	-std=c++11
CXXFLAGS	+=	-Werror
CXXFLAGS	+=	-I$(INCLUDE)

$(NAME):		$(OBJS)
				$(CXX) $(OBJS) $(LDFLAGS) -o $(NAME)

all:			$(NAME)

clean:
				@$(RM) $(OBJS)

fclean:			clean
				@$(RM) $(NAME)

re:				fclean all

.PHONY:			clean fclean all re
