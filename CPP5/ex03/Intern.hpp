/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vpolojie <vpolojie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/12 09:23:37 by vpolojie          #+#    #+#             */
/*   Updated: 2024/01/12 10:39:51 by vpolojie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INTERN_HPP
#define INTERN_HPP
#include "AForm.hpp"
#include "Bureaucrat.hpp"
#include <string>
#include <iostream>
#include <exception>

class Intern
{
  private:
    std::string tab[4];
  public:
    Intern();
    Intern(Intern const &_copy);
    Intern &operator=(Intern const &_OpCopy);
    ~Intern();
    class UnknownForm : public std::exception
    {
        public:
            virtual const char* UForm() const throw();
    };

    AForm   *makeForm(std::string _formName, std::string _formTarget);
};

#endif