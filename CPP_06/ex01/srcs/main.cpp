/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcros <gcros@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/09 17:18:24 by gcros             #+#    #+#             */
/*   Updated: 2025/03/09 17:31:33 by gcros            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Serializer.hpp"
#include <iostream>

int main()
{
	Data		data;
	uintptr_t	ptr;
	Data		*data_ptr;

	data.value = 1;
	ptr = Serializer::serialize(&data);
	data_ptr = Serializer::deserialize(ptr);
	std::cout << "ptr = " << ptr << std::endl;
	std::cout << "&data = " << &data << std::endl;
	std::cout << "&data == data_ptr = " << (&data == data_ptr) << std::endl;
	std::cout << "value = " << data_ptr->value << std::endl;
	return 0;
}
