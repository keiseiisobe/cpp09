#ifndef BITCOINEXCHANGE_HPP
#define BITCOINEXCHANGE_HPP

#include <iostream>
#include <fstream>
#include <sstream>
#include <map>
#include <cstdlib>

#include "Regex.hpp"

using std::string;

void	csv2map(const string& filename, std::map<string, float>& map);
string	getResult(std::map<string, float>& db, const string& line);
void	exchangeBtc(std::map<string, float>& db, const string& filename);

#endif
