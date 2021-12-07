NAME = temp

CXX = clang++

CXXFLAGS = -Wall -Wextra -Werror -std=c++98

MAIN = ./span.cpp ./main.cpp 

MAIN_OBJS = $(MAIN:.cpp=.o)

HEADERS = ./span.hpp

RM = rm -rf 

%.o: %.cpp ${HEADERS}
	$(CXX) $(CXXFLAGS) -c $< -o $@

all     :	$(NAME)

$(NAME) :	$(MAIN_OBJS)
	${CXX} ${CXXFLAGS} -o ${NAME} ${MAIN_OBJS}

clean   :
	$(RM) $(MAIN_OBJS)

fclean  : clean
	$(RM) $(NAME)

re      :	fclean all

.PHONY	:		all clean fclean re