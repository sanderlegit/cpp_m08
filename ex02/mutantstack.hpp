/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   mutantstack.hpp                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: averheij <averheij@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/02/01 13:09:24 by averheij      #+#    #+#                 */
/*   Updated: 2021/02/01 13:30:37 by averheij      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef MUTANTSTACK_HPP
# define MUTANTSTACK_HPP
# include <stack>

template<typename T>
class MutantStack : public std::stack<T> {
	public:
		MutantStack(void) {};
		MutantStack<T>(MutantStack<T> const & src) : std::stack<T>(src) {};
		~MutantStack(void) {};

		typedef typename std::stack<T>::container_type::iterator iterator;

		iterator begin() {
			return this->c.begin();
		}

		iterator end() {
			return this->c.end();
		}

		MutantStack &				operator=(MutantStack const & rhs);
	private:
};

template<typename T>
MutantStack<T> & 		MutantStack<T>::operator=(MutantStack<T> const & rhs) {
	std::stack<T>::operator=(rhs);
	return (*this);
}

#endif
