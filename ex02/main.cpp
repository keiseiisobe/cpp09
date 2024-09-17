#include "PmergeMe.hpp"

int	main(int argc, char *argv[])
{
	if (argc != 2)
	{
		std::cerr << "Notice: ./PmergeMe [positive integer sequence]" << std::endl;
		return 1;
	}
	std::array<int>	a;
	arg2intSeq(a, argv[1]);

	std::list<int>	l;
	intSeq2list(l, a);

//	std::vector<int>	v;
//	intSeq2vector(v, argv[1]);
}
