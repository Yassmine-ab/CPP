#ifndef SPAN_HPP
#define SPAN_HPP

#include <vector>
#include <exception>
#include <algorithm>

class Span
{
	private:
		unsigned int		_maxSize;
		std::vector<int>	_numbers;

		Span();

	public:
		Span(unsigned int N);
		Span(const Span& other);
		Span& operator=(const Span& other);
		~Span();

		void addNumber(int number);
		int shortestSpan() const;
		int longestSpan() const;

		template <typename Iterator>
		void addRange(Iterator begin, Iterator end)
		{
			if (std::distance(begin, end) + _numbers.size() > _maxSize)
				throw SpanFullException();
			_numbers.insert(_numbers.end(), begin, end);
		}

		class SpanFullException : public std::exception
		{
			public:
				virtual const char* what() const throw()
				{
					return ("Span is full, cannot add more numbers");
				}
		};

		class NoSpanException : public std::exception
		{
			public:
				virtual const char* what() const throw()
				{
					return ("No span can be found (need at least 2 numbers)");
				}
		};
};

#endif
