/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AAForm.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vpolojie <vpolojie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/26 18:02:35 by vpolojie          #+#    #+#             */
/*   Updated: 2024/01/02 17:57:53 by vpolojie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FORM_HPP
#define FORM_HPP
#include <string>
#include <iostream>
#include "Bureaucrat.hpp"

class Bureaucrat;

class AForm
{
  private:
    std::string const _name;
    bool _sign_status;
    int const _sign_grade;
    int const _exec_grade;
  public:
    AForm();
    AForm(std::string name, int sign_grade, int exec_grade);
    AForm(AForm const &_copy);
    AForm &operator=(AForm const &_OpCopy);
    std::string getName(void) const;
    bool        getStatus(void) const;
    int         getExecGrade(void) const;
    int         getSignGrade(void) const;
    void  beSigned(Bureaucrat &Employee);
    virtual void  execute(Bureaucrat const &executor) const = 0;
    virtual ~AForm();

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
    class FormSignException : public std::exception
    {
      public:
        virtual const char* FSignException() const throw();
    };
};

std::ostream    &operator<<(std::ostream &output, AForm const &outputform);

#endif