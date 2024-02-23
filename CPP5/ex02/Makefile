NAME = Bureau

OBJS = main.cpp Bureaucrat.cpp AForm.cpp PresidentialPardonForm.cpp RobotomyRequestForm.cpp ShrubberyCreationForm.cpp
SRCS = ${subst .cpp,.o,$(OBJS)}

CXX = c++

FLAGS = -std=c++98 -Wall -Werror -Wextra

all: ${NAME}

${NAME}: ${OBJS}
	@printf "\n"
	@printf "Creating your bureau ! : \n"
	${CXX} ${FLAGS} -o ${NAME} ${OBJS}
	@printf "\n"

main.o:	main.cpp Bureaucrat.hpp AForm.hpp PresidentialPardonForm.hpp ShrubberyCreationForm.hpp RobotomyRequestForm.hpp
	${CXX} ${FLAGS} -c main.cpp

Bureaucrat.o: Bureaucrat.hpp

AForm.o: AForm.hpp

ShrubberyCreationForm.o: ShrubberyCreationForm.hpp

PresidentialPardonForm.o: PresidentialPardonForm.hpp

RobotomyRequestForm.o: RobotomyRequestForm.hpp

clean :
	rm -rf ${SRCS}

fclean : clean
		rm -rf ${NAME}

re :	fclean all

.PHONY: all clean re%