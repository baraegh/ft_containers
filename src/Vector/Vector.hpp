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

# include "Iterator.hpp"
# include <iostream>

namespace ft
{
    template < class T, class Alloc = std::allocator<T> >
    class Vector
    {
        private:
            typedef T                               value_type;
            typedef Alloc                           allocator_type;
            typedef allocator_type::reference       reference;
            typedef allocator_type::const_reference	const_reference;
            typedef allocator_type::pointer         pointer;
            typedef allocator_type::const_pointer   const_pointer;
            /* add iterators */
            
            

        public:
            Vector();
            ~Vector();
    };
}



#endif