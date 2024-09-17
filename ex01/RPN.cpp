#include "RPN.hpp"

void	error(const string& msg, const string& str, int i)
{
	std::stringstream	ss;
	ss << i;
	string	err_msg = "Error: " + msg + " at str[";
	err_msg += ss.str();
	err_msg += "] ('";
	err_msg += str[i];
	err_msg += "')";
	throw err_msg;
}

bool	isOperator(char c)
{
	return (c == '+' || c == '-' || c == '/' || c == '*');
}

int	calculate(char operand, int a, int b)
{
	switch(operand)
	{
		case '+':
			return a + b;
		case '-':
			return a - b;
		case '/':
			if (b == 0)
				throw std::string("Error: floating point exception detected");
			return a / b;
		case '*':
			return a * b;
		default:
			return -1;
	}
}

int	rpn(const string& str)
{
	std::stack<int>	stack;
	int	tmp1 = 0;
	int	tmp2 = 0;
	int	result = 0;
	int	i = 0;
	for (;str[i];i++)
	{
		if (isspace(str[i]))
			continue;
		else if (isdigit(str[i]))
			stack.push(str[i] - '0');
		else if (isOperator(str[i]))
		{
			if (stack.size() < 2)
				error("cannot pop", str, i);
			tmp1 = stack.top();
			stack.pop();
			tmp2 = stack.top();
			stack.pop();
			result = calculate(str[i], tmp2, tmp1);
			stack.push(result);
		}
		else
			error("invalid character", str, i);
	}
	if (stack.empty())
		throw string("Error: stack is empty");
	return stack.top();
}
