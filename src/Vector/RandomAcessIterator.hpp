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

    template <typename Vector>
    class RandomAcessIterator
    {
        public:
            typedef typename Vector::value_type     value_type;
            typedef value_type*                     pointer_type;
            typedef value_type&                     reference_type;
            typedef std::ptrdiff_t                  difference_type;
        
        private:
            pointer_type _ptr;    
        
        public:
            RandomAcessIterator() :_ptr(NULL) {}
            
            RandomAcessIterator(pointer_type ptr) :_ptr(ptr) {}
            
            RandomAcessIterator(RandomAcessIterator const &it)
            {
                *this = it;    
            }
            
            ~RandomAcessIterator(){}

            RandomAcessIterator &operator=(RandomAcessIterator const & it)
            {
                if (it.ptr)
                    _ptr = it._ptr;
                return *this;
            }

            /**/

            RandomAcessIterator &operator++(void)
            {
                ++_ptr;
                return *this;
            }
            
            RandomAcessIterator operator++(int) const
            {
                RandomAcessIterator tmpIt = *this;
                ++(*this);
                return tmpIt;
            }

            RandomAcessIterator &operator--(void)
            {
                --_ptr;
                return *this;
            }
            
            RandomAcessIterator operator--(int) const
            {
                RandomAcessIterator tmpIt = *this;
                --(*this);
                return tmpIt;
            }
            
            /**/
            bool    operator==(RandomAcessIterator const & it)
            {
                return  _ptr == it._ptr;
            }

            bool    operator!=(RandomAcessIterator const & it)
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
            RandomAcessIterator operator+(int n) const
            {
                RandomAcessIterator tmpIt = *this;
                
                tmpIt._ptr += n; 
                return tmpIt;
            }

            RandomAcessIterator operator-(int n) const
            {
                RandomAcessIterator tmpIt = *this;
                
                tmpIt._ptr -= n; 
                return tmpIt;
            }
            
            difference_type  operator-(RandomAcessIterator const & it) const
            {
                return std::distance(*this, it);
            }

            /**/
            bool    operator<(RandomAcessIterator const & it) const
            {
                return *this < it;
            }

            bool    operator>(RandomAcessIterator const & it) const
            {
                return *this > it;
            }

            bool    operator<=(RandomAcessIterator const & it) const
            {
                return *this <= it;
            }

            bool    operator>=(RandomAcessIterator const & it) const
            {
                return *this >= it;
            }
            
            /**/
            RandomAcessIterator & operator+=(difference_type n)
            {
                _ptr = _ptr + n;
                return *this;
            }

            RandomAcessIterator & operator-=(difference_type n)
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