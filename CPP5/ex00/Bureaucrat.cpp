/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vpolojie <vpolojie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/01 09:12:42 by vpolojie          #+#    #+#             */
/*   Updated: 2024/01/08 18:08:17 by vpolojie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include <string>
#include <iostream>

Bureaucrat::Bureaucrat()
{
    std::cout << "Bureaucrat default constructor called" << std::endl;
}

Bureaucrat::Bureaucrat(std::string name, int grade) : _name(name)
{
    //std::cout << "Bureaucrat parameterized constructor called" << std::endl;
    std::cout << "Attempt to construct a bureaucrat !" << std::endl;
    if (grade > 150)
        throw GradeTooLowException();
    else if (grade < 1)
        throw GradeTooHighException();
    else
    {
        std::cout << "Construction successfull !" << std::endl;
        _grade = grade;
    }
}

Bureaucrat::Bureaucrat(Bureaucrat const &copy)
{
    std::cout << "Default Bureaucrat copy constructor called" << std::endl;
    *this = copy;
}

Bureaucrat  &Bureaucrat::operator=(Bureaucrat const &OpeCopy)
{
    std::cout << "Default Bureaucrat operator called" << std::endl;
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
    return ("Grade too low !");
}

const   char*Bureaucrat::GradeTooHighException::GTooHighException() const throw()
{
    return ("Grade too high !");
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
        throw GradeTooHighException();
    std::cout << "incrementing " << this->getName() << " grade by " << value << std::endl;
    this->_grade -= value;
}

void    Bureaucrat::decGrade(int value)
{
    std::cout << "attempt to decrement " << this->getName() << " by " << value << std::endl;
    if ((this->getGrade() + value) > 150)
        throw GradeTooLowException();
    std::cout << "decrementing " << this->getName() << " grade by " << value << std::endl;
    this->_grade += value;
}

std::ostream    &operator<<(std::ostream &output, Bureaucrat const &oBureau)
{
    output << oBureau.getName() << ", bureaucrat grade " << oBureau.getGrade();
    return (output);
}

