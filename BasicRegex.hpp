#ifndef BASICREGEX_HPP
#define BASICREGEX_HPP

#include <string>

namespace	my
{
	typedef struct s_automata
	{
		int	numBehavior;
		bool (*func)(char c)[numBehavior];
		bool	isBeginState = false;
		bool	isEndState = false;
		void	*next[numBehavior];
	}	t_automata;

//	template<class T, class C = traits...>
	class	BasicRegex
	{
		// typedef traits ...
		private:
			// delete these constructors
			BasicRegex();
			BasicRegex(const BasicRegex&);
			BasicRegex&	operator=(const BasicRegex&);
		public:
			t_automata	*automata;

			BasicRegex(std::string& pattern);
			~BasicRegex();
	};
}

#endif
