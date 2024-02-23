/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vpolojie <vpolojie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/14 10:32:55 by vpolojie          #+#    #+#             */
/*   Updated: 2024/01/18 14:00:55 by vpolojie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCALARCONVERTER_HPP
#define SCALARCONVERTER_HPP
#define MAX_INT 2147483647
#define MIN_INT -2147483648
#define MAX_DOUBLE 179769313486231570814527423731704356798070567525844996598917476803157260780028538760589558632766878171540458953514382464234321326889464182768467546703537516986049910576551282076245490090389328944075868508455133942304583236903222948165808559332123348274797826204144723168738177180919299881250404026184124858368.0000000000000000
#define MIN_DOUBLE -179769313486231570814527423731704356798070567525844996598917476803157260780028538760589558632766878171540458953514382464234321326889464182768467546703537516986049910576551282076245490090389328944075868508455133942304583236903222948165808559332123348274797826204144723168738177180919299881250404026184124858368.0000000000000000
#define MAX_FLOAT 340282346638528859811704183484516925440.0000000000000000
#define MIN_FLOAT -340282346638528859811704183484516925440.0000000000000000
#define MIN_CHAR 33
#define MAX_CHAR 127
#include <string>

class ScalarConverter
{
  private:
    ScalarConverter();
    ScalarConverter(ScalarConverter const &_copy);
    ScalarConverter &operator=(ScalarConverter const &_OpCopy);
    ~ScalarConverter();
  public:
    static void convert(char *literal);
    static bool  isInt(std::string arg);
    static void  doInt(std::string arg);
    static bool  isFloat(std::string arg);
    static void  doFloat(std::string arg);
    static bool  isChar(std::string arg);
    static void  doChar(std::string arg);
    static bool  isDouble(std::string arg);
    static void  doDouble(std::string arg);
};

#endif