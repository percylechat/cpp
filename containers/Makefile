NAME = container

NAME_STD = container_std

NPERF = perf

NPERF_STD = perf_std

CXX = clang++

CXXFLAGS = -Wall -Wextra -Werror -std=c++98

MAIN = ./main4.cpp

MAIN-STD = ./main4_std.cpp

PERF_E = ./perf.cpp

PERF_E_STD = ./perf_std.cpp

MAIN_OBJS = $(MAIN:.cpp=.o)

MAIN_STD_OBJS = $(MAIN-STD:.cpp=.o)

PERF_OBJS = $(PERF_E:.cpp=.o)

PERF_OBJS_STD = $(PERF_E_STD:.cpp=.o)

HEADERS = ./iterator.hpp ./map_iterator.hpp ./vector_iterator.hpp ./reverse_iterator.hpp ./pair.hpp ./vector.hpp ./map.hpp ./stack.hpp

RM = rm -rf 

%.o: %.cpp ${HEADERS}
	$(CXX) $(CXXFLAGS) -c $< -o $@

all     :	$(NAME) $(NAME_STD) $(NPERF) $(NPERF_STD) 

$(NAME) :	$(MAIN_OBJS)
	${CXX} ${CXXFLAGS} -o ${NAME} ${MAIN_OBJS}

$(NAME_STD) :	$(MAIN_STD_OBJS)
	${CXX} ${CXXFLAGS} -o ${NAME_STD} ${MAIN_STD_OBJS}

$(NPERF) :	$(PERF_OBJS)
	${CXX} ${CXXFLAGS} -o ${NPERF} ${PERF_OBJS}

$(NPERF_STD) :	$(PERF_OBJS_STD)
	${CXX} ${CXXFLAGS} -o ${NPERF_STD} ${PERF_OBJS_STD}

clean   :
	$(RM) $(MAIN_OBJS) ${MAIN_STD_OBJS} $(PERF_OBJS) $(PERF_OBJS_STD) 

fclean  : clean
	$(RM) $(NAME) $(NAME_STD) $(NPERF) $(NPERF_STD) 

re      :	fclean all

.PHONY	:		all clean fclean re