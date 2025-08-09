/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcros <gcros@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/05 18:36:46 by gcros             #+#    #+#             */
/*   Updated: 2025/03/11 17:59:58 by gcros            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string>
#include <cmath>
#include <iostream>
#include <climits>

bool	is_char(const std::string &value)
{
	if (value.size() != 1)
		return (false);
	return (true);
}

bool	is_float(const std::string &value)
{
	const char* s_ptr = value.c_str();
	bool	has_number = false;

	if (*s_ptr == '+' || *s_ptr == '-')
		s_ptr++;
	if (*s_ptr >= '0' && *s_ptr <= '9')
		has_number = true;
	while (*s_ptr >= '0' && *s_ptr <= '9')
		s_ptr++;
	
	if (*s_ptr == '.')
		s_ptr++;
	else
		return (false);
	
	if (*s_ptr >= '0' && *s_ptr <= '9')
		has_number = true;
	while (*s_ptr >= '0' && *s_ptr <= '9')
		s_ptr++;
	
	if (has_number && s_ptr[0] == 'f' && s_ptr[1] == '\0')
		return (true);
	return (false);
}

bool	is_double(const std::string &value)
{
	const char* s_ptr = value.c_str();
	bool	has_number = false;

	if (*s_ptr == '+' || *s_ptr == '-')
		s_ptr++;

	if (*s_ptr >= '0' && *s_ptr <= '9')
		has_number = true;
	while (*s_ptr >= '0' && *s_ptr <= '9')
		s_ptr++;
	
	if (*s_ptr == '.')
		s_ptr++;
	else
		return (false);

	if (*s_ptr >= '0' && *s_ptr <= '9')
		has_number = true;
	while (*s_ptr >= '0' && *s_ptr <= '9')
		s_ptr++;
	return (has_number && *s_ptr == '\0');
}

bool	is_int(const std::string &value)
{
	const char* s_ptr = value.c_str();
	bool	has_number = false;

	if (*s_ptr == '+' || *s_ptr == '-')
		s_ptr++;

	if (*s_ptr >= '0' && *s_ptr <= '9')
		has_number = true;
	while (*s_ptr >= '0' && *s_ptr <= '9')
		s_ptr++;

	return (has_number && *s_ptr == '\0');
}

static void print_char(double value)
{
	if (std::isinf(value) || std::isnan(value) || value < 0 || value > 127)
	{
		std::cout << "char: impossible" << std::endl;
		return ;
	}
	char c_value = static_cast<char>(value);
	if (!isprint(c_value))
	{
		std::cout << "char: not displayable" << std::endl;
		return ;
	}
	std::cout << "char: " << c_value << std::endl;
}

static void print_int(double value)
{
	if (std::isinf(value) || std::isnan(value))
	{
		std::cout << "int: impossible" << std::endl;
		return ;
	}
	if (value > INT_MAX || value < INT_MIN)
	{
		std::cout << "int: not displayable" << std::endl;
		return ;
	}
	int i_value = static_cast<int>(value);
	std::cout << "int: " << i_value << std::endl;
}

static void	print_float(double value)
{
	std::cout << "float: ";
	std::cout << static_cast<float>(value);
	if (!(std::isinf(value) || std::isnan(value) || std::abs(value) >= 1000000)
		&& std::floor(value) == value)
		std::cout << ".0";
	std::cout << "f" << std::endl;
}

static void	print_double(double value)
{
	std::cout << "double: ";
	std::cout << static_cast<float>(value);
	if (!(std::isinf(value) || std::isnan(value) || std::abs(value) >= 1000000)
		&& std::floor(value) == value)
		std::cout << ".0";
	std::cout << std::endl;
}

void	print_result(double value)
{
	print_char(value);
	print_int(value);
	print_float(value);
	print_double(value);
}
