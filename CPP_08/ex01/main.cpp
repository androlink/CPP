#include "Span.hpp"
#include "cstdlib"
#include <deque>
#include <iostream>
#include <sys/time.h>

void basic_test();
void copy_test();
void short_test();
void long_test();
void many_value(unsigned int size);
void exception_test();

int main()
{
	srand(time(NULL));
	basic_test();
	copy_test();
	short_test();
	long_test();
	many_value(100);
	many_value(10000);
	many_value(10000000);
	exception_test();
}

void many_value(unsigned int size)
{
	std::cout << "---\n\t" << "many_value" << std::endl;
	Span span(size);
	std::deque<int> tmp;
	// std::vector<int> tmp;

	for (unsigned int i = 0; i < size; i++) {
		tmp.push_back(rand() % (size * 10));
	}
	span.addManyNumbers(tmp.begin(), tmp.end());
	std::cout << "insert " << tmp.size() << " values" << std::endl;
	if (size < 1000)
		span.print();
	std::cout << "shortest: " << span.shortestSpan() << std::endl;
	std::cout << "longest: " << span.longestSpan() << std::endl;
}

void short_test()
{
	std::cout << "---\n\t" << "short_test" << std::endl;
	Span span(10);

	for (int i = 0; i < 10; i++) {
		span.addNumber(rand() % 100);
	}
	span.print();
	std::cout << "shortest: " << span.shortestSpan() << std::endl;
}

void long_test()
{
	std::cout << "---\n\t" << "long_test" << std::endl;
	Span span(10);

	for (int i = 0; i < 10; i++) {
		span.addNumber(rand() % 100);
	}
	span.print();
	std::cout << "longest: " << span.longestSpan() << std::endl;
}

void copy_test()
{
	std::cout << "---\n\t" << "copy_test" << std::endl;
	Span test(10);
	Span copy(10);

	for (int i = 0; i < 8; i++) {
		test.addNumber(i);
	}
	test.print();
	copy = test;
	test.addNumber(4);
	copy.print();
}

void basic_test()
{
	std::cout << "---\n\t" << "basic_test" << std::endl;
	Span sp = Span(5);

	sp.addNumber(6);
	sp.addNumber(3);
	sp.addNumber(17);
	sp.addNumber(9);
	sp.addNumber(11);

	sp.print();
	std::cout << sp.shortestSpan() << std::endl;
	std::cout << sp.longestSpan() << std::endl;
}

void exception_test()
{
	std::cout << "---\n\t" << "exception_test" << std::endl;
	try {
		Span s(1);
		s.addNumber(1);
		s.addNumber(1);
	} catch (std::exception &e) {
		std::cout << e.what() << std::endl;
	}
	try {
		Span s(1);
		s.addNumber(1);
		s.longestSpan();
	} catch (std::exception &e) {
		std::cout << e.what() << std::endl;
	}
	try {
		Span s(1);
		s.addNumber(1);
		s.shortestSpan();
	} catch (std::exception &e) {
		std::cout << e.what() << std::endl;
	}
	try {
		Span s(2);
		s.addNumber(1);
		std::vector<int> a(2);
		s.addManyNumbers(a.begin(), a.end());
	} catch (std::exception &e) {
		std::cout << e.what() << std::endl;
	}
}
