NAME = container

CXX = clang++

CXXFLAGS = -Wall -Wextra -Werror -std=c++98

MAIN = ./main4.cpp 

MAIN_OBJS = $(MAIN:.cpp=.o)

HEADERS = ./iterator.hpp ./map_iterator.hpp ./vector_iterator.hpp ./reverse_iterator.hpp ./pair.hpp ./vector.hpp ./map.hpp ./stack.hpp

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