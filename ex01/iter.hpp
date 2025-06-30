/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iter.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trgaspar <trgaspar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/27 14:57:03 by trgaspar          #+#    #+#             */
/*   Updated: 2025/06/27 15:32:57 by trgaspar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ITER_HPP
# define ITER_HPP

# include <iostream>

template <typename T>

void iter(T *array, size_t lenght, void (*func)(T))
{
	size_t i;

	i = 0;
	while (i != lenght)
	{
		func(array[i]);
		i++;
	}
}

template <typename T>

void display(T a)
{
	std::cout << a << std::endl;
}

#endif