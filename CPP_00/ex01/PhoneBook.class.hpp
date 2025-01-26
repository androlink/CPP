/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.class.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcros <gcros@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/21 17:40:33 by gcros             #+#    #+#             */
/*   Updated: 2024/08/14 13:57:58 by gcros            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_CLASS_HPP
# define PHONEBOOK_CLASS_HPP

# include "Contact.class.hpp"

class PhoneBook
{

	public:
		PhoneBook(void);
		int	add();
		int	search();
		~PhoneBook(void);

	private:
		Contact	contacts[8];
		int		contactnumber;
		Contact	createContact();
		void	removeFirst();
		void	printContacts();

};

#endif