/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vpolojie <vpolojie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/01 09:12:07 by vpolojie          #+#    #+#             */
/*   Updated: 2024/01/10 21:56:44 by vpolojie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "Form.hpp"
#include <string>
#include <iostream>
#include <new>

int main(void)
{
    /*
        FAIL TESTS :
        try
        {
            // exception because grade too low
            Bureaucrat  emp1("michel", 151);
        }
        catch(const GradeTooLowException& e1)
        {
            std::cout << e1.GTooLowException() << std::endl;
        }
        try
        {
            // exception because grade too high
            Bureaucrat  emp2("jean", 0);
        }
        catch(const GradeTooHighException& e2)
        {
            std::cout << e2.GTooHighException() << std::endl;
        }

        try
        {
            // form grade to sign too low
            Form    doc1("sub form", 160, 10);
        }
        catch(const GradeTooLowException& e3)
        {
            std::cout << e3.FGTooLowException() << std::endl;
        }
        try
        {
            // form grade to execute too high
            Form    doc2("credit card form", 6, -1);
        }
        catch(const GradeTooHighException& e4)
        {
            std::cout << e4.FGTooHighException() << std::endl;
        }
    */
    Bureaucrat  emp1("michel", 5);
    Bureaucrat  emp2("jean", 67);
    Bureaucrat  emp3("pierre", 125);
    Bureaucrat  emp4("ciseau", 48);
    std::cout << "\n";
    Form    doc1("subscription", 10, 10);
    Form    doc2("credit card", 6, 70);
    Form    doc3("passport", 2, 10);
    Form    doc4("tax", 150, 150);
    std::cout << "\n";
    std::cout << doc1 << std::endl;
    std::cout << doc2 << std::endl;
    std::cout << doc3 << std::endl;
    std::cout << doc4 << std::endl;
    // signed and executed well //
    emp1.signForm(doc1);
    
    try
    {
        // impossible to sign //
        emp2.signForm(doc2);
    }
    catch(const Bureaucrat::GradeTooLowException& exc1)
    {
        std::cout << exc1.GTooLowException() << std::endl;
    }
    std::cout << "\n";
    emp2.incGrade(62);
    std::cout << emp2 << std::endl;
    std::cout << "\n";
    try
    {
        // possible to sign because now emp2 is grade 5//
        emp2.signForm(doc2);
    }
    catch(const Bureaucrat::GradeTooLowException& exc1)
    {
        std::cout << exc1.GTooLowException() << std::endl;
    }
    return (0);
}