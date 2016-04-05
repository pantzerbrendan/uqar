
RM			=	rm -vf
CXX			=	g++
GXX			=	g++ -g

INCLUDE		=	./include
SOURCE		=	./source
TESTS		=	./_tests

NAME		=	INF11207TP3
TEST		=	INF11207TP3_test

## Test binaries names
TEST_COMP	=	INF11207TP3_test_compilation
## !(Test binaries names)

## Release
SRC			=	$(SOURCE)/fraction.cpp \
				$(SOURCE)/fraction_getseters.cpp \
				$(SOURCE)/fraction_unary_operators.cpp \
				$(SOURCE)/fraction_binary_operators.cpp \
				$(SOURCE)/fraction_relational_operators.cpp \
				$(SOURCE)/utils.cpp \

OBJS		=	$(SRC:.cpp=.o)
## !Release

## Test
D_SRC		=	$(SRC)

D_OBJS		=	$(D_SRC:.cpp=_test.o)
## !Test

CXXFLAGS	+=	-W -Wall -Wextra
CXXFLAGS	+=	-std=c++11 -O3
LDFLAGS		+=	-I$(INCLUDE)


%.o : 			%.cpp
				$(CXX) $(LDFLAGS) -c -o $@ $<

%_test.o : 	%.cpp
				$(CXX) $(LDFLAGS) -c -o $@ $<

$(NAME):		CXXFLAGS += -Werror
$(NAME):		$(OBJS)
				$(CXX) $(OBJS) -o $(NAME)

$(TEST):		$(D_OBJS)
				$(CXX) $(LDFLAGS) -c $(TESTS)/main_compilation.cpp -o $(TESTS)/main_compilation.o
				$(GXX) $(D_OBJS) $(TESTS)/main_compilation.o -o $(TEST_COMP)
## Add compilation test here

all:			$(NAME)

test:			CXXFLAGS += -DTEST=1
test:			$(TEST)

clean:
				@$(RM) $(OBJS)
				@$(RM) $(D_OBJS)
				@$(RM) $(TESTS)/main_compilation.o

fclean:			clean
				@$(RM) $(NAME)
				@$(RM) $(TEST_COMP)

re:				fclean all
re_test:		fclean test

.PHONY:			clean fclean all re test
