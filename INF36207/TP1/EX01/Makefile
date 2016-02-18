RM			=	rm -vf
CXX			=	g++
GXX			=	g++ -g

NAME			=	EX01

SRC			=	main.cpp \
				cesarNumber.cpp 

OBJS		=	$(SRC:.cpp=.o)

CXXFLAGS	+=	-W -Wall -Wextra
CXXFLAGS	+=	-std=c++11
CXXFLAGS	+=	-Werror

$(NAME):		$(OBJS)
				$(GXX) $(OBJS) -o $(NAME)

all:			$(NAME)

clean:
				@$(RM) $(OBJS)

fclean:			clean
				@$(RM) $(NAME)

re:				fclean all
