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
    // ft::vector<int> first;                                // empty vector of ints
    // ft::vector<int> second (4, 100);                       // four ints with value 100
    // ft::vector<int> third (second.begin(),second.end());  // iterating through second
    // ft::vector<int> fourth (third);                       // a copy of third

    // // // // the iterator constructor can also be used to construct from arrays:
    // int myints[] = {16, 2, 77, 29};
    // ft::vector<int> fifth(myints, myints + sizeof(myints) / sizeof(int));
    // std::cout << "The contents of fifth are:";
    // for (ft::vector<int>::iterator it = fifth.begin(); it != fifth.end(); ++it)
    //     std::cout << ' ' << *it;
    // std::cout << '\n';

    /* vector::assign */
    // ft::vector<int> first;
    // ft::vector<int> second;
    // ft::vector<int> third;

    // first.assign (7, 100);             // 7 ints with a value of 100

    // ft::vector<int>::iterator it;
    // it = first.begin() + 1;

    // second.assign(it, first.end() - 1); // the 5 central values of first

    // int myints[] = {1776, 7, 4};
    // third.assign(myints, myints + 3);   // assigning from array.

    // std::cout << "Size of first: " << int (first.size()) << '\n';
    // std::cout << "Size of second: " << int (second.size()) << '\n';
    // std::cout << "Size of third: " << int (third.size()) << '\n';

    /* vector::at */ 
    // ft::vector<int> myvector (10);   // 10 zero-initialized ints

    // // assign some values:
    // for (unsigned i = 0; i < myvector.size(); i++)
    //     myvector.at(i)=i;

    // std::cout << "myvector contains:";
    // for (unsigned i=0; i < myvector.size(); i++)
    //     std::cout << ' ' << myvector.at(i);
    // std::cout << '\n';

    /* vector::back */
    // ft::vector<int> myvector;

    // myvector.push_back(10);

    // while (myvector.back() != 0)
    // {
    //     myvector.push_back ( myvector.back() -1 );
    // }

    // std::cout << "myvector contains:";
    // for (unsigned i = 0; i < myvector.size(); i++)
    //     std::cout << ' ' << myvector[i];
    // std::cout << '\n';

    /* vecor::push_back */
    // ft::vector<int> myvector;
    // myvector.push_back(0);
    // myvector.push_back(100);
    // myvector.push_back(1000000);
    // std::cout << "size " << myvector.size() << '\n';
    // for(unsigned i = 0; i < myvector.size(); i++)
    //     std::cout << i << " : " << myvector.at(i) << '\n';

    /* comparing size, capacity and max_size */
    // ft::vector<int> myvector;

    // set some content in the vector:
    // for (int i=0; i<100; i++) myvector.push_back(i);

    // std::cout << "size: " << (int) myvector.size() << '\n';
    // std::cout << "capacity: " << (int) myvector.capacity() << '\n';
    // std::cout << "max_size: " << (int) myvector.max_size() << '\n';

    /* clearing vectors */
    // std::vector<int> myvector;
    // myvector.push_back (100);
    // myvector.push_back (200);
    // myvector.push_back (300);

    // std::cout << "myvector contains:";
    // for (unsigned i = 0; i < myvector.size(); i++)
    //     std::cout << ' ' << myvector[i];
    // std::cout << '\n';

    // myvector.clear();
    // myvector.push_back(1);
    // myvector.push_back(2);

    // std::cout << "myvector contains:";
    // for (unsigned i = 0; i < myvector.size(); i++)
    //     std::cout << ' ' << myvector[i];
    // std::cout << '\n';

    /* vector::pop_back */
    // std::vector<int> myvector;
    // int sum (0);

    // myvector.push_back(100);
    // myvector.push_back(200);
    // myvector.push_back(300);

    // while (!myvector.empty())
    // {
    //     sum += myvector.back();
    //     myvector.pop_back();
    // }

    // std::cout << "The elements of myvector add up to " << sum << '\n';

    /* vector::empty */
    // ft::vector<int> myvector;
    // int sum (0);

    // for (int i=1;i<=10;i++) myvector.push_back(i);

    // while (!myvector.empty())
    // {
    //     sum += myvector.back();
    //     myvector.pop_back();
    // }

    // td::cout << "total: " << sum << '\n';

    /* erasing from vector */ 
    // ft::vector<int> myvector;

    // // set some values (from 1 to 10)
    // for (int i = 1; i <= 10; i++) myvector.push_back(i);

    // // // erase the 6th element
    // myvector.erase (myvector.begin() + 5);

    // // erase the first 3 elements:
    // myvector.erase (myvector.begin() + 2, myvector.begin() + 4);

    // std::cout << "myvector contains:";
    // for (unsigned i = 0; i < myvector.size(); i++)
    //     std::cout << ' ' << myvector[i];
    // std::cout << '\n';

    /* vector::front */
    // std::vector<int> myvector;

    // myvector.push_back(78);
    // myvector.push_back(16);

    // now front equals 78, and back 16

    // myvector.front() -= myvector.back();

    // std::cout << "myvector.front() is now " << myvector.front() << '\n';


    /* inserting into a vector */
    // ft::vector<int> myvector (3, 100);
    // ft::vector<int>::iterator it;

    // it = myvector.begin();
    // it = myvector.insert(it, 200);

    // // myvector.push_back(1);
    // myvector.insert(it, 2, 300);
    // // std::cout << *it << '\n';

    // // "it" no longer valid, get a new one:
    // it = myvector.begin();

    // ft::vector<int> anothervector(2, 400);
    // myvector.insert(it + 2, anothervector.begin(), anothervector.end());

    // int myarray[] = {501, 502, 503};
    // myvector.insert(myvector.begin(), myarray, myarray + 3);

    // std::cout << "myvector contains:";
    // for (it = myvector.begin(); it < myvector.end(); it++)
    //     std::cout << ' ' << *it;
    // std::cout << '\n';

    
    /* vector::reserve */
    // ft::vector<int>::size_type sz;

    // ft::vector<int> foo;
    // sz = foo.capacity();
    // std::cout << "making foo grow:\n";
    // for (int i = 0; i < 100; ++i) {
    //     foo.push_back(i);
    //     if (sz != foo.capacity())
    //     {
    //         sz = foo.capacity();
    //         std::cout << "capacity changed: " << sz << '\n';
    //     }
    // }

    // ft::vector<int> bar;
    // sz = bar.capacity();
    // bar.reserve(100);   // this is the only difference with foo above
    // std::cout << "making bar grow:\n";
    // for (int i = 0; i < 100; ++i) {
    //     bar.push_back(i);
    //     if (sz != bar.capacity())
    //     {
    //         sz = bar.capacity();
    //         std::cout << "capacity changed: " << sz << '\n';
    //     }
    // }


    /* resizing vector */
    // ft::vector<int> myvector;

    // // set some initial content:
    // for (int i = 1; i < 10; i++) myvector.push_back(i);

    // myvector.resize(5);
    // myvector.resize(8, 100);
    // myvector.resize(12);

    // std::cout << "myvector contains:";
    // for (unsigned i = 0; i < myvector.size(); i++)
    //     std::cout << ' ' << myvector[i];
    // std::cout << '\n';

    return 0;
}