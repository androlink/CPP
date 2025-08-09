/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcros <gcros@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/20 15:14:37 by gcros             #+#    #+#             */
/*   Updated: 2025/03/09 16:41:24 by gcros            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ScalarConverter.hpp"
#include "../includes/utils.hpp"
#include <cstdlib>
#include <iostream>

ScalarConverter::ScalarConverter(){}
ScalarConverter::ScalarConverter(const ScalarConverter &){};
ScalarConverter::~ScalarConverter(){};
ScalarConverter &ScalarConverter::operator=(const ScalarConverter &) {return (*this);};

void ScalarConverter::convert(std::string str_value)
{
	double	d_value = 0.;
	if (is_double(str_value) || is_float(str_value))
		d_value = std::strtod(str_value.c_str(), NULL);
	else if (is_int(str_value))
		d_value = static_cast<double>(std::strtol(str_value.c_str(), NULL, 10));
	else if (is_char(str_value))
		d_value = static_cast<double>(str_value.c_str()[0]);
	else
	{
		std::cout << "not a convertible value" << std::endl;
		return ;
	}
	print_result(d_value);
}