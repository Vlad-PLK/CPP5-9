/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vpolojie <vpolojie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/06 11:25:47 by vpolojie          #+#    #+#             */
/*   Updated: 2024/01/10 22:16:16 by vpolojie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ShrubberyCreationForm.hpp"
#include "AForm.hpp"
#include "Bureaucrat.hpp"
#include <iostream>
#include <fstream>
#include <string>

ShrubberyCreationForm::ShrubberyCreationForm(){
    //std::cout << "Default SC Form constructor" << std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm(const std::string target) : AForm("ShrubberyCreationForm", 145, 137), _target(target)
{
    std::cout << "Shrubbery Creation Form has been created" << std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm(ShrubberyCreationForm const &_copy) : AForm(_copy)
{
    *this = _copy;
}

ShrubberyCreationForm   &ShrubberyCreationForm::operator=(ShrubberyCreationForm const &_ope)
{
    (std::string)this->_target = (std::string)_ope._target;
    return (*this);
}

void    ShrubberyCreationForm::execute(const Bureaucrat &emp) const
{
    std::ofstream outfile;
    if (this->getStatus() == false)
        std::cout << "this form is not signed yet !" << std::endl;
    else if (this->getStatus() == true && emp.getGrade() <= this->getExecGrade())
    {
        std::cout << "an ascii tree has been planted in " << this->_target << std::endl;
        std::string name;
        name.assign(this->_target);
        name.append("_shrubbery");
        outfile.open(name, std::ios::out);
        outfile << "                      v .   ._, |_  .," << std::endl;
        outfile << "           `-._\\//  .  \\ /    |/_      " << std::endl;
        outfile << "               \\  _\\, y | \\//        " << std::endl;
        outfile << "         _\\_.___\\, \\/ -.\\||         " << std::endl;
        outfile << "           `7-,--.`._||  / / ,        " << std::endl;
        outfile << "           /'     `-. `./ / |/_.'     " << std::endl;
        outfile << "                     |    |//         " << std::endl;
        outfile << "                     |_    /          " << std::endl;
        outfile << "                     |-   |           " << std::endl;
        outfile << "                     |   =|           " << std::endl;
        outfile << "                     |    |           " << std::endl;
        outfile << "--------------------/ ,  . \\--------._" << std::endl;
    }
    else
        throw Bureaucrat::GradeTooLowException();
}

ShrubberyCreationForm::~ShrubberyCreationForm(){
    std::cout << "Default SCF destructor" << std::endl;
}