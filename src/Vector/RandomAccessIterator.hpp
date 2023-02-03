/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RandomAccessIterator.hpp                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eel-ghan <eel-ghan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/17 17:11:38 by eel-ghan          #+#    #+#             */
/*   Updated: 2023/02/03 21:00:06 by eel-ghan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RANDOMACCESSITERATOR_HPP
# define RANDOMACCESSITERATOR_HPP

# include <cstddef>
# include <iterator>

namespace ft
{

    template <typename T>
    class random_access_iterator : public std::random_access_iterator_tag
    {
        public:
            typedef T                                           value_type;
            typedef T*                                          pointer;
            typedef const T*                                    const_pointer;
            typedef T&                                          reference;
            typedef const T&                                    const_reference;
            typedef std::ptrdiff_t                              difference_type;
            typedef std::random_access_iterator_tag             iterator_category;
        
        private:
            pointer _ptr;    
        
        public:
            random_access_iterator(pointer ptr) :_ptr(ptr) {}
            
            random_access_iterator() :_ptr(NULL) {}
            
            random_access_iterator(const random_access_iterator  &it)
                :_ptr(it._ptr) {}
            
            ~random_access_iterator(){}

            random_access_iterator &operator=(const random_access_iterator  &it)
            {
                if (this == &it)
                    return *this;
                _ptr = it._ptr;
                return *this;
            }

            operator random_access_iterator<const value_type>() {
                return random_access_iterator<const value_type>(_ptr);
            }

            /* operators overload */
            // pre-increment ++it
            random_access_iterator &operator++(void)
            {
                ++_ptr;
                return *this;
            }
            
            // post-increment it++
            random_access_iterator operator++(int)
            {
                random_access_iterator tmpIt = *this;
                ++(*this);
                return tmpIt;
            }

            // pre-increment --it
            random_access_iterator &operator--(void)
            {
                --_ptr;
                return *this;
            }
            
            // post-increment it--
            random_access_iterator operator--(int)
            {
                random_access_iterator tmpIt = *this;
                --(*this);
                return tmpIt;
            }
            
            bool    operator==(random_access_iterator const & it)
            {
                return  _ptr == it._ptr;
            }

            bool    operator!=(random_access_iterator const & it)
            {
                return  _ptr != it._ptr;
            }
            
            reference   operator*() const
            {
                return *(_ptr);
            }

            pointer     operator->() const
            {
                return _ptr;
            }

            random_access_iterator operator+(difference_type n) const
            {
                random_access_iterator tmpIt = *this;
                
                tmpIt._ptr += n; 
                return tmpIt;
            }

            template <typename T1>
            friend ft::random_access_iterator<T1> operator+(typename ft::random_access_iterator<T1>::difference_type n,
                ft::random_access_iterator<T1> const & it)
            {
                return it + n;
            }

            random_access_iterator operator-(difference_type n) const
            {
                random_access_iterator tmpIt = *this;
                
                tmpIt._ptr -= n; 
                return tmpIt;
            }
            
            difference_type  operator-(random_access_iterator const & it) const
            {
                return std::distance(it._ptr, _ptr);
            }

            bool    operator<(random_access_iterator const & it) const
            {
                return _ptr < it._ptr;
            }

            bool    operator>(random_access_iterator const & it) const
            {
                return _ptr > it._ptr;
            }

            bool    operator<=(random_access_iterator const & it) const
            {
                return _ptr <= it._ptr;
            }

            bool    operator>=(random_access_iterator const & it) const
            {
                return _ptr >= it._ptr;
            }
            
            random_access_iterator & operator+=(difference_type n)
            {
                _ptr = _ptr + n;
                return *this;
            }

            random_access_iterator & operator-=(difference_type n)
            {
                _ptr = _ptr - n;
                return *this;
            }

            reference  operator[](difference_type n)
            {
                return _ptr[n];
            }
    };

}


#endif