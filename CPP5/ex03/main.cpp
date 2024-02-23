/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vpolojie <vpolojie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/01 09:12:07 by vpolojie          #+#    #+#             */
/*   Updated: 2024/01/12 11:03:59 by vpolojie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "Intern.hpp"
#include <string>
#include <iostream>
#include <new>

int main(void)
{
    /*
        FAIL TESTS :
        try
        {
            Bureaucrat  emp1("michel", 151);
        }
        catch(const GradeTooLowException& e1)
        {
            std::cout << e1.GTooLowException() << std::endl;
        }
        try
        {
            Bureaucrat  emp2("jean", 0);
        }
        catch(const GradeTooHighException& e2)
        {
            std::cout << e2.GTooHighException() << std::endl;
        }

        try
        {
            AForm    doc1("sub form", 160, 10);
        }
        catch(const GradeTooLowException& e3)
        {
            std::cout << e3.FGTooLowException() << std::endl;
        }
        try
        {
            AForm    doc2("credit card form", 6, -1);
        }
        catch(const GradeTooHighException& e4)
        {
            std::cout << e4.FGTooHighException() << std::endl;
        }
    */
    Intern somerandomIntern;
    AForm *af;
    Bureaucrat b1("michel", 1);

    try
    {
        af = somerandomIntern.makeForm("Robotomy Request", "Bender");
        std::cout << *af;
        b1.signAForm(*af);
        b1.executeForm(*af);
        std::cout << "\n";
        af = somerandomIntern.makeForm("Shrubbery Form", "Bender");
        std::cout << *af;
        b1.signAForm(*af);
        b1.executeForm(*af);
        std::cout << "\n";
        af = somerandomIntern.makeForm("Presidential Form", "Bender");
        std::cout << *af;
        b1.signAForm(*af);
        b1.executeForm(*af);
        std::cout << "\n";
        af = somerandomIntern.makeForm("not a form", "Bender");
        std::cout << *af;
        b1.signAForm(*af);
        b1.executeForm(*af);
        std::cout << "\n";
    }
    catch(const Intern::UnknownForm& e)
    {
        std::cout << e.UForm() << std::endl;
    }
    
    
    return (0);
}