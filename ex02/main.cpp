#include "PosIntSeqArg.hpp"
#include "VectorPmergeMe.hpp"
#include <iostream>
#include <vector>

int main(int argc, const char *argv[])
{
	try
	{
		PosIntSeqArg arg(argc, argv);
		std::vector<size_t> before = arg.getSeq();
		std::vector<size_t>::iterator it = before.begin();
		std::cout << "Before: ";
		for (; it != before.end(); it++) {
			std::cout << *it << " ";
		}
		std::cout << std::endl;
		VectorPmergeMe v(before);
		v.sort();
		std::vector<size_t> vAfter = v.getSeq();
		std::vector<size_t>::iterator vit = vAfter.begin();
		std::cout << "After:  ";
		for (;vit != vAfter.end();vit++) {
			std::cout << *vit << " ";
		}
		std::cout << std::endl;
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
