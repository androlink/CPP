#ifndef EASYFIND_TPP
#define EASYFIND_TPP

#include "easyfind.hpp"
#include <algorithm>

template <typename T>
int &easyfind(T &cont, int n)
{
	typename T::iterator it = cont.begin();
	typename T::iterator end = cont.end();
	typename T::iterator f_it = std::find(it, end, n);
	if (f_it == end)
		throw(std::out_of_range("value not found, please try later."));
	return (*f_it);
}

template <typename T>
const int &easyfind(const T &cont, int n)
{
	typename T::const_iterator it = cont.begin();
	typename T::const_iterator end = cont.end();
	typename T::const_iterator f_it = std::find(it, end, n);
	if (f_it == end)
		throw(std::out_of_range("value not found, please try later."));
	return (*f_it);
}

#endif