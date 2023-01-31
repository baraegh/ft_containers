

#ifndef REVERSEITERATOR_HPP
# define REVERSEITERATOR_HPP

# include "IteratorTraits.hpp"
# include <iterator>

namespace ft
{
    template <typename Iterator>
    class reverse_iterator : public
        ft::random_access_iterator<typename ft::iterator_traits<Iterator>::value_type>
    {
        public:
            typedef Iterator                                                iterator_type;
            typedef typename ft::iterator_traits<Iterator>::difference_type difference_type;
            typedef typename ft::iterator_traits<Iterator>::reference       reference;
            typedef typename ft::iterator_traits<Iterator>::pointer         pointer;

        private:
            Iterator _it;

        public:
            // default constuctor
            reverse_iterator() :_it(NULL) {}

            // initialization constuctor
            explicit reverse_iterator(iterator_type it)
            :_it(it) {}

            // copy constuctor
            template <class Iter>
            reverse_iterator (const reverse_iterator<Iter>& rev_it)
            {
                this->_it = rev_it._it;
            }

            iterator_type base() const
            {
                return _it;
            }

            reverse_iterator operator-(difference_type n) const
            {
                return reverse_iterator(_it + n);
            }

            reverse_iterator& operator--()
            {
                ++_it;
                return *this;
            }

            reverse_iterator  operator--(int)
            {
                reverse_iterator    tmp_it = *this;

                ++_it;
                return tmp_it;
            }

            reverse_iterator& operator-=(difference_type n)
            {
                _it += n;
                return *this;
            }

            pointer operator->() const
            {
                return &(operator*());
            }

            reference operator[](difference_type n) const
            {
                return _it[-n - 1];
            }

            reference operator*() const
            {
                Iterator    tmp_it = _it;
                return *--tmp_it;
            }

            reverse_iterator operator+(difference_type n) const
            {
                return reverse_iterator(_it - n);
            }

            reverse_iterator& operator++()
            {
                --_it;
                return *this;
            }

            reverse_iterator  operator++(int)
            {
                reverse_iterator    tmp_it = *this;
                --_it;
                return  *tmp_it;
            }

            reverse_iterator& operator+= (difference_type n)
            {
                _it -= n;
                return *this;
            }
    };
}


#endif