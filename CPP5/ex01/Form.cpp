/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vpolojie <vpolojie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/26 18:02:09 by vpolojie          #+#    #+#             */
/*   Updated: 2024/01/10 21:57:05 by vpolojie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"
#include "Bureaucrat.hpp"
#include <iostream>
#include <string>

Form::Form() : _sign_status(false), _sign_grade(1), _exec_grade(1)
{
    //std::cout << "Def form constructor called" << std::endl;
}

Form::Form(std::string name, int sign_grade, int exec_grade) : _name(name), _sign_status(false), _sign_grade(sign_grade), _exec_grade(exec_grade)
{
    //std::cout << "Parameterized constructor called" << std::endl;
    std::cout << "Creating a form" << std::endl;
    if (sign_grade > 150 || exec_grade > 150)
        throw Form::GradeTooLowException();
    else if (sign_grade < 1 || exec_grade < 1)
        throw Form::GradeTooHighException();
}

Form::Form(Form const &_copy) : _sign_grade(this->getSignGrade()), _exec_grade(this->getExecGrade())
{
    //std::cout << "Def form copy constructor called" << std::endl;
    *this = _copy;
}

Form&   Form::operator=(Form const &opeCopy)
{
    //std::cout << "Default form operator constructor called" << std::endl;
    (std::string)this->_name = (std::string)opeCopy._name;
    return (*this);
}

Form::~Form(){
    std::cout << "default form destructor called" << std::endl;
}

const   char*Form::GradeTooLowException::GTooLowException() const throw()
{
    return ("Form Grade too low !");
}

const   char*Form::GradeTooHighException::GTooHighException() const throw()
{
    return ("Form Grade too high !");
}

std::string Form::getName(void) const
{
    return (this->_name);
}

bool    Form::getStatus(void) const
{
    return (this->_sign_status);
}

int Form::getExecGrade(void) const
{
    return (this->_exec_grade);
}

int Form::getSignGrade(void) const
{
    return (this->_sign_grade);
}

std::ostream &operator<<(std::ostream &output, Form const &papier)
{
    output << "Form : " << papier.getName() << " Grade required to sign : " << papier.getSignGrade() 
    << " Grade required to execute : " << papier.getExecGrade() << " Form status : " << papier.getStatus() << std::endl; 
    return (output);
}

void    Form::beSigned(Bureaucrat &Employee)
{
    if (this->getStatus() == true)
        std::cout << "this form is already signed" << std::endl;
    else if (this->getStatus() == false && Employee.getGrade() <= this->getSignGrade())
    {
        this->_sign_status = true;
        std::cout << "form status is now <signed> thanks to " << Employee.getName() << std::endl;
    }
    else if (this->getStatus() == false && Employee.getGrade() > this->getSignGrade())
    {
        std::cout << "Bureaucrat " << Employee.getName() << " is not allowed to sign this form" << std::endl;
        throw Bureaucrat::GradeTooLowException();
    }
}