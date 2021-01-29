/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   span.hpp                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: averheij <averheij@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/01/29 14:48:16 by averheij      #+#    #+#                 */
/*   Updated: 2021/01/29 16:52:46 by averheij      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef SPAN_HPP
# define SPAN_HPP
#include <vector>
#include <stdexcept>
#include <algorithm> //minmax_element
#include <limits.h>

#include <iostream>

#define PRINT_CHECKS	0

typedef std::vector<int>::iterator IT;

class Span {
	public:
		Span(void);
		Span(unsigned int size);
		Span(Span const & src);
		~Span(void);

		void				addNumber(int n);
		int					shortestSpan(void);
		int					longestSpan(void);
		void				print(void);

		Span &				operator=(Span const & rhs);
	private:
		unsigned long int	_idx;
		unsigned long int	_size;
		std::vector<int>	_v;
};

#endif
