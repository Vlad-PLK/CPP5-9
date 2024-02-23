/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vpolojie <vpolojie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/14 10:36:34 by vpolojie          #+#    #+#             */
/*   Updated: 2024/01/19 11:32:19 by vpolojie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string>
#include <iostream>
#include <iomanip>
#include <exception>
#include "ScalarConverter.hpp"
#include <typeinfo>
#include <cstdlib>

ScalarConverter::ScalarConverter(){
    std::cout << "Default Constructor" << std::endl;
}

ScalarConverter::ScalarConverter(const ScalarConverter& _copy)
{
    *this = _copy;
}

ScalarConverter &ScalarConverter::operator=(const ScalarConverter& _OpeCopy)
{
    (void)_OpeCopy;
    return (*this);
}

ScalarConverter::~ScalarConverter(){
    std::cout << "Default Destructor" << std::endl;
}

void    ScalarConverter::doInt(std::string arg)
{
    int v;
    double exception;
    char int_to_char;
    float int_to_float;
    double int_to_double;

    try
    {
        v = stoi(arg);
        if (0 <= v && v <= 127)
        {
            int_to_char = static_cast<char>(v);
            if (v > 32 && v <= 127)
                std::cout << "char: '" << int_to_char << "'" << std::endl;
            else
                std::cout << "char: Non displayable" << std::endl;
        }
        else
        {
            int_to_char = '\0';
            std::cout << "char: impossible" << std::endl;
        }
        if (MIN_INT <= v && v <= MAX_INT)
        {
            v = static_cast<int>(v);
            std::cout << "int: " << v << std::endl;
        }
        else
            std::cout << "int: impossible" << std::endl;
        int_to_float = static_cast<float>(v);
        std::cout << "float: " << int_to_float << ".0f" << std::endl;
        int_to_double = static_cast<double>(v);
        std::cout << "double: " << int_to_double << ".0" << std::endl;
    }
    catch(const std::out_of_range& e)
    {
        try
        {
            exception = stod(arg);
            std::cout << "char: impossible" << std::endl;
            std::cout << "int: impossible" << std::endl;
            int_to_float = static_cast<float>(exception);
            std::cout << std::fixed << std::setprecision(1) << "float: " << int_to_float << "f" << std::endl;
            int_to_double = static_cast<double>(exception);
            std::cout << std::fixed << std::setprecision(1) << "double: " << int_to_double << std::endl;
        }
        catch(const std::exception& e)
        {
            std::cout << "char: impossible" << std::endl;
            std::cout << "int: impossible" << std::endl;
            std::cout << "float: impossible" << std::endl;
            std::cout << "double: impossible" << std::endl;
        }
    }
}

bool    ScalarConverter::isInt(std::string arg)
{
    //std::cout << "i'm int" << std::endl;
    if (arg.find('.') == std::string::npos && (isdigit(arg[0]) || (arg[0] == '-' && isdigit(arg[1]))))
        return (true);
    else
        return (false);
}

void    ScalarConverter::doFloat(std::string arg)
{
    float f;
    char  float_to_char;
    int   float_to_int;
    double float_to_double;

    try
    {
        f = stof(arg);
        if (0 <= f && f <= 127)
        {
            float_to_char = static_cast<char>(f);
            if (f > 32 && f <= 127)
                std::cout << "char: '" << float_to_char << "'" << std::endl;
            else
                std::cout << "char: Non displayable" << std::endl;
        }
        else
            std::cout << "char: impossible" << std::endl;
        if (MIN_INT <= f && f <= MAX_INT)
        {
            float_to_int = static_cast<int>(f);
            std::cout << "int: " << float_to_int << std::endl;
        }
        else
            std::cout << "int: impossible" << std::endl;
        f = static_cast<float>(f);
        std::cout << std::fixed << std::setprecision(1) << "float: " << f << "f" << std::endl;
        float_to_double = static_cast<double>(f);
        std::cout << std::fixed << std::setprecision(1) << "double: " << float_to_double << std::endl;
        }
    catch(const std::out_of_range& e)
    {
        float_to_double = stod(arg);
        std::cout << "char: impossible" << std::endl;
        std::cout << "int: impossible" << std::endl;
        std::cout << "float: impossible" << std::endl;
        std::cout << std::fixed << std::setprecision(1) << "double: " << float_to_double << std::endl;
    }
}

bool    ScalarConverter::isFloat(std::string arg)
{
    //std::cout << "i'm float" << std::endl;
    if (arg.compare("nanf") == 0 || arg.compare("-inff") == 0 || arg.compare("+inff") == 0 || arg.compare("inff") == 0)
        return (true);
    else if (arg.find('f') != std::string::npos && arg.find('.') != std::string::npos)
        return (true);
    else
        return (false);
}

void    ScalarConverter::doChar(std::string arg)
{
    int i;
    char c;
    int  char_to_int;
    float char_to_float;
    double char_to_double;

    i = arg[0];
    if (0 <= i && i <= 127)
    {
        c = static_cast<char>(i);
        if (c > 32 && c <= 127)
            std::cout << "char: '" << c << "'" << std::endl;
        else
            std::cout << "char: Non displayable" << std::endl;
    }
    else
    {
        c = '\0';
        std::cout << "char: impossible" << std::endl;
        return ;
    }
    char_to_int = static_cast<int>(c);
    std::cout << "int: " << char_to_int << std::endl;
    char_to_float = static_cast<float>(c);
    std::cout << "float: " << char_to_float << ".0f" << std::endl;
    char_to_double = static_cast<double>(c);
    std::cout << "double: " << char_to_double << ".0" << std::endl;

}

bool    ScalarConverter::isChar(std::string arg)
{
    //std::cout << "i'm char" << std::endl;
    if (arg.length() == 1 && !(isdigit(arg[0])))
        return (true);
    else
        return (false);
}

void    ScalarConverter::doDouble(std::string arg)
{
    double d;
    char double_to_char;
    int double_to_int;
    float double_to_float;

    try
    {
        d = stod(arg);
        if (0 <= d && d <= 127)
        {
            double_to_char = static_cast<char>(d);
            if (d > 32 && d <= 127)
                std::cout << "char: '" << double_to_char << "'" << std::endl;
            else
                std::cout << "char: Non displayable" << std::endl;
        }
        else
            std::cout << "char: impossible" << std::endl;
        if (MIN_INT <= d && d <= MAX_INT)
        {
            double_to_int = static_cast<int>(d);
            std::cout << "int: " << double_to_int << std::endl;
        }
        else
            std::cout << "int: impossible" << std::endl;
        double_to_float = static_cast<float>(d);
        std::cout << std::fixed << std::setprecision(1) << "float: " << double_to_float << "f" << std::endl;
        d = static_cast<double>(d);
        std::cout << std::fixed << std::setprecision(1) << "double: " << d << std::endl;
    }
    catch(const std::out_of_range& e)
    {
        std::cout << "char: impossible" << std::endl;
        std::cout << "int: impossible" << std::endl;
        std::cout << "float: impossible" << std::endl;
        std::cout << "double: impossible" << std::endl;
    }
}

bool    ScalarConverter::isDouble(std::string arg)
{
    //std::cout << "i'm double" << std::endl;
    if (arg.compare("nan") == 0 || arg.compare("-inf") == 0 || arg.compare("+inf") == 0 || arg.compare("inf") == 0)
        return (true);
    else if (arg.find('.') != std::string::npos && arg.find('f') == std::string::npos)
        return (true);
    else
        return (false);
}

void    ScalarConverter::convert(char *literal)
{
    std::string arg;

    arg.assign(literal);
    if (isChar(arg) == true)
    {
        doChar(arg);
        return ;
    }
    else if (isInt(arg) == true)
    {
        doInt(arg);
        return ;
    }
    else if (isFloat(arg) == true)
    {
        doFloat(arg);
        return ;
    }
    else if (isDouble(arg) == true)
    {
        doDouble(arg);
        return ;
    }
    else
        std::cout << "Impossible to convert this input" << std::endl;
}