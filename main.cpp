#include "btc.hpp"

int	main(int argc, char *argv[])
{
	std::map<string, float>	map;
	try
	{
		// downloading data.csv
		Csv2map("data.csv", map);
	}
	catch (string& err_msg)
	{
		std::cerr << err_msg << std::endl;
		return 1;
	}
	// handle input file looping each line
//	while (line = getline(std::cin))
//	{
//		stringstream	ss = getResult(line);
//		std::cout << ss << std::endl;
//	}
//	return 0;
}
