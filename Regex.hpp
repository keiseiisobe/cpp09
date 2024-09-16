#ifndef REGEX_HPP
#define REGEX_HPP

#include <string>
#include <cstdlib>

namespace	my
{
	class	Regex
	{
		private:
			// delete
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
