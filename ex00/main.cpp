/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.cpp                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: averheij <averheij@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/01/29 13:37:14 by averheij      #+#    #+#                 */
/*   Updated: 2021/01/29 14:10:15 by averheij      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "easyfind.hpp"
#include <vector>
#include <list>
#include <iostream>

void	test_vector(void) {
	std::vector<int>	v1(10, 0);

	for (long unsigned int i = 0; i < v1.size(); i++) {
		v1[i] = i * 10;
	}

	for (std::vector<int>::iterator i = v1.begin(); i != v1.end(); ++i)
		std::cout << *i << " ";
	std::cout << std::endl;

	std::cout << easyfind(v1, 0) << std::endl;
	std::cout << easyfind(v1, 20) << std::endl;
	std::cout << easyfind(v1, 70) << std::endl;
	std::cout << easyfind(v1, 90) << std::endl;
	try {
		std::cout << easyfind(v1, -1) << std::endl;
	} catch (std::exception &e) {
		std::cout << "not found" << std::endl;
	}
}

void	test_list(void) {
	std::list<int>	lst;

	for (long unsigned int i = 0; i < 10; i++) {
		lst.push_back(i * 10);
	}

	for (std::list<int>::iterator i = lst.begin(); i != lst.end(); ++i)
		std::cout << *i << " ";
	std::cout << std::endl;

	std::cout << easyfind(lst, 0) << std::endl;
	std::cout << easyfind(lst, 20) << std::endl;
	std::cout << easyfind(lst, 70) << std::endl;
	std::cout << easyfind(lst, 90) << std::endl;
	try {
		std::cout << easyfind(lst, -1) << std::endl;
	} catch (std::exception &e) {
		std::cout << "not found" << std::endl;
	}
}

int		main(void) {
	test_vector();
	test_list();
}
