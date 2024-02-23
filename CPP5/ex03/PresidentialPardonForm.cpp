/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.cpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vpolojie <vpolojie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/08 15:32:59 by vpolojie          #+#    #+#             */
/*   Updated: 2024/01/12 11:00:03 by vpolojie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PresidentialPardonForm.hpp"
#include "AForm.hpp"
#include "Bureaucrat.hpp"
#include <string>

PresidentialPardonForm::PresidentialPardonForm(){
    //std::cout << "Default Constructor Called" << std::endl;
}

PresidentialPardonForm::PresidentialPardonForm(const std::string target) : AForm("PresidentialPardonForm", 25, 5), _target(target)
{
    //std::cout << "Presidential Pardon Form created ! " << std::endl;
}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm &_copy) : AForm(_copy)
{
    *this = _copy;
}

PresidentialPardonForm &PresidentialPardonForm::operator=(const PresidentialPardonForm &_opecopy)
{
    (std::string)this->_target = (std::string)_opecopy._target;
    return (*this);
}

PresidentialPardonForm::~PresidentialPardonForm(){
    std::cout << "Default PPF destructor called" << std::endl;
}

void    PresidentialPardonForm::execute(const Bureaucrat &emp) const
{
    if (this->getStatus() == false)
        std::cout << "this form is not signed yet ! " << std::endl;
    else if (this->getStatus() == true && emp.getGrade() <= this->getExecGrade())
        std::cout << this->_target << " has been pardoned by Zaphod Beeblebrox." << std::endl;
    else
        throw Bureaucrat::GradeTooLowException();
}