
#include <algorithm>
#include <cstdlib>
#include <fstream>
#include <iostream>
#include <map>
#include <string>

bool load_data(std::map<std::string, double> &data);
bool isNumber(const std::string &str);
bool is_date(const std::string &str);
std::pair<std::string, double> parseLine(const std::string &line, const std::string &separator);
std::map<std::string, double>::const_iterator getDate(const std::map<std::string, double> &data,
													  const std::string &date);
struct btc_exception
{
	btc_exception(const std::string &str) : _str(str)
	{
	}
	std::string _str;
};

int main(int ac, char **av)
try {
	if (ac != 2) {
		std::cout << "Error: could not open file." << std::endl;
		return 1;
	}
	std::map<std::string, double> data;
	if (load_data(data)) {
		std::cout << "error while parsing" << std::endl;
		return 1;
	}

	std::string line;
	std::ifstream file(av[1]);
	if (!file.is_open()) {
		std::cout << "Error: could not open file." << av[1] << std::endl;
		return 1;
	}
	std::getline(file, line); // ignore first line;
	while (!file.eof()) {
		std::getline(file, line);
		if (file.fail()) {
			std::cout << "Error: file read" << std::endl;
			return 1;
		}
		std::pair<std::string, double> d;
		try {
			d = parseLine(line, " | ");
			if (d.second < 0.)
				throw(btc_exception("not a positive number."));
			if (d.second > 1000.)
				throw(btc_exception("too large number."));
			std::map<std::string, double>::const_iterator it = getDate(data, d.first);
			if (it == data.end()) {
				throw(btc_exception("value not found"));
			}
			std::cout << d.first << " => " << d.second << " = " << it->second * d.second
					  << std::endl;
		} catch (const btc_exception &bpe) {
			std::cout << "Error: " << bpe._str << std::endl;
			continue;
		}
	}
	return 0;
} catch (const std::exception &e) {
	std::cout << e.what() << std::endl;
	return 1;
}

std::map<std::string, double>::const_iterator getDate(const std::map<std::string, double> &data,
													  const std::string &date)
{
	std::map<std::string, double>::const_iterator it = data.find(date);
	if (it != data.end())
		return it;
	it = data.upper_bound(date);
	return it == data.end() ? it : --it;
}

std::pair<std::string, double> parseLine(const std::string &line, const std::string &separator)
{
	size_t l;
	l = line.find(separator);
	if (l == line.npos)
		throw btc_exception("bad input => " + line);
	std::string key = line.substr(0, l);
	std::string str_val = line.substr(l + separator.size());
	if (!is_date(key)) {
		throw btc_exception("bad input => " + key);
	}
	if (!isNumber(str_val)) {
		throw btc_exception("not a number");
	}
	double val = std::strtold(str_val.c_str(), NULL);
	return (std::pair<std::string, double>(key, val));
}

bool load_data(std::map<std::string, double> &data)
{
	std::string line;
	std::ifstream file("data.csv");
	if (!file.is_open())
		return true;
	std::getline(file, line); // ignore first line;
	try {
		while (!file.eof()) {
			std::getline(file, line);
			if (file.eof())
				break;
			if (file.fail()) {
				std::cout << "error: file read" << std::endl;
				return true;
			}
			std::pair<std::string, double> d = parseLine(line, ",");
			if (d.second < 0)
				return true;
			data.insert(d);
		}
	} catch (const btc_exception &) {
		return true;
	}
	return false;
}

bool isNumber(const std::string &str)
{
	size_t i = 0;
	if (str[i] == '+' || str[i] == '-')
		i++;
	for (; i < str.size(); i++) {
		if (str[i] == '.')
			break;
		if (!isdigit(str[i]))
			return false;
	}
	if (str[i] == '.')
		i++;
	for (; i < str.size(); i++) {
		if (!isdigit(str[i]))
			return false;
	}
	return true;
}

bool is_date(const std::string &str)
{
	if (str.size() < 10)
		return false;
	for (size_t i = 0; i < 4; i++)
		if (!isdigit(str[i]))
			return false;
	if (str[4] != '-')
		return false;
	for (size_t i = 5; i < 7; i++)
		if (!isdigit(str[i]))
			return false;
	if (str[7] != '-')
		return false;
	for (size_t i = 8; i < 10; i++)
		if (!isdigit(str[i]))
			return false;

	int month_day[] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

	int year = (str[0] - '0') * 1000 + (str[1] - '0') * 100 + (str[2] - '0') * 10 + (str[3] - '0');
	int month = (str[5] - '0') * 10 + (str[6] - '0');
	int day = (str[8] - '0') * 10 + (str[9] - '0');
	if ((year % 100 != 0 && year % 4 == 0) || year % 400 == 0)
		month_day[2] = 29;
	if (month <= 0 || month > 12)
		return false;
	if (day <= 0 || day > month_day[month])
		return false;
	return true;
}
