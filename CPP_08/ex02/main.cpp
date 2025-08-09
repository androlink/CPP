#include "MutantStack.hpp"
#include <iostream>
#include <list>

void basic_test();
void basic_test_list();
void assignation_test();

int main()
{
	basic_test();
	basic_test_list();
	assignation_test();
}

void basic_test()
{
	std::cout << "---\n\t" << "basic_test" << std::endl;
	MutantStack<int> mstack;
	mstack.push(5);
	mstack.push(17);
	std::cout << mstack.top() << std::endl;
	mstack.pop();
	std::cout << mstack.size() << std::endl;
	mstack.push(3);
	mstack.push(5);
	mstack.push(737);
	//[...]
	mstack.push(0);
	MutantStack<int>::iterator it = mstack.begin();
	MutantStack<int>::iterator ite = mstack.end();
	++it;
	--it;
	while (it != ite) {
		std::cout << *it << std::endl;
		++it;
	}
	std::stack<int> s(mstack);
}

void basic_test_list()
{
	std::cout << "---\n\t" << "basic_test_list" << std::endl;
	std::list<int> mstack;
	mstack.push_back(5);
	mstack.push_back(17);
	std::cout << mstack.back() << std::endl;
	mstack.pop_back();
	std::cout << mstack.size() << std::endl;
	mstack.push_back(3);
	mstack.push_back(5);
	mstack.push_back(737);
	//[...]
	mstack.push_back(0);
	std::list<int>::iterator it = mstack.begin();
	std::list<int>::iterator ite = mstack.end();
	++it;
	--it;
	while (it != ite) {
		std::cout << *it << std::endl;
		++it;
	}
}

void assignation_test()
{
	std::cout << "---\n\t" << "assignation_test" << std::endl;

	MutantStack<int> istack;
	{
		MutantStack<int> mstack;
		mstack.push(5);
		mstack.push(17);
		istack = mstack;
	}
	MutantStack<int>::iterator it = istack.begin();
	MutantStack<int>::iterator ite = istack.end();
	while (it != ite) {
		std::cout << *it << std::endl;
		++it;
	}
}
