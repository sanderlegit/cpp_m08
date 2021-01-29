/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.cpp                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: averheij <averheij@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/01/29 15:32:35 by averheij      #+#    #+#                 */
/*   Updated: 2021/01/29 17:01:54 by averheij      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "span.hpp"
#include <stdlib.h>
#include <time.h>

#define MAX 100000
#define FT_TEST	1
#define COPY_TEST	1
#define RANDOM_TEST	1
#define PRINT_ADD 0
#define PRINT_INTERVAL 0
#define PRINT_SORTED 0

void	big_brain_42(void) {
	std::cout << std::endl << "\t----42 TEST---" << std::endl;
	Span sp = Span(5);
	sp.addNumber(5);
	sp.addNumber(3);
	sp.addNumber(17);
	sp.addNumber(9);
	sp.addNumber(11);
	std::cout << sp.shortestSpan() << std::endl;
	std::cout << sp.longestSpan() << std::endl;
}

void	real_test(void) {
	unsigned int	size = rand() % MAX;
	Span			s = Span(size);
	int				tmp;

	std::cout << std::endl << "\t----RANDOM FILL TEST---" << std::endl;
	std::cout << "\ttesting size:\t" << size << std::endl;
	for (unsigned int i = 0; i < size + 1; i++) {
		try {
			tmp = rand() % (MAX * 10);
			if (PRINT_ADD)
				std::cout << tmp << ' ';
			s.addNumber(tmp);
		} catch (std::exception &e) {
			if (PRINT_ADD)
				std::cout << std::endl;
			std::cout << "\tadded:\t\t" << i << " ints" << std::endl;
			std::cout << "span: '" << e.what() << "'" << std::endl;
		}
		if (PRINT_INTERVAL && i != 0 && i % (size / 5) == 0) {
			if (PRINT_ADD)
				std::cout << std::endl;
			std::cout << "\tadded:\t\t" << i << " ints" << std::endl;
			try {
				std::cout << "current shortestSpan:\t" << std::endl << s.shortestSpan() << std::endl;
				std::cout << "current longestSpan:\t" << std::endl << s.longestSpan() << std::endl;
			} catch (std::exception &e) {
				std::cout << "not enough numbers pal" << std::endl;
			}
		}
	}
	try {
		std::cout << "shortestSpan:\t";
		if (PRINT_CHECKS)
			std::cout << std::endl;
		std::cout << s.shortestSpan() << std::endl;
		std::cout << "longestSpan:\t";
		if (PRINT_CHECKS)
			std::cout << std::endl;
		std::cout << s.longestSpan() << std::endl;
	} catch (std::exception &e) {
		std::cout << "not enough numbers pal" << std::endl;
	}
	if (PRINT_SORTED)
		s.print();
}

void	copy_test(void) {
	unsigned int	size = rand() % 100;
	Span			s = Span(size);
	int				tmp;

	std::cout << std::endl << "\t----COPY TEST---" << std::endl;
	std::cout << "\ttesting size:\t" << size << std::endl;
	for (unsigned int i = 0; i < size + 1; i++) {
		try {
			tmp = rand() % (MAX * 10);
			if (PRINT_ADD)
				std::cout << tmp << ' ';
			s.addNumber(tmp);
		} catch (std::exception &e) {
			if (PRINT_ADD)
				std::cout << std::endl;
			std::cout << "\tadded:\t\t" << i << " ints" << std::endl;
			std::cout << "span: '" << e.what() << "'" << std::endl;
		}
	}
	Span			s2 = s;
	Span			s3 = Span(s);
	s.print();
	s2.print();
	s3.print();
}


int		main(void) {
	srand(time(0));
	if (FT_TEST)
		big_brain_42();
	if (COPY_TEST)
		copy_test();
	if (RANDOM_TEST)
		real_test();
	return (0);
}
