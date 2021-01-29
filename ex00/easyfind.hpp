/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   easyfind.hpp                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: averheij <averheij@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/01/29 13:29:58 by averheij      #+#    #+#                 */
/*   Updated: 2021/01/29 13:54:01 by averheij      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef EASYFIND_HPP
#define EASYFIND_HPP

#include <algorithm>	//find

/* Ret: An iterator to the first element in the range that compares equal to val.
 * If no elements match, the function returns last.
*/

template<typename T>
int		easyfind(T t, int f) {
	typename T::iterator 	i;

	i = find(t.begin(), t.end(), f);
	if (i == t.end())
		throw std::exception();
	return (*i);
}

#endif
