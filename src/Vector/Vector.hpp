/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Vector.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eel-ghan <eel-ghan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/17 17:11:44 by eel-ghan          #+#    #+#             */
/*   Updated: 2023/01/17 21:58:28 by eel-ghan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VECTOR_HPP
# define VECTOR_HPP

# include "RandomAcessIterator.hpp"
# include "../traits_type/enable_if.hpp"
# include "../traits_type/is_integral.hpp"
# include <iostream>
# include <memory>
# include <vector>

namespace ft
{
    template < class T, class Alloc = std::allocator<T> >
    class vector
    {
        public:
            typedef T                                           value_type;
            typedef Alloc                                       allocator_type;
            typedef typename allocator_type::reference          reference;
            typedef typename allocator_type::const_reference    const_reference;
            typedef typename allocator_type::pointer            pointer;
            typedef typename allocator_type::const_pointer      const_pointer;
            typedef ft::random_acess_iterator<value_type>       iterator;
            typedef ft::random_acess_iterator<const value_type> const_iterator;
            //to be replaced with ft:reverse_iterator..
            // typedef std::reverse_iterator<iterator>             reverse_iterator;
            // typedef std::reverse_iterator<const_iterator>       const_reverse_iterator;              
            typedef std::ptrdiff_t                              difference_type;
            typedef size_t                                      size_type;
            

        private:
            size_type       _size;
            difference_type _capacity;
            allocator_type  _allocator;
            pointer         _data;
            

        public:
            explicit vector (const allocator_type& alloc = allocator_type())
                : _allocator(alloc)
            {}

            explicit vector (size_type n, const value_type& val = value_type(),
                 const allocator_type& alloc = allocator_type())
                 :  _size(n), _capacity(_size),
                    _allocator(alloc), _data(_allocator.allocate(n))
            {
                for (size_type i = 0; i < _size; i++)
                    _allocator.construct(_data + i, val);
            }

            template <class It>
            vector (It first, It last,
                    const allocator_type& alloc = allocator_type(),
                    typename ft::enable_if<!ft::is_integral<It>::value, It>::type* = 0)
                :   _size(last - first), _capacity(_size),
                    _allocator(alloc), _data(_allocator.allocate(_size))
            {
                for (size_type i = 0; i < _size; i++)
                    _allocator.construct(_data + i, *(first++));  
            }

            vector (const vector& x) { *this = x; }

            ~vector()
            {
                for (size_type i = 0; i < _size; i++)
                    _allocator.destroy(_data + i);
                _allocator.deallocate(_data, _size);
            }

            iterator begin()
            {
                return iterator(_data);
            }

            const_iterator begin() const
            {
                return const_iterator(_data);
            }
            
            iterator end()
            {
                return iterator(_data + _size);
            }

            const_iterator end() const
            {
                return const_iterator(_data + _size);
            }

            allocator_type get_allocator() const
            {
                return  _allocator;
            }


            /* operators overloads */
            vector  &operator=(vector const & x)
            {
                _size = x._size;
                _capacity = x._capacity;
                _data = _allocator.allocate(_capacity);
                for (size_type i; i < _size; i++)
                    _allocator.construct(_data + i, x._data[i]);
            }

            // to be edited
            value_type  operator[](int i)
            {
                return _data[i];
            }
    };
}



#endif