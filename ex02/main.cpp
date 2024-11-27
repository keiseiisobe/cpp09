#include "PosIntSeqArg.hpp"
#include "VectorPmergeMe.hpp"
#include "ListPmergeMe.hpp"
#include <iostream>
#include <vector>
#include <ctime>
#include <iomanip>
#include <sys/time.h>

#ifdef TEST
template<class T>
bool noDuplication(T& t)
{
	typename T::iterator it = t.begin();
	size_t prev = *it;
	it++;
	for (;it != t.end();it++)
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

		// vector
		struct timeval vTv1;
		gettimeofday(&vTv1, NULL);
		VectorPmergeMe v(before);
		v.sort();
		struct timeval vTv2;
		gettimeofday(&vTv2, NULL);
		std::vector<size_t> vAfter = v.getSeq();
		std::vector<size_t>::iterator vit = vAfter.begin();
		std::cout << "After: ";
		for (;vit != vAfter.end();vit++) {
			std::cout << *vit << " ";
		}
		std::cout << std::endl;
		double vDiff = vTv2.tv_usec - vTv1.tv_usec;
		std::cout << "Time to process a range of " << before.size() << " elements with std::vector : " << std::setprecision(6) << vDiff << " us" << std::endl;

		// list
		struct timeval lTv1;
		gettimeofday(&lTv1, NULL);
		ListPmergeMe l(before);
		l.sort();
		struct timeval lTv2;
		gettimeofday(&lTv2, NULL);
		std::list<size_t> lAfter = l.getSeq();
		/*
		std::list<size_t>::iterator lit = lAfter.begin();
		std::cout << "lAfter: ";
		for (;lit != lAfter.end();lit++)
		{
			std::cout << *lit << " ";
		}
		std::cout << std::endl;
		*/
		double lDiff = lTv2.tv_usec - lTv1.tv_usec;
		std::cout << "Time to process a range of " << before.size() << " elements with std::list : " << std::setprecision(6) << lDiff << " us" << std::endl;
#ifdef TEST
		if (!std::is_sorted(vAfter.begin(), vAfter.end()))
		{
			std::cout << "PmergeMeTest: sort failed in vector" << std::endl;
			return 0;
		}
		else if (!noDuplication(vAfter))
		{
			std::cout << "PmergeMeTest: duplication after sort in vector" << std::endl;
			return 0;
		}
		else if (!std::is_sorted(lAfter.begin(), lAfter.end()))
		{
			std::cout << "PmergeMeTest: sort failed in list" << std::endl;
			return 0;
		}
		else if (!noDuplication(lAfter))
		{
			std::cout << "PmergeMeTest: duplication after sort in list" << std::endl;
			return 0;
		}
		else
		{
			std::cout << "successfully sorted" << std::endl;
			std::cout << "total comparison of vector: " << v.numOfComparison << std::endl;
			std::cout << "total comparison of list: " << l.numOfComparison << std::endl;
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
