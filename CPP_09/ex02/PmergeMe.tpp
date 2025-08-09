#ifndef PEMERGME_TPP
#define PEMERGME_TPP

#include "PmergeMe.hpp"
#include <algorithm>
#include <iostream>

template <typename CONTAINER_TYPE>
void merge_insert_sort(CONTAINER_TYPE &values, size_t depth = 0);
template <typename CONTAINER_TYPE>
void packer(CONTAINER_TYPE &values, const size_t packet_number, const size_t packet_size);
template <typename CONTAINER_TYPE>
size_t binary_search(CONTAINER_TYPE &values, size_t high, const size_t packet_size, val_type value);

template <typename CONTAINER_TYPE>
bool is_sorted(CONTAINER_TYPE &values);

template <typename CONTAINER_TYPE>
bool parse(CONTAINER_TYPE &value, int ac, char **av)
{
	for (int i = 0; i < ac; i++) {
		val_type v;
		if (!is_number(av[i]))
			return false;
		v = std::strtoul(av[i], NULL, 10);
		if (v == __SIZE_MAX__ && std::string("18446744073709551615") != av[i])
			return false;
		value.push_back(v);
	}
	return true;
}

template <typename CONTAINER_TYPE>
bool is_sorted(CONTAINER_TYPE &values)
{
	typename CONTAINER_TYPE::iterator it = values.begin();
	typename CONTAINER_TYPE::iterator end = values.end();

	while (it != end && it + 1 != end) {
		if (*it > *(it + 1))
			return false;
		it++;
	}
	return true;
}

template <typename CONTAINER_TYPE>
void print_values(const CONTAINER_TYPE &values, const size_t limit)
{
	typename CONTAINER_TYPE::const_iterator it = values.begin();
	typename CONTAINER_TYPE::const_iterator end =
		values.size() > limit ? values.begin() + (limit == 0 ? 0 : limit - 1) : values.end();
	for (; it != end; it++) {
		std::cout << *it << " ";
	}
	if (values.size() > limit)
		std::cout << "[...]";
	std::cout << std::endl;
}

template <typename CONTAINER_TYPE>
void packer(CONTAINER_TYPE &values, const size_t packet_number, const size_t packet_size)
{
	for (size_t i = 0; i + 1 < packet_number; i += 2) {
		const size_t p1 = i * packet_size;
		const size_t p2 = (i + 1) * packet_size;

		typename CONTAINER_TYPE::iterator it1 = values.begin() + p1;
		typename CONTAINER_TYPE::iterator it2 = values.begin() + p2;

		typename CONTAINER_TYPE::iterator end1 = it1 + packet_size;
		typename CONTAINER_TYPE::iterator end2 = it2 + packet_size;
#if DEBUG
		std::cout << "testing packet " << p1 + packet_size - 1 << " and " << p2 + packet_size - 1
				  << std::endl;
		std::cout << "testing values " << *(end1 - 1) << " ?> " << *(end2 - 1) << std::endl;
#endif
		if (*(end1 - 1) > *(end2 - 1))
			std::swap_ranges(it1, end1, it2);
	}
}

template <typename CONTAINER_TYPE>
size_t binary_search(CONTAINER_TYPE &values, size_t high, const size_t packet_size, val_type value)
{
	size_t step = 0, index = 0, first = 0;
	while (high > 0) {
		index = first;
		step = high >> 1;
		index += step;
		const size_t tested_index = index * packet_size;
		const val_type tested_value = *(values.begin() + tested_index + packet_size - 1);
		if (tested_value < value) {
			first = ++index;
			high -= step + 1;
		}
		else {
			high = step;
		}
	}
	return (first);
}

