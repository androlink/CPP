#ifndef EASYFIND_HPP
#define EASYFIND_HPP

#include <stdexcept>

template <typename T>
int &easyfind(T &cont, int n);

template <typename T>
const int &easyfind(const T &cont, int n);

#include "easyfind.tpp"

#endif