NAME = Bureau

OBJS = main.cpp Bureaucrat.cpp Form.cpp

SRCS = ${subst .cpp,.o,$(OBJS)}

CXX = c++

FLAGS = -std=c++98 -Wall -Werror -Wextra

all: ${NAME}

${NAME}: ${OBJS}
	@printf "\n"
	@printf "Creating your bureau ! : \n"
	${CXX} ${FLAGS} -o ${NAME} ${OBJS}
	@printf "\n"

main.o:	main.cpp Bureaucrat.hpp Form.hpp
	${CXX} ${FLAGS} -c main.cpp

Bureaucrat.o: Bureaucrat.hpp

Form.o: Form.hpp

clean :
	rm -rf ${SRCS}

fclean : clean
		rm -rf ${NAME}

re :	clean all

.PHONY: all clean re%