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
# include <iostream>
# include <memory>
# include <vector>

namespace ft
{
    template < class T, class Alloc = std::allocator<T> >
    class Vector
    {
        private:
            typedef T                                           value_type;
            typedef Alloc                                       allocator_type;
            typedef typename allocator_type::reference          reference;
            typedef typename allocator_type::const_reference    const_reference;
            typedef typename allocator_type::pointer            pointer;
            typedef typename allocator_type::const_pointer      const_pointer;
            typedef ft::RandomAcessIterator<value_type>         iterator;
            typedef ft::RandomAcessIterator<const value_type>   const_iterator;
            // typedef ft::ReverseIterator::<iterator>          reverse_iterator;
            // typedef ft::ReverseIterator::<const_iterator>    const_reverse_iterator;              
            typedef std::ptrdiff_t                              difference_type;
            typedef size_t                                      size_type;
            

        public:
            Vector();
            ~Vector();
    };
}



#endif