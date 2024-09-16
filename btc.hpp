#ifndef BTC_HPP
#define BTC_HPP

#include <iostream>
#include <fstream>
#include <map>
#include <cstdlib>

#include "Regex.hpp"

using std::string;

void	Csv2map(const string& filename, std::map<string, float>& map);

#endif
