#include "PmergeMe.hpp"
#include <deque>
#include <vector>

int run(int ac, char **av)
{
	Timer vec_time, dq_time;
	std::deque<val_type> dq_values;
	std::vector<val_type> vec_values;
	std::deque<val_type> ref_val;

	if (!parse(ref_val, ac, av)) {
		std::cout << "Error: parsing error." << std::endl;
	}
	print_values(ref_val, 5);
	std::sort(ref_val.begin(), ref_val.end());
	print_values(ref_val, 5);
	{
		dq_time.start();
		parse(dq_values, ac, av);
		merge_insert_sort(dq_values);
		dq_time.stop();
		vec_time.start();
		parse(vec_values, ac, av);
		merge_insert_sort(vec_values);
		vec_time.stop();
	}
	const std::string units[] = {"s", "ms", "µs"};
	const double factor[] = {1, 1000, 1000000};
	size_t i = 0;
	while (i < 3) {
		if (dq_time() * factor[i] > 1 || vec_time() * factor[i] > 1)
			break;
		i++;
	}
	std::cout << "Time to process a range of " << ref_val.size() << " elements with std::deque : ";
	std::cout << dq_time() * factor[i] << units[i] << std::endl;
	std::cout << "Time to process a range of " << ref_val.size() << " elements with std::vector : ";
	std::cout << vec_time() * factor[i] << units[i] << std::endl;
	if (!is_sorted(dq_values))
		std::cout << "Error: fail to sort deque" << std::endl;
	if (!is_sorted(vec_values))
		std::cout << "Error: fail to sort vector" << std::endl;
	return (!is_sorted(dq_values) || !is_sorted(vec_values));
}

size_t jacobsthal_number(size_t index)
{
	return (((2 << (index + 1)) + ((((index) & 1) << 1) - 1)) / 3);
}

Timer::Timer()
{
}

Timer::Timer(const Timer &t)
{
	m_start = t.m_start;
	m_stop = t.m_stop;
}

Timer::~Timer()
{
}

Timer &Timer::operator=(const Timer &t)
{
	m_start = t.m_start;
	m_stop = t.m_stop;
	return *this;
}

double Timer::operator()()
{

	return diff();
}

void Timer::start()
{
	this->m_start = std::clock();
}

void Timer::stop()
{
	this->m_stop = std::clock();
}

double Timer::diff()
{
	return (m_stop - m_start) / (double)CLOCKS_PER_SEC;
}

bool is_number(const char *value)
{
	if (value[0] == 0)
		return false;
	for (size_t i = 0; value[i] != 0; i++)
		if (value[i] < '0' || value[i] > '9')
			return false;
	return true;
}
