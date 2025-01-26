/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.class.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcros <gcros@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/21 17:40:41 by gcros             #+#    #+#             */
/*   Updated: 2024/06/18 21:06:46 by gcros            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.class.hpp"
#include <iomanip>
#include <iostream>

PhoneBook::PhoneBook(void)
{
	this->contactnumber = 0;
}

int	PhoneBook::add()
{
	Contact new_contact = this->createContact();
	if (!new_contact.is_valide())
	{
		std::cout << "bad input" << std::endl;
		return (0);
	}
	std::cout << "Contact created" << std::endl;
	if (this->contactnumber == 8)
		this->removeFirst();
	this->contacts[this->contactnumber] = new_contact;
	this->contactnumber++;
	std::cout << "contact added" << std::endl;
	return (1);
}

void	PhoneBook::removeFirst()
{
	for (int i = 1; i < 8; i++)
		this->contacts[i - 1] = this->contacts[i];
	this->contactnumber--;
}

void	PhoneBook::printContacts()
{
	for (int i = 0; i < this->contactnumber; i++)
	{
		std::cout << std::setw(10) << i << "|";
		if (this->contacts[i].getFirstname().size() < 10)
			std::cout << std::setw(10) << this->contacts[i].getFirstname() << "|";
		else
			std::cout << std::setw(10) << this->contacts[i].getFirstname().replace(9, 2, ".").substr(0, 10) << "|";
		if (this->contacts[i].getLastname().size() < 10)
			std::cout << std::setw(10) << this->contacts[i].getLastname() << "|";
		else
			std::cout << std::setw(10) << this->contacts[i].getLastname().replace(9, 2, ".").substr(0, 10) << "|";
		if (this->contacts[i].getNickname().size() < 10)
			std::cout << std::setw(10) << this->contacts[i].getNickname() << "|";
		else
			std::cout << std::setw(10) << this->contacts[i].getNickname().replace(9, 2, ".").substr(0, 10) << "|";
		std::cout << std::endl;
	}
}

int	is_valide(std::string num)
{
	if (num.size() != 1)
		return (0);
	return (num.at(0) >= '0' && num.at(0) <= '8');
}

int	PhoneBook::search()
{
	std::string	line;

	printContacts();
	std::cout << "type index of your choice : " << std::flush;
	std::getline(std::cin, line);

	if (!is_valide(line) || line.at(0) - '0' >= this->contactnumber)
	{
		std::cout << "bad index" << std::endl;
		return (1);
	}
	contacts[line.at(0) - '0'].print();
	return (0);
}

PhoneBook::~PhoneBook(void)
{
}

Contact	PhoneBook::createContact()
{
	std::string	firstname;
	std::string	lastname;
	std::string	nickname;
	std::string	phonenumber;
	std::string	secret;

	std::cout << "create a new contact" << std::endl;
	{
		std::cout << "enter fist name : " << std::flush;
		std::getline(std::cin, firstname);
		if (firstname.size() == 0)
			return (Contact());
	}
	{
		std::cout << "enter last name : " << std::flush;
		std::getline(std::cin, lastname);
		if (lastname.size() == 0)
			return (Contact());
	}
	{
		std::cout << "enter nickname : " << std::flush;
		std::getline(std::cin, nickname);
		if (nickname.size() == 0)
			return (Contact());
	}
	{
		std::cout << "enter phone number : " << std::flush;
		std::getline(std::cin, phonenumber);
		if (phonenumber.size() == 0)
			return (Contact());
	}
	{
		std::cout << "enter secret : " << std::flush;
		std::getline(std::cin, secret);
		if (secret.size() == 0)
			return (Contact());
	}
	return (Contact(firstname, lastname, nickname, phonenumber, secret));
}