#pragma once 

#include <vector>
#include <algorithm>
#include <exception>

class Span
{
    private: 
        const unsigned int _N;
        unsigned int _size;
        std::vector<int> _numbers;

    public:
        Span();
        Span(unsigned int n);
        Span(const Span &other);
        ~Span();
        Span &operator=(const Span &other);

        void addNumber(int number);
        int shortestSpan() const;
        int longestSpan() const;

    class SpanFullException : public std::exception
    {
        public:
            const char *what() const throw();
    };

    class SpanNotEnoughNumbersException : public std::exception
    {
        public:
            const char *what() const throw();
    };
};