#ifndef SPAN_HPP
#define SPAN_HPP

#include <stdexcept>
#include <vector>

class Span
{
private:
	Span();
	unsigned int m_maxSize;
	std::vector<int> m_data;
	bool m_sorted;

public:
	Span(const Span &rp);
	Span(unsigned int length);
	Span &operator=(const Span &rp);
	~Span();

	void addNumber(int value);
	template <typename CONT_TYPE>
	void addManyNumbers(CONT_TYPE begin, CONT_TYPE end)
	{
		if (m_data.size() + (end - begin) > m_maxSize) {
			throw(std::out_of_range("addManyNumbers: cannot insert values"));
		}
		m_data.insert(m_data.end(), begin, end);
		m_sorted = false;
	}

	unsigned int shortestSpan();
	unsigned int longestSpan();

	void print() const;
};

#endif