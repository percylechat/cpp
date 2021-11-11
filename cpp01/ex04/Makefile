NAME = replace

CXX = clang++

CXXFLAGS = -Wall -Wextra -Werror -std=c++98

MAIN = ./main.cpp 

MAIN_OBJS = $(MAIN:.cpp=.o)

RM = rm -rf 

all     :	$(NAME)

$(NAME) :	$(MAIN_OBJS)
	${CXX} ${CXXFLAGS} -o ${NAME} ${MAIN_OBJS}

clean   :
	$(RM) $(MAIN_OBJS)

fclean  : clean
	$(RM) $(NAME)

re      :	fclean all

.PHONY	:		all clean fclean re