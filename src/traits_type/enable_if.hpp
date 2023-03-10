/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   enable_if.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eel-ghan <eel-ghan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/10 23:14:02 by eel-ghan          #+#    #+#             */
/*   Updated: 2023/02/10 23:14:05 by eel-ghan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */



#ifndef ENABLE_IF_HPP
# define ENABLE_IF_HPP

namespace ft {
    template<bool b, class T = void>
    struct  enable_if {};

    template<class T>
    struct enable_if<true, T>
    {
        typedef T type;
    };
}

#endif