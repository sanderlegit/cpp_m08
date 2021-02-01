/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.cpp                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: averheij <averheij@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/02/01 13:14:57 by averheij      #+#    #+#                 */
/*   Updated: 2021/02/01 13:37:19 by averheij      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "mutantstack.hpp"
#include <iostream>

int main()
{
	MutantStack<int> mstack;

	std::cout << "Pushing 2..." << std::endl;

	mstack.push(5);
	mstack.push(17);

	std::cout << "Top:" << std::endl;
	std::cout << mstack.top() << std::endl;

	std::cout << "Pop 1..." << std::endl;
	mstack.pop();

	std::cout << "Size:" << std::endl;
	std::cout << mstack.size() << std::endl;

	std::cout << "Pushing 5..." << std::endl;
	mstack.push(3);
	mstack.push(5);
	mstack.push(737);
	mstack.push(101);
	mstack.push(0);

	MutantStack<int>::iterator it = mstack.begin();
	MutantStack<int>::iterator ite = mstack.end();

	std::cout << "Created iterators..." << std::endl;
	std::cout << "++ --" << std::endl;
	++it;
	--it;
	std::cout << "Full iteration..." << std::endl;
	while (it != ite)
	{
		std::cout << *it << std::endl;
		++it;
	}

	std::cout << "Copy constructor..." << std::endl;
	std::stack<int> s(mstack);
	std::cout << "Full pop (will be reverse)..." << std::endl;
	while (!s.empty())
	{
		std::cout << s.top() << std::endl;
		s.pop();
	}
	return 0;
}

