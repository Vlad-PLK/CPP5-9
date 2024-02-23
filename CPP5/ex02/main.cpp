/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vpolojie <vpolojie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/01 09:12:07 by vpolojie          #+#    #+#             */
/*   Updated: 2024/01/11 15:22:36 by vpolojie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
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
    Bureaucrat b1("leon", 1);
    Bureaucrat b2("michel", 5);
    Bureaucrat b3("gerard", 150);
    std::cout << "\n";
    ShrubberyCreationForm a1("home");
    RobotomyRequestForm   a2("bob");
    PresidentialPardonForm a3("vlad");
    PresidentialPardonForm a4("JFK");
    std::cout << "\n";
    std::cout << b1 << std::endl;
    std::cout << b2 << std::endl;
    std::cout << "\n";
    std::cout << a1 << std::endl;
    std::cout << a2 << std::endl;
    std::cout << a3 << std::endl;
    std::cout << a4 << std::endl;
    std::cout << "\n";
    b2.signAForm(a1);
    b2.signAForm(a2);
    b2.signAForm(a3);
    std::cout << "\n";
    b2.executeForm(a1);
    b2.executeForm(a2);
    b2.executeForm(a3);
    std::cout << "\n";
    try
    {
        // b3 can't sign a4 //
        b3.signAForm(a4);
        b3.executeForm(a4);
    }
    catch(const Bureaucrat::GradeTooLowException& e)
    {
        std::cout << e.GTooLowException() << std::endl;
    }
    std::cout << "\n";
    b3.incGrade(146);
    // b3 can sign and execute a4 because he's now grade 4
    b3.signAForm(a4);
    b3.executeForm(a4);
    std::cout << "\n";
    try
    {
        // a2 has already been signed
        b3.signAForm(a2);
        b3.executeForm(a2);
    }
    catch(const AForm::FormSignException& e)
    {
        std::cout << e.FSignException() << std::endl;
    }
    std::cout << "\n";

    return (0);
}