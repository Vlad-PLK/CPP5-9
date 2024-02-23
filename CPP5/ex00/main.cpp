/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vpolojie <vpolojie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/01 09:12:07 by vpolojie          #+#    #+#             */
/*   Updated: 2024/01/08 18:06:50 by vpolojie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include <string>
#include <iostream>
#include <new>

int main(void)
{
    Bureaucrat *b1;
    Bureaucrat *b2;
    Bureaucrat *b3;
    Bureaucrat *b4;
    try
    {
        // creation de 4 bureaucrat sans retour d'exception //
        b1 = new Bureaucrat("francis", 23);
        b2 = new Bureaucrat("leon", 5);
        b3 = new Bureaucrat("michel", 30);
        b4 = new Bureaucrat("daniel", 1);

        std::cout << "\n";
        std::cout << *b1 << std::endl;
        std::cout << *b2 << std::endl;
        std::cout << *b3 << std::endl;
        std::cout << *b4 << std::endl;
        std::cout << "\n";
    }
    catch (const Bureaucrat::GradeTooHighException &h)
    {
        std::cout << h.GTooHighException() << std::endl;
    }
    catch (const Bureaucrat::GradeTooLowException &l)
    {
        std::cout << l.GTooLowException() << std::endl;
    }
    std::cout << "\n";
    try 
    {
        std::cout << *b1 << std::endl;
        // incrementation de 22 grade -> possible car grade final = 1
        b1->incGrade(22);
        std::cout << *b1 << std::endl;
        // incrementation de 2 grade -> impossible car grade final = -1
        b1->incGrade(2);
        // retour d'exception "grade too high" //
        std::cout << *b1 << std::endl;
        // aucune instruction supplementaire exécutées car exception renvoyée //
        std::cout << *b3 << std::endl;
        b3->decGrade(100);
        std::cout << *b3 << std::endl;
        b3->decGrade(20);
        std::cout << *b3 << std::endl;
        b3->decGrade(1);
        std::cout << *b3 << std::endl;
    }
    catch (const Bureaucrat::GradeTooHighException &h2)
    {
        std::cout << h2.GTooHighException() << std::endl;
    }
    catch (const Bureaucrat::GradeTooLowException &l2)
    {
        std::cout << l2.GTooLowException() << std::endl;
    }
    std::cout << "\n";
    try
    {
        // tentative de créer un bureaucrat de grade 151 -> impossible donc retour d'exception
        Bureaucrat jo("johny", 151);
    }
    catch(const Bureaucrat::GradeTooLowException &h3)
    {
        std::cout << h3.GTooLowException() << std::endl;
    }
    std::cout << "\n";
    try
    {
        // creation d'un bureaucrat de grade 5 -> ok //
        Bureaucrat to("tony", 5);
        std::cout << to << std::endl;
        // decrementation de grade 146 -> pas ok //
        to.decGrade(146);
        std::cout << to << std::endl;
    }
    catch(const Bureaucrat::GradeTooLowException &h3)
    {
        std::cout << h3.GTooLowException() << std::endl;
    }
    
    //system("leaks Bureau");
    return (0);
}