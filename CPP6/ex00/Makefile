NAME = convert

OBJS = main.cpp ScalarConverter.cpp

SRCS = ${subst .cpp,.o,$(OBJS)}

CXX = c++

FLAGS = -std=c++98 -Wall -Werror -Wextra

all: ${NAME}

${NAME}: ${OBJS}
	@printf "\n"
	@printf "Creating your converter ! : \n"
	${CXX} ${FLAGS} -o ${NAME} ${OBJS}
	@printf "\n"

main.o:	main.cpp ScalarConverter.hpp
	${CXX} ${FLAGS} -c main.cpp

ScalarConverter.o: ScalarConverter.hpp

clean :
	rm -rf ${SRCS}

fclean : clean
		rm -rf ${NAME}

re :	fclean all

.PHONY: all clean re%