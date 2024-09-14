#include "BasicRegex.hpp"

my::BasicRegex::BasicRegex() // deleted
{
}

my::BasicRegex::BasicRegex(std::string pattern)
: automata(compilePattern(automata, pattern))
{
}

my::BasicRegex::BasicRegex(const BasicRegex&) // deleted
{
}

my::BasicRegex&	my::BasicRegex::operator=(const BasicRegex&) // deleted
{
}

my::BasicRegex::~BasicRegex()
{
	deleteAutomata();
}

t_automata	*compilePattern(t_automata *automata, std::string& pattern)
{
	return compilePatternInternal(automata, pattern, 0);
}

t_automata	*compilePatternInternal(t_automata *automata, std::string& pattern, int index)
{
	automata = new t_automata;
	if (isSpecialCharacter(pattern[index]))
	{
		if (pattern[++index] == 'd')
		{
			func[0] = std::isdigit;
		}
	}
}

bool	isSpacialCharacter(char c)
{
	if (c == '\\' || c == '(') // ...
		return true;
	return false;
}
