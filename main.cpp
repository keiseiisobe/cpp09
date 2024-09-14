#include <iostream>
#include <stringstream>
#include <map>

int	main()
{
	// downloading data.csv
	std::map<>	m = getCsvData();
	// handle input file looping each line
	while (line = getline(std::cin))
	{
		std::stringstream	ss = getResult(line);
		std::cout << ss << std::endl;
	}
	return 0;
}
