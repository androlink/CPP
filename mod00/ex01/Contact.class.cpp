/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.class.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcros <gcros@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/21 17:40:39 by gcros             #+#    #+#             */
/*   Updated: 2024/06/18 20:47:39 by gcros            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.class.hpp"
#include <iostream>

Contact::Contact(void)
{
}
Contact::Contact(
	std::string firstname,
	std::string lastname,
	std::string nickname,
	std::string phonenumber,
	std::string secret):
	firstname(firstname),
	lastname(lastname),
	nickname(nickname),
	phonenumber(phonenumber),
	secret(secret)
{
}

void	Contact::print(void)
{
	std::cout << "firstname : " << this->firstname << std::endl;
	std::cout << "lastname : " << this->lastname << std::endl;
	std::cout << "nickname : " << this->nickname << std::endl;
	std::cout << "phonenumber : " << this->phonenumber << std::endl;
	std::cout << "secret : " << this->secret << std::endl;
}

Contact::~Contact(void)
{
}

std::string	Contact::getFirstname(void)
{
	return (this->firstname);
}

std::string	Contact::getLastname(void)
{
	return (this->lastname);
}

std::string	Contact::getNickname(void)
{
	return (this->nickname);
}

std::string	Contact::getPhonenumber(void)
{
return (this->phonenumber);
}

std::string	Contact::getSecret(void)
{
return (this->secret);
}

int	Contact::is_valide(void)
{
	if (this->firstname.size() == 0)
		return (0);
	if (this->lastname.size() == 0)
		return (0);
	if (this->nickname.size() == 0)
		return (0);
	if (this->phonenumber.size() == 0)
		return (0);
	if (this->secret.size() == 0)
		return (0);
	return (1);
}
