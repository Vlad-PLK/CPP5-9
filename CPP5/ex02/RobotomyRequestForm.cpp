/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vpolojie <vpolojie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/06 12:56:01 by vpolojie          #+#    #+#             */
/*   Updated: 2024/01/10 22:16:06 by vpolojie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "Bureaucrat.hpp"
#include <string>
#include <stdlib.h>

RobotomyRequestForm::RobotomyRequestForm(){
    //std::cout << "Default Constructor Called" << std::endl;
}

RobotomyRequestForm::RobotomyRequestForm(const std::string target) : AForm("RobotomyRequestForm", 72, 45), _target(target)
{
    std::cout << "Robotomy Request Form created ! " << std::endl;
}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm &_copy) : AForm(_copy)
{
    *this = _copy;
}

RobotomyRequestForm &RobotomyRequestForm::operator=(const RobotomyRequestForm &_opecopy)
{
    (std::string)this->_target = (std::string)_opecopy._target;
    return (*this);
}

RobotomyRequestForm::~RobotomyRequestForm(){
    std::cout << "Default RRF destructor called" << std::endl;
}

void    RobotomyRequestForm::execute(const Bureaucrat &emp) const
{
    srand(time(NULL));
    int i = rand() % 2 + 1;
    if (this->getStatus() == false)
        std::cout << "this form is not signed yet !" << std::endl;
    else if (this->getStatus() == true && emp.getGrade() <= this->getExecGrade())
    {
        std::cout << "Some driling noises : Drrrrrr Drrrrrrrr ... Dr Dre ?" << std::endl;
        if (i % 2 == 0)
            std::cout << this->_target << " has been robotomized successfully" << std::endl;
        else
            std::cout << "the robotomy has failed" << std::endl;
    }
    else
        throw Bureaucrat::GradeTooLowException();
}
