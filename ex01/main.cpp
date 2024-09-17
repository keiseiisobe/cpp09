#include "RPN.hpp"
#include <iostream>

int	main(int argc, char *argv[])
{
	if (argc != 2)
	{
		std::cerr << "Notice: ./RPN [reverse polish notation]" << std::endl;
		return 1;
	}
	try
	{
		std::cout << rpn(argv[1]) << std::endl;
	}
	catch (string& err_msg)
	{
		std::cerr << err_msg << std::endl;
	}
	return 0;
}
