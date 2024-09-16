#include "btc.hpp"

void	Csv2map(const string& filename, std::map<string, float>& map)
{
	std::ifstream	ifs(filename.c_str());
	if (!ifs.is_open())
		throw string("Error: could not open file.");
	string::size_type	pos;
	string	line;
	getline(ifs, line);
	for (;getline(ifs, line);)
	{
		if ((pos = line.find(",")) == string::npos)
			throw string("Error: invalid csv format.");
		string	key = line.substr(0, pos);
		string	value = line.substr(++pos);
		if (!my::Regex::isDatePattern(key))
			throw string("Error: invalid date format in csv.");
		if (!my::Regex::isPositivePointNumberPattern(value))
			throw string("Error: invalid positive point number format in csv.");
		map[key] = atof(value.c_str()); // if map[key] already exist, assign.
	}
}
