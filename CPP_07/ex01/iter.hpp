/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iter.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcros <gcros@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/16 23:41:49 by gcros             #+#    #+#             */
/*   Updated: 2025/03/16 23:56:55 by gcros            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ITER_HPP
#define ITER_HPP

#include <cstddef>

template<typename T>
void	iter(T* array, size_t lenght, void (*f)(T &value))
{
	for (size_t i = 0; i < lenght; i++)
		f(array[i]);
}

template<typename T>
void	iter(const T* array, size_t lenght, void (*f)(const T &value))
{
	for (size_t i = 0; i < lenght; i++)
		f(array[i]);
}

#endif