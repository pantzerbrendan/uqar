
RM			=	rm -vf
CXX			=	g++
GXX			=	g++ -g

INCLUDE		=	./include
SOURCE		=	./source

NAME		=	INF11207TP2
DEBUG		=	INF11207TP2_debug

## Release
SRC			=	$(SOURCE)/main.cpp \
				$(SOURCE)/Application.cpp \
				$(SOURCE)/factory/Factory.cpp \
				$(SOURCE)/factory/FactoryBaseType.cpp \
				$(SOURCE)/Accounts/A_Account.cpp \
				$(SOURCE)/Accounts/RegularAccount.cpp \
				$(SOURCE)/Accounts/RetirementAccount.cpp \
				$(SOURCE)/Accounts/ChildAccount.cpp \
				$(SOURCE)/users/User.cpp \
				$(SOURCE)/utils/Date.cpp

OBJS		=	$(SRC:.cpp=.o)
## !Release

## Debug
D_SRC		=	$(SRC)

D_OBJS		=	$(D_SRC:.cpp=_debug.o)
## !Debug

CXXFLAGS	+=	-W -Wall -Wextra
CXXFLAGS	+=	-std=c++11 -O3
LDFLAGS		+=	-I$(INCLUDE)


%.o : 			%.cpp
				$(CXX) $(LDFLAGS) -c -o $@ $<

%_debug.o : 	%.cpp
				$(CXX) $(LDFLAGS) -c -o $@ $<

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
