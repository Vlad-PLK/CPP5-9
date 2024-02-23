/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vpolojie <vpolojie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/01 09:12:42 by vpolojie          #+#    #+#             */
/*   Updated: 2024/01/10 21:56:56 by vpolojie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include <string>
#include <iostream>

Bureaucrat::Bureaucrat()
{
    //std::cout << "Bureaucrat default constructor called" << std::endl;
}

Bureaucrat::Bureaucrat(std::string name, int grade) : _name(name)
{
    //std::cout << "Bureaucrat parameterized constructor called" << std::endl;
    std::cout << "Attempt to construct a bureaucrat ..." << std::endl;
    if (grade > 150)
        throw Bureaucrat::GradeTooLowException();
    else if (grade < 1)
        throw Bureaucrat::GradeTooHighException();
    else
    {
        _grade = grade;
        std::cout << "Bureaucrat : " << this->getName() << " has been created" << std::endl; 
    }
}

Bureaucrat::Bureaucrat(Bureaucrat const &copy)
{
    // std::cout << "Default Bureaucrat copy constructor called" << std::endl;
    *this = copy;
}

Bureaucrat  &Bureaucrat::operator=(Bureaucrat const &OpeCopy)
{
    // std::cout << "Default Bureaucrat operator called" << std::endl;
    this->_grade = OpeCopy._grade;
    (std::string)this->_name = (std::string)OpeCopy._name;
    return (*this);
}

Bureaucrat::~Bureaucrat(void)
{
    std::cout << "Default Bureaucrat destructor called" << std::endl;
}

const   char*Bureaucrat::GradeTooLowException::GTooLowException() const throw()
{
    return ("Bureaucrat Grade too low !");
}

const   char*Bureaucrat::GradeTooHighException::GTooHighException() const throw()
{
    return ("Bureaucrat Grade too high !");
}

std::string const Bureaucrat::getName(void) const
{
    return (this->_name);
}

int Bureaucrat::getGrade(void) const
{
    return (this->_grade);
}

void    Bureaucrat::incGrade(int value)
{
    std::cout << "attempt to increment " << this->getName() << " by " << value << std::endl;
    if ((this->getGrade() - value) < 1)
        throw Bureaucrat::GradeTooHighException();
    std::cout << "incrementing " << this->getName() << " grade by " << value << std::endl;
    this->_grade -= value;
}

void    Bureaucrat::decGrade(int value)
{
    std::cout << "attempt to decrement " << this->getName() << " by " << value << std::endl;
    if ((this->getGrade() + value) > 150)
        throw Bureaucrat::GradeTooLowException();
    std::cout << "decrementing " << this->getName() << " grade by " << value << std::endl;
    this->_grade += value;
}

void    Bureaucrat::signForm(Form &papier)
{
    try
    {
        papier.beSigned(*this);
        std::cout << this->getName() << " signed form : " << papier.getName() << std::endl;
    }
    catch(const Bureaucrat::GradeTooLowException &e)
    {
        std::cout << this->getName() << " couldn't sign " << papier.getName() << " because : " << std::endl;
        std::cout << e.GTooLowException() << std::endl;
    }
}

std::ostream    &operator<<(std::ostream &output, Bureaucrat const &oBureau)
{
    output << oBureau.getName() << ", bureaucrat grade " << oBureau.getGrade();
    return (output);
}

