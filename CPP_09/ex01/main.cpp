#include <RPN.h>
#include <cmath>
#include <iostream>
#include <stack>

// https://www.dcode.fr/reverse-polish-notation

#define COLOR_RED "\e[31;40m"
#define COLOR_GREEN "\e[32;40m"
#define COLOR_BLUE "\e[34;40m"
#define COLOR_DEFAULT "\e[30;37m"

#define DEBUG 0

void do_operation(std::stack<double> &numbers, char op);
void set_next(std::stack<double> &numbers, double value);
double get_next(std::stack<double> &numbers);

int main(int ac, char **av)
try {
	if (ac != 2) {
		std::cout << av[0] << " <operation>" << std::endl;
		return 1;
	}
	std::stack<double> numbers;
	std::string operation(av[1]);
	for (size_t i = 0; i < operation.size(); i++) {
		char &op = operation[i];
		if (op >= '0' && op <= '9')
			set_next(numbers, op - '0');
		else if (op == ' ')
			continue;
		else
			do_operation(numbers, op);
	}
	if (numbers.size() > 1)
		throw rpn_error("Error: missing operator");
	else if (numbers.size() < 1)
		throw rpn_error("Error: no number in stack");
	else
		std::cout << numbers.top() << std::endl;
	return 0;
} catch (const rpn_error &e) {
	std::cout << e.str << std::endl;
	return 2;
}

double get_next(std::stack<double> &numbers)
{
	double n = numbers.top();
#if DEBUG
	std::cout << COLOR_RED << " >> " << n << COLOR_DEFAULT << std::endl;
#endif // DEBUG
	numbers.pop();
	return n;
}

void set_next(std::stack<double> &numbers, double value)
{
	numbers.push(value);
#if DEBUG
	std::cout << COLOR_GREEN << " << " << value << COLOR_DEFAULT << std::endl;
#endif // DEBUG
}

void do_operation(std::stack<double> &numbers, char op)
{
	if (numbers.size() < 2) {
		throw rpn_error("Error: not enough number");
	}
	double n2 = get_next(numbers);
	double n1 = get_next(numbers);
	double res;
#if DEBUG
	std ::cout << COLOR_BLUE << " " << n1 << " " << op << " " << n2 << COLOR_DEFAULT << std::endl;
#endif // DEBUG
	switch (op) {
	case '-':
		res = n1 - n2;
		break;
	case '+':
		res = n1 + n2;
		break;
	case '*':
		res = n1 * n2;
		break;
	case '/':
		if (n2 == 0. || n2 == -0.)
			throw rpn_error("Error: Divide by zero");
		res = n1 / n2;
		break;
	default:
		throw rpn_error(std::string("Error: bad operator: '") + op + "'");
	}
	set_next(numbers, res);
}
