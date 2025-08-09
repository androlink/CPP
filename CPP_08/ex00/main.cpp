
#include <iostream>
#include <list>
#include <vector>

#include "easyfind.hpp"

void vector_test();
void list_test();
void out_of_range_test();
void const_test();

int main()
{
	vector_test();
	list_test();
	out_of_range_test();
	const_test();
}

void vector_test()
try {
	std::cout << "---\n\t" << "vector_test" << std::endl;
	int v[] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
	std::vector<int> t(v, v + 10);
	std::cout << easyfind(t, 5) << std::endl;
} catch (std::exception &e) {
	std::cout << e.what() << std::endl;
}

void const_test()
try {
	std::cout << "---\n\t" << "const_test" << std::endl;
	int v[] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
	std::vector<int> const_t(v, v + 10);
	std::cout << easyfind(const_t, 5) << std::endl;
} catch (std::exception &e) {
	std::cout << e.what() << std::endl;
}

void list_test()
try {
	std::cout << "---\n\t" << "list_test" << std::endl;
	int v[] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
	std::vector<int> t(v, v + 10);
	std::cout << easyfind(t, 5) << std::endl;
} catch (std::exception &e) {
	std::cout << e.what() << std::endl;
}

void out_of_range_test()
try {
	std::cout << "---\n\t" << "out_of_range_test" << std::endl;
	int v[] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
	std::vector<int> t(v, v + 10);
	std::cout << easyfind(t, 20) << std::endl;
} catch (std::exception &e) {
	std::cout << e.what() << std::endl;
}
