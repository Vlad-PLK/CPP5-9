/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vpolojie <vpolojie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/12 09:26:38 by vpolojie          #+#    #+#             */
/*   Updated: 2024/01/12 11:05:24 by vpolojie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.hpp"
#include "AForm.hpp"
#include "Bureaucrat.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include <string>
#include <iostream>

Intern::Intern()
{
    // std::cout << "Default Constructor called" << std::endl;
    this->tab[0] = "Shrubbery Form";
    this->tab[1] = "Robotomy Request";
    this->tab[2] = "Presidential Form";
}

Intern::Intern(const Intern &_copy)
{
    *this = _copy;
}

Intern  &Intern::operator=(const Intern &_opeCopy)
{
    (void)_opeCopy;
    return (*this);
}

Intern::~Intern()
{
    // std::cout << "Default Destructor called" << std::endl;
}

const   char*Intern::UnknownForm::UForm() const throw()
{
    return ("Unknown Form, please try again");
}

AForm   *Intern::makeForm(std::string _formName, std::string _formTarget)
{
    AForm *af;
    int     i;
    for (i = 0; i != 4; i++)
        if (_formName.compare(this->tab[i]) == 0)
            break;
    if (i == 4)
        throw Intern::UnknownForm();
    else
        switch (i)
        {
        case 0:
            af = new ShrubberyCreationForm(_formTarget);
            break;
        case 1:
            af = new RobotomyRequestForm(_formTarget);
            break;
        case 2:
            af = new PresidentialPardonForm(_formTarget);
            break;
        }
    std::cout << "Intern creates form " << _formName << std::endl;
    return (af);
}