template <typename CONTAINER_TYPE>
void insert_value(CONTAINER_TYPE &values, const size_t old_pos, const size_t new_pos,
				  const size_t packet_size)
{
	typename CONTAINER_TYPE::iterator packet_it = values.begin() + old_pos * packet_size;
	typename CONTAINER_TYPE::iterator packet_end = packet_it + packet_size;

	CONTAINER_TYPE tmp(packet_it, packet_end);

	values.erase(packet_it, packet_end);
	typename CONTAINER_TYPE::iterator new_it = values.begin() + new_pos * packet_size;
	values.insert(new_it, tmp.begin(), tmp.end());
}

template <typename CONTAINER_TYPE>
void jacobsthal_insert(CONTAINER_TYPE &values, const size_t packet_number, const size_t packet_size)
{
	size_t insert_packet = 0;
	size_t pend_packet = packet_number;
	size_t rest = values.size() % packet_size;
	CONTAINER_TYPE unused_vals(values.end() - rest, values.end());
	values.erase(values.end() - rest, values.end());
	CONTAINER_TYPE pend_vals(values.begin(), values.end());
	values.clear();
	// insert big values
	for (size_t i = 1; i < pend_packet; i++) {
		typename CONTAINER_TYPE::iterator packet_it = pend_vals.begin() + i * packet_size;
		typename CONTAINER_TYPE::iterator packet_end = packet_it + packet_size;
		values.insert(values.end(), packet_it, packet_end);
		pend_vals.erase(packet_it, packet_end);
		insert_packet++;
		pend_packet--;
	}
#if DEBUG
	std::cout << "big values: ";
	print_values(values, -1);
#endif
	size_t last_jacobstal = 0;
	size_t loop_count = 0;
	// sort little value
	while (!pend_vals.empty()) {
		size_t jacobstal_index = jacobsthal_number(loop_count) - last_jacobstal;
		last_jacobstal = jacobsthal_number(loop_count);
		loop_count++;
#if DEBUG
		std::cout << "jacobstal_index: " << jacobstal_index << std::endl;
		std::cout << "pend_packet: " << pend_packet << std::endl;
#endif
		if (jacobstal_index > pend_packet)
			jacobstal_index = pend_packet;
		while (jacobstal_index-- > 0 && !pend_vals.empty()) {
			typename CONTAINER_TYPE::iterator packet_it =
				pend_vals.begin() + jacobstal_index * packet_size;
			typename CONTAINER_TYPE::iterator packet_end = packet_it + packet_size;
			size_t new_pos = binary_search(values, insert_packet, packet_size, *(packet_end - 1));

			typename CONTAINER_TYPE::iterator new_it = values.begin() + new_pos * packet_size;
			values.insert(new_it, packet_it, packet_end);
			pend_vals.erase(packet_it, packet_end);
			insert_packet++;
			pend_packet--;
		}
	}

	values.insert(values.end(), pend_vals.begin(), pend_vals.end());
	values.insert(values.end(), unused_vals.begin(), unused_vals.end());
#if DEBUG
	std::cout << "all values: ";
	print_values(values, -1);
	std::cout << "---" << std::endl;
#endif
}

template <typename CONTAINER_TYPE>
void merge_insert_sort(CONTAINER_TYPE &values, const size_t depth)
{
	const size_t packet_size = 1 << depth;
	const size_t packet_number = values.size() >> depth;

#if DEBUG
	const size_t unused_cells = values.size() % packet_size;
	std::cout << "---" << "\n";
	std::cout << "depth: " << depth << "\n";
	std::cout << "packet found: " << packet_number << "\n";
	std::cout << "packet size: " << packet_size << "\n";
	std::cout << "packet unused: " << unused_cells << std::endl;
#endif
	packer(values, packet_number, packet_size);
#if DEBUG
	print_values(values, -1);
#endif
	if (packet_number > 1)
		merge_insert_sort(values, depth + 1);

#if DEBUG
	std::cout << "---" << "\n";
	std::cout << "depth: " << depth << "\n";
	std::cout << "packet found: " << packet_number << "\n";
	std::cout << "packet size: " << packet_size << std::endl;
#endif
	jacobsthal_insert(values, packet_number, packet_size);
#if DEBUG
	print_values(values, -1);
#endif
}

#endif