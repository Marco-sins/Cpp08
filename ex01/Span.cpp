#include "Span.hpp"

Span::Span() : _N(0), _size(0) {}

Span::Span(unsigned int n) : _N(n), _size(0) {}

Span::Span(const Span &copy) : _N(copy._N), _size(copy._size), _numbers(copy._numbers) {}

Span::~Span() {}

Span &Span::operator=(const Span &copy)
{
    if (this != &copy)
        *this = copy;
    return *this;
}

void Span::addNumber(int number)
{
    if (_size >= _N)
        throw SpanFullException();
    _numbers.push_back(number);
    _size++;
}

int Span::shortestSpan() const
{
    if (_size < 2)
        throw SpanNotEnoughNumbersException();
    std::vector<int> sortedNumbers = _numbers;
    std::sort(sortedNumbers.begin(), sortedNumbers.end());
    int minSpan = sortedNumbers[1] - sortedNumbers[0];
    for (size_t i = 1; i < sortedNumbers.size(); i++)
    {
        int span = sortedNumbers[i] - sortedNumbers[i - 1];
        if (span < minSpan)
            minSpan = span;
    }
    return minSpan;
}

int Span::longestSpan() const
{
    if (_size < 2)
        throw SpanNotEnoughNumbersException();
    int min = *std::min_element(_numbers.begin(), _numbers.end());
    int max = *std::max_element(_numbers.begin(), _numbers.end());
    return max - min;
}

const char *Span::SpanFullException::what() const throw()
{
    return "Span is full. Cannot add more numbers.";
}

const char *Span::SpanNotEnoughNumbersException::what() const throw()
{
    return "Not enough numbers to find a span.";
}