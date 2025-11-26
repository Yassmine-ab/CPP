#include "RPN.hpp"

RPN::RPN()
{
}

RPN::RPN(const RPN& other)
{
	*this = other;
}

RPN& RPN::operator=(const RPN& other)
{
	if (this != &other)
		this->_stack = other._stack;
	return (*this);
}

RPN::~RPN()
{
}

bool RPN::isOperator(const std::string& token) const
{
	return (token == "+" || token == "-" || token == "*" || token == "/");
}

bool RPN::isNumber(const std::string& token) const
{
	if (token.length() == 1 && std::isdigit(token[0]))
		return (true);
	return (false);
}

int RPN::performOperation(int a, int b, char op) const
{
	switch (op)
	{
		case '+':
			return (a + b);
		case '-':
			return (a - b);
		case '*':
			return (a * b);
		case '/':
			if (b == 0)
				throw std::runtime_error("Error: division by zero");
			return (a / b);
		default:
			// Ne devrait jamais arriver
			throw std::runtime_error("Error: invalid operator");
	}
}

int RPN::calculate(const std::string& expression)
{
	std::istringstream iss(expression); // Flux d'entrée pour parcourir l'expression
	std::string token;
	
	// Vider la pile au cas où elle contiendrait des données précédentes
	while (!_stack.empty())
		_stack.pop();

	while (iss >> token) // Parcourt chaque token de l'expression
	{
		if (isNumber(token))
			_stack.push(token[0] - '0');
		else if (isOperator(token))
		{
			if (_stack.size() < 2)
				throw std::runtime_error("Error: insufficient operands");
			int b = _stack.top(); // retourne une référence à l'élément au sommet de la pile
			_stack.pop(); // retire l'élément au sommet de la pile
			int a = _stack.top();
			_stack.pop();
			int result = performOperation(a, b, token[0]);
			_stack.push(result);
		}
		else
			throw std::runtime_error("Error: invalid token");
	}

	if (_stack.size() != 1)
		throw std::runtime_error("Error: invalid expression");
	
	return (_stack.top());
}
