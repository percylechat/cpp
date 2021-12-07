NAME = administration

CXX = clang++

CXXFLAGS = -Wall -Wextra -Werror -std=c++98

SRCS = ./Bureaucrat.cpp ./Form.cpp ./ShrubberyCreationForm.cpp ./PresidentialPardonForm.cpp ./RobotomyRequestForm.cpp
MAIN = ./main.cpp 

OBJS = $(SRCS:.cpp=.o)
MAIN_OBJS = $(MAIN:.cpp=.o)

HEADERS = ./Bureaucrat.hpp ./Form.hpp ./ShrubberyCreationForm.hpp ./PresidentialPardonForm.hpp ./RobotomyRequestForm.hpp

RM = rm -rf 

%.o: %.cpp ${HEADERS}
	$(CXX) $(CXXFLAGS) -c $< -o $@

all     :	$(NAME)

$(NAME) :	$(OBJS) $(MAIN_OBJS)
	${CXX} ${CXXFLAGS} -o ${NAME} ${OBJS} ${MAIN_OBJS}

clean   :
	$(RM) $(OBJS)
	$(RM) $(MAIN_OBJS)

fclean  : clean
	$(RM) $(NAME)

re      :	fclean all

.PHONY	:		all clean fclean re