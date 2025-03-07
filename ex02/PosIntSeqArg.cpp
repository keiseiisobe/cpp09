#include "PosIntSeqArg.hpp"
#include <iostream>

bool PosIntSeqArg::isPosInt(const int argc, const char *argv[]) const
{
	for (int i = 1; i < argc; i++) {
		std::string num(argv[i]);
		for (size_t j = 0; j < num.size(); j++) {
			if (!isdigit(num[j]))
				return false;
		}
		std::string intMax("2147483647");
		if (num.size() > intMax.size() || (num.size() == intMax.size() && num > intMax))
			return false;
	}
	return true;
}

PosIntSeqArg::PosIntSeqArg(const int argc, const char *argv[])
{
	if (argc < 2)
		throw std::string("./PmergeMe [positive interger sequense (no duplication)]");
	if (!isPosInt(argc, argv))
		throw std::string("Invalid number detected (only positive interger is available)");
	for (int i = 1; i < argc; i++) {
		seq.push_back(static_cast<size_t>(std::atoi(argv[i])));
	}
	if (!noDuplication())
		throw std::string("some number are duplicated");
}

PosIntSeqArg::~PosIntSeqArg()
{
}

const std::vector<size_t>& PosIntSeqArg::getSeq() const
{
	return seq;
}

bool PosIntSeqArg::noDuplication() const
{
	std::vector<size_t> tmp(seq);
	std::sort(tmp.begin(), tmp.end());
	std::vector<size_t>::iterator it = tmp.begin();
	size_t prev = *it;
	it++;
	for (;it != tmp.end();it++)
	{
		if (prev == *it)
			return false;
		prev = *it;
	}
	return true;
}
