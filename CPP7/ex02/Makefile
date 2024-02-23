NAME = array

OBJS = main.cpp

SRCS = ${subst .cpp,.o,$(OBJS)}

CXX = c++

FLAGS = -std=c++98 -Wall -Werror -Wextra

all: ${NAME}

${NAME}: ${OBJS}
	@printf "\n"
	@printf "Creating your array ! : \n"
	${CXX} ${FLAGS} -o ${NAME} ${OBJS}
	@printf "\n"

main.o:	main.cpp Array.hpp
	${CXX} ${FLAGS} -c main.cpp

clean :
	rm -rf ${SRCS}

fclean : clean
		rm -rf ${NAME}

re :	fclean all

.PHONY: all clean re%