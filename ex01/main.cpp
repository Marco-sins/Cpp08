#include "Span.hpp"
#include <iostream>

int main()
{
    Span sp = Span(5);
    try 
    {
        std::cout << sp.shortestSpan() << std::endl; // Exception: Not enough numbers
    }
    catch (const std::exception &e)
    {
        std::cerr << e.what() << std::endl;
    }
    sp.addNumber(6);
    sp.addNumber(3);
    sp.addNumber(17);
    sp.addNumber(9);
    sp.addNumber(11);
    try 
    {
        sp.addNumber(20); // Exception: Span is full
    }
    catch (const std::exception &e)
    {
        std::cerr << e.what() << std::endl;
    }
    std::cout << sp.shortestSpan() << std::endl; // 2
    std::cout << sp.longestSpan() << std::endl; // 14
    return 0;
}