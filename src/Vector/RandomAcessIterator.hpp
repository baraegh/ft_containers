/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RandomAcessIterator.hpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eel-ghan <eel-ghan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/17 17:11:38 by eel-ghan          #+#    #+#             */
/*   Updated: 2023/01/18 23:24:11 by eel-ghan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RANDOMACESSITERATOR_HPP
# define RANDOMACESSITERATOR_HPP

# include <cstddef>
# include <iterator>

namespace ft
{

    template <typename T>
    class random_acess_iterator : public std::random_access_iterator_tag
    {
        public:
            typedef T      value_type;
            typedef T*      pointer_type;
            typedef T&     reference_type;
            typedef std::ptrdiff_t  difference_type;
        
        private:
            pointer_type _ptr;    
        
        public:
            random_acess_iterator(pointer_type ptr) :_ptr(ptr) {}
            
            random_acess_iterator() :_ptr(NULL) {}
            
            random_acess_iterator(random_acess_iterator const &it)
            {
                *this = it;    
            }
            
            ~random_acess_iterator(){}

            random_acess_iterator &operator=(random_acess_iterator const & it)
            {
                if (it._ptr)
                    _ptr = it._ptr;
                return *this;
            }

            /**/
            // pre-increment ++it
            random_acess_iterator &operator++(void)
            {
                ++_ptr;
                return *this;
            }
            
            // post-increment it++
            random_acess_iterator operator++(int)
            {
                random_acess_iterator tmpIt = *this;
                ++(*this);
                return tmpIt;
            }

            // pre-increment --it
            random_acess_iterator &operator--(void)
            {
                --_ptr;
                return *this;
            }
            
            // post-increment it--
            random_acess_iterator operator--(int)
            {
                random_acess_iterator tmpIt = *this;
                --(*this);
                return tmpIt;
            }
            
            /**/
            bool    operator==(random_acess_iterator const & it)
            {
                return  _ptr == it._ptr;
            }

            bool    operator!=(random_acess_iterator const & it)
            {
                return  _ptr != it._ptr;
            }
            
            /**/
            reference_type   operator*() const
            {
                return *(_ptr);
            }

            pointer_type     operator->() const
            {
                return _ptr;
            }

            /* */
            random_acess_iterator operator+(difference_type n) const
            {
                random_acess_iterator tmpIt = *this;
                
                tmpIt._ptr += n; 
                return tmpIt;
            }

            random_acess_iterator operator-(difference_type n) const
            {
                random_acess_iterator tmpIt = *this;
                
                tmpIt._ptr -= n; 
                return tmpIt;
            }
            
            difference_type  operator-(random_acess_iterator const & it) const
            {
                return std::distance(it._ptr, _ptr);
            }

            /**/
            bool    operator<(random_acess_iterator const & it) const
            {
                return _ptr < it._ptr;
            }

            bool    operator>(random_acess_iterator const & it) const
            {
                return _ptr > it._ptr;
            }

            bool    operator<=(random_acess_iterator const & it) const
            {
                return _ptr <= it._ptr;
            }

            bool    operator>=(random_acess_iterator const & it) const
            {
                return _ptr >= it._ptr;
            }
            
            /**/
            random_acess_iterator & operator+=(difference_type n)
            {
                _ptr = _ptr + n;
                return *this;
            }

            random_acess_iterator & operator-=(difference_type n)
            {
                _ptr = _ptr - n;
                return *this;
            }

            reference_type  operator[](difference_type n)
            {
                return _ptr[n];
            }
    };

}


#endif