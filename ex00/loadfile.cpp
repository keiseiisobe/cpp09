#include "btc.hpp"

void	csv2map(const string& filename, std::map<string, float>& map)
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

string	getResult(std::map<string, float>& db, const string& line)
{
	string::size_type	pos;
	if ((pos = line.find(" | ")) == string::npos)
		throw string("Error: invalid txt file format.");
	string	key = line.substr(0, pos);
	string	value = line.substr(pos + 3);
	if (!my::Regex::isDatePattern(key))
		throw string("Error: invalid date format in csv.");
	if (!my::Regex::isPositivePointNumberPattern(value))
		throw string("Error: invalid positive point number format in csv.");
	float	v = atof(value.c_str());
	int	tmp = static_cast<int>(v);
	if (!(tmp >= 0 && tmp <= 1000))
		throw string("Error: too large a number.");
	std::stringstream	ss;
	ss << key << " => " << value << " = ";
	try
	{
		ss << db.at(key) * v;
	}
	catch (std::out_of_range&)
	{
		db[key] = 0;
		std::map<string, float>::iterator	it = db.find(key);
		if (it == db.begin()) // date referenced by key is older than date bitcoin launched.
			throw string("Error: too old date.");
		ss << (--it)->second * v;
		db.erase(key);
	}
	return ss.str();
}

void	exchangeBtc(std::map<string, float>& db, const string& filename)
{
	std::ifstream	ifs(filename.c_str());
	if (!ifs.is_open())
		throw string("Error: could not open file.");
	string	line;
	getline(ifs, line);
	for (;getline(ifs, line);)
	{
		try
		{
			string	result = getResult(db, line);
			std::cout << result << std::endl;
		}
		catch (string& err_msg)
		{
			std::cerr << err_msg << std::endl;
		}
	}
}
