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
# include <stdexcept> 
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
            size_type       _capacity;
            size_type       _max_size;
            allocator_type  _allocator;
            pointer         _data;
            

        public:
            // default constructor
            explicit vector (const allocator_type& alloc = allocator_type())
                : _size(0), _capacity(0), _allocator(alloc), _data(_allocator.allocate(_capacity))
            {}

            // fill constructor
            explicit vector (size_type n, const value_type& val = value_type(),
                 const allocator_type& alloc = allocator_type())
                 :  _size(n), _capacity(_size),
                    _allocator(alloc), _data(_allocator.allocate(_capacity))
            {
                for (size_type i = 0; i < _size; i++)
                    _allocator.construct(_data + i, val);
            }

            // range constructor
            template <class InputIterator>
            vector(InputIterator first, InputIterator last,
                    const allocator_type& alloc = allocator_type(),
                    typename ft::enable_if<!ft::is_integral<InputIterator>::value, InputIterator>::type* = 0)
                :   _size(last - first), _capacity(_size),
                    _allocator(alloc), _data(_allocator.allocate(_capacity))
            {
                for (size_type i = 0; i < _size; i++)
                    _allocator.construct(_data + i, *(first++));
            }

            // copy constructor
            vector(const vector& x) { *this = x; }

            ~vector()
            {
                for (size_type i = 0; i < _size; i++)
                    _allocator.destroy(_data + i);
                _allocator.deallocate(_data, _size);
            }

            // fill
            void assign(size_type n, const value_type& val)
            {
                for (size_type i = 0; i < _size; i++)
                    _allocator.destroy(_data + i);
                _allocator.deallocate(_data, _size);
                _size = n;
                _capacity = _size;
                _data = _allocator.allocate(_capacity);
                for (size_type i = 0; i < _size; i++)
                    _allocator.construct(_data + i, val);
            }

            // range
            template <class InputIterator>
            void assign(InputIterator first, InputIterator last,
                         typename ft::enable_if<!ft::is_integral<InputIterator>::value, InputIterator>::type* = 0)
            {
                for (size_type i = 0; i < _size; i++)
                    _allocator.destroy(_data + i);
                _allocator.deallocate(_data, _size);
                _size = last - first;
                _capacity = _size;
                _data = _allocator.allocate(_capacity);
                for (size_type i = 0; i < _size; i++)
                    _allocator.construct(_data + i, *(first++));
            }

            reference at(size_type n)
            {
                if (n >= _size)
                    throw std::out_of_range("Index out of range");
                return _data[n];
            }

            const_reference at(size_type n) const
            {
                if (n >= _size)
                    throw std::out_of_range("Index out of range");
                return _data[n];
            }

            reference back()
            {
                return _data[_size - 1];;
            }

            const_reference back() const
            {
                return _data[_size - 1];
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

            void pop_back()
            {
                _allocator.destroy(_data + _size - 1);
                _size--;
            }

            void push_back(const value_type& val)
            {
                if (_size == _capacity)
                {
                    // I should find the right size of the new_data
                    pointer new_data = _allocator.allocate(_capacity + 1);
                    for (size_type i = 0; i < _size; i++)
                        new_data[i] = _data[i];
                    for (size_type i = 0; i < _size; i++)
                        _allocator.destroy(_data + i);
                    _allocator.deallocate(_data, _size);
                    _data = new_data;
                }
                _size++;
                _capacity++;
                _allocator.construct(_data + _size - 1, val);
            }

            allocator_type get_allocator() const
            {
                return  _allocator;
            }

            size_type capacity() const
            {
                return _capacity;
            }

            size_type size() const
            {
                return _size;
            }

            void clear()
            {
                for (size_type i = 0; i < _size; i++)
                    _allocator.destroy(_data + i);
                _size = 0;
            }

            bool empty() const
            {
                if (_size == 0)
                    return true;
                return false;
            }

            // iterator erase(iterator position)
            // {
            //     iterator    first = this->begin();
            //     iterator    last = this->end();
            //     size_type   i = 0;

            //     for (; first != last; first++)
            //     {
            //         if (first == last)
            //             break;
            //         i++;
            //     }

            //     this->assign(j + 1,)

            // }

            // iterator erase(iterator first, iterator last)
            // {

            // }

            /* operators overloads */
            vector  &operator=(vector const & x)
            {
                _size = x._size;
                _capacity = x._capacity;
                _data = _allocator.allocate(_capacity);
                for (size_type i = 0; i < _size; i++)
                    _allocator.construct(_data + i, x._data[i]);
                
                return *this;
            }

            value_type  operator[](int i)
            {
                return _data[i];
            }
    };
}



#endif