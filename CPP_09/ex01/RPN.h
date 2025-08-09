#ifndef RPN_H
#define RPN_H

#include <string>

struct rpn_error
{
	rpn_error(const std::string &str) : str(str)
	{
	}
	std::string str;
};

#endif