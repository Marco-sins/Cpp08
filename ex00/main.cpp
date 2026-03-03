#include "easyfind.hpp"
#include <iostream>
#include <vector>
#include <list>
#include <deque>


int main()
{
    std::vector<int> vec;
    for (int i = 0; i < 10; i++)
        vec.push_back(i);
    try
    {
        typename std::vector<int>::iterator it = easyfind(vec, 5);
        std::cout << *it << std::endl;
        it = easyfind(vec, 10);
        std::cout << *it << std::endl;
        it = easyfind(vec, 6);
        std::cout << *it << std::endl;
    }
    catch (const NotFoundException &e)
    {
        std::cerr << e.what() << std::endl;
    }

    std::list<int> lst;
    lst.push_back(15);
    lst.push_back(25);
    lst.push_back(35);
    try
    {
        typename std::list<int>::iterator it = easyfind(lst, 25);
        std::cout << *it << std::endl;
        it = easyfind(lst, 30);
        std::cout << *it << std::endl;
    }
    catch (const NotFoundException &e)
    {
        std::cerr << e.what() << std::endl;
    }

    std::deque<int> deq;
    deq.push_back(100);
    deq.push_back(200);
    deq.push_back(300);
    try
    {
        typename std::deque<int>::iterator it = easyfind(deq, 200);
        std::cout << *it << std::endl;
        it = easyfind(deq, 400);
        std::cout << *it << std::endl;
    }
    catch (const NotFoundException &e)
    {
        std::cerr << e.what() << std::endl;
    }

    return 0;
}