/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcros <gcros@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/20 15:13:40 by gcros             #+#    #+#             */
/*   Updated: 2025/04/28 16:07:22 by gcros            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCALARCONVERTER_HPP
# define SCALARCONVERTER_HPP

# include <string>

class ScalarConverter
{
	public: 
	static void	convert(std::string value);
	
	private:
	ScalarConverter();
	ScalarConverter(const ScalarConverter &);
	~ScalarConverter();
	ScalarConverter &operator=(const ScalarConverter &);
};

#endif