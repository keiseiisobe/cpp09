#include "PosIntSeqArg.hpp"
#include <iostream>
#include <vector>

int main(int argc, const char *argv[])
{
	try
	{
		PosIntSeqArg arg(argc, argv);
		std::vector<size_t> value = arg.getSeq();
		std::vector<size_t>::iterator it = value.begin();
		for (; it != value.end(); it++) {
			std::cout << *it << " " << std::endl;
		}
	}
	catch(std::string& msg)
	{
		std::cout << "PmergeMe: " << msg << std::endl;
	}
	catch(std::exception& e)
	{
		std::cout << "PmergeMe: " << e.what() << std::endl;
	}
    return 0;
}
