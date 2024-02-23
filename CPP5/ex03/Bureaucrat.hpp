/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vpolojie <vpolojie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/01 09:12:39 by vpolojie          #+#    #+#             */
/*   Updated: 2024/01/10 22:00:18 by vpolojie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP
#include <string>
#include <iostream>
#include "AForm.hpp"

class AForm;

class Bureaucrat
{
  private:
    std::string const   _name;
    int                 _grade;
  public:
    Bureaucrat();
    Bureaucrat(std::string name, int grade);
    Bureaucrat(Bureaucrat const &_copy);
    Bureaucrat &operator=(Bureaucrat const &_OpCopy);
    ~Bureaucrat();

    std::string const getName() const;
    int               getGrade() const;
    void              incGrade(int value);
    void              decGrade(int value);
    void              signAForm(AForm &papier);
    void              executeForm(AForm const &form);

    class GradeTooHighException : public std::exception
    {
      public:
        virtual const char* GTooHighException() const throw();
    };
    class GradeTooLowException : public std::exception
    {
      public:
        virtual const char* GTooLowException() const throw();
    };
};

std::ostream    &operator<<(std::ostream &output, Bureaucrat const &OutCopy);

#endif