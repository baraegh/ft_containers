/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eel-ghan <eel-ghan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/18 16:59:24 by eel-ghan          #+#    #+#             */
/*   Updated: 2023/02/18 17:37:22 by eel-ghan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STACK_HPP
# define STACK_HPP

#include "../vector/vector.hpp"


namespace ft 
{
    template <class T, class Container = vector<T> > 
    class stack
    {
        public:
            typedef T                                           value_type;
            typedef Container                                   container_type;
            typedef size_t                                      size_type;
            typedef typename container_type::reference          reference;
            typedef typename container_type::const_reference    const_reference;
        
        private:
            container_type  _ct;

        public:
            explicit stack(const container_type& ctnr = container_type())
            : _ct(ctnr) {}

            ~stack()
			{}
        
            bool empty() const { return _ct.empty(); }

            size_type size() const { return _ct.size(); }

            value_type& top() { return _ct.back(); }
            
            const value_type& top() const { return _ct.back(); }

            void pop() { _ct.pop_back(); }

            void push(const value_type& val) { _ct.push_back(val); }
            
            template <class V, class Cont>
            friend bool operator==(const ft::stack<V, Cont>& lhs, const ft::stack<V, Cont>& rhs)
            {
                return (lhs._ct == rhs._ct);
            }

            template <class V, class Cont>
            friend bool operator!=(const ft::stack<V, Cont>& lhs, const ft::stack<V, Cont>& rhs)
            {
                return (lhs._ct != rhs._ct);
            }

            template <class V, class Cont>
            friend bool operator<(const ft::stack<V, Cont>& lhs, const ft::stack<V, Cont>& rhs)
            {
                return (lhs._ct < rhs._ct);
            }

            template <class V, class Cont>
            friend bool operator<=(const ft::stack<V, Cont>& lhs, const ft::stack<V, Cont>& rhs)
            {
                return (lhs._ct <= rhs._ct);
            }

            template <class V, class Cont>
            friend bool operator>(const ft::stack<V, Cont>& lhs, const ft::stack<V, Cont>& rhs)
            {
                return (lhs._ct > rhs._ct);
            }

            template <class V, class Cont>
            friend bool operator>=(const ft::stack<V, Cont>& lhs, const ft::stack<V, Cont>& rhs)
            {
                return (lhs._ct >= rhs._ct);
            }
    };

}

#endif