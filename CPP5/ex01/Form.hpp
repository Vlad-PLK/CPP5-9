/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vpolojie <vpolojie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/26 18:02:35 by vpolojie          #+#    #+#             */
/*   Updated: 2024/01/10 15:05:38 by vpolojie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FORM_HPP
#define FORM_HPP
#include <string>
#include <iostream>
#include "Bureaucrat.hpp"

class Bureaucrat;

class Form
{
  private:
    std::string const _name;
    bool _sign_status;
    int const _sign_grade;
    int const _exec_grade;
  public:
    Form();
    Form(std::string name, int sign_grade, int exec_grade);
    Form(Form const &_copy);
    Form &operator=(Form const &_OpCopy);
    std::string getName(void) const;
    bool        getStatus(void) const;
    int         getExecGrade(void) const;
    int         getSignGrade(void) const;
    void  beSigned(Bureaucrat &Employee);
    ~Form();

    class GradeTooLowException : public std::exception
    {
      public:
        virtual const char *GTooLowException() const throw();
    };

    class GradeTooHighException : public std::exception
    {
      public:
        virtual const char *GTooHighException() const throw();
    };
};

std::ostream    &operator<<(std::ostream &output, Form const &outputform);

#endif