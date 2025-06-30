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

template <typename T, typename F>

void iter(T *array, size_t lenght, F ft)
{
	size_t i;

	i = 0;
	while (i != lenght)
	{
		ft(array[i]);
		i++;
	}
}

template <typename T>

void display(T a)
{
	std::cout << a << std::endl;
}

#endif
