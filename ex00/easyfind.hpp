#pragma once

#include <algorithm>
#include <exception>
#include <iterator>
#include <vector>
#include <list>

class NotFoundException : public std::exception
{
    public:
        virtual const char* what() const throw();
};

const char *NotFoundException::what() const throw()
{
    return "Not found";
}

template <typename T>
typename T::iterator easyfind(T &container, int value)
{
    typename T::iterator it = std::find(container.begin(), container.end(), value);
    if (it == container.end())
        throw NotFoundException();
    return it;
}