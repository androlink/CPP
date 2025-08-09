/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcros <gcros@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/21 22:12:45 by gcros             #+#    #+#             */
/*   Updated: 2025/03/21 22:38:10 by gcros            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ARRAY_HPP
#define ARRAY_HPP

#include <exception>
#include <cstddef>
#include <stdexcept>

template<typename T>
class Array
{
	private:
	T*	data;
	std::size_t	lenght;
	
	public:
	Array()
	{
		lenght = 0;
		data = new T[0]();
	}

	Array(int n)
	{
		lenght = n;
		data = new T[n]();
	}

	Array(const Array &rp)
	{
		lenght = rp.lenght;
		data = new T[lenght]();
		for (std::size_t i = 0; i < lenght; i++)
			data[i] = rp.data[i];
	}

	Array &operator=(const Array &rp)
	{
		if (this == &rp)
			return (*this);
		lenght = rp.lenght;
		delete[] data;
		data = new T[lenght]();
		for (std::size_t i = 0; i < lenght; i++)
			data[i] = rp.data[i];
		return (*this);
	}

	T& operator[](std::size_t i)
	{
		if (i >= lenght)
			throw std::out_of_range("index out of range\a");
		return (data[i]);
	}

	~Array()
	{
		delete[] data;
	}

	std::size_t size() { return lenght;}
};

#endif