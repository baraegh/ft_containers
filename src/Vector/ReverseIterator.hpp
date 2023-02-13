

#ifndef REVERSEITERATOR_HPP
# define REVERSEITERATOR_HPP

# include "IteratorTraits.hpp"
# include <cstddef>
// # include <iterator>

namespace ft
{
    template <typename Iterator>
    class reverse_iterator
    //  : public
        // random_access_iterator<typename iterator_traits<Iterator>::value_type>
    {
        public:
            typedef Iterator                                                iterator_type;
            typedef typename iterator_traits<Iterator>::difference_type difference_type;
            typedef typename iterator_traits<Iterator>::iterator_category iterator_category;
            typedef typename iterator_traits<Iterator>::reference       reference;
            typedef typename iterator_traits<Iterator>::pointer         pointer;
            typedef typename iterator_traits<Iterator>::value_type         value_type;

        private:
            iterator_type _it;

        public:
            // default constuctor
            reverse_iterator() :_it(NULL) {}

            // initialization constuctor
            explicit reverse_iterator(iterator_type it)
            :_it(it) {}

            // copy constuctor
            template <class Iter>
            reverse_iterator (const reverse_iterator<Iter>& rev_it)
                : _it(rev_it.base()){}

            reverse_iterator &operator=(const reverse_iterator  &rev_it)
            {
                this->_it = rev_it.base();
                return *this;
            }

            iterator_type base() const
            {
                return _it;
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

            reference operator[](difference_type n)
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
                return  tmp_it;
            }

            reverse_iterator& operator+= (difference_type n)
            {
                _it -= n;
                return *this;
            }

            bool    operator==(reverse_iterator const & it)
            {
                return  _it == it.base();
            }

            bool    operator!=(reverse_iterator const & it)
            {
                return  _it != it.base();
            }

            template<class T1, class T2>
            friend bool    operator<(reverse_iterator<T1> const & it1, reverse_iterator<T2> const & it2)
            {
                return  it1.base() > it2.base();
            }

            template<class T1, class T2>
            friend bool    operator>(reverse_iterator<T1> const & it1, reverse_iterator<T2> const & it2)
            {
                return  it1.base() < it2.base();
            }

            template<class T1, class T2>
            friend bool    operator>=(reverse_iterator<T1> const & it1, reverse_iterator<T2> const & it2)
            {
                return  it1.base() <= it2.base();
            }

            template<class T1, class T2>
            friend bool    operator<=(reverse_iterator<T1> const & it1, reverse_iterator<T2> const & it2)
            {
                return  it1.base() >= it2.base();
            }

            template <typename T1>
            friend reverse_iterator<T1> operator+(typename reverse_iterator<T1>::difference_type n,
                reverse_iterator<T1> const & it)
            {
                return reverse_iterator<T1>(it.base() - n);
            }

            difference_type operator-(reverse_iterator const & rev_it) const
            {
                return std::distance(_it, rev_it.base());
            }

            reverse_iterator operator-(difference_type n) const
            {
                return reverse_iterator(_it + n);
            }

            


    };
}


#endif