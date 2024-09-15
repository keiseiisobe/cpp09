#ifndef REGEX_HPP
#define REGEX_HPP

#include <iostream> // debug
#include <string>
#include <cstdlib>

namespace	my
{
	class	Regex
	{
		private:
			Regex();
			Regex(const Regex&);
			Regex&	operator=(const Regex&);
		public:
			~Regex();
			static bool	isDatePattern(const std::string& str);
			static bool	isPositiveIntegerPattern(const std::string& str);
			static bool	isPositivePointNumberPattern(const std::string& str);
	};
};

#endif
