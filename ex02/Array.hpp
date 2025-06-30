/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trgaspar <trgaspar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/27 16:28:00 by trgaspar          #+#    #+#             */
/*   Updated: 2025/06/30 09:39:27 by trgaspar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ARRAY_HPP
# define ARRAY_HPP

# include <iostream>
# include <cstdlib>

template <typename T>
class Array
{
	private:
		T *_array;
		size_t _n;
	public:
		Array();
		Array(const Array &cpy);
		Array(unsigned int n);
		~Array();
		Array &operator=(const Array &ref);
		T &operator[](const int i);
		const T &operator[](const int i) const;
		size_t size();
	public:
		class BadIndex : public std::exception
		{
			virtual const char *what() const throw();
		};
};

template <typename T>
Array<T>::Array()
{
	_array = new T[0];
	_n = 0;
}

template <typename T>
Array<T>::Array(unsigned int n)
{
	_array = new T[n];
	_n = n;
}

template <typename T>
Array<T>::Array(const Array &cpy)
{
    _n = cpy._n;
    _array = new T[_n];
    for (size_t i = 0; i < _n; ++i)
    {
        _array[i] = cpy._array[i];
    }
}

template <typename T>
Array<T> &Array<T>::operator=(const Array &ref)
{
	if (this != &ref)
    {
        delete[] _array;
        _n = ref._n;
        _array = new T[_n];
        for (size_t i = 0; i < _n; ++i)
        {
            _array[i] = ref._array[i];
        }
    }
    return (*this);
}

template <typename T>
T &Array<T>::operator[](int i)
{
    if (i < 0 || i >= static_cast<int>(_n))
        throw BadIndex();
    return _array[i];
}

template <typename T>
const T &Array<T>::operator[](int i) const
{
    if (i < 0 || i >= static_cast<int>(_n))
        throw BadIndex();
    return _array[i];
}

template <typename T>
const char *Array<T>::BadIndex::what() const throw()
{
	return ("Index no valid");
}

template <typename T>
size_t Array<T>::size()
{
	return (_n);
}

template <typename T>
Array<T>::~Array()
{
	delete[] _array;
}

#endif