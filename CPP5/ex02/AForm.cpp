/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vpolojie <vpolojie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/26 18:02:09 by vpolojie          #+#    #+#             */
/*   Updated: 2024/01/02 17:13:22 by vpolojie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.hpp"
#include "Bureaucrat.hpp"
#include <iostream>
#include <string>

AForm::AForm() : _sign_status(false), _sign_grade(1), _exec_grade(1)
{
    //std::cout << "Def form constructor called" << std::endl;
}

AForm::AForm(std::string name, int sign_grade, int exec_grade) : _name(name), _sign_status(false), _sign_grade(sign_grade), _exec_grade(exec_grade)
{
    //std::cout << "Parameterized constructor called" << std::endl;
    if (sign_grade > 150 || exec_grade > 150)
        throw GradeTooLowException();
    else if (sign_grade < 1 || exec_grade < 1)
        throw GradeTooHighException();
}

AForm::AForm(AForm const &_copy) : _sign_grade(this->getSignGrade()), _exec_grade(this->getExecGrade())
{
    //std::cout << "Def form copy constructor called" << std::endl;
    *this = _copy;
}

AForm&   AForm::operator=(AForm const &opeCopy)
{
    //std::cout << "Default form operator constructor called" << std::endl;
    (std::string)this->_name = (std::string)opeCopy._name;

    return (*this);
}

AForm::~AForm(){
    //std::cout << "Default form destructor called" << std::endl;
}

std::string AForm::getName(void) const
{
    return (this->_name);
}

bool    AForm::getStatus(void) const
{
    return (this->_sign_status);
}

int AForm::getExecGrade(void) const
{
    return (this->_exec_grade);
}

int AForm::getSignGrade(void) const
{
    return (this->_sign_grade);
}

void    AForm::beSigned(Bureaucrat &Employee)
{
    if (this->getStatus() == true)
    {
        std::cout << "Bureaucrat " << Employee.getName() << " couldn't sign this form because : " << std::endl;
        throw AForm::FormSignException();
    }
    else if (this->getStatus() == false && Employee.getGrade() <= this->getSignGrade())
    {
        this->_sign_status = true;
        std::cout << this->getName() << " is now <signed> thanks to " << Employee.getName() << std::endl;
    }
    else if (this->getStatus() == false && Employee.getGrade() > this->getSignGrade())
    {
        std::cout << "Bureaucrat " << Employee.getName() << " couldn't sign this form because : " << std::endl;
        throw Bureaucrat::GradeTooLowException();
    }
}

const char *AForm::GradeTooHighException::GTooHighException() const throw()
{
    return ("Form Grade Too High ! ");
}

const char *AForm::GradeTooLowException::GTooLowException() const throw()
{
    return ("Form Grade Too Low ! ");
}

const char *AForm::FormSignException::FSignException() const throw()
{
    return ("Form already signed ! ");
}

std::ostream &operator<<(std::ostream &output, AForm const &papier)
{
    output << "Form : " << papier.getName() << " | Grade required to sign : " << papier.getSignGrade() 
    << " | Grade required to execute : " << papier.getExecGrade() << " | Form status : " << papier.getStatus() << std::endl; 
    return (output);
}