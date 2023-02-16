/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Vector.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eel-ghan <eel-ghan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/17 17:11:44 by eel-ghan          #+#    #+#             */
/*   Updated: 2023/02/15 23:25:15 by eel-ghan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef vector_HPP
# define vector_HPP

# include "RandomAccessIterator.hpp"
# include "ReverseIterator.hpp"
# include "IteratorTraits.hpp"
# include "../traits_type/enable_if.hpp"
# include "../traits_type/is_integral.hpp"
# include "../traits_type/is_input.hpp"
# include <cstring>
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
            typedef T                                                           value_type;
            typedef Alloc                                                       allocator_type;
            typedef typename allocator_type::reference                          reference;
            typedef typename allocator_type::const_reference                    const_reference;
            typedef typename allocator_type::pointer                            pointer;
            typedef typename allocator_type::const_pointer                      const_pointer;
            typedef ft::random_access_iterator<value_type>                      iterator;
            typedef ft::random_access_iterator<const value_type>                const_iterator;
            typedef ft::reverse_iterator<iterator>                              reverse_iterator;
            typedef ft::reverse_iterator<const_iterator>                        const_reverse_iterator;              
            typedef typename ft::iterator_traits<iterator>::difference_type     difference_type;
            typedef typename allocator_type::size_type                          size_type;
            

        private:
            size_type       _size;
            size_type       _capacity;
            allocator_type  _allocator;
            pointer         _data;
            

        public:
            // default constructor
            explicit vector(const allocator_type& alloc = allocator_type())
                : _size(0), _capacity(0), _allocator(alloc), _data(NULL)
            {}

            // fill constructor
            explicit vector(size_type n, const value_type& val = value_type(),
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
                    typename enable_if<!is_integral<InputIterator>::value, InputIterator>::type* = 0)
            {
                _allocator = alloc;
                if (!is_input< typename iterator_traits<InputIterator>::iterator_category>::value)
                {
                    _size = std::distance(first, last);
                    _capacity = _size;
                    _data = _allocator.allocate(_capacity);
                    for (size_type i = 0; i < _size; i++)
                        _allocator.construct(_data + i, *(first++));
                }
                else
                {
                    _capacity = 0;
                    _size = 0;
                    _data = _allocator.allocate(_capacity);
                    while (first != last)
                        this->push_back(*(first++));
                }
            }

            // copy constructor
            vector(const vector& x)
            : _size(0), _capacity(_size), _allocator(allocator_type()), _data(_allocator.allocate(_capacity))
            { *this = x; }

            ~vector()
            {
                if (_data)
                {
                    for (size_type i = 0; i < _size; i++)
                        _allocator.destroy(_data + i);
                    _allocator.deallocate(_data, _capacity);
                }
            }

            // fill
            void assign(size_type n, const value_type& val)
            {
                if (_data)
                {
                    for (size_type i = 0; i < _size; i++)
                        _allocator.destroy(_data + i);
                    _allocator.deallocate(_data, _capacity);
                }
                _size = n;
                if (_capacity < _size)
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
                if (_data)
                {
                    for (size_type i = 0; i < _size; i++)
                        _allocator.destroy(_data + i);
                    _allocator.deallocate(_data, _capacity);
                }
                if (!is_input< typename iterator_traits<InputIterator>::iterator_category>::value)
                {
                    _size = std::distance(first, last);
                    _capacity = _size;
                    _data = _allocator.allocate(_capacity);
                    for (size_type i = 0; i < _size; i++)
                        _allocator.construct(_data + i, *(first++));
                }
                else
                {
                    _size = 0;
                    _capacity = _size;
                    _data = _allocator.allocate(_capacity);
                    while (first != last)
                        this->push_back(*(first++));
                }
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
                return _data[_size - 1];
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
                if (_size == 0)
                    reserve(_size + 1);
                else if (_size == _capacity)
                    reserve(_capacity * 2);
                _allocator.construct(_data + _size, val);
                _size++;
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
            
            size_type max_size() const
            {
                return (sizeof(T) == 1) ? _allocator.max_size() / 2 : _allocator.max_size();
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

            iterator erase(iterator position)
            {
                iterator    it = position;
                while (it + 1 != this->end())
                    *(it++) = *(it + 1);
                _allocator.destroy(_data + _size - 1);
                _size--;
                return position;
            }

            iterator erase(iterator first, iterator last)
            {
                size_type   diff =  last - first;
                size_type   first_i = first - this->begin();
                pointer     tmp_data;
                
                if (diff == 0)
                    return _data; 
                tmp_data = _allocator.allocate(_capacity);
                for (size_type i = 0; i < first_i; i++)
                    _allocator.construct(tmp_data + i, _data[i]);
                for (size_type i = first_i; i < _size - diff; i++)
                    _allocator.construct(tmp_data + i, _data[i + diff]);
                if (_data)
                {
                    for (size_type i = 0; i < _size; i++)
                        _allocator.destroy(_data + i); 
                    _allocator.deallocate(_data, _capacity);
                }
                _data = tmp_data;
                _size -= (last - first);
                return _data + first_i;
            }

            reference front()
            {
                return _data[0];
            }
            
            const_reference front() const
            {
                return _data[0];
            }

            // insert single element
            iterator insert(iterator position, const value_type& val)
            {
                size_type   index = position - this->begin();
                pointer     tmp_data;

                if (_size >= _capacity)
                {
                    if (_capacity == 0)
                        tmp_data = _allocator.allocate(_capacity + 1);
                    else
                        tmp_data = _allocator.allocate(_capacity * 2);
                    for (size_type i = 0; i < index; i++)
                        _allocator.construct(tmp_data + i, _data[i]);
                    _allocator.construct(tmp_data + index, val);
                    for (size_type i = index + 1; i < _size + 1; i++)
                         _allocator.construct(tmp_data + i, _data[i - 1]);
                    if (_data)
                    {
                        for (size_type i = 0; i < _size; i++)
                            _allocator.destroy(_data + i);
                        _allocator.deallocate(_data, _capacity);
                    }
                    _data = tmp_data;
                    if (_capacity == 0)
                        _capacity++;
                    else
                        _capacity *= 2;
                }
                else
                {
                    iterator it = this->end();
                    _allocator.construct(_data + _size, val);
                    while (position != it)
                        *(it--) = *(it - 1);
                    *position = val;
                }
                _size++;
                return _data + index;
            }

            // fill insert
            void insert(iterator position, size_type n, const value_type& val)
            {
                size_type   index = position - this->begin();
                pointer     tmp_data;
                // size_type   tmp_size;
                size_type   tmp_capacity = _capacity;
                
                if (n == 0)
                    return;
                else if (_size + n > _capacity)
                {
                    if (_capacity < _size + n - 1 && _capacity * 2 >= _size + n - 1)
                        tmp_capacity = _capacity * 2;
                    else
                        tmp_capacity = n + _size;
                    tmp_data = _allocator.allocate(tmp_capacity);
                    for (size_type i = 0; i < index; i++)
                        _allocator.construct(tmp_data + i, _data[i]);
                    if (index == n)
                        _allocator.construct(tmp_data + index, val);
                    else
                        for (size_type i = index; i < index + n; i++)
                            _allocator.construct(tmp_data + i, val);
                    for (size_type i = index + n; i < _size + n; i++)
                        _allocator.construct(tmp_data + i, _data[i - n]);
                    if (_data)
                    {
                        for (size_type i = 0; i < _size; i++)
                            _allocator.destroy(_data + i);
                        _allocator.deallocate(_data, _capacity);
                    }
                    _data = tmp_data;
                }
                else
                {
                    iterator it = this->end();
                    for (size_type i = 0; i < n; i++)
                        _allocator.construct(_data + _size + i, val);
                    while (it != position - 1)
                    {
                        *(it + n) = *it;
                        it--;
                    }
                    for (size_type i = 0; i < n; i++)
                        *(position  + i) = val;
                }
                _capacity = tmp_capacity;
                _size += n;
            }

            // range insert
            template <class InputIterator>
                void insert(iterator position, InputIterator first, InputIterator last,
                             typename ft::enable_if<!ft::is_integral<InputIterator>::value, InputIterator>::type* = 0)
            {
                size_type   index = position - this->begin();

                if (!is_input< typename iterator_traits<InputIterator>::iterator_category>::value)
                {
                    size_type   diff = std::distance(first, last);
                    pointer     tmp_data;
                    size_type   tmp_capacity = _capacity;

                    if (_size + diff > tmp_capacity)
                    {
                       if (_capacity < _size + diff - 1 && _capacity * 2 >= _size + diff - 1)
                            tmp_capacity = _capacity * 2;
                        else
                            tmp_capacity = diff + _size;
                        tmp_data = _allocator.allocate(tmp_capacity);
                        for (size_type i = 0; i < index; i++)
                            _allocator.construct(tmp_data + i, _data[i]);
                        for (size_type i = index; first != last; first++)
                            _allocator.construct(tmp_data + i++, *first);
                        for (size_type i = index + diff; i < _size + diff; i++)
                            _allocator.construct(tmp_data + i, _data[i - diff]);
                        if (_data)
                        {
                            for (size_type i = 0; i < _size; i++)
                                _allocator.destroy(_data + i);
                            _allocator.deallocate(_data, _capacity);
                        }
                        _data = tmp_data;
                    }
                    else
                    {
                        iterator it = this->end();
                        for (size_type i = 0; i < diff; i++)
                            _allocator.construct(_data + _size + i, *first);
                        while (it != position - 1)
                        {
                            *(it + diff) = *it;
                            it--;
                        }
                        for (size_type i = 0; i < diff; i++)
                            *(position  + i) = *(first++);
                    }
                    _capacity = tmp_capacity;
                    _size += diff;
                }
                else
                {
                    vector v;
                    iterator it = this->begin();
                    
                    if (_size == index)
                    {
                        while (it != this->end())
                            v.push_back(*(it++));
                        while (first != last)
                            v.push_back(*(first++));
                    }
                    else
                        while (it != this->end())
                        {
                            if (it - this->begin() == (difference_type)index)
                            {
                                while (first != last)
                                    v.push_back(*(first++));
                            }
                            v.push_back(*(it++));
                        }
                    *this = v;
                }
            }

            void reserve(size_type n)
            {
                if (n > _capacity)
                {
                    pointer tmp_data = _allocator.allocate(n);
                    for (size_type i = 0; i < _size; i++)
                        _allocator.construct(tmp_data + i, _data[i]);
                    if (_data)
                    {
                        for (size_type i = 0; i < _size; i++)
                            _allocator.destroy(_data + i);
                        _allocator.deallocate(_data, _capacity);
                    }
                    _data = tmp_data;
                    _capacity = n;
                }
            }

            void resize(size_type n, value_type val = value_type())
            {
                reserve(n);
                if (n > _size)
                {
                    for (size_type i = _size; i < n; i++)
                        _allocator.construct(_data + i, val);
                }
                else if (n < _size)
                {
                    for (size_type i = 0; i < _size; i++)
                        if (i >= n)
                            _allocator.destroy(_data + i);
                }
                _size = n;
            }

            void swap(vector& x)
            {
                std::swap(_data, x._data);
                std::swap(_size, x._size);
                std::swap(_capacity, x._capacity);
                std::swap(_allocator, x._allocator);
            }

            reverse_iterator rbegin()
            {
                return reverse_iterator(_data + _size);
            }

            const_reverse_iterator rbegin() const
            {
                return reverse_iterator(_data + _size);
            }

            reverse_iterator rend()
            {
                return reverse_iterator(_data);
            }

            const_reverse_iterator rend() const
            {
                return reverse_iterator(_data);
            }

            /* operators overloads */
            vector  &operator=(vector const & x)
            {
                if (_data)
                {
                    for (size_type i = 0; i < _size; i++)
                        _allocator.destroy(_data + i);
                    _allocator.deallocate(_data, _capacity);
                }
                _size = x._size;
                _capacity = x._capacity;
                _data = _allocator.allocate(_capacity);
                for (size_type i = 0; i < _size; i++)
                    _allocator.construct(_data + i, x._data[i]);
                
                return *this;
            }
            
            reference operator[](size_type n)
            {
                return _data[n];
            }
            
            const_reference operator[](size_type n) const
            {
                return _data[n];
            }
    };

    template <class InputIterator1, class InputIterator2>
        bool equal(InputIterator1 first1, InputIterator1 last1, InputIterator2 first2)
    {
        while (first1 != last1)
        {
            if (!(*first1 == *first2))
                return false;
            ++first1; 
            ++first2;
        }
        return true;
    }

    template <class InputIterator1, class InputIterator2, class BinaryPredicate>
        bool equal( InputIterator1 first1, InputIterator1 last1,
                    InputIterator2 first2, BinaryPredicate pred)
    {
        while (first1 != last1)
        {
            if (!pred(*first1, *first2))
                return false;
            ++first1; 
            ++first2;
        }
        return true;
    }

    template <class InputIterator1, class InputIterator2>
        bool lexicographical_compare(   InputIterator1 first1, InputIterator1 last1,
                                        InputIterator2 first2, InputIterator2 last2)
    {
        while (first1 != last1)
        {
            if (first2 == last2 || *first2 < *first1)
                return false;
            else if (*first1 < *first2)
                return true;
            ++first1; ++first2;
        }
        return (first2 != last2);
    }

    // template <class InputIterator1, class InputIterator2, class Compare>
    //     bool lexicographical_compare (  InputIterator1 first1, InputIterator1 last1,
    //                                     InputIterator2 first2, InputIterator2 last2,
    //                                     Compare comp)
    // {
        
    // }
    
    template <class T, class Alloc>
        bool operator==(const ft::vector<T,Alloc>& v1, const ft::vector<T,Alloc>& v2)
    {
        if (v1.size() == v2.size())
            return ft::equal(v1.begin(), v1.end(), v2.begin());
        return false;
    }

    template <class T, class Alloc>
        bool operator!=(const ft::vector<T,Alloc>& v1, const ft::vector<T,Alloc>& v2)
    {
        return !(v1 == v2);
    }

    template <class T, class Alloc>
        bool operator<(const ft::vector<T,Alloc>& v1, const ft::vector<T,Alloc>& v2)
    {
        return ft::lexicographical_compare(v1.begin(), v1.end(), v2.begin(), v2.end());
    }
    
    template <class T, class Alloc>
        bool operator<=(const ft::vector<T,Alloc>& v1, const ft::vector<T,Alloc>& v2)
    {
        return !(v2 < v1);
    }

    template <class T, class Alloc>
        bool operator>(const ft::vector<T,Alloc>& v1, const ft::vector<T,Alloc>& v2)
    {
        return v2 < v1;
    }

    template <class T, class Alloc>
        bool operator>=(const ft::vector<T,Alloc>& v1, const ft::vector<T,Alloc>& v2)
    {
        return !(v1 < v2);
    }

    template <class T, class Alloc>
    void swap(vector<T,Alloc>& x, vector<T,Alloc>& y)
    {
        vector<T,Alloc> tmp;

        tmp.swap(x);
        x.swap(y);
        y.swap(tmp);
    }
}



#endif