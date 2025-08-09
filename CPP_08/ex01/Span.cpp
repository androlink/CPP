#include "Span.hpp"
#include <iostream>
#include <stdexcept>

#include <algorithm>

Span::Span(unsigned int size)
{
	m_maxSize = size;
	m_sorted = true;
}

Span::~Span()
{
}

Span &Span::operator=(const Span &rp)
{
	if (this != &rp) {
		m_data = rp.m_data;
		m_maxSize = rp.m_maxSize;
		m_sorted = rp.m_sorted;
	}
	return (*this);
}

void Span::addNumber(int value)
{
	if (m_data.size() == m_maxSize)
		throw(std::out_of_range("addNumber: cannot insert value"));
	this->m_data.push_back(value);
	m_sorted = false;
}

unsigned int Span::shortestSpan()
{
	if (m_data.size() < 2)
		throw(std::out_of_range("shortestSpan: not enought number"));
	if (m_sorted == false) {
		std::sort(m_data.begin(), m_data.end());
		m_sorted = true;
	}

	std::vector<int>::const_iterator it = m_data.begin();
	std::vector<int>::const_iterator end = m_data.end();

	unsigned int max = *(it + 1) - *it;
	for (; it + 1 != end; it++)
		if (static_cast<unsigned int>(*(it + 1) - *it) < max)
			max = *(it + 1) - *it;
	return max;
}

unsigned int Span::longestSpan()
{
	if (m_data.size() < 2)
		throw(std::out_of_range("longestSpan: not enought number"));
	if (m_sorted == false) {
		std::sort(m_data.begin(), m_data.end());
		m_sorted = true;
	}
	return *m_data.rbegin() - *m_data.begin();
}

Span::Span(const Span &rp)
{
	m_maxSize = rp.m_maxSize;
	m_data = rp.m_data;
	m_sorted = rp.m_sorted;
}

void Span::print() const
{
	if (m_data.size() == 0) {
		std::cout << std::endl;
		return;
	}
	std::vector<int>::const_iterator it = m_data.begin();
	std::vector<int>::const_iterator end = m_data.end();
	for (; it + 1 != end; it++)
		std::cout << *it << ", ";
	std::cout << *it << std::endl;
}
