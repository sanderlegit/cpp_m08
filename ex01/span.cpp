/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   span.cpp                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: averheij <averheij@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/01/29 14:48:14 by averheij      #+#    #+#                 */
/*   Updated: 2021/01/29 16:59:44 by averheij      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "span.hpp"

Span::Span(void) : _idx(0), _size(0) {
	return;
}

Span::Span(unsigned int size) : _idx(0), _size(size) {
	return;
}


Span::Span(Span const & src) {
	*this = src;
	return;
}

Span::~Span(void) {
	return;
}

void					Span::addNumber(int n) {
	if (_idx < _size) {
		_v.push_back(n);
		_idx++;
	} else
		throw std::length_error("Container is at max size");
	return;
}

int						Span::shortestSpan(void) {
	int				min;
	unsigned int	count = 0;

	if (_idx < 2)
		throw std::exception();
	std::sort(_v.begin(), _v.end());

	min = INT_MAX;
	for (IT i = _v.begin(); (i + 1) != _v.end(); ++i) {
		if ((*(i + 1) - *i) < min) {
			min = *(i + 1) - *i;
			if (PRINT_CHECKS)
				std::cout << "min found: idx[" << (count + 1) << "," << count << "]: " << *(i + 1) << " " << *i << std::endl;
			if (min == 0)
				return (0);
		}
		count++;
	}
	return (min);
}

int						Span::longestSpan(void) {
	if (_idx < 2)
		throw std::exception();

	IT max = std::max_element(_v.begin(), _v.end());
	IT min = std::min_element(_v.begin(), _v.end());
	return (*max - *min);
}

void					Span::print(void) {
	std::cout << "size: " << _size << "\tidx: " << (_idx + 1) << std::endl;
	for (IT i = _v.begin(); i != _v.end(); ++i)
		std::cout << *i << " ";
	std::cout << std::endl;
}


Span &					Span::operator=(Span const & rhs) {
	_v = std::vector<int>(rhs._v);
	_idx = rhs._idx;
	_size = rhs._size;
	return *this;
}
