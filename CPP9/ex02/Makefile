NAME = PmergeMe

OBJS = main.cpp PmergeMe.cpp

SRCS = ${subst .cpp,.o,$(OBJS)}

CXX = g++

FLAGS = -std=c++98 -Wall -Werror -Wextra

all: ${NAME}

${NAME}: ${OBJS}
	@printf "\n"
	@printf "Creating your algorithm ! : \n"
	${CXX} ${FLAGS} -o ${NAME} ${OBJS}
	@printf "\n"

main.o:	main.cpp PmergeMe.hpp
	${CXX} ${FLAGS} -c main.cpp

PmergeMe.o: PmergeMe.hpp

clean :
	rm -rf ${SRCS}

fclean : clean
		rm -rf ${NAME}

re :	fclean all

.PHONY: all clean re%