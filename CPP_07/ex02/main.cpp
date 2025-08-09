/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcros <gcros@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/21 22:11:14 by gcros             #+#    #+#             */
/*   Updated: 2025/05/09 14:30:27 by gcros            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Array.hpp"

#include <ctime>
#include <iostream>
#include <cstdlib>

int basic_test();

#define MAX_VAL 750

int main(int, char**)
{
	basic_test();
    return 0;
}

int basic_test()
{
	Array<int> numbers(MAX_VAL);
	int* mirror = new int[MAX_VAL];
	srand(time(NULL));
	for (int i = 0; i < MAX_VAL; i++)
	{
	    const int value = rand();
	    numbers[i] = value;
	    mirror[i] = value;
	}
	//SCOPE
	{
	    Array<int> tmp = numbers;
	    Array<int> test(tmp);
	}
    
	for (int i = 0; i < MAX_VAL; i++)
	{
	    if (mirror[i] != numbers[i])
	    {
		std::cerr << "didn't save the same value!!" << std::endl;
		return 1;
	    }
	}
	try
	{
	    numbers[-2] = 0;
	}
	catch(const std::exception& e)
	{
	    std::cerr << e.what() << '\n';
	}
	try
	{
	    numbers[MAX_VAL] = 0;
	}
	catch(const std::exception& e)
	{
	    std::cerr << e.what() << '\n';
	}
    
	for (int i = 0; i < MAX_VAL; i++)
	{
	    numbers[i] = rand();
	}
	delete [] mirror;//
	return (0);
}
