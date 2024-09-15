#include "Regex.hpp"

using my::Regex;

Regex::Regex()
{
}

Regex::Regex(const Regex&)
{
}

Regex&	Regex::operator=(const Regex&)
{
	return *this;
}

Regex::~Regex()
{
}

bool	Regex::isDatePattern(const std::string& str) // yyyy-mm-dd
{
	const int	monthMin = 1;
	const int	monthMax = 12;
	const int	dayMin = 1;
	const int	dayMax = 31;

	int	i = 0;
	for (int c = 0;c < 4;c++,i++)
	{
		if (!str[i] || !std::isdigit(str[i]))
			return false;
	}
	if (str[i++] != '-')
		return false;
	for (int c= 0;c < 2;c++,i++)
	{
		if (!str[i] || !std::isdigit(str[i]))
			return false;
	}
	int	month = std::atoi(str.substr(i - 2, 2).c_str()); // extract mm, and convert to int
	if (!(month >= monthMin && month <= monthMax))
		return false;
	if (str[i++] != '-')
		return false;
	for (int c= 0;c < 2;c++,i++)
	{
		if (!str[i] || !std::isdigit(str[i]))
			return false;
	}
	int	day = std::atoi(str.substr(i - 2, 2).c_str()); // extract dd, and convert to int
	if (!(day >= dayMin && day <= dayMax))
		return false;
	if (str[i])
		return false;
	return true;
}

bool	Regex::isPositiveIntegerPattern(const std::string& str)
{
	if (str.empty())
		return false;
	for (int i = 0;str[i];i++)
	{
		if (!std::isdigit(str[i]))
			return false;
	}
	return true;
}

bool	Regex::isPositivePointNumberPattern(const std::string& str)
{
	if (str.empty())
		return false;
	if (Regex::isPositiveIntegerPattern(str))
		return true;
	int i = 0;
	if (!std::isdigit(str[i++]))
		return false;
	for (;str[i];i++)
	{
		if (!std::isdigit(str[i]))
			break;
	}
	if (str[i++] != '.')
		return false;
	if (!Regex::isPositiveIntegerPattern(str.substr(i)))
		return false;
	return true;
}
