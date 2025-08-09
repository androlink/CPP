/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcros <gcros@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/09 17:18:24 by gcros             #+#    #+#             */
/*   Updated: 2025/03/09 19:48:19 by gcros            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "../includes/Base.hpp"
#include "../includes/A.hpp"
#include "../includes/B.hpp"
#include "../includes/C.hpp"
#include <ctime>
#include <cstdlib>

Base *generate();
void identify(Base* p);
void identify(Base& p);
void test();

int main()
{
	srand(time(NULL));
	for (int i = 0; i < 100; i++)
		test();
	return 0;
}

void test()
{
	std::cout << "---test---" << std::endl;
	Base * base = generate();
	try
	{
		identify(base);
		identify(*base);
	}catch(...) {}
	delete base;
}

Base *generate()
{
	switch (rand() % 3)
	{
		case 0:
			std::cout << "generate A" << std::endl;
			return (new A());
		case 1:
			std::cout << "generate B" << std::endl;
			return (new B());
		case 2:
			std::cout << "generate C" << std::endl;
			return (new C());
		default:
			break ;
	}
	std::cout << "[/\\]generate Base" << std::endl;
	return (new Base());
}

void identify(Base* p)
{
	if (dynamic_cast<A*>(p) != NULL)
		std::cout << "identify A ptr" << std::endl;
	else if (dynamic_cast<B*>(p) != NULL)
		std::cout << "identify B ptr" << std::endl;
	
	else if (dynamic_cast<C*>(p) != NULL)
		std::cout << "identify C ptr" << std::endl;
	else
		std::cout << "[/\\]identify not convertible ptr" << std::endl;
}

void identify(Base& p)
{
	try
	{
		(void) dynamic_cast<A&>(p);
		std::cout << "identify A ref" << std::endl;
		return ;
	}
	catch(...) {}
	try
	{
		(void) dynamic_cast<B&>(p);
		std::cout << "identify B ref" << std::endl;
		return ;
	}
	catch(...) {}
	try
	{
		(void) dynamic_cast<C&>(p);
		std::cout << "identify C ref" << std::endl;
		return ;
	}
	catch (...) {}
	std::cout << "[/\\]identify not convertible ref" << std::endl;
}
