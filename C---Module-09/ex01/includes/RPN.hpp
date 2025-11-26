#ifndef RPN_HPP
#define RPN_HPP

#include <string>
#include <stack>
#include <iostream>
#include <sstream>
#include <exception>

class RPN
{
	private:
		std::stack<int> _stack;
		
		bool	isOperator(const std::string& token) const;
		bool	isNumber(const std::string& token) const;
		int		performOperation(int a, int b, char op) const;
		
	public:
		RPN();
		RPN(const RPN& other);
		RPN& operator=(const RPN& other);
		~RPN();
		
		int		calculate(const std::string& expression);
};

#endif
