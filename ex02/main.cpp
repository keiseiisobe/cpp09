#include "PosIntSeqArg.hpp"
#include "VectorPmergeMe.hpp"
#include <iostream>
#include <vector>
#include <ctime>
#include <iomanip>
#include <sys/time.h>

#ifdef TEST
bool noDuplication(std::vector<size_t>& v)
{
	std::vector<size_t>::iterator it = v.begin();
	size_t prev = *it;
	it++;
	for (;it != v.end();it++)
	{
		if (prev == *it)
			return false;
		prev = *it;
	}
	return true;
}
#endif

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
		struct timeval vTv1;
		gettimeofday(&vTv1, NULL);
		VectorPmergeMe v(before);
		v.sort();
		struct timeval vTv2;
		gettimeofday(&vTv2, NULL);
		std::vector<size_t> vAfter = v.getSeq();
		std::vector<size_t>::iterator vit = vAfter.begin();
		std::cout << "After:  ";
		for (;vit != vAfter.end();vit++) {
			std::cout << *vit << " ";
		}
		std::cout << std::endl;
		double vDiff = vTv2.tv_usec - vTv1.tv_usec;
		std::cout << "Time to process a range of " << before.size() << " elements with std::vector : " << std::setprecision(6) << vDiff << " us" << std::endl;
#ifdef TEST
		if (!std::is_sorted(vAfter.begin(), vAfter.end()))
		{
			std::cout << "PmergeMeTest: sort failed" << std::endl;
			return 0;
		}
		else if (!noDuplication(vAfter))
		{
			std::cout << "PmergeMeTest: duplication after sort" << std::endl;
			return 0;
		}
		else
		{
			std::cout << "successfully sorted" << std::endl;
			std::cout << "total comparison: " << v.numOfComparison << std::endl;
		}
#endif
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
