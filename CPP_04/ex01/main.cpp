/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcros <gcros@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/29 13:23:55 by gcros             #+#    #+#             */
/*   Updated: 2024/12/03 15:09:38 by gcros            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"
#include <string>

void	defaultTest()
{
	std::cout << "/*	defaultTest	*/" << std::endl;
	const Animal* j = new Dog();
	const Animal* i = new Cat();
	delete j;//should not create a leak
	delete i;
}

void	allocTest()
{
	std::cout << "/*	allocTest	*/" << std::endl;
	Animal *animals[100];
	for (int i = 0; i < 100; i++)
		if (i < 50)
			animals[i] = new Dog();
		else
			animals[i] = new Cat();

	for (int i = 0; i < 100; i++)
		delete animals[i];
}

void	copyCat()
{
	std::cout << "/*	copyCat	*/" << std::endl;
	Cat *c1 = new Cat();
	const Cat *c2 = new Cat(*c1);

	std::cout << "c1 " << c1->getBrain()->getIdeaAt(0) << std::endl;
	std::cout << "c2 " << c2->getBrain()->getIdeaAt(0) << std::endl;

	{
		Cat *c3 = new Cat();

		c3->getBrain()->setIdeaAt("destroy the world", 0);

		std::cout << "c1 " << c1->getBrain()->getIdeaAt(0) << std::endl;
		std::cout << "c3 " << c3->getBrain()->getIdeaAt(0) << std::endl;
		delete c1;
		c1 = new Cat(*c3);
		delete c3;
	}
	std::cout << "c1 " << c1->getBrain()->getIdeaAt(1) << std::endl;
		delete c1;
		delete c2;
}

void	copyDog()
{
	std::cout << "/*	copyDog	*/" << std::endl;
	Dog *c1 = new Dog();
	const Dog *c2 = new Dog(*c1);

	std::cout << "c1 " << c1->getBrain()->getIdeaAt(0) << std::endl;
	std::cout << "c2 " << c2->getBrain()->getIdeaAt(0) << std::endl;

	{
		Dog *c3 = new Dog();

		c3->getBrain()->setIdeaAt("destroy the world", 0);

		std::cout << "c1 " << c1->getBrain()->getIdeaAt(0) << std::endl;
		std::cout << "c3 " << c3->getBrain()->getIdeaAt(0) << std::endl;
		delete c1;
		c1 = new Dog(*c3);
		delete c3;
	}
	std::cout << "c1 " << c1->getBrain()->getIdeaAt(1) << std::endl;
		delete c1;
		delete c2;
}

void fullIdea()
{
	std::cout << "/*	fullIdea	*/" << std::endl;
	Cat	*cat = new Cat();
	Brain *brain;

	brain = cat->getBrain();
	for (int i = 0; i < 200; i++)
		brain->setIdeaAt("new idea", i);
	delete cat;
}

int main()
{
	defaultTest();
	allocTest();
	copyCat();
	copyDog();
	fullIdea();
	return 0;
}
