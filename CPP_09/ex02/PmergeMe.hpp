#ifndef PMERGEME_HPP
#define PMERGEME_HPP

#include <cstdlib>
#include <ctime>
#include <deque>
#include <vector>

#ifndef DEBUG
#define DEBUG 0
#endif

class Timer
{
	std::clock_t m_start;
	std::clock_t m_stop;

public:
	Timer();
	Timer(const Timer &t);
	~Timer();
	Timer &operator=(const Timer &);
	double operator()();
	void start();
	void stop();
	double diff();
};

typedef size_t val_type;
typedef std::vector<val_type> container_type;

template <typename CONTAINER_TYPE>
void print_values(const CONTAINER_TYPE &values, size_t limit = 5);

template <typename CONTAINER_TYPE>
bool parse(CONTAINER_TYPE &value, int ac, char **av);

int run(int ac, char **av);

size_t jacobsthal_number(size_t index);

bool is_number(const char *value);

#include <PmergeMe.tpp>

#endif
