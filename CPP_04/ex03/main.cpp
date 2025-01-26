/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcros <gcros@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/30 20:18:39 by gcros             #+#    #+#             */
/*   Updated: 2024/11/13 16:18:04 by gcros            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "IMateriaSource.hpp"
#include "MateriaSource.hpp"
#include "ICharacter.hpp"
#include "Character.hpp"
#include "Ice.hpp"
#include "Cure.hpp"
#include <iostream>

void	basic_test();
void	ref_test();
void	unset_test();

int	main()
{
	basic_test();
	ref_test();
	unset_test();
	return 0;
}

void	unset_test()
{
	std::cout << "unset_test" << std::endl;

	ICharacter* bruce = new Character("bruce");
	ICharacter* me = new Character("me");
	bruce->use(0, *me);
	bruce->use(-1, *me);
	delete me;
	delete bruce;
}

void	ref_test()
{
	std::cout << "ref_test" << std::endl;

	IMateriaSource* src = new MateriaSource();
	src->learnMateria(new Ice());
	src->learnMateria(new Cure());
	
	Character* bruce = new Character("bruce");
	bruce->equip(src->createMateria("cure"));
	ICharacter* bruce_ref = new Character(*bruce);
	bruce_ref->use(0, *bruce);
	bruce->use(0, *bruce_ref);
	delete bruce;
	delete bruce_ref;
	delete src;
}

void	basic_test()
{
	std::cout << "basic test" << std::endl;
	
	IMateriaSource* src = new MateriaSource();
	src->learnMateria(new Ice());
	src->learnMateria(new Cure());
	ICharacter* me = new Character("me");
	AMateria* tmp;
	tmp = src->createMateria("ice");
	me->equip(tmp);
	tmp = src->createMateria("cure");
	me->equip(tmp);
	ICharacter* bob = new Character("bob");
	me->use(0, *bob);
	me->use(1, *bob);
	delete bob;
	delete me;
	delete src;
}
