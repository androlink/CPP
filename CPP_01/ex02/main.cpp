/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcros <gcros@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/10 15:10:20 by gcros             #+#    #+#             */
/*   Updated: 2024/07/13 17:59:26 by gcros            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string>
#include <iostream>

int	main()
{
	std::string stringVar = "HI THIS IS BRAIN";
	std::string *stringPtr = &stringVar;
	std::string &stringRef = stringVar;

	std::cout << "string value: " << &stringVar << std::endl;
	std::cout << "string ptr: " << stringPtr << std::endl;
	std::cout << "string ref: " << &stringRef << std::endl;

	std::cout << "string value: " << stringVar << std::endl;
	std::cout << "string ptr: " << *stringPtr << std::endl;
	std::cout << "string ref: " << stringRef << std::endl;
}
