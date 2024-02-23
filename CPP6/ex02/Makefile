NAME = type

OBJS = main.cpp Base.cpp A.cpp B.cpp C.cpp

SRCS = ${subst .cpp,.o,$(OBJS)}

CXX = c++

FLAGS = -std=c++98 -Wall -Werror -Wextra

all: ${NAME}

${NAME}: ${OBJS}
	@printf "\n"
	@printf "Creating your identifier ! : \n"
	${CXX} ${FLAGS} -o ${NAME} ${OBJS}
	@printf "\n"

main.o:	main.cpp Base.hpp A.hpp B.hpp C.hpp
	${CXX} ${FLAGS} -c main.cpp

Base.o: Base.hpp

A.o: A.hpp

B.o: B.hpp

C.o: C.hpp

clean :
	rm -rf ${SRCS}

fclean : clean
		rm -rf ${NAME}

re :	fclean all

.PHONY: all clean re%