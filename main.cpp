/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eel-ghan <eel-ghan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/17 17:11:33 by eel-ghan          #+#    #+#             */
/*   Updated: 2023/01/17 17:15:01 by eel-ghan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <vector>
#include "src/Vector/Vector.hpp"
#include <cstdlib>

int main(void)
{
    /* constructors used in the same order as described above:*/
    std::vector<int> first;                                // empty vector of ints
    std::vector<int> second (4,100);                       // four ints with value 100
    std::vector<int> third (second.begin(),second.end());  // iterating through second
    std::vector<int> fourth (third);                       // a copy of third

    // the iterator constructor can also be used to construct from arrays:
    int myints[] = {16,2,77,29};
    std::vector<int> fifth (myints, myints + sizeof(myints) / sizeof(int) );

    std::cout << "The contents of fifth are:";
    for (std::vector<int>::iterator it = fifth.begin(); it != fifth.end(); ++it)
        std::cout << ' ' << *it;
    std::cout << '\n';

    // vector assign
    // std::vector<int> first;
    // std::vector<int> second;
    // std::vector<int> third;

    // first.assign (7,100);             // 7 ints with a value of 100

    // std::vector<int>::iterator it;
    // it=first.begin()+1;

    // second.assign (it,first.end()-1); // the 5 central values of first

    // int myints[] = {1776,7,4};
    // third.assign (myints,myints+3);   // assigning from array.

    // std::cout << "Size of first: " << int (first.size()) << '\n';
    // std::cout << "Size of second: " << int (second.size()) << '\n';
    // std::cout << "Size of third: " << int (third.size()) << '\n';

    return 0;
}