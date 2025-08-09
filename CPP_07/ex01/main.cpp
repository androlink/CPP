/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcros <gcros@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/16 23:42:13 by gcros             #+#    #+#             */
/*   Updated: 2025/05/09 13:52:10 by gcros            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "iter.hpp"
#include <iostream>

template<typename T>
void print(const T &value)
{
	std::cout << value << ", ";
}

void increment(int &value)
{
	value++;
}

void basic_test();
void const_test();

void print_args_test(int ac, const char *av[]);

int	main(int ac, const char *av[])
{
	print_args_test(ac, av);
	basic_test();
	const_test();
} 

void print_args_test(int ac, const char *av[])
{
	::iter(av, ac, print);
	std::cout << std::endl;
}

void basic_test()
{
	int array[10] = {-1, 0, 1, 2, 3, 4, 5, 6, 7, 8};

	::iter(array, 10, &increment);
	::iter(array, 10, print);
	std::cout << std::endl;
}

void const_test()
{
	const int array[10] = {-1, 0, 1, 2, 3, 4, 5, 6, 7, 8};

	//::iter(array, 10, &increment); // don't compile
	::iter(array, 10, print);
	std::cout << std::endl;
}
