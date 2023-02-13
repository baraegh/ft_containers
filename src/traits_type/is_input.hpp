/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_input.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eel-ghan <eel-ghan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/10 23:20:51 by eel-ghan          #+#    #+#             */
/*   Updated: 2023/02/10 23:23:14 by eel-ghan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef IS_INPUT_HPP
# define IS_INPUT_HPP

#include <iterator>

namespace ft
{
    template <typename T>
    struct is_input
    {
       static const bool value = false;
    };

    template <>
    struct is_input<std::input_iterator_tag>
    {
       static const bool value = true;
    };
    
}

#endif