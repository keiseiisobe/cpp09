#include "BitcoinExchange.hpp"

int	main(int argc, char *argv[])
{
	if (argc != 2)
	{
		std::cerr << "Notice: ./btc [filename]" << std::endl;
		return 1;
	}
	std::map<string, float>	map;
	try
	{
		csv2map("data.csv", map);
		exchangeBtc(map, argv[1]);
	}
	catch (string& err_msg)
	{
		std::cerr << err_msg << std::endl;
		return 1;
	}
	return 0;
}
