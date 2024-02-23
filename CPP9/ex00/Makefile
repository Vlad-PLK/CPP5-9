NAME = btc

OBJS = main.cpp BitcoinExchange.cpp

SRCS = ${subst .cpp,.o,$(OBJS)}

CXX = c++

FLAGS = -std=c++98 -Wall -Werror -Wextra

all: ${NAME}

${NAME}: ${OBJS}
	@printf "\n"
	@printf "Creating your bitcoin price visualizer ! : \n"
	${CXX} ${FLAGS} -o ${NAME} ${OBJS}
	@printf "\n"

main.o:	main.cpp BitcoinExchange.hpp
	${CXX} ${FLAGS} -c main.cpp

BitcoinExchange.o: BitcoinExchange.hpp

clean :
	rm -rf ${SRCS}

fclean : clean
		rm -rf ${NAME}

re :	fclean all

.PHONY: all clean re%