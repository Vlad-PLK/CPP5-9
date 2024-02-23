/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vpolojie <vpolojie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/12 15:19:29 by vpolojie          #+#    #+#             */
/*   Updated: 2024/02/13 15:00:08 by vpolojie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string>
#include <iostream>
#include <algorithm>
#include <stdexcept>
#include "RPN.hpp"

RPN::RPN(){
    //std::cout << "Default constructor called" << std::endl;
}

RPN::RPN(const RPN &_copy)
{
    *this = _copy;
}

RPN &RPN::operator=(const RPN &_opeCopy)
{
    (void)_opeCopy;
    return (*this);
}

RPN::~RPN(){
    //std::cout << "Default destructor called" << std::endl;
}

void    RPN::set_operations(void)
{
    this->tab[0] = '+';
    this->tab[1] = '-';
    this->tab[2] = '*';
    this->tab[3] = '/';
}

void    RPN::set_arg(char *_arg)
{
    this->arg = _arg;
}

std::string RPN::get_arg(void) const
{
    return (this->arg);
}

void    RPN::proceed_operation(int &tmp_result, int j)
{
    switch (j)
    {
    case 0:
        tmp_result += this->stack.top();
        break;
    case 1:
        tmp_result = this->stack.top() - tmp_result;
        break;
    case 2:
        tmp_result *= this->stack.top();
        break;
    case 3:
        if (this->stack.top() == 0)
            throw std::runtime_error("Math error: Attempted to divide by 0");
        else
            tmp_result = this->stack.top() / tmp_result;
        break;
    }
}

void    RPN::set_stack()
{
    std::string number;
    int         tmp_result = 0;

    this->set_operations();
    for (size_t i=0; i != this->arg.length(); i++)
    {
        if (isdigit(this->arg[i]))
        {
            number.assign(this->arg.substr(i, i +1));
            this->stack.push(atoi(number.c_str()));
        }
        else if (this->arg[i] != ' ')
        {
            int j = 0;
            while (this->tab[j] != this->arg[i])
                j++;
            if (this->stack.size() > 1)
            {
                tmp_result = this->stack.top();
                this->stack.pop();
                try
                {
                    this->proceed_operation(tmp_result, j);
                }
                catch(const std::runtime_error& e)
                {
                    std::cout << "Exception occurred : " << e.what() << std::endl;
                    return ;
                }
                this->stack.pop();
                this->stack.push(tmp_result);
            }
            else
            {
                std::cout << "Error: impossible to proceed this operation !" << std::endl;
                return ;
            }
        }
    }
    std::cout << tmp_result << std::endl;
    return ;
}

int    parse_arg(char *arg)
{
    RPN         rpn;

    rpn.set_arg(arg);
    for (size_t i=0; i != rpn.get_arg().length(); i++)
    {
        if ((isdigit(rpn.get_arg()[i]) && isdigit(rpn.get_arg()[i +1])) || isalpha(rpn.get_arg()[i]) || (!isblank(rpn.get_arg()[i]) && !isdigit(rpn.get_arg()[i]) && rpn.get_arg()[i] != '-'
            && rpn.get_arg()[i] != '+' && rpn.get_arg()[i] != '*' && rpn.get_arg()[i] != '/'))
        {
            std::cout << "Error" << std::endl;
            return (1);
        }
    }
    rpn.set_stack();
    return (0);
}